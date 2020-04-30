# pragma once

#include "../include/ModbusRS485.hpp"
#include <serial/serial.h>
#include <octomap/octomap.h>
#include <octomap_msgs/Octomap.h>
#include <octomap_msgs/conversions.h>
#include <octomap/ColorOcTree.h>
#include <pcl_conversions/pcl_conversions.h>
#include <pcl_ros/point_cloud.h>
#include <geometry_msgs/PoseStamped.h>
#include <message_filters/subscriber.h>
#include "visualization_msgs/Marker.h"
#include <trajectory_msgs/MultiDOFJointTrajectory.h>
#include <nav_msgs/Odometry.h>
#include <geometry_msgs/Pose.h>
#include <nav_msgs/Path.h>
#include <geometry_msgs/PoseStamped.h>

#include <ompl/base/spaces/SE3StateSpace.h>
#include <ompl/base/OptimizationObjective.h>
#include <ompl/base/objectives/PathLengthOptimizationObjective.h>
// #include <ompl/geometric/planners/rrt/RRTstar.h>
#include <ompl/geometric/planners/rrt/InformedRRTstar.h>
#include <ompl/geometric/SimpleSetup.h>
#include <ompl/config.h>
#include <iostream>

#include "fcl/fcl.h"
//#include "fcl/config.h"
//#include "fcl/geometry/octree/octree.h"
//#include "fcl/traversal/traversal_node_octree.h"
//#include "fcl/narrowphase/collision.h"
//#include "fcl/broadphase/broadphase.h"
//#include "fcl/math/transform.h"

namespace tx2slam {

class Navigation
{
public:

  Navigation();
  ~Navigation();
  void init();

  void rrtStarPlan(pcl::PointCloud<pcl::PointXYZRGB>* pclCloud, geometry_msgs::PoseStamped pose_Start, geometry_msgs::PoseStamped pose_Goal);
  void cmdVelPub();

  bool setTargetSpeed(float vLeft, float vRight, uint8_t direction);
  bool setTargetOmega(float omega, float omegaBias);
  float pidController(float omegaTarget, float omegaActual);


//  ModbusRS485 ser;
  serial::Serial ser;
  std::vector<uint8_t> speedArray;

private:

  const float KP = 0.6;
  const float KI = 0.0;
  const float KD = 0.0;

  // construct the state space we are planning in
  ompl::base::StateSpacePtr space;
  // construct an instance of  space information from this state space
  ompl::base::SpaceInformationPtr si;
  // create a problem instance
  ompl::base::ProblemDefinitionPtr pdef;
  ompl::geometric::PathGeometric* path_smooth;

  bool replan_flag = false;

  std::shared_ptr<fcl::CollisionGeometry<float>> slamCar;
  std::shared_ptr<fcl::CollisionGeometry<float>> tree_obj;

  bool isStateValid(const ompl::base::State *state);

  // Returns a structure representing the optimization objective to use for optimal motion planning.
  // This method returns an objective which attempts to minimize the length in configuration space of computed paths.
  ompl::base::OptimizationObjectivePtr getThresholdPathLengthObj(const ompl::base::SpaceInformationPtr& si);
  // This method returns an objective which attempts to minimize the cost in configuration space of computed paths.
  ompl::base::OptimizationObjectivePtr getPathLengthObjWithCostToGo(const ompl::base::SpaceInformationPtr& si);

