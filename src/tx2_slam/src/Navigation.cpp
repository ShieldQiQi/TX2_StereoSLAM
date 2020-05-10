/////////////////////////////////////////////////////////////////////////

// All copyRights reserved
// Author: Qi
// Date: 2020:05:07
// contract me by: qi.shield95@foxmail.com
// This module use infoRRT* to plan a path and use PID to control the car

/////////////////////////////////////////////////////////////////////////

// Copyright (c) 2020, Qi.

// All rights reserved.

// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

/////////////////////////////////////////////////////////////////////////

#include "../include/Navigation.hpp"

using namespace tx2slam;
using namespace Eigen;

// get the cmd from UI
void Navigation::QTUI_cmd_Callback(const std_msgs::Int32MultiArray::ConstPtr& msg)
{
  mappingStatusCmd = msg->data.at(1);
  if(slamGoalSet == 0)
    slamGoalSet = mappingStatusCmd;

  goalPoseStamped.pose.position.x = msg->data.at(4)/1000.0;
  goalPoseStamped.pose.position.y = msg->data.at(5)/1000.0;

  if(msg->data.at(2) != 0){
    goalSet = msg->data.at(2);
  }

  cmd_vel = msg->data.at(3)/100.0;

}

// read the orb_slam2 pose
void Navigation::carTF_orb_Callback(const geometry_msgs::PoseStamped::ConstPtr& pose){
  carTF_orb = *pose;
}

// read Imu msg data
void Navigation::imuCallback(const sensor_msgs::Imu::ConstPtr& msg) {
  imu_Msg = *msg;
}

// read the zed2_imu pose
void Navigation::carTF_zed2_Callback(const geometry_msgs::PoseStamped::ConstPtr& pose){
  carTF_zed2 = *pose;
}

// read the tracking state of the slam
void Navigation::trackingState_Callback(const std_msgs::Int32::ConstPtr& trackingStateMsg)
{
  trackingState = *trackingStateMsg;
}

// plan a path and control the car
void Navigation::navigation_Callback(const ros::TimerEvent& event)
{
  if(ser.available()){
      std_msgs::String speedMsg;
      speedMsg.data = ser.read(ser.available());
      realSpeed = (speedMsg.data[0]-' '+32)/255.0*2;
  }
  if(goalSet == 1 || slamGoalSet == 1) // try to find a solution
  {
    if(rrtStarPlan(cloud_xyzFused,carTF_zed2,
          slamGoalSet == 1? generateGoal(cloud_xyzFused) : goalPoseStamped) == true){
      smoothTraj_pub.publish(smooth_msg);
      traj_pub.publish(msg);
      smooth_msg.poses.clear();
      msg.poses.clear();
      if(slamGoalSet == 1)
        slamGoalSet = 2;
    }else{
      ROS_WARN("could't find a solution, try once again");
      if(rrtStarPlan(cloud_xyzFused,carTF_zed2,goalPoseStamped)){
        ROS_INFO("find a solution at a second time");
        smoothTraj_pub.publish(smooth_msg);
        traj_pub.publish(msg);
        smooth_msg.poses.clear();
        msg.poses.clear();
        if(slamGoalSet == 1)
          slamGoalSet = 2;
      }else{
        ROS_INFO("give up trying");
      }
    }
    goalSet = 0;
    setTargetSpeed(0, 0, 0);
  }else if((goalSet == 2 || slamGoalSet == 2) && trackingState.data != 3) // move the car base on planned solution step by step
  {
    if(pathQueue.empty()){
      ROS_INFO("speed: %f",realSpeed);
      if(realSpeed < stopThreshold)
      {
        ROS_INFO("Finish the Goal successfully!");
        goalSet = 0;
        if(slamGoalSet == 2)
          slamGoalSet = 1;
      }
    }
    if(!pathQueue.empty())
    {
      if(fromPoseCmdvel(pathQueue.front())){
        // Go the next goal
        isFinishRotation = false;
        pathQueue.pop();
      }else{
//        ROS_INFO("Going to the goal...");
      }
    }
  }else // do nothing but stand
  {
    if(trackingState.data == 3){
      ROS_ERROR("Orb_slam2 tracking lost");
    }
    setTargetSpeed(0, 0, 0);
  }

  // capture the car real trajectory
  if(pow(realPathQueue.poses.back().pose.position.x - carTF_zed2.pose.position.x, 2)
     + pow(realPathQueue.poses.back().pose.position.y - carTF_zed2.pose.position.y, 2) > 0.04)
  {
    geometry_msgs::PoseStamped pose;
    pose.pose.position.x = carTF_zed2.pose.position.x;
    pose.pose.position.y = carTF_zed2.pose.position.y;
    pose.pose.position.z = carTF_zed2.pose.position.z;

    pose.pose.orientation.x = carTF_zed2.pose.orientation.x;
    pose.pose.orientation.y = carTF_zed2.pose.orientation.y;
    pose.pose.orientation.z = carTF_zed2.pose.orientation.z;
    pose.pose.orientation.w = carTF_zed2.pose.orientation.w;

    realPathQueue.poses.push_back(pose);

    realPathQueue.header.stamp = ros::Time::now();
    realPathQueue.header.frame_id = "map";
    realTraj_pub.publish(realPathQueue);
  }
}

