# TX2_StereoSLAM
[![License](https://img.shields.io/badge/License-Apache%202.0-green.svg)](https://opensource.org/licenses/Apache-2.0)
[![Platform](https://img.shields.io/badge/ROS-melodic-yellow.svg)](<>)
[![Status](https://img.shields.io/badge/Staus-Processing-blue.svg)](<>)
<br><br>
develop a SLAM algorithm based on `ORB_SLAM2` along with `Jetson TX2`、`ZED2`、`ROS` and a mobile platform
<br>
## Install

Open a terminal, clone the repository, update the dependencies and build the packages:

    $ git clone https://github.com/ShieldQiQi/TX2_StereoSLAM.git
    $ cd ../
    $ rosdep install --from-paths src --ignore-src -r -y
    $ catkin_make -DCMAKE_BUILD_TYPE=Release
    $ source ./devel/setup.bash

## Begin

Open a terminal, and run command below to start:
<br><br>
`roslaunch tx2_slam orb_slam2_zed2_stereo.launch`

## Tiral

***

<image src="https://github.com/ShieldQiQi/TX2_StereoSLAM/tree/master/Demo_Pictures/1.png" width="100" alt="Demo"/>
<image src="https://github.com/ShieldQiQi/TX2_StereoSLAM/tree/master/Demo_Pictures/2.png" width="100" alt="Demo"/>

***

## About

any question, contact me by<br>
`email`:qi.shield95@foxmail.com<br>
you can get my blog about this project on<br>
`zhihu`:https://zhuanlan.zhihu.com/QIQI-HITwh
