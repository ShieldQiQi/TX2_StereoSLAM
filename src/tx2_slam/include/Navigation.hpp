/////////////////////////////////////////////////////////////////////////

// All copyRights reserved
// Author: Qi
// Date: 2020:05:07
// contract me by: qi.shield95@foxmail.com
// This module use infoRRT* to plan a path and control the car

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
#include <std_msgs/Int32.h>
#include <std_msgs/String.h>
#include <sensor_msgs/Imu.h>

#include <ompl/base/spaces/SE3StateSpace.h>
#include <ompl/base/OptimizationObjective.h>
#include <ompl/base/objectives/PathLengthOptimizationObjective.h>
// #include <ompl/geometric/planners/rrt/RRTstar.h>
#include <ompl/geometric/planners/rrt/InformedRRTstar.h>
#include <ompl/geometric/SimpleSetup.h>
#include <ompl/config.h>
#include <iostream>
#include <queue>
#include <Eigen/Core>
#include <Eigen/Geometry>
#include <cmath>

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

  bool fromPoseCmdvel(geometry_msgs::PoseStamped);
  bool setTargetSpeed(float vLeft, float vRight, uint8_t direction);
  bool setTargetOmega(float omega, float omegaBias);
  bool posePidController(float targetAngle, float currentAngle);
  void trackingState_Callback(const std_msgs::Int32::ConstPtr& trackingStateMsg);
  bool posePidController(float target_x, float target_y, float current_x, float current_y, float targetAngle, float currentAngle);
  float omegaPidController(float omegaTarget, float omegaActual);
  float thetaPidController(float thetaTarget, float thetaActual);
  geometry_msgs::PoseStamped generateGoal(pcl::PointCloud<pcl::PointXYZRGB> *pclCloud);

  // create the path-to-act queue
  std::queue<geometry_msgs::PoseStamped> pathQueue;
  // add a poses queue which the car actually went
  nav_msgs::Path realPathQueue;

//  ModbusRS485 ser;
  serial::Serial ser;
  float realSpeed = 0;
  std::vector<uint8_t> speedArray;

  uint16_t goalSet = 0;
  uint8_t slamGoalSet = 0;
  float cmd_vel = 0;
  geometry_msgs::PoseStamped goalPoseStamped;
  uint16_t mappingStatusCmd = 0;

  pcl::PointCloud<pcl::PointXYZRGB>* cloud_xyzFused = new pcl::PointCloud<pcl::PointXYZRGB>;
  geometry_msgs::PoseStamped carTF_zed2;
  geometry_msgs::PoseStamped carTF_orb;
  sensor_msgs::Imu imu_Msg;

  /*
   * SYSTEM_NOT_READY=-1,
   * NO_IMAGES_YET=0,
   * NOT_INITIALIZED=1,
   * OK=2,
   * LOST=3
  */
  std_msgs::Int32 trackingState;

  ros::Publisher smoothTraj_pub;
  ros::Publisher traj_pub;
  ros::Publisher realTraj_pub;
  ros::Subscriber carTF_orb_sub;
  ros::Subscriber carTF_zed2_sub;
  ros::Subscriber pointFusedCloud_sub;
  ros::Subscriber QTUI_cmd_sub;
  ros::Timer navigationCtrlTimer;
  ros::Subscriber trackingStat_sub;
  ros::Subscriber imu_sub;

  void QTUI_cmd_Callback(const std_msgs::Int32MultiArray::ConstPtr &msg);
  void navigation_Callback(const ros::TimerEvent& event);
  void carTF_orb_Callback(const geometry_msgs::PoseStamped::ConstPtr& pose);
  void imuCallback(const sensor_msgs::Imu::ConstPtr& msg);
  void carTF_zed2_Callback(const geometry_msgs::PoseStamped::ConstPtr& pose);
  void readPointFusedCloud(const sensor_msgs::PointCloud2::ConstPtr& cloud);

  double rrtRange = 1.0;
  double rrtSolutionTimeLimit = 0.2;
  double NavigatonTimerDuration = 0.05;
  double bounds_lmin = -5.0;
  double bounds_lmax = 5.0;
  double bounds_wmin = -5.0;
  double bounds_wmax = 5.0;
  double bounds_hmin = -0.5;
  double bounds_hmax = 0.5;
  double SLAMCarShape_l = 0.8;
  double SLAMCarShape_w = 0.8;
  double SLAMCarShape_h = 0.3;

  double cmd_vel_l_max = 0.6;
  double cmd_vel_r_max = 0.6;
  double cmd_vel_l_min = 0.3;
  double cmd_vel_r_min = 0.3;
  double cmd_vel_ro_r_max = 0.4;
  double cmd_vel_ro_l_max = 0.4;

  double straight_kp = 2.0;
  double straight_ki = 0.0;
  double straight_kd = 0.0;
  double orient_kp = 5.0;
  double orient_ki = 0.0;
  double orient_kd = 0.0;
  double omega_kp = 0.6;
  double omega_ki = 0.0;
  double omega_kd = 0.0;
  double theta_kp = 0.5;
  double theta_ki = 0.0;
  double theta_kd = 0.0;
  bool isUseOmegaPid = false;
  bool isUsePosePid = true;
  bool isUseThetaPid = true;
  double constSpeed = 0.3;
  double constOmega = 0.7;

  double straight_bia = 0.1;
  double orient_bia = 0.09;

  double l_r_vel_bia = 0.2;

  double carLength = 0.3;
  double groundHeightMax = 0.2;

  double thetaBiaRange = 1.04;
  double thetaBiaInc = 0.1;
  double lengthRange = 5;
  double lengthInc = 0.1;
  double lengthMax_threshold = 3.0;
  double lengthMax_security = 2.0;
  double stopThreshold = 0.01;


private:

  bool isFinishRotation = false;

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