// decoder the target position to cmd_vels to communication with the car
bool Navigation::fromPoseCmdvel(geometry_msgs::PoseStamped)
{
  // transform the pose to the cmd_vel of the moveBaseCar
  if(pow(pathQueue.front().pose.position.x - carTF_zed2.pose.position.x,2)
     +pow(pathQueue.front().pose.position.y - carTF_zed2.pose.position.y,2) < 0.1){
    // done the current goal
    return true;
  }else{

    Quaterniond quaternion_0(carTF_zed2.pose.orientation.w,
                           carTF_zed2.pose.orientation.x,
                           carTF_zed2.pose.orientation.y,
                           carTF_zed2.pose.orientation.z);
    Matrix3d rotation_matrix_0;
    rotation_matrix_0=quaternion_0.toRotationMatrix();
    float currentAngle = rotation_matrix_0(1,0) > 0?
          acos(rotation_matrix_0(0,0)*1 + rotation_matrix_0(1,0)*0):
          -acos(rotation_matrix_0(0,0)*1 + rotation_matrix_0(1,0)*0);

    float current_x = carTF_zed2.pose.position.x - carLength*cos(currentAngle);
    float current_y = carTF_zed2.pose.position.y - carLength*sin(currentAngle);

    float targetAngle = pathQueue.front().pose.position.y - current_y > 0?
          acos((pathQueue.front().pose.position.x - current_x)
               /sqrt(pow(pathQueue.front().pose.position.x - current_x, 2) +
                     pow(pathQueue.front().pose.position.y - current_y,2))*1
               + (pathQueue.front().pose.position.y - current_y)
               /sqrt(pow(pathQueue.front().pose.position.x - current_x, 2) +
                     pow(pathQueue.front().pose.position.y - current_y,2))*0):
          -acos((pathQueue.front().pose.position.x - current_x)
                /sqrt(pow(pathQueue.front().pose.position.x - current_x, 2) +
                      pow(pathQueue.front().pose.position.y - current_y,2))*1
                + (pathQueue.front().pose.position.y - current_y)
                /sqrt(pow(pathQueue.front().pose.position.x - current_x, 2) +
                      pow(pathQueue.front().pose.position.y - current_y,2))*0);
    ROS_INFO("currentAngle:%f targetAngle :%f", currentAngle, targetAngle);

    // Going to the current goal
    if(!isFinishRotation){
      // rotate first
      isFinishRotation = posePidController(targetAngle, currentAngle);
    }else{
      if(abs(pathQueue.front().pose.position.x) + abs(pathQueue.front().pose.position.y)  < 60){
        // then perform transform
        return posePidController(pathQueue.front().pose.position.x, pathQueue.front().pose.position.y
                          , carTF_zed2.pose.position.x, carTF_zed2.pose.position.y, targetAngle, currentAngle);
      }else{
        return true;
      }
    }
    return false;
  }
}

// fix the angle by absolute pid
bool Navigation::posePidController(float targetAngle, float currentAngle)
{
  static float Bias,thetaBias,Integral_bias,Last_Bias;
  Bias=targetAngle-currentAngle;
  Integral_bias+=Bias;
  thetaBias=orient_kp*Bias+orient_ki*Integral_bias+orient_kd*(Bias-Last_Bias);
  Last_Bias=Bias;

  if(isUsePosePid == true)
    setTargetOmega(thetaBias, isUseOmegaPid == true?omegaPidController(0.3, imu_Msg.angular_velocity.z):0);
  else if(thetaBias > 0)
    setTargetOmega(constOmega, 0);
  else
    setTargetOmega(-constOmega, 0);

  if(abs(Bias) < orient_bia){
    // stop and perform transform next
    setTargetSpeed(0, 0, 0);
    return true;
  }else{
    return false;
  }
}

