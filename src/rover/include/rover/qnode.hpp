/**
 * @file /include/rover/qnode.hpp
 *
 * @brief Communications central!
 *
 * @date February 2011
 **/
/*****************************************************************************
** Ifdefs
*****************************************************************************/

#ifndef rover_QNODE_HPP_
#define rover_QNODE_HPP_

/*****************************************************************************
** Includes
*****************************************************************************/

// To workaround boost/qt4 problems that won't be bugfixed. Refer to
//    https://bugreports.qt.io/browse/QTBUG-22829
#ifndef Q_MOC_RUN
#include <ros/ros.h>
#include <geometry_msgs/PoseStamped.h>
#include <pcl_ros/point_cloud.h>
#endif
#include <string>
#include <QThread>
#include <QStringListModel>

/*****************************************************************************
** Namespaces
*****************************************************************************/

namespace rover {

/*****************************************************************************
** Class
*****************************************************************************/

class QNode : public QThread {
    Q_OBJECT
public:
	QNode(int argc, char** argv );
	virtual ~QNode();
	bool init();
    void readPointFusedCloud(const pcl::PCLPointCloud2::ConstPtr& cloud);
    void readPointCloud(const pcl::PCLPointCloud2::ConstPtr& cloud);
    void readTF(geometry_msgs::PoseStamped msg);
	bool init(const std::string &master_url, const std::string &host_url);
	void run();

	/*********************
	** Logging
	**********************/
	enum LogLevel {
	         Debug,
	         Info,
	         Warn,
	         Error,
	         Fatal
	 };

    char count = 0;
    pcl::PointCloud<pcl::PointXYZ> cloud_xyz,cloudFused_xyz;
    geometry_msgs::PoseStamped carTF;
	QStringListModel* loggingModel() { return &logging_model; }
	void log( const LogLevel &level, const std::string &msg);

Q_SIGNALS:
	void loggingUpdated();
    void rosShutdown();
    void slamStateChanged(char flag);
    void slamMapUpdated();
    void cloudUpdated();

private:
	int init_argc;
	char** init_argv;
	ros::Publisher chatter_publisher;
    ros::Subscriber pointFusedCloud_sub,pointCloud_sub,carTF_sub;
    QStringListModel logging_model;
};

}  // namespace rover

#endif /* rover_QNODE_HPP_ */
