#include "../include/Navigation.hpp"

using namespace tx2slam;

void Navigation::QTUI_cmd_Callback(const std_msgs::Int32MultiArray::ConstPtr& msg)
{
  mappingStatusCmd = msg->data.at(1);

  goalPoseStamped.pose.position.x = msg->data.at(4)/1000.0;
  goalPoseStamped.pose.position.y = msg->data.at(5)/1000.0;

  if(msg->data.at(2) != 0){
    goalSet = msg->data.at(2);
  }

  cmd_vel = msg->data.at(3)/100.0;

}

void Navigation::carTF_orb_Callback(const geometry_msgs::PoseStamped::ConstPtr& pose){
  carTF_orb = *pose;
}

void Navigation::carTF_zed2_Callback(const geometry_msgs::PoseStamped::ConstPtr& pose){
  carTF_zed2 = *pose;
}

void Navigation::navigation_Callback(const ros::TimerEvent& event)
{

  if(goalSet == 1 || slamGoalSet == 1)
  {
//    setTargetSpeed(0.3, 0.3, 0);
//    setTargetOmega(0.7, 0/*pidController(0.3, imu_Msg.angular_velocity.z)*/);
//    ROS_INFO("omega_target is: %f, omega_actual is: %f",0.3,imu_Msg.angular_velocity.z);
    if(rrtStarPlan(cloud_xyzFused,carTF_zed2,goalPoseStamped) == true){
      smoothTraj_pub.publish(smooth_msg);
      traj_pub.publish(msg);
      smooth_msg.poses.clear();
      msg.poses.clear();
      isGetSolution = 1;
    }else{
      ROS_WARN("could't find a solution, try once again");
      if(rrtStarPlan(cloud_xyzFused,carTF_zed2,goalPoseStamped)){
        ROS_INFO("find a solution at a second time");
      }else{
        ROS_INFO("give up trying");
      }
      isGetSolution = 0;
    }
    slamGoalSet = 0;
    goalSet = 0;
//    cmdVelPub();
  }else{
    setTargetSpeed(0, 0, 0);
  }

}

void Navigation::readPointFusedCloud(const sensor_msgs::PointCloud2::ConstPtr& cloud)
{
  pcl::PCLPointCloud2* cloud2 = new pcl::PCLPointCloud2;
  pcl::PCLPointCloud2ConstPtr cloudPtr(cloud2);
  pcl_conversions::toPCL(*cloud, *cloud2);

  if ((cloudPtr->width * cloudPtr->height) == 0)
    return;
  pcl::fromPCLPointCloud2 (*cloudPtr, *cloud_xyzFused);
}

