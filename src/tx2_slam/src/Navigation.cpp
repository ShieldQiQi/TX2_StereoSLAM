#include "../include/Navigation.hpp"
#include "../include/ModbusRS485.hpp"
#include <ros/ros.h>

using namespace tx2slam;

void Navigation::init()
{
  ros::init (init_argc, init_argv, "Navigation");
  ros::NodeHandle n;

  ros::Rate loop_rate(100);
  while(ros::ok())
  {
//    if(ser.isConnected == TRUE)
//    {
//      ser.ReadFromPort();
//    }
//    loop_rate.sleep();
    ros::spinOnce();
  }
}

int main(int argc, char** argv)
{
  Navigation navigator(argc,argv);
  navigator.init();
}

