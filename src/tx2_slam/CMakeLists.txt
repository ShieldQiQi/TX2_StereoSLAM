cmake_minimum_required(VERSION 2.8.3)
project(tx2_slam)

find_package(Eigen3)
find_package(modbus)
find_package(octomap REQUIRED)
find_package(ompl)
find_package(fcl REQUIRED)

find_package(OpenCV 3.0 QUIET)
if(NOT OpenCV_FOUND)
  message(FATAL_ERROR "OpenCV > 3.0.0 not found.")
endif()

find_package(catkin REQUIRED COMPONENTS
  serial
  roscpp
  rospy
  std_msgs
  cv_bridge
  image_transport
  sensor_msgs
  pcl_conversions
  pcl_ros
  pcl_msgs
  message_filters
  nav_msgs
  geometry_msgs
  trajectory_msgs
  visualization_msgs
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
  /usr/local/include/modbus
  /usr/local/include/fcl/
  /usr/local/include/ompl-1.5/
  ${EIGEN3_INCLUDE_DIR}
  ${OCTOMAP_INCLUDE_DIRS}
  ${fcl_INCLUDE_DIRS}
)
link_directories(/usr/lib)

add_executable(Slam src/Slam.cpp)
target_link_libraries(Slam /usr/local/lib/libccd.so ${fcl_LIBRARIES} /usr/local/lib/libompl.so /usr/local/lib/libfcl.so ${OCTOMAP_LIBRARIES} ${Boost_LIBRARIES} ${catkin_LIBRARIES} ${PCL_LIBRARIES} /usr/local/lib/libmodbus.so /usr/lib/libopencv_highgui.so.3.2.0 ${EIGEN3_LIBS})

add_executable(Navigation src/Navigation.cpp)
target_link_libraries(Navigation /usr/local/lib/libccd.so ${fcl_LIBRARIES} /usr/local/lib/libompl.so /usr/local/lib/libfcl.so ${OCTOMAP_LIBRARIES} ${Boost_LIBRARIES} ${catkin_LIBRARIES} ${PCL_LIBRARIES} /usr/local/lib/libmodbus.so /usr/lib/libopencv_highgui.so.3.2.0 ${EIGEN3_LIBS})


add_executable(MapLoad src/MapLoad.cpp)
target_link_libraries(MapLoad ${Boost_LIBRARIES} ${catkin_LIBRARIES} ${PCL_LIBRARIES})
