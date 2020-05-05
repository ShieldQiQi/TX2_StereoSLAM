# pragma once
#include <ros/ros.h>
#include "../include/SaveMap.h"
#include <std_msgs/Int32MultiArray.h>
#include <std_msgs/Int32.h>
#include <sensor_msgs/PointCloud2.h>
#include <sensor_msgs/Imu.h>
#include <pcl_conversions/pcl_conversions.h>
#include <pcl_ros/point_cloud.h>
#include <pcl_ros/filters/voxel_grid.h>
#include <pcl_ros/filters/passthrough.h>
#include <pcl_ros/filters/statistical_outlier_removal.h>
#include <tf2_ros/buffer.h>
#include <tf2_ros/transform_listener.h>
#include <tf2_eigen/tf2_eigen.h>
#include <pcl/io/pcd_io.h>
#include <pcl/registration/correspondence_estimation.h>
#include <geometry_msgs/PoseStamped.h>
#include <message_filters/subscriber.h>
#include <message_filters/time_synchronizer.h>
#include <message_filters/sync_policies/approximate_time.h>
#include <math.h>
#include "../include/Navigation.hpp"

namespace tx2slam {

class MapBuild/*:public Navigation*/
{
public:
  ~MapBuild()
  {
//    delete cloud_xyz;
//    delete cloud_xyzFused;
//    delete mPointcloudFusedMsg_pointer;
  }
  MapBuild(int argc, char** argv)
  {
    init_argc = argc;
    init_argv = argv;
    init();
  }

  void QTUI_cmd_Callback(const std_msgs::Int32MultiArray::ConstPtr& msg);
//    void navigation_Callback(const ros::TimerEvent& event);
  void imuCallback(const sensor_msgs::Imu::ConstPtr& msg);
  void carTF_orb_Callback(const geometry_msgs::PoseStamped::ConstPtr& pose);
  void buildMap_callback(const sensor_msgs::PointCloud2::ConstPtr& cloud, const geometry_msgs::PoseStamped::ConstPtr& pose);
  void trackingState_Callback(const std_msgs::Int32::ConstPtr& trackingStateMsg);
  void init();

  typedef message_filters::sync_policies::ApproximateTime<sensor_msgs::PointCloud2, geometry_msgs::PoseStamped> sync_pol;
  message_filters::Subscriber<sensor_msgs::PointCloud2> *pointCloud_sub;
  message_filters::Subscriber<geometry_msgs::PoseStamped> *carTF_zed2_sub;
  message_filters::Synchronizer<sync_pol> *sync_;

//    ros::Publisher smoothTraj_pub;
//    ros::Publisher traj_pub;
  ros::Publisher pointCloudFused_pub;
  ros::Subscriber imu_sub;
  ros::Subscriber QTUI_cmd_sub;
  ros::Subscriber carTF_orb_sub;
  ros::Subscriber trackingStat_sub;
  ros::ServiceClient client;

  orb_slam2_ros::SaveMap srv;

  pcl::PointCloud<pcl::PointXYZRGB>* cloud_xyz = new pcl::PointCloud<pcl::PointXYZRGB>;
  pcl::PointCloud<pcl::PointXYZRGB>* cloud_xyzFused = new pcl::PointCloud<pcl::PointXYZRGB>;
  pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud_xyzPtr;
  pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud_xyzFusedPtr;

  pcl::PCLPointCloud2* mPointcloudFusedMsg_pointer = new pcl::PCLPointCloud2;

  sensor_msgs::PointCloud2Ptr mPointcloudFusedMsg;
  sensor_msgs::Imu imu_Msg;
  geometry_msgs::PoseStamped carTF_zed2;
  geometry_msgs::PoseStamped carTF_orb;

  /*
   * SYSTEM_NOT_READY=-1,
   * NO_IMAGES_YET=0,
   * NOT_INITIALIZED=1,
   * OK=2,
   * LOST=3
  */
  std_msgs::Int32 trackingState;

  double timeNow = 0;
  double timeLast = 0;
  bool startTimer = 0;

  float x_bias = 0;
  float y_bias = 0;
  float z_bias = 0;

  uint16_t savemapFlag = 0;
  uint16_t mappingStatusCmd = 0;

  double VoxelGrid_LeafSize = 0.05;
  double PassThrough_yMin = -4.0;
  double PassThrough_yMax = 4.0;
  double PassThrough_zMin = -1.0;
  double PassThrough_zMax = 2.0;
  double StatisticalOutlierRemoval_MeanK = 50;
  double StatisticalOutlierRemoval_StddevMulThresh = 0.3;

  double TimeLimit = 10.0;
  double PoseBiasLimit = 0.1;
  double angular_velocityLimit = 0.8;

private:
  int init_argc;
  char** init_argv;

};

class PointCloudToPCD
{

  private:
    std::string prefix_ = "/home/qi/catkin_qi/src/tx2_slam/map/pcd_files/";
    std::string filename_ = "slamMap";
    bool binary_;
    bool compressed_;
    std::string fixed_frame_;
    tf2_ros::Buffer tf_buffer_;
    tf2_ros::TransformListener tf_listener_;

  public:

    void save (const pcl::PCLPointCloud2::ConstPtr& cloud)
    {
      if ((cloud->width * cloud->height) == 0)
        return;

      ROS_INFO ("Received %d data points in frame %s with the following fields: %s",
                (int)cloud->width * cloud->height,
                cloud->header.frame_id.c_str (),
                pcl::getFieldsList (*cloud).c_str ());

      Eigen::Vector4f v = Eigen::Vector4f::Zero ();
      Eigen::Quaternionf q = Eigen::Quaternionf::Identity ();
      if (!fixed_frame_.empty ()) {
        if (!tf_buffer_.canTransform (fixed_frame_, cloud->header.frame_id, pcl_conversions::fromPCL (cloud->header.stamp), ros::Duration (3.0))) {
          ROS_WARN("Could not get transform!");
          return;
        }

        Eigen::Affine3d transform;
        transform = tf2::transformToEigen (tf_buffer_.lookupTransform (fixed_frame_, cloud->header.frame_id,  pcl_conversions::fromPCL (cloud->header.stamp)));
        v = Eigen::Vector4f::Zero ();
        v.head<3> () = transform.translation ().cast<float> ();
        q = transform.rotation ().cast<float> ();
      }

      std::stringstream ss;
      if (filename_ != "")
      {
        ss << prefix_ << filename_ << ".pcd";
      }
      else
      {
        ss << prefix_ << cloud->header.stamp << ".pcd";
      }
      ROS_INFO ("Data saved to %s", ss.str ().c_str ());

      pcl::PCDWriter writer;
      if(binary_)
      {
        if(compressed_)
        {
          writer.writeBinaryCompressed (ss.str (), *cloud, v, q);
        }
        else
        {
          writer.writeBinary (ss.str (), *cloud, v, q);
        }
      }
      else
      {
        writer.writeASCII (ss.str (), *cloud, v, q, 8);
      }

    }

    PointCloudToPCD () : binary_(false), compressed_(false), tf_listener_(tf_buffer_)
    {
    }
    ~PointCloudToPCD(){}
};

}
