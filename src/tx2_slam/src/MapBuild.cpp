#include "../include/MapBuild.h"
#include "../include/SaveMap.h"
#include <cstdlib>

using namespace std;

int main (int argc, char** argv)
{
  ros::init (argc, argv, "MapBuild", ros::init_options::AnonymousName);

//  ros::NodeHandle n;
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
  ros::spin ();

  return (0);
}