// go to the goal by absolute pid
bool Navigation::posePidController(float target_x, float target_y, float current_x, float current_y, float targetAngle, float currentAngle)
{
  static float Bias,poseBias,Integral_bias,Last_Bias;
  Bias = sqrt(pow(target_x - current_x,2)+pow(target_y - current_y,2));
  Integral_bias+=Bias;
  poseBias=straight_kp*Bias+straight_ki*Integral_bias+straight_kd*(Bias-Last_Bias);
  Last_Bias=Bias;

  // get the current angle and direction
  uint8_t direction;
  float currentAngleAbs = abs(currentAngle);
  if((currentAngleAbs <= M_PI/4 && current_x <= target_x)
     || (currentAngleAbs >= M_PI*3/4 && current_x >= target_x)
     || (currentAngle <= M_PI*3/4 && currentAngle >= M_PI/4 && current_y <= target_y)
     || (currentAngle <= -M_PI/4 && currentAngle >= -M_PI*3/4 && current_y >= target_y)){
    direction = 0;
  }else{
    direction = 3;
  }

  if(isUsePosePid == true)
    setTargetSpeed(
          abs(poseBias) - (isUseThetaPid == true?thetaPidController(targetAngle, currentAngle):0),
          abs(poseBias) + (isUseThetaPid == true?thetaPidController(targetAngle, currentAngle):0),
          direction);
  else
    setTargetSpeed(constSpeed, constSpeed, direction);
  if(Bias < straight_bia){
    // stop and perform transform next
    setTargetSpeed(0, 0, 0);
    return true;
  }else{
    return false;
  }
}

// fix the theta by increment pid
float Navigation::thetaPidController(float thetaTarget, float thetaActual)
{
  static float Bias,thetaBias,Integral_bias,Last_Bias;
  Bias=thetaTarget-thetaActual;
  Integral_bias+=Bias;
  thetaBias=theta_kp*Bias+theta_ki*Integral_bias+theta_kd*(Bias-Last_Bias);
  Last_Bias=Bias;

  return thetaBias;
}

// fix the omega by increment pid
float Navigation::omegaPidController(float omegaTarget, float omegaActual)
{
  static float Bias,omegaBias,Integral_bias,Last_Bias;
  Bias=omegaTarget-omegaActual;
  Integral_bias+=Bias;
  omegaBias=omega_kp*Bias+omega_ki*Integral_bias+omega_kd*(Bias-Last_Bias);
  Last_Bias=Bias;

  return omegaBias;
}

