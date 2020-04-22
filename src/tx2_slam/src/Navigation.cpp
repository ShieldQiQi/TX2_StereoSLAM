#include "../include/Navigation.h"
#include "../include/ModbusRS485.hpp"
#include <ros/ros.h>

int main (int argc, char** argv)
{
    ros::init(argc, argv, "Navigation");

    ros::spin();
}