bool Navigation::plan(void)
{
  // create a planner for the defined space
  ompl::geometric::InformedRRTstar* rrt = new ompl::geometric::InformedRRTstar(si);
  // set the maximum length of a motion to be added in the tree of motions,
  // which greatly influences the runtime of the algorithm
  ompl::base::PlannerPtr plan(rrt);

  // set the problem we are trying to solve for the planner
  plan->setProblemDefinition(pdef);
  // perform setup steps for the planner
  plan->setup();
  // print the settings for this space
//  si->printSettings(std::cout);
//  ROS_INFO("the problem setting is:");
  // Print information about the start and goal states and the optimization objective.
//  pdef->print(std::cout);
  // attempt to solve the problem within one second of planning time

  ompl::base::PlannerStatus solved;
  try{
    solved = plan->solve(1);
  }
  catch(ompl::Exception e)
  {
    ROS_WARN("Error occourred: %s", e.what());
  }

  if (solved)
  {
    // get the goal representation from the problem definition (not the same as the goal state)
    // and inquire about the found path
    ROS_INFO("Found solution:");
    ompl::base::PathPtr path = pdef->getSolutionPath();
    ompl::geometric::PathGeometric* pth = pdef->getSolutionPath()->as<ompl::geometric::PathGeometric>();
    ROS_INFO("Origin Path:");
    pth->printAsMatrix(std::cout);
    // print the path to screen
    path->print(std::cout);

    msg.header.stamp = ros::Time::now();
    msg.header.frame_id = "map";

    for (std::size_t path_idx = 0; path_idx < pth->getStateCount (); path_idx++)
    {
        const ompl::base::SE3StateSpace::StateType *se3state = pth->getState(path_idx)->as<ompl::base::SE3StateSpace::StateType>();
        // extract the first component of the state and cast it to what we expect
        const ompl::base::RealVectorStateSpace::StateType *pos = se3state->as<ompl::base::RealVectorStateSpace::StateType>(0);
        // extract the second component of the state and cast it to what we expect
        const ompl::base::SO3StateSpace::StateType *rot = se3state->as<ompl::base::SO3StateSpace::StateType>(1);
        geometry_msgs::PoseStamped pose;

        pose.pose.position.x = pos->values[0];
        pose.pose.position.y = pos->values[1];
        pose.pose.position.z = pos->values[2];

        pose.pose.orientation.x = rot->x;
        pose.pose.orientation.y = rot->y;
        pose.pose.orientation.z = rot->z;
        pose.pose.orientation.w = rot->w;

        msg.poses.push_back(pose);
    }

    // Path smoothing using bspline
    // B spline optimize
    ompl::geometric::PathSimplifier* pathBSpline = new ompl::geometric::PathSimplifier(si);
    path_smooth = new ompl::geometric::PathGeometric(dynamic_cast<const ompl::geometric::PathGeometric&>(*pdef->getSolutionPath()));
    pathBSpline->smoothBSpline(*path_smooth,3);
    ROS_INFO("Smoothed Path:");
    path_smooth->print(std::cout);

    smooth_msg.header.stamp = ros::Time::now();
    smooth_msg.header.frame_id = "map";

    for (std::size_t idx = 0; idx < path_smooth->getStateCount (); idx++)
    {
        // cast the abstract state type to the type we expect
        const ompl::base::SE3StateSpace::StateType *se3state = path_smooth->getState(idx)->as<ompl::base::SE3StateSpace::StateType>();
        // extract the first component of the state and cast it to what we expect
        const ompl::base::RealVectorStateSpace::StateType *pos = se3state->as<ompl::base::RealVectorStateSpace::StateType>(0);
        // extract the second component of the state and cast it to what we expect
        const ompl::base::SO3StateSpace::StateType *rot = se3state->as<ompl::base::SO3StateSpace::StateType>(1);

        geometry_msgs::PoseStamped point;

        point.pose.position.x = pos->values[0];
        point.pose.position.y = pos->values[1];
        point.pose.position.z = pos->values[2];

        point.pose.orientation.x = rot->x;
        point.pose.orientation.y = rot->y;
        point.pose.orientation.z = rot->z;
        point.pose.orientation.w = rot->w;

        smooth_msg.poses.push_back(point);

    }

//    // Clear memory
    pdef->clearSolutionPaths();

    return true;
  }
  else{
      ROS_ERROR("No solution found");
      return false;
  }
  return true;
}

bool Navigation::isStateValid(const ompl::base::State *state)
{
  // cast the abstract state type to the type we expect
  const ompl::base::SE3StateSpace::StateType *se3state = state->as<ompl::base::SE3StateSpace::StateType>();

  // extract the first component of the state and cast it to what we expect
  const ompl::base::RealVectorStateSpace::StateType *pos = se3state->as<ompl::base::RealVectorStateSpace::StateType>(0);

  // extract the second component of the state and cast it to what we expect
  const ompl::base::SO3StateSpace::StateType *rot = se3state->as<ompl::base::SO3StateSpace::StateType>(1);

  fcl::CollisionObject<float> treeObj((tree_obj));
  fcl::CollisionObject<float> slamCarObject(slamCar);

  // check validity of state defined by pos & rot
  fcl::Vector3f translation(pos->values[0],pos->values[1],pos->values[2]);
  fcl::Quaternionf rotation(rot->w, rot->x, rot->y, rot->z);
  slamCarObject.setTransform(rotation, translation);
  fcl::CollisionRequest<float> requestType(1,false,1,false);
  fcl::CollisionResult<float> collisionResult;
  fcl::collide(&slamCarObject, &treeObj, requestType, collisionResult);

  return(!collisionResult.isCollision());
}

ompl::base::OptimizationObjectivePtr Navigation::getThresholdPathLengthObj(const ompl::base::SpaceInformationPtr& si)
{
    ompl::base::OptimizationObjectivePtr obj(new ompl::base::PathLengthOptimizationObjective(si));
    // obj->setCostThreshold(ob::Cost(1.51));
    return obj;
}

