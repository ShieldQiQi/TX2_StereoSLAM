/**
 * @file /src/qnode.cpp
 *
 * @brief Ros communication central!
 *
 * @date February 2011
 **/

/*****************************************************************************
** Includes
*****************************************************************************/

#include <ros/ros.h>
#include <ros/network.h>
#include <string>
#include <std_msgs/String.h>
#include <sstream>
#include "qnode.hpp"

/*****************************************************************************
** Namespaces
*****************************************************************************/

namespace rover {

/*****************************************************************************
** Implementation
*****************************************************************************/

QNode::QNode(int argc, char** argv ) :
	init_argc(argc),
	init_argv(argv)
	{}

QNode::~QNode() {
    if(ros::isStarted()) {
      ros::shutdown(); // explicitly needed since we use ros::start();
      ros::waitForShutdown();
    }
	wait();
}

void QNode::readTF(geometry_msgs::PoseStamped msg)
{
  carTF = msg;
}

void QNode::readTFzed2(geometry_msgs::PoseStamped msg)
{
  carTFzed2 = msg;
}

void QNode::readPointFusedCloud(const pcl::PCLPointCloud2::ConstPtr& cloud)
{
  if ((cloud->width * cloud->height) == 0)
    return;
  pcl::fromPCLPointCloud2 (*cloud, cloudFused_xyz);

  if(count++==3){
    Q_EMIT slamMapUpdated();
    count = 0;
  }
}

void QNode::readPointCloud(const pcl::PCLPointCloud2::ConstPtr& cloud)
{
  if ((cloud->width * cloud->height) == 0)
    return;
  pcl::fromPCLPointCloud2 (*cloud, cloud_xyz);

//  if(count++==3){
  Q_EMIT cloudUpdated();
//    count = 0;
//  }
}

bool QNode::init() {
	ros::init(init_argc,init_argv,"rover");
	if ( ! ros::master::check() ) {
		return false;
	}
	ros::start(); // explicitly needed since our nodehandle is going out of scope.
	ros::NodeHandle n;
	// Add your ros communications here.
	chatter_publisher = n.advertise<std_msgs::String>("chatter", 1000);
    pointFusedCloud_sub = n.subscribe("/zed2/zed_node/mapping/fused_cloud",1000,
                                 &QNode::readPointFusedCloud, this);
    pointCloud_sub = n.subscribe("/zed2/zed_node/point_cloud/cloud_registered",1000,
                                 &QNode::readPointCloud, this);
    carTF_sub = n.subscribe("/orb_slam2_stereo/pose",1000,
                            &QNode::readTF, this);
    carTFzed2_sub = n.subscribe("/zed2/zed_node/pose",1000,
                            &QNode::readTFzed2, this);

	start();
	return true;
}

bool QNode::init(const std::string &master_url, const std::string &host_url) {
	std::map<std::string,std::string> remappings;
	remappings["__master"] = master_url;
	remappings["__hostname"] = host_url;
	ros::init(remappings,"rover");
	if ( ! ros::master::check() ) {
		return false;
	}
	ros::start(); // explicitly needed since our nodehandle is going out of scope.
	ros::NodeHandle n;
	// Add your ros communications here.
	chatter_publisher = n.advertise<std_msgs::String>("chatter", 1000);
	start();
	return true;
}

void QNode::run() {
	ros::Rate loop_rate(1);
    int count = 0;\
    char flag = 0;
	while ( ros::ok() ) {

		std_msgs::String msg;
		std::stringstream ss;
		ss << "hello world " << count;
		msg.data = ss.str();
        chatter_publisher.publish(msg);
//        log(Info,std::string("I sent: ")+msg.data);
		ros::spinOnce();
		loop_rate.sleep();
		++count;       

        Q_EMIT slamStateChanged(flag);
        flag+=10;
        if(flag == 40){
          flag = 0;
        }
	}
	std::cout << "Ros shutdown, proceeding to close the gui." << std::endl;
	Q_EMIT rosShutdown(); // used to signal the gui for a shutdown (useful to roslaunch)
}


void QNode::log( const LogLevel &level, const std::string &msg) {
	logging_model.insertRows(logging_model.rowCount(),1);
	std::stringstream logging_model_msg;
	switch ( level ) {
		case(Debug) : {
				ROS_DEBUG_STREAM(msg);
				logging_model_msg << "[DEBUG] [" << ros::Time::now() << "]: " << msg;
				break;
		}
		case(Info) : {
				ROS_INFO_STREAM(msg);
				logging_model_msg << "[INFO] [" << ros::Time::now() << "]: " << msg;
				break;
		}
		case(Warn) : {
				ROS_WARN_STREAM(msg);
				logging_model_msg << "[INFO] [" << ros::Time::now() << "]: " << msg;
				break;
		}
		case(Error) : {
				ROS_ERROR_STREAM(msg);
				logging_model_msg << "[ERROR] [" << ros::Time::now() << "]: " << msg;
				break;
		}
		case(Fatal) : {
				ROS_FATAL_STREAM(msg);
				logging_model_msg << "[FATAL] [" << ros::Time::now() << "]: " << msg;
				break;
		}
	}
	QVariant new_row(QString(logging_model_msg.str().c_str()));
	logging_model.setData(logging_model.index(logging_model.rowCount()-1),new_row);
	Q_EMIT loggingUpdated(); // used to readjust the scrollbar
}

}  // namespace rover