  void plan(void);
  void replan(void);

};

void Navigation::plan(void)
{
  // create a planner for the defined space
  ompl::geometric::InformedRRTstar* rrt = new ompl::geometric::InformedRRTstar(si);
  // set rrt range
  rrt->setRange(0.2);
  ompl::base::PlannerPtr plan(rrt);
  // set the problem we are trying to solve for the planner
  plan->setProblemDefinition(pdef);
  // perform setup steps for the planner
  plan->setup();
  // print the settings for this space
  si->printSettings(std::cout);
  std::cout << "problem setting\n";
  // print the problem settings
  pdef->print(std::cout);
  // attempt to solve the problem within one second of planning time
  ompl::base::PlannerStatus solved = plan->solve(1);

  if (solved)
  {
      // get the goal representation from the problem definition (not the same as the goal state)
      // and inquire about the found path
      std::cout << "Found solution:" << std::endl;
      ompl::base::PathPtr path = pdef->getSolutionPath();
      ompl::geometric::PathGeometric* pth = pdef->getSolutionPath()->as<ompl::geometric::PathGeometric>();
      pth->printAsMatrix(std::cout);
      // print the path to screen
      // path->print(std::cout);

      nav_msgs::Path msg;
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
//				pose.header.frame_id = "/world"

          pose.pose.position.x = pos->values[0];
          pose.pose.position.y = pos->values[1];
          pose.pose.position.z = pos->values[2];

          pose.pose.orientation.x = rot->x;
          pose.pose.orientation.y = rot->y;
          pose.pose.orientation.z = rot->z;
          pose.pose.orientation.w = rot->w;

          msg.poses.push_back(pose);
      }
//      traj_pub.publish(msg);

      //Path smoothing using bspline
      //B样条曲线优化
      ompl::geometric::PathSimplifier* pathBSpline = new ompl::geometric::PathSimplifier(si);
      path_smooth = new ompl::geometric::PathGeometric(dynamic_cast<const ompl::geometric::PathGeometric&>(*pdef->getSolutionPath()));
      pathBSpline->smoothBSpline(*path_smooth,3);
      // std::cout << "Smoothed Path" << std::endl;
      // path_smooth.print(std::cout);


      //Publish path as markers

      nav_msgs::Path smooth_msg;
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

//				pose.header.frame_id = "/world"

          point.pose.position.x = pos->values[0];
          point.pose.position.y = pos->values[1];
          point.pose.position.z = pos->values[2];

          point.pose.orientation.x = rot->x;
          point.pose.orientation.y = rot->y;
          point.pose.orientation.z = rot->z;
          point.pose.orientation.w = rot->w;

          smooth_msg.poses.push_back(point);

//          std::cout << "Published marker: " << idx << std::endl;
      }

//      vis_pub.publish(smooth_msg);
      // ros::Duration(0.1).sleep();


      // Clear memory
      pdef->clearSolutionPaths();
      replan_flag = false;

  }
  else
      std::cout << "No solution found" << std::endl;
}

void Navigation::replan(void)
{
  std::cout << "Total Points:" << path_smooth->getStateCount () << std::endl;
  if(path_smooth->getStateCount () <= 2){
      plan();
  }else{
      for (std::size_t idx = 0; idx < path_smooth->getStateCount (); idx++)
      {
          if(!replan_flag)
              replan_flag = !isStateValid(path_smooth->getState(idx));
          else
              break;
      }
      if(replan_flag)
          plan();
//      else
//          std::cout << "Replanning not required" << std::endl;
  }
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

void Navigation::rrtStarPlan(pcl::PointCloud<pcl::PointXYZRGB>* pclCloud, geometry_msgs::PoseStamped pose_Start, geometry_msgs::PoseStamped pose_Goal)
{
  // turn the pcl cloud to fcl::CollisionGeometry after octree
  // updtae the octomap
  octomap::OcTree treeOctomap( 0.05 );
  for(auto p:pclCloud->points)
  {
    treeOctomap.updateNode( octomap::point3d(p.x, p.y, p.z), true );
  }
  treeOctomap.updateInnerOccupancy();
  fcl::OcTree<float>* tree = new fcl::OcTree<float>(std::shared_ptr<const octomap::OcTree>(&treeOctomap));
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
  replan();
}

void Navigation::cmdVelPub()
{

}

void Navigation::init()
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

Navigation::Navigation()
{
  // slam Car shape define
  slamCar = std::shared_ptr<fcl::CollisionGeometry<float>>(new fcl::Box<float>(0.8, 0.8, 0.3));
  fcl::OcTree<float>* tree = new fcl::OcTree<float>(std::shared_ptr<const octomap::OcTree>(new octomap::OcTree(0.05)));
  tree_obj = std::shared_ptr<fcl::CollisionGeometry<float>>(tree);

  space = ompl::base::StateSpacePtr(new ompl::base::SE3StateSpace());
  // create a start state
  ompl::base::ScopedState<ompl::base::SE3StateSpace> start(space);
  // create a goal state
  ompl::base::ScopedState<ompl::base::SE3StateSpace> goal(space);

  // set the bounds for the R^3 part of SE(3)
  // set space limitation
  ompl::base::RealVectorBounds bounds(3);

  bounds.setLow(0,-5);
  bounds.setHigh(0,5);
  bounds.setLow(1,-5);
  bounds.setHigh(1,5);
  bounds.setLow(2,0);
  bounds.setHigh(2,3);

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
  std::cout << "Initialized: " << std::endl;

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

}

Navigation::~Navigation()
{

}

}
