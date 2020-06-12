# TX2_StereoSLAM
大家好，这是一个连校优答辩资格都拿不到的垃圾毕设<br><br>
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

    $ roslaunch tx2_slam orb_slam2_zed2_stereo.launch

## Tiral

Feel free for using this at case, whatever indoor or outdoor

![demo0](https://github.com/ShieldQiQi/TX2_StereoSLAM/blob/master/Demo_Pictures/0.png)
![demo1](https://github.com/ShieldQiQi/TX2_StereoSLAM/blob/master/Demo_Pictures/1.png)
![demo2](https://github.com/ShieldQiQi/TX2_StereoSLAM/blob/master/Demo_Pictures/2.png)
![demo3](https://github.com/ShieldQiQi/TX2_StereoSLAM/blob/master/Demo_Pictures/3.png)
![demo4](https://github.com/ShieldQiQi/TX2_StereoSLAM/blob/master/Demo_Pictures/4.png)
![demo5](https://github.com/ShieldQiQi/TX2_StereoSLAM/blob/master/Demo_Pictures/5.png)

## About

any question, contact me by<br>
`email`:qi.shield95@foxmail.com<br>
you can get my blog about this project on<br>
`zhihu`:https://zhuanlan.zhihu.com/QIQI-HITwh
