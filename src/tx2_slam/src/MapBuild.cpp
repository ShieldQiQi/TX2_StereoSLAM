#include "../include/MapBuild.h"
#include "../include/SaveMap.h"
#include <cstdlib>
#include <Eigen/Core>
#include <Eigen/Geometry>

using namespace std;
using namespace Eigen;

MapBuild::MapBuild(int argc, char** argv ) : init_argc(argc), init_argv(argv)
{
  if(init()) {
    ROS_ERROR("fail to init the mapBuild node");
  }
}

MapBuild::~MapBuild()
{

}

void MapBuild::carTF_orb_Callback(const geometry_msgs::PoseStamped::ConstPtr& pose)
{
  carTF_orb = *pose;
}

void MapBuild::imuCallback(const sensor_msgs::Imu::ConstPtr& msg) {
  imu_Msg = *msg;
  {
    //    ROS_INFO( "Accel: %.3f,%.3f,%.3f [m/s^2] - Ang. vel: %.3f,%.3f,%.3f [deg/sec] - Orient. Quat: %.3f,%.3f,%.3f,%.3f",
    //              msg->linear_acceleration.x, msg->linear_acceleration.y, msg->linear_acceleration.z,
    //              msg->angular_velocity.x, msg->angular_velocity.y, msg->angular_velocity.z,
    //              msg->orientation.x, msg->orientation.y, msg->orientation.z, msg->orientation.w);

  }
}

void MapBuild::buildMap_callback(const sensor_msgs::PointCloud2::ConstPtr& cloud, const geometry_msgs::PoseStamped::ConstPtr& pose)
{
  if(imu_Msg.angular_velocity.x<0.1 && imu_Msg.angular_velocity.y<0.1 && imu_Msg.angular_velocity.z<0.1
     && imu_Msg.linear_acceleration.x<0.005 && imu_Msg.linear_acceleration.y<0.005 && imu_Msg.linear_acceleration.z<0.005)
  {
    carTF_zed2 = *pose;
//    ROS_WARN("\nthe offset from zed2Pose to orbPose2 is:\nx:%f   y:%f   z:%f \n-------------"
//              ,carTF_zed2.pose.position.x - carTF_orb.pose.position.x
//              ,carTF_zed2.pose.position.y - carTF_orb.pose.position.y
//              ,carTF_zed2.pose.position.z - carTF_orb.pose.position.z);
    // Perform the actual filtering
    // VoxelGrid(decrease the memory occupation) & PassThrough(delete some incorrect points)
    pcl::PCLPointCloud2* cloud2 = new pcl::PCLPointCloud2;
    pcl::PCLPointCloud2ConstPtr cloudPtr(cloud2);
    pcl_conversions::toPCL(*cloud, *cloud2);
    // VoxelGrid
    pcl::PCLPointCloud2* cloud_filtered_1 = new pcl::PCLPointCloud2;
    pcl::PCLPointCloud2ConstPtr cloud_filter_1_Ptr(cloud_filtered_1);
    pcl::VoxelGrid<pcl::PCLPointCloud2> filter_1;
    filter_1.setInputCloud (cloudPtr);
    filter_1.setLeafSize (0.05, 0.05, 0.05);
    filter_1.filter(*cloud_filtered_1);
    // PassThrough
    pcl::PCLPointCloud2 cloud_filtered_2;
    pcl::PassThrough<pcl::PCLPointCloud2> filter_2;
    filter_2.setInputCloud (cloud_filter_1_Ptr);
    filter_2.setFilterFieldName ("y");
    filter_2.setFilterLimits (-1.5, 1.5);
//    filter_2.setFilterLimitsNegative (true);
    filter_2.filter(cloud_filtered_2);

    if ((cloud_filtered_2.width * cloud_filtered_2.height) == 0)
      return;
    pcl::fromPCLPointCloud2 (cloud_filtered_2, cloud_xyz);

    Quaterniond quaternion(carTF_zed2.pose.orientation.w,
                           carTF_zed2.pose.orientation.x,
                           carTF_zed2.pose.orientation.y,
                           carTF_zed2.pose.orientation.z);
    Matrix3d rotation_matrix;
    rotation_matrix=quaternion.toRotationMatrix();

    // transform the cloud link to the "map" frame
    Vector3d position_transform(carTF_zed2.pose.position.x,carTF_zed2.pose.position.y,carTF_zed2.pose.position.z);

//    float min = 100,max = 0;
    for (int i=0; i<cloud_xyz.width; i++)
    {
      Vector3d position_(cloud_xyz.at(i).x,cloud_xyz.at(i).y,cloud_xyz.at(i).z);
      Vector3d position = rotation_matrix*position_ + position_transform;
      cloud_xyz.at(i).x = position[0];
      cloud_xyz.at(i).y = position[1];
      cloud_xyz.at(i).z = position[2];
//      if(min>cloud_xyz.at(i).x)
//        min = cloud_xyz.at(i).x;
//      if(max<cloud_xyz.at(i).x)
//        max = cloud_xyz.at(i).x;
    }
//    ROS_ERROR("min:%f max:%f",min,max);

    // fused the current cloud to the fused cloud
    cloud_xyzFused += cloud_xyz;

    pcl::toROSMsg(cloud_xyzFused, mPointcloudFusedMsg);

    mPointcloudFusedMsg.header.frame_id = "map";
    pointCloudFused_pub.publish(mPointcloudFusedMsg);
  }
}


bool MapBuild::init()
{

  ros::init (init_argc, init_argv, "MapBuild", ros::init_options::AnonymousName);

  ros::NodeHandle n;

  pointCloudFused_pub = n.advertise<sensor_msgs::PointCloud2>("/mapBuild/cloud_Fused", 1);

  imu_sub = n.subscribe("/zed/zed_node/imu/data", 1, &MapBuild::imuCallback,this);
  carTF_orb_sub = n.subscribe("/orb_slam2_stereo/pose", 1, &MapBuild::carTF_orb_Callback,this);

  pointCloud_sub = new message_filters::Subscriber<sensor_msgs::PointCloud2>
      ( n, "/zed2/zed_node/point_cloud/cloud_registered", 1);
  carTF_zed2_sub = new message_filters::Subscriber<geometry_msgs::PoseStamped>
      (n, "/zed2/zed_node/pose", 1);

  sync_ = new message_filters::Synchronizer<sync_pol> (sync_pol(10), *pointCloud_sub, *carTF_zed2_sub);
  sync_->registerCallback(boost::bind(&MapBuild::buildMap_callback, this, _1, _2));


  {
  //  ros::ServiceClient client = n.serviceClient<orb_slam2_ros::SaveMap>("/orb_slam2_stereo/save_map");

  //  orb_slam2_ros::SaveMap srv;
  //  srv.request.name = "/home/qi/catkin_qi/src/tx2_slam/map/bin/zed2_slam_Map.bin";
  //  if (client.call(srv))
  //  {
  //    ROS_INFO("Ready to create Map");
  //  }
  //  else
  //  {
  //    ROS_ERROR("Failed to call service SaveMap");
  //    return 1;
  //  }
  //  PointCloudToPCD b;
  }

  ros::spin ();

}

int main(int argc, char** argv)
{
  MapBuild map(argc,argv);
}
