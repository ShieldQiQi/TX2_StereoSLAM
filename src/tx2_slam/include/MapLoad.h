/////////////////////////////////////////////////////////////////////////

// All copyRights reserved
// Author: Qi
// Date: 2020:05:07
// contract me by: qi.shield95@foxmail.com
// This module use orbSlam2 and zed2 to build a map and save map

///////////////////////////////////////////////////////////////////////////
//
// Copyright (c) 2020, Qi.
//
// All rights reserved.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
///////////////////////////////////////////////////////////////////////////
#pragma once

#include <ros/ros.h>
#include <pcl_conversions/pcl_conversions.h>

#include <string>
#include <sstream>

namespace tx2slam {

template <typename T>
T get_param(std::string const& name, T default_value) {
    T value;
    ros::param::param<T>(name, value, default_value);
    return value;
}

class pcd_to_pointcloud {
    ros::NodeHandle nh;
    // the topic to publish at, will be overwritten to give the remapped name
    std::string cloud_topic;
    // source file name, will be overwritten to produce actually configured file
    std::string file_name;
    // republish interval in seconds
    double interval;
    // tf2 frame_id
    std::string frame_id;
    // latched topic enabled/disabled
    bool latch;
    // pointcloud message and publisher
    sensor_msgs::PointCloud2 cloud;
    ros::Publisher pub;
    // timer to handle republishing
    ros::Timer timer;

    void publish() {
        ROS_DEBUG_STREAM_ONCE("Publishing pointcloud");
        ROS_DEBUG_STREAM_ONCE(" * number of points: " << cloud.width * cloud.height);
        ROS_DEBUG_STREAM_ONCE(" * frame_id: " << cloud.header.frame_id);
        ROS_DEBUG_STREAM_ONCE(" * topic_name: " << cloud_topic);
        int num_subscribers = pub.getNumSubscribers();
        if (num_subscribers > 0) {
            ROS_DEBUG("Publishing data to %d subscribers.", num_subscribers);
        }
        // update timestamp and publish
        cloud.header.stamp = ros::Time::now();
        pub.publish(cloud);
    }

    void timer_callback(ros::TimerEvent const&) {
        // just re-publish
        publish();
    }

public:
    pcd_to_pointcloud()
    : cloud_topic("cloud_pcd"), file_name(""), interval(0.0), frame_id("base_link"), latch(false)
    {
        // update potentially remapped topic name for later logging
        cloud_topic = nh.resolveName(cloud_topic);
    }

    void parse_ros_params() {
        file_name = get_param("~file_name", file_name);
        interval = get_param("~interval", interval);
        frame_id = get_param("~frame_id", frame_id);
        latch = get_param("~latch", latch);
    }

    void parse_cmdline_args(int argc, char** argv) {
        if (argc > 1) {
            file_name = argv[1];
        }
        if (argc > 2) {
            std::stringstream str(argv[2]);
            double x;
            if (str >> x)
                interval = x;
        }
    }

    bool try_load_pointcloud() {
        if (file_name.empty()) {
            ROS_ERROR_STREAM("Can't load pointcloud: no file name provided");
            return false;
        }
        else if (pcl::io::loadPCDFile(file_name, cloud) < 0) {
            ROS_ERROR_STREAM("Failed to parse pointcloud from file ('" << file_name << "')");
            return false;
        }
        // success: set frame_id appropriately
        cloud.header.frame_id = frame_id;
        return true;
    }

    void init_run() {
        // init publisher
        pub = nh.advertise<sensor_msgs::PointCloud2>(cloud_topic, 1, latch);
        // treat publishing once as a special case to interval publishing
        bool oneshot = interval <= 0;
        timer = nh.createTimer(ros::Duration(interval),
                               &pcd_to_pointcloud::timer_callback,
                               this,
                               oneshot);
    }

    void print_config_info() {
        ROS_INFO_STREAM("Recognized the following parameters");
        ROS_INFO_STREAM(" * file_name: " << file_name);
        ROS_INFO_STREAM(" * interval: " << interval);
        ROS_INFO_STREAM(" * frame_id: " << frame_id);
        ROS_INFO_STREAM(" * topic_name: " << cloud_topic);
        ROS_INFO_STREAM(" * latch: " << std::boolalpha << latch);
    }

    void print_data_info() {
        ROS_INFO_STREAM("Loaded pointcloud with the following stats");
        ROS_INFO_STREAM(" * number of points: " << cloud.width * cloud.height);
        ROS_INFO_STREAM(" * total size [bytes]: " << cloud.data.size());
        ROS_INFO_STREAM(" * channel names: " << pcl::getFieldsList(cloud));
    }
};

}


