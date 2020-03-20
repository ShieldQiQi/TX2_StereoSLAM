# TX2_StereoSLAM
[![License](https://img.shields.io/badge/License-Apache%202.0-green.svg)](https://opensource.org/licenses/Apache-2.0)
[![Platform](https://img.shields.io/badge/ROS-melodic-yellow.svg)](<>)
[![Status](https://img.shields.io/badge/Staus-Processing-blue.svg)](<>)
<br><br>
develop a SLAM algorithm based on `ORB_SLAM2` along with `Jetson TX2`、`ZED2`、`ROS` and a mobile platform
<br>
## Install

Open a terminal, clone the repository, update the dependencies and build the packages:

    $ cd ~/catkin_ws/src
    $ git clone https://github.com/stereolabs/zed-ros-wrapper.git
    $ cd ../
    $ rosdep install --from-paths src --ignore-src -r -y
    $ catkin_make -DCMAKE_BUILD_TYPE=Release
    $ source ./devel/setup.bash

## About

contact me by qi.shield95@foxmail.com
