cmake_minimum_required(VERSION 2.8.3)
project(tx2_slam)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
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
)

add_executable(imageStore src/imageStore.cpp)
target_link_libraries(imageStore ${catkin_LIBRARIES})
