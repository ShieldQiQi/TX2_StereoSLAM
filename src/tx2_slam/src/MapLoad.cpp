#include "../include/MapLoad.h"

using namespace tx2slam;

int main (int argc, char** argv) {
    // init ROS
    ros::init(argc, argv, "pcd_to_pointcloud");
    // set up node
    pcd_to_pointcloud node;
    // initializes from ROS parameters
    node.parse_ros_params();
    // also allow config to be provided via command line args
    // the latter take precedence
    node.parse_cmdline_args(argc, argv);
    // print info about effective configuration settings
    node.print_config_info();
    // try to load pointcloud from file
    if (!node.try_load_pointcloud()) {
        return -1;
    }
    // print info about pointcloud
    node.print_data_info();
    // initialize run
    node.init_run();
    // blocking call to process callbacks etc
    ros::spin();
}