ompl::base::OptimizationObjectivePtr Navigation::getPathLengthObjWithCostToGo(const ompl::base::SpaceInformationPtr& si)
{
    ompl::base::OptimizationObjectivePtr obj(new ompl::base::PathLengthOptimizationObjective(si));
    obj->setCostToGoHeuristic(&ompl::base::goalRegionCostToGo);
    return obj;
}

bool Navigation::rrtStarPlan(pcl::PointCloud<pcl::PointXYZRGB>* pclCloud, geometry_msgs::PoseStamped pose_Start, geometry_msgs::PoseStamped pose_Goal)
{
  // turn the pcl cloud to fcl::CollisionGeometry after octree
  // updtae the octomap
  octomap::OcTree* treeOctomapPtr = new octomap::OcTree( 0.05 );
  for(auto p:pclCloud->points)
  {
    treeOctomapPtr->updateNode( octomap::point3d(p.x, p.y, p.z), true );
  }
  treeOctomapPtr->updateInnerOccupancy();
  fcl::OcTree<float>* tree = new fcl::OcTree<float>(std::shared_ptr<const octomap::OcTree>(treeOctomapPtr));
  tree_obj = std::shared_ptr<fcl::CollisionGeometry<float>>(tree);

  // set start and goal
  ompl::base::ScopedState<ompl::base::SE3StateSpace> start(space);
  start->setXYZ(pose_Start.pose.position.x, pose_Start.pose.position.y, pose_Start.pose.position.z);
  start->as<ompl::base::SO3StateSpace::StateType>(1)->setIdentity();
  pdef->clearStartStates();
  pdef->addStartState(start);
  ompl::base::ScopedState<ompl::base::SE3StateSpace> goal(space);
  goal->setXYZ(pose_Goal.pose.position.x, pose_Goal.pose.position.y, pose_Goal.pose.position.z);
  goal->as<ompl::base::SO3StateSpace::StateType>(1)->setIdentity();
  pdef->clearGoal();
  pdef->setGoalState(goal);
  // plan the trajectory
//  replan();
  bool isFindSolution = plan();

  return isFindSolution;
}

void Navigation::cmdVelPub()
{

}

bool Navigation::setTargetSpeed(float vLeft, float vRight, uint8_t direction)
{
  if(vLeft < 0)
    vLeft = 0;
  else if(vLeft > 1)
    vLeft = 1;

  if(vRight < 0)
    vRight = 0;
  else if(vRight > 1)
    vRight = 1;

  switch(direction)
  {
  case 0: // go straight
//    ser.UT_REGISTERS_TAB[0] = (((uint16_t)(vLeft/1*127)) << 8) | ((uint16_t)(vRight/1*127));
    speedArray[1] = (uint8_t)(vLeft/1*127);
    speedArray[2] = (uint8_t)(vRight/1*127);
    break;
  case 1: // turn left
//    ser.UT_REGISTERS_TAB[0] = (((uint16_t)(255-vLeft/1*127)) << 8) | ((uint8_t)(vRight/1*127));
    speedArray[1] = (uint8_t)(255-vLeft/1*127);
    speedArray[2] = (uint8_t)(vRight/1*127);
    break;
  case 2: // turn right
//    ser.UT_REGISTERS_TAB[0] = (((uint16_t)(vLeft/1*127)) << 8) | ((uint8_t)(255-vRight/1*127));
    speedArray[1] = (uint8_t)(vLeft/1*127);
    speedArray[2] = (uint8_t)(255-vRight/1*127);
    break;
  case 3: // go back
//    ser.UT_REGISTERS_TAB[0] = (((uint16_t)(255-vLeft/1*127)) << 8) | ((uint8_t)(255-vRight/1*127));
    speedArray[1] = (uint8_t)(255-vLeft/1*127);
    speedArray[2] = (uint8_t)(255-vRight/1*127);
    break;
  }

  if(ser.isOpen()){
    ser.write(speedArray);
  }else{
    ROS_ERROR("Unable to send data since port not open");
  }

//  if(ser.WriteToPort()){
//    return true;
//  }else{
////    ROS_ERROR("Fail to send serial mag");
//    return false;
//  }
}

bool Navigation::setTargetOmega(float omega, float omegaBias)
{
  if(omega >= 0){
    setTargetSpeed((omega+omegaBias)*0.4,omega+omegaBias,1);
  }else{
    setTargetSpeed(-omega+omegaBias,(-omega+omegaBias)*0.4,2);
  }
  return true;
}