// send cmd_vel to the car use serial
bool Navigation::setTargetSpeed(float vLeft, float vRight, uint8_t direction)
{
  if(goalSet == 2 || slamGoalSet == 2){
    // set the max speed limit
    if(isFinishRotation == true){
      if(vLeft > cmd_vel_l_max)
        vLeft = cmd_vel_l_max;
      if(vRight > cmd_vel_r_max)
        vRight = cmd_vel_r_max;
    }else{
      if(vLeft > cmd_vel_ro_l_max)
        vLeft = cmd_vel_ro_l_max;
      if(vRight > cmd_vel_ro_r_max)
        vRight = cmd_vel_ro_r_max;
    }
    // set the min speed limit
    if(trackingState.data != 3)
    {
      if(isFinishRotation == true){
        if(vLeft < 1.3*cmd_vel_l_min)
          vLeft = 1.3*cmd_vel_l_min;
        if(vRight < 1.3*cmd_vel_r_min)
          vRight = 1.3*cmd_vel_r_min;
      }else{
        if(vLeft < cmd_vel_l_min)
          vLeft = cmd_vel_l_min;
        if(vRight < cmd_vel_r_min)
          vRight = cmd_vel_r_min;
      }

      vLeft += l_r_vel_bia;
    }

    ROS_INFO("V_left:%f    V_right:%f     %d", vLeft, vRight, direction);
  }

  switch(direction)
  {
  case 0: // go straight
//    ser.UT_REGISTERS_TAB[0] = (((uint16_t)(vLeft/1*127)) << 8) | ((uint16_t)(vRight/1*127));
    speedArray[1] = (uint8_t)(vLeft/2*127);
    speedArray[2] = (uint8_t)(vRight/2*127);
    break;
  case 1: // turn left
//    ser.UT_REGISTERS_TAB[0] = (((uint16_t)(255-vLeft/1*127)) << 8) | ((uint8_t)(vRight/1*127));
    speedArray[1] = (uint8_t)(255-vLeft/2*127);
    speedArray[2] = (uint8_t)(vRight/2*127);
    break;
  case 2: // turn right
//    ser.UT_REGISTERS_TAB[0] = (((uint16_t)(vLeft/1*127)) << 8) | ((uint8_t)(255-vRight/1*127));
    speedArray[1] = (uint8_t)(vLeft/2*127);
    speedArray[2] = (uint8_t)(255-vRight/2*127);
    break;
  case 3: // go back
//    ser.UT_REGISTERS_TAB[0] = (((uint16_t)(255-vLeft/1*127)) << 8) | ((uint8_t)(255-vRight/1*127));
    speedArray[1] = (uint8_t)(255-vLeft/2*127);
    speedArray[2] = (uint8_t)(255-vRight/2*127);
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

// convert the omega to the cmd_vels of the left&right
bool Navigation::setTargetOmega(float omega, float omegaBias)
{
  if(omega >= 0){
    setTargetSpeed((omega+omegaBias),omega+omegaBias,1);
  }else{
    setTargetSpeed(-omega+omegaBias,(-omega+omegaBias),2);
  }
  return true;
}

// get the map cloud to prepare for collision and path planning
void Navigation::readPointFusedCloud(const sensor_msgs::PointCloud2::ConstPtr& cloud)
{
  pcl::PCLPointCloud2* cloud2 = new pcl::PCLPointCloud2;
  pcl::PCLPointCloud2ConstPtr cloudPtr(cloud2);
  pcl_conversions::toPCL(*cloud, *cloud2);

  if ((cloudPtr->width * cloudPtr->height) == 0)
    return;
  pcl::fromPCLPointCloud2 (*cloudPtr, *cloud_xyzFused);
}

// use infoRRT* to get a path
bool Navigation::plan(void)
{
  // create a planner for the defined space
  ompl::geometric::InformedRRTstar* rrt = new ompl::geometric::InformedRRTstar(si);
  // set the maximum length of a motion to be added in the tree of motions,
  // which greatly influences the runtime of the algorithm
  rrt->setRange(rrtRange);
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
    solved = plan->solve(rrtSolutionTimeLimit);
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
//    pth->printAsMatrix(std::cout);
    // print the path to screen
    path->print(std::cout);

    msg.header.stamp = ros::Time::now();
    msg.header.frame_id = "map";

    // clear the pathQueue
    std::queue<geometry_msgs::PoseStamped> emptyPathQueue;
    pathQueue.swap(emptyPathQueue);

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
        pathQueue.push(pose);
//        if(pathQueue.empty())
//        {
//          geometry_msgs::PoseStamped poseConst;
//          poseConst.pose.position.x = 2;
//          poseConst.pose.position.y = -1;
//          poseConst.pose.position.z = 0;
//          pathQueue.push(poseConst);
//        }
    }

    // Path smoothing using bspline
    // B spline optimize
    ompl::geometric::PathSimplifier* pathBSpline = new ompl::geometric::PathSimplifier(si);
    path_smooth = new ompl::geometric::PathGeometric(dynamic_cast<const ompl::geometric::PathGeometric&>(*pdef->getSolutionPath()));
    pathBSpline->smoothBSpline(*path_smooth,3);
//    ROS_INFO("Smoothed Path:");
//    path_smooth->print(std::cout);

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

// check if there exist a crashs
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

// Optimize the planned path
ompl::base::OptimizationObjectivePtr Navigation::getThresholdPathLengthObj(const ompl::base::SpaceInformationPtr& si)
{
    ompl::base::OptimizationObjectivePtr obj(new ompl::base::PathLengthOptimizationObjective(si));
    // obj->setCostThreshold(ob::Cost(1.51));
    return obj;
}

// Optimize the planned path
ompl::base::OptimizationObjectivePtr Navigation::getPathLengthObjWithCostToGo(const ompl::base::SpaceInformationPtr& si)
{
    ompl::base::OptimizationObjectivePtr obj(new ompl::base::PathLengthOptimizationObjective(si));
    obj->setCostToGoHeuristic(&ompl::base::goalRegionCostToGo);
    return obj;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
// * This function try to find a reasonable goal
// * Which based on the longest point that the car would not crashs on if in it's direction
// * I plot a simple figure below to make it more eary to understand
// * of course, there wouldn't just be five ray-lines in real programming
// *
//                 ^ Go ahead
//                 |
//                 |
//         X       |       X
//          \      |      /
//           *     |     /
//            \    |  ****** obstacle     if no way, then turn around
//             \   |   *****
//     **       \  |  /
//  X-***------- O---O -----------X
//            zed2-camera
//
// * if there is no point's length longer than the manual set threshold
// * then set a cmd goal to turn around
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
geometry_msgs::PoseStamped Navigation::generateGoal(pcl::PointCloud<pcl::PointXYZRGB>* pclCloud)
{
  // get the current pose of the zed2 camera
  Quaterniond quaternion(carTF_zed2.pose.orientation.w,
                         carTF_zed2.pose.orientation.x,
                         carTF_zed2.pose.orientation.y,
                         carTF_zed2.pose.orientation.z);
  Matrix3d rotation_matrix;
  rotation_matrix=quaternion.toRotationMatrix();
  Vector3d position_transform
      (carTF_zed2.pose.position.x,
       carTF_zed2.pose.position.y,
       carTF_zed2.pose.position.z);

  // use Octomap and FCL to check if the ray meet end
  octomap::OcTree* treeOctomapPtr = new octomap::OcTree( 0.05 );
  for(auto p:pclCloud->points)
  {
    if(p.z > groundHeightMax)
      treeOctomapPtr->updateNode( octomap::point3d(p.x, p.y, p.z), true );
  }
  treeOctomapPtr->updateInnerOccupancy();
  fcl::OcTree<float>* tree = new fcl::OcTree<float>(std::shared_ptr<const octomap::OcTree>(treeOctomapPtr));
  tree_obj = std::shared_ptr<fcl::CollisionGeometry<float>>(tree);
  fcl::CollisionObject<float> treeObj((tree_obj));
  fcl::CollisionObject<float> slamCarObject(slamCar);
  fcl::CollisionRequest<float> requestType(1,false,1,false);

  // find the longest point
  float lengthMax = 0;
  float thetaFinal = 0;
  for(float thetaBia = 0; thetaBia < thetaBiaRange; thetaBia += thetaBiaInc)
  {
    // solve the right hand
    Matrix3d rotation_matrix_of_checkerPoint_in_zed2Frame_r;
    rotation_matrix_of_checkerPoint_in_zed2Frame_r <<
          cos(-thetaBia), -sin(-thetaBia),   0,
          sin(-thetaBia),  cos(-thetaBia),   0,
                     0.0,             0.0,   1.0;
    Matrix3d rotation_matrix_of_checkerPoint_r = rotation_matrix * rotation_matrix_of_checkerPoint_in_zed2Frame_r;

    for(float len = 0; len <= lengthRange; len += lengthInc )
    {
      Vector3d position_(len*cos(thetaBia), -len*sin(thetaBia), 0);
      Vector3d position = rotation_matrix*position_ + position_transform;
//      ROS_INFO("x: %f y: %f", position[0], position[1]);

      fcl::Vector3f translation(position[0], position[1], position[2]);
      fcl::Matrix3f rotation;
      for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
        {
          rotation(i, j) = rotation_matrix_of_checkerPoint_r(i, j);
        }
      slamCarObject.setTransform(rotation, translation);
      fcl::CollisionResult<float> collisionResult;
      fcl::collide(&slamCarObject, &treeObj, requestType, collisionResult);

      if(len > lengthMax){
        lengthMax = len;
        thetaFinal = -thetaBia;
      }
      // update the longest point
      if(collisionResult.isCollision())
      {
//        ROS_INFO("lengthmax: %f theta: %f", lengthMax, -thetaBia);
        break;
      }
    }

    // solve left hand
    Matrix3d rotation_matrix_of_checkerPoint_in_zed2Frame_l;
    rotation_matrix_of_checkerPoint_in_zed2Frame_l <<
          cos(thetaBia), -sin(thetaBia),   0,
          sin(thetaBia),  cos(thetaBia),   0,
                     0.0,             0.0,   1.0;
    Matrix3d rotation_matrix_of_checkerPoint_l = rotation_matrix * rotation_matrix_of_checkerPoint_in_zed2Frame_l;

    for(float len = 0; len <= lengthRange; len += lengthInc )
    {
      Vector3d position_(len*cos(thetaBia), len*sin(thetaBia), 0);
      Vector3d position = rotation_matrix*position_ + position_transform;
//      ROS_INFO("x: %f y: %f", position[0], position[1]);

      fcl::Vector3f translation(position[0], position[1], position[2]);
      fcl::Matrix3f rotation;
      for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
        {
          rotation(i, j) = rotation_matrix_of_checkerPoint_l(i, j);
        }
      slamCarObject.setTransform(rotation, translation);
      fcl::CollisionResult<float> collisionResult;
      fcl::collide(&slamCarObject, &treeObj, requestType, collisionResult);

      if(len > lengthMax){
        lengthMax = len;
        thetaFinal = thetaBia;
      }
      // update the longest point
      if(collisionResult.isCollision())
      {
//        ROS_INFO("lengthmax: %f theta: %f", lengthMax, thetaBia);
        break;
      }
    }

    if(lengthMax >= lengthRange - 0.05)
      break;
  }

  // get the target pose
  geometry_msgs::PoseStamped targetPose;
  if(lengthMax < lengthMax_threshold){
    // no target point find
    ROS_INFO("There is no target point find, try go around");
    // turn left by 45 degree as default
    // assume "100" as just rotate but no transform
    Vector3d position_(100.0, 100.0, 0.0);
    Vector3d position = rotation_matrix*position_ + position_transform;
    targetPose.pose.position.x = position[0];
    targetPose.pose.position.y = position[1];
  }else{
    // to avoid crash, cut the lengthmax by 2.0 metres
    lengthMax -= lengthMax_security;
    Vector3d position_(lengthMax*cos(thetaFinal), lengthMax*sin(thetaFinal), 0);
    Vector3d position = rotation_matrix*position_ + position_transform;
    targetPose.pose.position.x = position[0];
    targetPose.pose.position.y = position[1];

    ROS_INFO("Find a targetGoal: x: %f  y: %f", position[0], position[1]);
  }
  return targetPose;

}

// RRT plan setting
bool Navigation::rrtStarPlan(pcl::PointCloud<pcl::PointXYZRGB>* pclCloud, geometry_msgs::PoseStamped pose_Start, geometry_msgs::PoseStamped pose_Goal)
{
  if(abs(pose_Goal.pose.position.x) + abs(pose_Goal.pose.position.y) < 60)
  {
    // turn the pcl cloud to fcl::CollisionGeometry after octree
    // updtae the octomap
    octomap::OcTree* treeOctomapPtr = new octomap::OcTree( 0.05 );
    for(auto p:pclCloud->points)
    {
      if(p.z > groundHeightMax + carTF_zed2.pose.position.z)
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
  }else{
    geometry_msgs::PoseStamped pose;

    pose.pose.position.x = pose_Goal.pose.position.x;
    pose.pose.position.y = pose_Goal.pose.position.y;
    pose.pose.position.z = pose_Goal.pose.position.z;

    pose.pose.orientation.x = 0;
    pose.pose.orientation.y = 0;
    pose.pose.orientation.z = 0;
    pose.pose.orientation.w = 1;

//    msg.poses.push_back(pose);
    pathQueue.push(pose);

    return true;
  }

}

// init ROS node... and so on...
void Navigation::init()
{
  ros::init (init_argc, init_argv, "Navigation");
  ros::NodeHandle n;

  ROS_INFO("/*************\nNavigation Parameters:\n--------------------------------------");
  n.getParam("Navigation/rrtRange",rrtRange);
  ROS_INFO("Navigation/rrtRange: %f",rrtRange);
  n.getParam("Navigation/rrtSolutionTimeLimit",rrtSolutionTimeLimit);
  ROS_INFO("rrtSolutionTimeLimit: %f",rrtSolutionTimeLimit);
  n.getParam("Navigation/NavigatonTimerDuration",NavigatonTimerDuration);
  ROS_INFO("NavigatonTimerDuration: %f",NavigatonTimerDuration);
  n.getParam("Navigation/bounds_lmin",bounds_lmin);
  ROS_INFO("bounds_lmin: %f",bounds_lmin);
  n.getParam("Navigation/bounds_lmax",bounds_lmax);
  ROS_INFO("bounds_lmax: %f",bounds_lmax);
  n.getParam("Navigation/bounds_wmin",bounds_wmin);
  ROS_INFO("bounds_wmin: %f",bounds_wmin);
  n.getParam("Navigation/bounds_wmax",bounds_wmax);
  ROS_INFO("bounds_wmax: %f",bounds_wmax);
  n.getParam("Navigation/bounds_hmin",bounds_hmin);
  ROS_INFO("bounds_hmin: %f",bounds_hmin);
  n.getParam("Navigation/bounds_hmax",bounds_hmax);
  ROS_INFO("bounds_hmax: %f",bounds_hmax);
  n.getParam("Navigation/SLAMCarShape_l",SLAMCarShape_l);
  ROS_INFO("SLAMCarShape_l: %f",SLAMCarShape_l);
  n.getParam("Navigation/SLAMCarShape_w",SLAMCarShape_w);
  ROS_INFO("SLAMCarShape_w: %f",SLAMCarShape_w);
  n.getParam("Navigation/SLAMCarShape_h",SLAMCarShape_h);
  ROS_INFO("SLAMCarShape_h: %f",SLAMCarShape_h);
  n.getParam("Navigation/cmd_vel_l_max",cmd_vel_l_max);
  ROS_INFO("cmd_vel_l_max: %f",cmd_vel_l_max);
  n.getParam("Navigation/cmd_vel_r_max",cmd_vel_r_max);
  ROS_INFO("cmd_vel_r_max: %f",cmd_vel_r_max);
  ROS_INFO("cmd_vel_l_min: %f",cmd_vel_l_min);
  n.getParam("Navigation/cmd_vel_l_min",cmd_vel_l_min);
  ROS_INFO("cmd_vel_r_min: %f",cmd_vel_r_min);
  n.getParam("Navigation/cmd_vel_r_min",cmd_vel_r_min);
  ROS_INFO("cmd_vel_ro_l_max: %f",cmd_vel_ro_l_max);
  n.getParam("Navigation/cmd_vel_ro_l_max",cmd_vel_ro_l_max);
  ROS_INFO("cmd_vel_ro_r_max: %f",cmd_vel_ro_r_max);
  n.getParam("Navigation/cmd_vel_ro_r_max",cmd_vel_ro_r_max);
  n.getParam("Navigation/straight_kp",straight_kp);
  ROS_INFO("straight_kp: %f",straight_kp);
  n.getParam("Navigation/straight_ki",straight_ki);
  ROS_INFO("straight_ki: %f",straight_ki);
  n.getParam("Navigation/straight_kd",straight_kd);
  ROS_INFO("straight_kd: %f",straight_kd);
  n.getParam("Navigation/orient_kp",orient_kp);
  ROS_INFO("orient_kp: %f",orient_kp);
  n.getParam("Navigation/orient_ki",orient_ki);
  ROS_INFO("orient_ki: %f",orient_ki);
  n.getParam("Navigation/orient_kd",orient_kd);
  ROS_INFO("orient_kd: %f",orient_kd);
  n.getParam("Navigation/omega_kp",omega_kp);
  ROS_INFO("omega_kp: %f",omega_kp);
  n.getParam("Navigation/omega_ki",omega_ki);
  ROS_INFO("omega_ki: %f",omega_ki);
  n.getParam("Navigation/omega_kd",omega_kd);
  ROS_INFO("omega_kd: %f",omega_kd);
  n.getParam("Navigation/isUseOmegaPid",isUseOmegaPid);
  ROS_INFO("isUseOmegaPid: %d",isUseOmegaPid);
  n.getParam("Navigation/isUsePosePid",isUsePosePid);
  ROS_INFO("isUsePosePid: %d",isUsePosePid);
  n.getParam("Navigation/straight_bia",straight_bia);
  ROS_INFO("straight_bia: %f",straight_bia);
  n.getParam("Navigation/orient_bia",orient_bia);
  ROS_INFO("orient_bia: %f",orient_bia);
  n.getParam("Navigation/constSpeed",constSpeed);
  ROS_INFO("constSpeed: %f",constSpeed);
  n.getParam("Navigation/constOmega",constOmega);
  ROS_INFO("constOmega: %f",constOmega);
  n.getParam("Navigation/carLength",carLength);
  ROS_INFO("carLength: %f",carLength);
  n.getParam("Navigation/groundHeightMax",groundHeightMax);
  ROS_INFO("groundHeightMax: %f",groundHeightMax);
  n.getParam("Navigation/l_r_vel_bia",l_r_vel_bia);
  ROS_INFO("l_r_vel_bia: %f",l_r_vel_bia);
  n.getParam("Navigation/thetaBiaRange",thetaBiaRange);
  ROS_INFO("thetaBiaRange: %f",thetaBiaRange);
  n.getParam("Navigation/thetaBiaInc",thetaBiaInc);
  ROS_INFO("thetaBiaInc: %f",thetaBiaInc);
  n.getParam("Navigation/lengthRange",lengthRange);
  ROS_INFO("lengthRange: %f",lengthRange);
  n.getParam("Navigation/lengthInc",lengthInc);
  ROS_INFO("lengthInc: %f",lengthInc);
  n.getParam("Navigation/lengthMax_threshold",lengthMax_threshold);
  ROS_INFO("lengthMax_threshold: %f",lengthMax_threshold);
  n.getParam("Navigation/lengthMax_security",lengthMax_security);
  ROS_INFO("lengthMax_security: %f",lengthMax_security);
  n.getParam("Navigation/stopThreshold",stopThreshold);
  ROS_INFO("stopThreshold: %f",stopThreshold);
  n.getParam("Navigation/theta_kp",theta_kp);
  ROS_INFO("theta_kp: %f",theta_kp);
  n.getParam("Navigation/theta_ki",theta_ki);
  ROS_INFO("theta_ki: %f",theta_ki);
  n.getParam("Navigation/theta_kd",theta_kd);
  ROS_INFO("theta_kd: %f",theta_kd);
  n.getParam("Navigation/isUseThetaPid",isUseThetaPid);
  ROS_INFO("isUseThetaPid: %d",isUseThetaPid);


  // publish planned path
  smoothTraj_pub = n.advertise<nav_msgs::Path>( "Trajectory_marker", 1 );
  traj_pub = n.advertise<nav_msgs::Path>("waypoints",1);
  realTraj_pub = n.advertise<nav_msgs::Path>("realwaypoints",1);

  // subscribe poses and fused pointcloud
  carTF_orb_sub = n.subscribe("/orb_slam2_stereo/pose", 1, &Navigation::carTF_orb_Callback,this);
  carTF_zed2_sub = n.subscribe("/zed2/zed_node/pose", 1, &Navigation::carTF_zed2_Callback,this);
  pointFusedCloud_sub = n.subscribe("/mapBuild/cloud_Fused",1, &Navigation::readPointFusedCloud, this);
  trackingStat_sub = n.subscribe("/orb_slam2_stereo/trackingState", 1, &Navigation::trackingState_Callback,this);
  imu_sub = n.subscribe("/zed2/zed_node/imu/data", 1, &Navigation::imuCallback,this);

  // set a Timer to call path-plan function 20Hz
  navigationCtrlTimer = n.createTimer(ros::Duration(NavigatonTimerDuration), &Navigation::navigation_Callback,this);

  // receive the UI cmd
  QTUI_cmd_sub = n.subscribe("/rover/QtUI_cmd_Msg", 1, &Navigation::QTUI_cmd_Callback,this);

}

// structor
Navigation::Navigation(int argc, char** argv)
{

  init_argc = argc;
  init_argv = argv;
  init();

  // slam Car shape define
  slamCar = std::shared_ptr<fcl::CollisionGeometry<float>>(new fcl::Box<float>(SLAMCarShape_l, SLAMCarShape_w, SLAMCarShape_h));
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
  bounds.setLow(0,bounds_lmin);
  bounds.setHigh(0,bounds_lmax);
  bounds.setLow(1,bounds_wmin);
  bounds.setHigh(1,bounds_wmax);
  bounds.setLow(2,bounds_hmin);
  bounds.setHigh(2,bounds_hmax);

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
    // you'd better not use the /dev/ttyUSB* port or it will occupy the zed2 image transmission
    // you'd better use the /dev/ttyTHS2 as default since the /dev/ttyTHS1 & /dev/ttyTHS3 are for other use
    // if you find can't open it, try to change the port's permission
    ser.setPort("/dev/ttyTHS2");
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

  // test mode
//  geometry_msgs::PoseStamped poseConst;
//  poseConst.pose.position.x = 2;
//  poseConst.pose.position.y = -0.1;
//  poseConst.pose.position.z = 0;
//  pathQueue.push(poseConst);

  geometry_msgs::PoseStamped pose;
  pose.pose.position.x = 0;
  pose.pose.position.y = 0;
  pose.pose.position.z = 0;
  pose.pose.orientation.x = 0;
  pose.pose.orientation.y = 0;
  pose.pose.orientation.z = 0;
  pose.pose.orientation.w = 1;
  realPathQueue.poses.push_back(pose);

  ros::spin();

//  ros::MultiThreadedSpinner spinner(7);
//  spinner.spin();
}

// destructor
Navigation::~Navigation()
{
  delete cloud_xyzFused;
}

int main(int argc, char** argv)
{
  Navigation navigator(argc,argv);
}


/////////////////////////////////////////////////////////////////////////

// Copyright (c) 2020, Qi.

// All rights reserved.

// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

/////////////////////////////////////////////////////////////////////////
