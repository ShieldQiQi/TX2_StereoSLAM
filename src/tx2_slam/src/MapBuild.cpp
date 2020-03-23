#include "../include/MapBuild.h"
#include <ros/ros.h>
#include <sensor_msgs/PointCloud2.h>
#include <pcl_conversions/pcl_conversions.h>
#include <pcl_ros/point_cloud.h>

void cloudCallback(const sensor_msgs::PointCloud2::ConstPtr& msg)
{
//  ROS_INFO("the point_step:%d\nthe row_step:%d\nthe height:%d",
//           msg->point_step,msg->row_step,msg->height);
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "MapBuild");
  ros::NodeHandle nh;
  ros::Subscriber sub = nh.subscribe
      ("/zed2/zed_node/point_cloud/cloud_registered", 1000, cloudCallback);

//  ros::Publisher pcl_pub = nh.advertise
//      <sensor_msgs::PointCloud2>("/tx2_slam/mapCloud",1);
//  sensor_msgs::PointCloud2 output;
//  pcl_pub.publish(output);

  ros::spin();
}