float Navigation::pidController(float omegaTarget, float omegaActual)
{
  static float Bias,omegaBias,Integral_bias,Last_Bias;
  Bias=omegaTarget-omegaActual;
  Integral_bias+=Bias;
  omegaBias=KP*Bias+KI*Integral_bias+KD*(Bias-Last_Bias);
  Last_Bias=Bias;

  return omegaBias;
}

void Navigation::init()
{
  ros::init (init_argc, init_argv, "Navigation");
  ros::NodeHandle n;

  // publish planned path
  smoothTraj_pub = n.advertise<nav_msgs::Path>( "Trajectory_marker", 1 );
  traj_pub = n.advertise<nav_msgs::Path>("waypoints",1);

  // subscribe poses and fused pointcloud
  carTF_orb_sub = n.subscribe("/orb_slam2_stereo/pose", 1, &Navigation::carTF_orb_Callback,this);
  carTF_zed2_sub = n.subscribe("/zed2/zed_node/pose", 1, &Navigation::carTF_zed2_Callback,this);
  pointFusedCloud_sub = n.subscribe("/mapBuild/cloud_Fused",1, &Navigation::readPointFusedCloud, this);

  // set a Timer to call path-plan function
  navigationCtrlTimer = n.createTimer(ros::Duration(0.1), &Navigation::navigation_Callback,this);

  // receive the UI cmd
  QTUI_cmd_sub = n.subscribe("/rover/QtUI_cmd_Msg", 1, &Navigation::QTUI_cmd_Callback,this);

  ros::spin();
}

Navigation::Navigation(int argc, char** argv)
{
  // slam Car shape define
  slamCar = std::shared_ptr<fcl::CollisionGeometry<float>>(new fcl::Box<float>(0.8, 0.8, 0.3));
//  fcl::OcTree<float>* tree = new fcl::OcTree<float>(std::shared_ptr<const octomap::OcTree>(new octomap::OcTree(0.05)));
//  ROS_ERROR("1use_count %ld",tree_obj.use_count());
//  tree_obj = std::shared_ptr<fcl::CollisionGeometry<float>>(tree);

  space = ompl::base::StateSpacePtr(new ompl::base::SE3StateSpace());
  // create a start state
  ompl::base::ScopedState<ompl::base::SE3StateSpace> start(space);
  // create a goal state
  ompl::base::ScopedState<ompl::base::SE3StateSpace> goal(space);

  // set the bounds for the R^3 part of SE(3)
  ompl::base::RealVectorBounds bounds(3);

  // set X-Y-Z dimensions bound
  bounds.setLow(0,-5);
  bounds.setHigh(0,5);
  bounds.setLow(1,-5);
  bounds.setHigh(1,5);
  bounds.setLow(2,-0.5);
  bounds.setHigh(2,0.5);

  space->as<ompl::base::SE3StateSpace>()->setBounds(bounds);
  // construct an instance of  space information from this state space
  si = ompl::base::SpaceInformationPtr(new ompl::base::SpaceInformation(space));
  start->setXYZ(0,0,0);
  start->as<ompl::base::SO3StateSpace::StateType>(1)->setIdentity();
  // start.random();
  goal->setXYZ(0,0,0);
  goal->as<ompl::base::SO3StateSpace::StateType>(1)->setIdentity();
  // goal.random();
  // set state validity checking for this space
  si->setStateValidityChecker(std::bind(&Navigation::isStateValid, this, std::placeholders::_1 ));
  // create a problem instance
  pdef = ompl::base::ProblemDefinitionPtr(new ompl::base::ProblemDefinition(si));
  // set the start and goal states
  pdef->setStartAndGoalStates(start, goal);
  // set Optimizattion objective
  pdef->setOptimizationObjective(getPathLengthObjWithCostToGo(si));
  ROS_INFO("RRT* planer Initialized");

  try
  {
      ser.setPort("/dev/ttyUSB0");
      ser.setBaudrate(115200);
      serial::Timeout to = serial::Timeout::simpleTimeout(1000);
      ser.setTimeout(to);
      ser.open();
  }
  catch (serial::IOException& e)
  {
      ROS_ERROR_STREAM("Unable to open port ");
  }

  speedArray.push_back(0xff);
  speedArray.push_back(0);
  speedArray.push_back(0);

  init_argc = argc;
  init_argv = argv;
  init();
}

Navigation::~Navigation()
{

}

int main(int argc, char** argv)
{
  Navigation navigator(argc,argv);
}
