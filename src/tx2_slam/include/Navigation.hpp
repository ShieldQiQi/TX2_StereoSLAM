# pragma once

#include <ros/ros.h>
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
#include <std_msgs/Int32MultiArray.h>

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

  Navigation(int argc, char** argv);
  ~Navigation();
  void init();

  nav_msgs::Path smooth_msg;
  nav_msgs::Path msg;

  bool rrtStarPlan(pcl::PointCloud<pcl::PointXYZRGB>* pclCloud, geometry_msgs::PoseStamped pose_Start, geometry_msgs::PoseStamped pose_Goal);
  void cmdVelPub();

  bool setTargetSpeed(float vLeft, float vRight, uint8_t direction);
  bool setTargetOmega(float omega, float omegaBias);
  float pidController(float omegaTarget, float omegaActual);


//  ModbusRS485 ser;
  serial::Serial ser;
  std::vector<uint8_t> speedArray;

  uint16_t goalSet = 0;
  bool slamGoalSet = 0;
  float cmd_vel = 0;
  geometry_msgs::PoseStamped goalPoseStamped;
  uint16_t mappingStatusCmd = 0;

  bool isGetSolution = 0;

  pcl::PointCloud<pcl::PointXYZRGB>* cloud_xyzFused = new pcl::PointCloud<pcl::PointXYZRGB>;
  geometry_msgs::PoseStamped carTF_zed2;
  geometry_msgs::PoseStamped carTF_orb;

  ros::Publisher smoothTraj_pub;
  ros::Publisher traj_pub;
  ros::Subscriber carTF_orb_sub;
  ros::Subscriber carTF_zed2_sub;
  ros::Subscriber pointFusedCloud_sub;
  ros::Subscriber QTUI_cmd_sub;
  ros::Timer navigationCtrlTimer;

  void QTUI_cmd_Callback(const std_msgs::Int32MultiArray::ConstPtr &msg);
  void navigation_Callback(const ros::TimerEvent& event);
  void carTF_orb_Callback(const geometry_msgs::PoseStamped::ConstPtr& pose);
  void carTF_zed2_Callback(const geometry_msgs::PoseStamped::ConstPtr& pose);
  void readPointFusedCloud(const sensor_msgs::PointCloud2::ConstPtr& cloud);

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

  std::shared_ptr<fcl::CollisionGeometry<float>> slamCar;
  std::shared_ptr<fcl::CollisionGeometry<float>> tree_obj;

  bool isStateValid(const ompl::base::State *state);

  // Returns a structure representing the optimization objective to use for optimal motion planning.
  // This method returns an objective which attempts to minimize the length in configuration space of computed paths.
  ompl::base::OptimizationObjectivePtr getThresholdPathLengthObj(const ompl::base::SpaceInformationPtr& si);
  // This method returns an objective which attempts to minimize the cost in configuration space of computed paths.
  ompl::base::OptimizationObjectivePtr getPathLengthObjWithCostToGo(const ompl::base::SpaceInformationPtr& si);

  bool plan(void);

  int init_argc;
  char** init_argv;

};
}
