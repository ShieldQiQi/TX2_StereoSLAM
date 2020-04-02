#include "../include/MapBuild.h"
#include "../include/SaveMap.h"
#include <cstdlib>
#include <Eigen/Core>
#include <Eigen/Geometry>

using namespace std;
using namespace Eigen;

MapBuild::MapBuild(int argc, char** argv ) :
    init_argc(argc),
    init_argv(argv)
{
  if(init()) {
    ROS_ERROR("fail to init the mapBuild node");
  }
}

MapBuild::~MapBuild()
{

}

void MapBuild::callback(const sensor_msgs::PointCloud2::ConstPtr& cloud, const geometry_msgs::PoseStamped::ConstPtr& pose)
{
  carTFzed2 = *pose;
  // decrease the memory occupation
  // Perform the actual filtering
  pcl::PCLPointCloud2* cloud2 = new pcl::PCLPointCloud2;
  pcl::PCLPointCloud2ConstPtr cloudPtr(cloud2);
  pcl_conversions::toPCL(*cloud, *cloud2);

  pcl::PCLPointCloud2 cloud_filtered;
  pcl::VoxelGrid<pcl::PCLPointCloud2> sor;
  sor.setInputCloud (cloudPtr);
  sor.setLeafSize (0.1, 0.1, 0.1);
  sor.filter(cloud_filtered);

//  cloud_filtered.header.frame_id = "map";
//  pointCloudFused_pub.publish(cloud_filtered);

  if ((cloud_filtered.width * cloud_filtered.height) == 0)
    return;
  pcl::fromPCLPointCloud2 (cloud_filtered, cloud_xyz);

  Quaterniond quaternion(carTFzed2.pose.orientation.w,
                         carTFzed2.pose.orientation.x,
                         carTFzed2.pose.orientation.y,
                         carTFzed2.pose.orientation.z);
  Matrix3d rotation_matrix;
  rotation_matrix=quaternion.toRotationMatrix();

  // transform the cloud link to the "map" frame
  Vector3d position_transform(carTFzed2.pose.position.x,carTFzed2.pose.position.y,carTFzed2.pose.position.z);
//  std::cout<<cloud_xyz.width<<std::endl;
  for (int i=0; i<cloud_xyz.width; i++)
  {
    Vector3d position_(cloud_xyz.at(i).x,cloud_xyz.at(i).y,cloud_xyz.at(i).z);
    Vector3d position = rotation_matrix*position_ + position_transform;
    cloud_xyz.at(i).x = position[0];
    cloud_xyz.at(i).y = position[1];
    cloud_xyz.at(i).z = position[2];
  }

  // fused the current cloud to the fused cloud
  cloud_xyzFused += cloud_xyz;

  pcl::toROSMsg(cloud_xyzFused, mPointcloudFusedMsg);

  mPointcloudFusedMsg.header.frame_id = "map";
  pointCloudFused_pub.publish(mPointcloudFusedMsg);
}


bool MapBuild::init()
{

  ros::init (init_argc, init_argv, "MapBuild", ros::init_options::AnonymousName);

  ros::NodeHandle n;

//  carTF_sub = n.subscribe("/orb_slam2_stereo/pose",1000,&MapBuild::readTF, this);
//  carTFzed2_sub = n.subscribe("/zed2/zed_node/pose",1000,&MapBuild::readTFzed2, this);
  pointCloudFused_pub = n.advertise<sensor_msgs::PointCloud2>("/mapBuild/cloud_Fused", 1);
//  pointCloud_sub = n.subscribe("/zed2/zed_node/point_cloud/cloud_registered",10,
//                               &MapBuild::readPointCloud, this);

  pointCloud_sub = new message_filters::Subscriber<sensor_msgs::PointCloud2>
      ( n, "/zed2/zed_node/point_cloud/cloud_registered", 1);
  carTFzed2_sub = new message_filters::Subscriber<geometry_msgs::PoseStamped>
      (n, "/zed2/zed_node/pose", 1);

  sync_ = new message_filters::Synchronizer<sync_pol> (sync_pol(10), *pointCloud_sub, *carTFzed2_sub);
  sync_->registerCallback(boost::bind(&MapBuild::callback, this, _1, _2));


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
