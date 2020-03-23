cmake_minimum_required(VERSION 2.8.3)
project(tx2_slam)

find_package(OpenCV 3.0 QUIET)
if(NOT OpenCV_FOUND)
  message(FATAL_ERROR "OpenCV > 3.0.0 not found.")
endif()

find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
  cv_bridge
  image_transport
  sensor_msgs
  pcl_conversions
  pcl_ros
  pcl_msgs
)

catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES tx2_slam
#  CATKIN_DEPENDS roscpp rospy std_msgs
#  DEPENDS system_lib
)

include_directories(
# include
  ${catkin_INCLUDE_DIRS}
  /opt/ros/melodic/include
  include /usr/include
  /usr/include/pcl-1.8
)
link_directories(/usr/lib)

add_executable(MapBuild src/MapBuild.cpp)
target_link_libraries(MapBuild ${catkin_LIBRARIES} /usr/lib/libopencv_highgui.so.3.2.0)
