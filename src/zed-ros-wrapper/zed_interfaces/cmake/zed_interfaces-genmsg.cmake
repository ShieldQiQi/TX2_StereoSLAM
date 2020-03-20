# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "zed_interfaces: 2 messages, 13 services")

set(MSG_I_FLAGS "-Ized_interfaces:/home/qi/catkin_qi/src/zed-ros-wrapper/zed_interfaces/msg;-Istd_msgs:/opt/ros/melodic/share/std_msgs/cmake/../msg;-Igeometry_msgs:/opt/ros/melodic/share/geometry_msgs/cmake/../msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(geneus REQUIRED)
find_package(genlisp REQUIRED)
find_package(gennodejs REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(zed_interfaces_generate_messages ALL)

# verify that message/service dependencies have not changed since configure



get_filename_component(_filename "/home/qi/catkin_qi/src/zed-ros-wrapper/zed_interfaces/srv/start_3d_mapping.srv" NAME_WE)
add_custom_target(_zed_interfaces_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "zed_interfaces" "/home/qi/catkin_qi/src/zed-ros-wrapper/zed_interfaces/srv/start_3d_mapping.srv" ""
)

get_filename_component(_filename "/home/qi/catkin_qi/src/zed-ros-wrapper/zed_interfaces/srv/stop_3d_mapping.srv" NAME_WE)
add_custom_target(_zed_interfaces_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "zed_interfaces" "/home/qi/catkin_qi/src/zed-ros-wrapper/zed_interfaces/srv/stop_3d_mapping.srv" ""
)

get_filename_component(_filename "/home/qi/catkin_qi/src/zed-ros-wrapper/zed_interfaces/srv/stop_svo_recording.srv" NAME_WE)
add_custom_target(_zed_interfaces_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "zed_interfaces" "/home/qi/catkin_qi/src/zed-ros-wrapper/zed_interfaces/srv/stop_svo_recording.srv" ""
)

get_filename_component(_filename "/home/qi/catkin_qi/src/zed-ros-wrapper/zed_interfaces/srv/set_pose.srv" NAME_WE)
add_custom_target(_zed_interfaces_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "zed_interfaces" "/home/qi/catkin_qi/src/zed-ros-wrapper/zed_interfaces/srv/set_pose.srv" ""
)

get_filename_component(_filename "/home/qi/catkin_qi/src/zed-ros-wrapper/zed_interfaces/msg/object_stamped.msg" NAME_WE)
add_custom_target(_zed_interfaces_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "zed_interfaces" "/home/qi/catkin_qi/src/zed-ros-wrapper/zed_interfaces/msg/object_stamped.msg" "geometry_msgs/Vector3:geometry_msgs/Point32:std_msgs/Header"
)

get_filename_component(_filename "/home/qi/catkin_qi/src/zed-ros-wrapper/zed_interfaces/srv/set_led_status.srv" NAME_WE)
add_custom_target(_zed_interfaces_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "zed_interfaces" "/home/qi/catkin_qi/src/zed-ros-wrapper/zed_interfaces/srv/set_led_status.srv" ""
)

get_filename_component(_filename "/home/qi/catkin_qi/src/zed-ros-wrapper/zed_interfaces/srv/start_remote_stream.srv" NAME_WE)
add_custom_target(_zed_interfaces_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "zed_interfaces" "/home/qi/catkin_qi/src/zed-ros-wrapper/zed_interfaces/srv/start_remote_stream.srv" ""
)

get_filename_component(_filename "/home/qi/catkin_qi/src/zed-ros-wrapper/zed_interfaces/srv/toggle_led.srv" NAME_WE)
add_custom_target(_zed_interfaces_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "zed_interfaces" "/home/qi/catkin_qi/src/zed-ros-wrapper/zed_interfaces/srv/toggle_led.srv" ""
)

get_filename_component(_filename "/home/qi/catkin_qi/src/zed-ros-wrapper/zed_interfaces/srv/start_object_detection.srv" NAME_WE)
add_custom_target(_zed_interfaces_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "zed_interfaces" "/home/qi/catkin_qi/src/zed-ros-wrapper/zed_interfaces/srv/start_object_detection.srv" ""
)

get_filename_component(_filename "/home/qi/catkin_qi/src/zed-ros-wrapper/zed_interfaces/srv/reset_tracking.srv" NAME_WE)
add_custom_target(_zed_interfaces_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "zed_interfaces" "/home/qi/catkin_qi/src/zed-ros-wrapper/zed_interfaces/srv/reset_tracking.srv" ""
)

get_filename_component(_filename "/home/qi/catkin_qi/src/zed-ros-wrapper/zed_interfaces/srv/start_svo_recording.srv" NAME_WE)
add_custom_target(_zed_interfaces_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "zed_interfaces" "/home/qi/catkin_qi/src/zed-ros-wrapper/zed_interfaces/srv/start_svo_recording.srv" ""
)

get_filename_component(_filename "/home/qi/catkin_qi/src/zed-ros-wrapper/zed_interfaces/msg/objects.msg" NAME_WE)
add_custom_target(_zed_interfaces_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "zed_interfaces" "/home/qi/catkin_qi/src/zed-ros-wrapper/zed_interfaces/msg/objects.msg" "geometry_msgs/Vector3:std_msgs/Header:geometry_msgs/Point32:zed_interfaces/object_stamped"
)

get_filename_component(_filename "/home/qi/catkin_qi/src/zed-ros-wrapper/zed_interfaces/srv/reset_odometry.srv" NAME_WE)
add_custom_target(_zed_interfaces_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "zed_interfaces" "/home/qi/catkin_qi/src/zed-ros-wrapper/zed_interfaces/srv/reset_odometry.srv" ""
)

get_filename_component(_filename "/home/qi/catkin_qi/src/zed-ros-wrapper/zed_interfaces/srv/stop_object_detection.srv" NAME_WE)
add_custom_target(_zed_interfaces_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "zed_interfaces" "/home/qi/catkin_qi/src/zed-ros-wrapper/zed_interfaces/srv/stop_object_detection.srv" ""
)

get_filename_component(_filename "/home/qi/catkin_qi/src/zed-ros-wrapper/zed_interfaces/srv/stop_remote_stream.srv" NAME_WE)
add_custom_target(_zed_interfaces_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "zed_interfaces" "/home/qi/catkin_qi/src/zed-ros-wrapper/zed_interfaces/srv/stop_remote_stream.srv" ""
)

#
#  langs = gencpp;geneus;genlisp;gennodejs;genpy
#

### Section generating for lang: gencpp
### Generating Messages
_generate_msg_cpp(zed_interfaces
  "/home/qi/catkin_qi/src/zed-ros-wrapper/zed_interfaces/msg/objects.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Vector3.msg;/opt/ros/melodic/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Point32.msg;/home/qi/catkin_qi/src/zed-ros-wrapper/zed_interfaces/msg/object_stamped.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/zed_interfaces
)
_generate_msg_cpp(zed_interfaces
  "/home/qi/catkin_qi/src/zed-ros-wrapper/zed_interfaces/msg/object_stamped.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Vector3.msg;/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Point32.msg;/opt/ros/melodic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/zed_interfaces
)

### Generating Services
_generate_srv_cpp(zed_interfaces
  "/home/qi/catkin_qi/src/zed-ros-wrapper/zed_interfaces/srv/start_3d_mapping.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/zed_interfaces
)
_generate_srv_cpp(zed_interfaces
  "/home/qi/catkin_qi/src/zed-ros-wrapper/zed_interfaces/srv/stop_object_detection.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/zed_interfaces
)
_generate_srv_cpp(zed_interfaces
  "/home/qi/catkin_qi/src/zed-ros-wrapper/zed_interfaces/srv/stop_3d_mapping.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/zed_interfaces
)
_generate_srv_cpp(zed_interfaces
  "/home/qi/catkin_qi/src/zed-ros-wrapper/zed_interfaces/srv/stop_svo_recording.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/zed_interfaces
)
_generate_srv_cpp(zed_interfaces
  "/home/qi/catkin_qi/src/zed-ros-wrapper/zed_interfaces/srv/set_pose.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/zed_interfaces
)
_generate_srv_cpp(zed_interfaces
  "/home/qi/catkin_qi/src/zed-ros-wrapper/zed_interfaces/srv/set_led_status.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/zed_interfaces
)
_generate_srv_cpp(zed_interfaces
  "/home/qi/catkin_qi/src/zed-ros-wrapper/zed_interfaces/srv/stop_remote_stream.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/zed_interfaces
)
_generate_srv_cpp(zed_interfaces
  "/home/qi/catkin_qi/src/zed-ros-wrapper/zed_interfaces/srv/toggle_led.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/zed_interfaces
)
_generate_srv_cpp(zed_interfaces
  "/home/qi/catkin_qi/src/zed-ros-wrapper/zed_interfaces/srv/start_object_detection.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/zed_interfaces
)
_generate_srv_cpp(zed_interfaces
  "/home/qi/catkin_qi/src/zed-ros-wrapper/zed_interfaces/srv/reset_tracking.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/zed_interfaces
)
_generate_srv_cpp(zed_interfaces
  "/home/qi/catkin_qi/src/zed-ros-wrapper/zed_interfaces/srv/reset_odometry.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/zed_interfaces
)
_generate_srv_cpp(zed_interfaces
  "/home/qi/catkin_qi/src/zed-ros-wrapper/zed_interfaces/srv/start_remote_stream.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/zed_interfaces
)
_generate_srv_cpp(zed_interfaces
  "/home/qi/catkin_qi/src/zed-ros-wrapper/zed_interfaces/srv/start_svo_recording.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/zed_interfaces
)

### Generating Module File
_generate_module_cpp(zed_interfaces
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/zed_interfaces
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(zed_interfaces_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(zed_interfaces_generate_messages zed_interfaces_generate_messages_cpp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/qi/catkin_qi/src/zed-ros-wrapper/zed_interfaces/srv/start_3d_mapping.srv" NAME_WE)
add_dependencies(zed_interfaces_generate_messages_cpp _zed_interfaces_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/qi/catkin_qi/src/zed-ros-wrapper/zed_interfaces/srv/stop_3d_mapping.srv" NAME_WE)
add_dependencies(zed_interfaces_generate_messages_cpp _zed_interfaces_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/qi/catkin_qi/src/zed-ros-wrapper/zed_interfaces/srv/stop_svo_recording.srv" NAME_WE)
add_dependencies(zed_interfaces_generate_messages_cpp _zed_interfaces_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/qi/catkin_qi/src/zed-ros-wrapper/zed_interfaces/srv/set_pose.srv" NAME_WE)
add_dependencies(zed_interfaces_generate_messages_cpp _zed_interfaces_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/qi/catkin_qi/src/zed-ros-wrapper/zed_interfaces/msg/object_stamped.msg" NAME_WE)
add_dependencies(zed_interfaces_generate_messages_cpp _zed_interfaces_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/qi/catkin_qi/src/zed-ros-wrapper/zed_interfaces/srv/set_led_status.srv" NAME_WE)
add_dependencies(zed_interfaces_generate_messages_cpp _zed_interfaces_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/qi/catkin_qi/src/zed-ros-wrapper/zed_interfaces/srv/start_remote_stream.srv" NAME_WE)
add_dependencies(zed_interfaces_generate_messages_cpp _zed_interfaces_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/qi/catkin_qi/src/zed-ros-wrapper/zed_interfaces/srv/toggle_led.srv" NAME_WE)
add_dependencies(zed_interfaces_generate_messages_cpp _zed_interfaces_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/qi/catkin_qi/src/zed-ros-wrapper/zed_interfaces/srv/start_object_detection.srv" NAME_WE)
add_dependencies(zed_interfaces_generate_messages_cpp _zed_interfaces_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/qi/catkin_qi/src/zed-ros-wrapper/zed_interfaces/srv/reset_tracking.srv" NAME_WE)
add_dependencies(zed_interfaces_generate_messages_cpp _zed_interfaces_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/qi/catkin_qi/src/zed-ros-wrapper/zed_interfaces/srv/start_svo_recording.srv" NAME_WE)
add_dependencies(zed_interfaces_generate_messages_cpp _zed_interfaces_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/qi/catkin_qi/src/zed-ros-wrapper/zed_interfaces/msg/objects.msg" NAME_WE)
add_dependencies(zed_interfaces_generate_messages_cpp _zed_interfaces_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/qi/catkin_qi/src/zed-ros-wrapper/zed_interfaces/srv/reset_odometry.srv" NAME_WE)
add_dependencies(zed_interfaces_generate_messages_cpp _zed_interfaces_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/qi/catkin_qi/src/zed-ros-wrapper/zed_interfaces/srv/stop_object_detection.srv" NAME_WE)
add_dependencies(zed_interfaces_generate_messages_cpp _zed_interfaces_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/qi/catkin_qi/src/zed-ros-wrapper/zed_interfaces/srv/stop_remote_stream.srv" NAME_WE)
add_dependencies(zed_interfaces_generate_messages_cpp _zed_interfaces_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(zed_interfaces_gencpp)
add_dependencies(zed_interfaces_gencpp zed_interfaces_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS zed_interfaces_generate_messages_cpp)

### Section generating for lang: geneus
### Generating Messages
_generate_msg_eus(zed_interfaces
  "/home/qi/catkin_qi/src/zed-ros-wrapper/zed_interfaces/msg/objects.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Vector3.msg;/opt/ros/melodic/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Point32.msg;/home/qi/catkin_qi/src/zed-ros-wrapper/zed_interfaces/msg/object_stamped.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/zed_interfaces
)
_generate_msg_eus(zed_interfaces
  "/home/qi/catkin_qi/src/zed-ros-wrapper/zed_interfaces/msg/object_stamped.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Vector3.msg;/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Point32.msg;/opt/ros/melodic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/zed_interfaces
)

### Generating Services
_generate_srv_eus(zed_interfaces
  "/home/qi/catkin_qi/src/zed-ros-wrapper/zed_interfaces/srv/start_3d_mapping.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/zed_interfaces
)
_generate_srv_eus(zed_interfaces
  "/home/qi/catkin_qi/src/zed-ros-wrapper/zed_interfaces/srv/stop_object_detection.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/zed_interfaces
)
_generate_srv_eus(zed_interfaces
  "/home/qi/catkin_qi/src/zed-ros-wrapper/zed_interfaces/srv/stop_3d_mapping.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/zed_interfaces
)
_generate_srv_eus(zed_interfaces
  "/home/qi/catkin_qi/src/zed-ros-wrapper/zed_interfaces/srv/stop_svo_recording.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/zed_interfaces
)
_generate_srv_eus(zed_interfaces
  "/home/qi/catkin_qi/src/zed-ros-wrapper/zed_interfaces/srv/set_pose.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/zed_interfaces
)
_generate_srv_eus(zed_interfaces
  "/home/qi/catkin_qi/src/zed-ros-wrapper/zed_interfaces/srv/set_led_status.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/zed_interfaces
)
_generate_srv_eus(zed_interfaces
  "/home/qi/catkin_qi/src/zed-ros-wrapper/zed_interfaces/srv/stop_remote_stream.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/zed_interfaces
)
_generate_srv_eus(zed_interfaces
  "/home/qi/catkin_qi/src/zed-ros-wrapper/zed_interfaces/srv/toggle_led.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/zed_interfaces
)
_generate_srv_eus(zed_interfaces
  "/home/qi/catkin_qi/src/zed-ros-wrapper/zed_interfaces/srv/start_object_detection.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/zed_interfaces
)
_generate_srv_eus(zed_interfaces
  "/home/qi/catkin_qi/src/zed-ros-wrapper/zed_interfaces/srv/reset_tracking.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/zed_interfaces
)
_generate_srv_eus(zed_interfaces
  "/home/qi/catkin_qi/src/zed-ros-wrapper/zed_interfaces/srv/reset_odometry.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/zed_interfaces
)
_generate_srv_eus(zed_interfaces
  "/home/qi/catkin_qi/src/zed-ros-wrapper/zed_interfaces/srv/start_remote_stream.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/zed_interfaces
)
_generate_srv_eus(zed_interfaces
  "/home/qi/catkin_qi/src/zed-ros-wrapper/zed_interfaces/srv/start_svo_recording.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/zed_interfaces
)

### Generating Module File
_generate_module_eus(zed_interfaces
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/zed_interfaces
  "${ALL_GEN_OUTPUT_FILES_eus}"
)

add_custom_target(zed_interfaces_generate_messages_eus
  DEPENDS ${ALL_GEN_OUTPUT_FILES_eus}
)
add_dependencies(zed_interfaces_generate_messages zed_interfaces_generate_messages_eus)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/qi/catkin_qi/src/zed-ros-wrapper/zed_interfaces/srv/start_3d_mapping.srv" NAME_WE)
add_dependencies(zed_interfaces_generate_messages_eus _zed_interfaces_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/qi/catkin_qi/src/zed-ros-wrapper/zed_interfaces/srv/stop_3d_mapping.srv" NAME_WE)
add_dependencies(zed_interfaces_generate_messages_eus _zed_interfaces_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/qi/catkin_qi/src/zed-ros-wrapper/zed_interfaces/srv/stop_svo_recording.srv" NAME_WE)
add_dependencies(zed_interfaces_generate_messages_eus _zed_interfaces_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/qi/catkin_qi/src/zed-ros-wrapper/zed_interfaces/srv/set_pose.srv" NAME_WE)
add_dependencies(zed_interfaces_generate_messages_eus _zed_interfaces_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/qi/catkin_qi/src/zed-ros-wrapper/zed_interfaces/msg/object_stamped.msg" NAME_WE)
add_dependencies(zed_interfaces_generate_messages_eus _zed_interfaces_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/qi/catkin_qi/src/zed-ros-wrapper/zed_interfaces/srv/set_led_status.srv" NAME_WE)
add_dependencies(zed_interfaces_generate_messages_eus _zed_interfaces_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/qi/catkin_qi/src/zed-ros-wrapper/zed_interfaces/srv/start_remote_stream.srv" NAME_WE)
add_dependencies(zed_interfaces_generate_messages_eus _zed_interfaces_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/qi/catkin_qi/src/zed-ros-wrapper/zed_interfaces/srv/toggle_led.srv" NAME_WE)
add_dependencies(zed_interfaces_generate_messages_eus _zed_interfaces_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/qi/catkin_qi/src/zed-ros-wrapper/zed_interfaces/srv/start_object_detection.srv" NAME_WE)
add_dependencies(zed_interfaces_generate_messages_eus _zed_interfaces_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/qi/catkin_qi/src/zed-ros-wrapper/zed_interfaces/srv/reset_tracking.srv" NAME_WE)
add_dependencies(zed_interfaces_generate_messages_eus _zed_interfaces_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/qi/catkin_qi/src/zed-ros-wrapper/zed_interfaces/srv/start_svo_recording.srv" NAME_WE)
add_dependencies(zed_interfaces_generate_messages_eus _zed_interfaces_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/qi/catkin_qi/src/zed-ros-wrapper/zed_interfaces/msg/objects.msg" NAME_WE)
add_dependencies(zed_interfaces_generate_messages_eus _zed_interfaces_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/qi/catkin_qi/src/zed-ros-wrapper/zed_interfaces/srv/reset_odometry.srv" NAME_WE)
add_dependencies(zed_interfaces_generate_messages_eus _zed_interfaces_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/qi/catkin_qi/src/zed-ros-wrapper/zed_interfaces/srv/stop_object_detection.srv" NAME_WE)
add_dependencies(zed_interfaces_generate_messages_eus _zed_interfaces_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/qi/catkin_qi/src/zed-ros-wrapper/zed_interfaces/srv/stop_remote_stream.srv" NAME_WE)
add_dependencies(zed_interfaces_generate_messages_eus _zed_interfaces_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(zed_interfaces_geneus)
add_dependencies(zed_interfaces_geneus zed_interfaces_generate_messages_eus)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS zed_interfaces_generate_messages_eus)

### Section generating for lang: genlisp
### Generating Messages
_generate_msg_lisp(zed_interfaces
  "/home/qi/catkin_qi/src/zed-ros-wrapper/zed_interfaces/msg/objects.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Vector3.msg;/opt/ros/melodic/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Point32.msg;/home/qi/catkin_qi/src/zed-ros-wrapper/zed_interfaces/msg/object_stamped.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/zed_interfaces
)
_generate_msg_lisp(zed_interfaces
  "/home/qi/catkin_qi/src/zed-ros-wrapper/zed_interfaces/msg/object_stamped.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Vector3.msg;/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Point32.msg;/opt/ros/melodic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/zed_interfaces
)

### Generating Services
_generate_srv_lisp(zed_interfaces
  "/home/qi/catkin_qi/src/zed-ros-wrapper/zed_interfaces/srv/start_3d_mapping.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/zed_interfaces
)
_generate_srv_lisp(zed_interfaces
  "/home/qi/catkin_qi/src/zed-ros-wrapper/zed_interfaces/srv/stop_object_detection.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/zed_interfaces
)
_generate_srv_lisp(zed_interfaces
  "/home/qi/catkin_qi/src/zed-ros-wrapper/zed_interfaces/srv/stop_3d_mapping.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/zed_interfaces
)
_generate_srv_lisp(zed_interfaces
  "/home/qi/catkin_qi/src/zed-ros-wrapper/zed_interfaces/srv/stop_svo_recording.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/zed_interfaces
)
_generate_srv_lisp(zed_interfaces
  "/home/qi/catkin_qi/src/zed-ros-wrapper/zed_interfaces/srv/set_pose.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/zed_interfaces
)
_generate_srv_lisp(zed_interfaces
  "/home/qi/catkin_qi/src/zed-ros-wrapper/zed_interfaces/srv/set_led_status.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/zed_interfaces
)
_generate_srv_lisp(zed_interfaces
  "/home/qi/catkin_qi/src/zed-ros-wrapper/zed_interfaces/srv/stop_remote_stream.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/zed_interfaces
)
_generate_srv_lisp(zed_interfaces
  "/home/qi/catkin_qi/src/zed-ros-wrapper/zed_interfaces/srv/toggle_led.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/zed_interfaces
)
_generate_srv_lisp(zed_interfaces
  "/home/qi/catkin_qi/src/zed-ros-wrapper/zed_interfaces/srv/start_object_detection.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/zed_interfaces
)
_generate_srv_lisp(zed_interfaces
  "/home/qi/catkin_qi/src/zed-ros-wrapper/zed_interfaces/srv/reset_tracking.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/zed_interfaces
)
_generate_srv_lisp(zed_interfaces
  "/home/qi/catkin_qi/src/zed-ros-wrapper/zed_interfaces/srv/reset_odometry.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/zed_interfaces
)
_generate_srv_lisp(zed_interfaces
  "/home/qi/catkin_qi/src/zed-ros-wrapper/zed_interfaces/srv/start_remote_stream.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/zed_interfaces
)
_generate_srv_lisp(zed_interfaces
  "/home/qi/catkin_qi/src/zed-ros-wrapper/zed_interfaces/srv/start_svo_recording.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/zed_interfaces
)

### Generating Module File
_generate_module_lisp(zed_interfaces
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/zed_interfaces
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(zed_interfaces_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(zed_interfaces_generate_messages zed_interfaces_generate_messages_lisp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/qi/catkin_qi/src/zed-ros-wrapper/zed_interfaces/srv/start_3d_mapping.srv" NAME_WE)
add_dependencies(zed_interfaces_generate_messages_lisp _zed_interfaces_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/qi/catkin_qi/src/zed-ros-wrapper/zed_interfaces/srv/stop_3d_mapping.srv" NAME_WE)
add_dependencies(zed_interfaces_generate_messages_lisp _zed_interfaces_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/qi/catkin_qi/src/zed-ros-wrapper/zed_interfaces/srv/stop_svo_recording.srv" NAME_WE)
add_dependencies(zed_interfaces_generate_messages_lisp _zed_interfaces_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/qi/catkin_qi/src/zed-ros-wrapper/zed_interfaces/srv/set_pose.srv" NAME_WE)
add_dependencies(zed_interfaces_generate_messages_lisp _zed_interfaces_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/qi/catkin_qi/src/zed-ros-wrapper/zed_interfaces/msg/object_stamped.msg" NAME_WE)
add_dependencies(zed_interfaces_generate_messages_lisp _zed_interfaces_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/qi/catkin_qi/src/zed-ros-wrapper/zed_interfaces/srv/set_led_status.srv" NAME_WE)
add_dependencies(zed_interfaces_generate_messages_lisp _zed_interfaces_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/qi/catkin_qi/src/zed-ros-wrapper/zed_interfaces/srv/start_remote_stream.srv" NAME_WE)
add_dependencies(zed_interfaces_generate_messages_lisp _zed_interfaces_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/qi/catkin_qi/src/zed-ros-wrapper/zed_interfaces/srv/toggle_led.srv" NAME_WE)
add_dependencies(zed_interfaces_generate_messages_lisp _zed_interfaces_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/qi/catkin_qi/src/zed-ros-wrapper/zed_interfaces/srv/start_object_detection.srv" NAME_WE)
add_dependencies(zed_interfaces_generate_messages_lisp _zed_interfaces_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/qi/catkin_qi/src/zed-ros-wrapper/zed_interfaces/srv/reset_tracking.srv" NAME_WE)
add_dependencies(zed_interfaces_generate_messages_lisp _zed_interfaces_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/qi/catkin_qi/src/zed-ros-wrapper/zed_interfaces/srv/start_svo_recording.srv" NAME_WE)
add_dependencies(zed_interfaces_generate_messages_lisp _zed_interfaces_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/qi/catkin_qi/src/zed-ros-wrapper/zed_interfaces/msg/objects.msg" NAME_WE)
add_dependencies(zed_interfaces_generate_messages_lisp _zed_interfaces_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/qi/catkin_qi/src/zed-ros-wrapper/zed_interfaces/srv/reset_odometry.srv" NAME_WE)
add_dependencies(zed_interfaces_generate_messages_lisp _zed_interfaces_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/qi/catkin_qi/src/zed-ros-wrapper/zed_interfaces/srv/stop_object_detection.srv" NAME_WE)
add_dependencies(zed_interfaces_generate_messages_lisp _zed_interfaces_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/qi/catkin_qi/src/zed-ros-wrapper/zed_interfaces/srv/stop_remote_stream.srv" NAME_WE)
add_dependencies(zed_interfaces_generate_messages_lisp _zed_interfaces_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(zed_interfaces_genlisp)
add_dependencies(zed_interfaces_genlisp zed_interfaces_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS zed_interfaces_generate_messages_lisp)

### Section generating for lang: gennodejs
### Generating Messages
_generate_msg_nodejs(zed_interfaces
  "/home/qi/catkin_qi/src/zed-ros-wrapper/zed_interfaces/msg/objects.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Vector3.msg;/opt/ros/melodic/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Point32.msg;/home/qi/catkin_qi/src/zed-ros-wrapper/zed_interfaces/msg/object_stamped.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/zed_interfaces
)
_generate_msg_nodejs(zed_interfaces
  "/home/qi/catkin_qi/src/zed-ros-wrapper/zed_interfaces/msg/object_stamped.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Vector3.msg;/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Point32.msg;/opt/ros/melodic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/zed_interfaces
)

### Generating Services
_generate_srv_nodejs(zed_interfaces
  "/home/qi/catkin_qi/src/zed-ros-wrapper/zed_interfaces/srv/start_3d_mapping.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/zed_interfaces
)
_generate_srv_nodejs(zed_interfaces
  "/home/qi/catkin_qi/src/zed-ros-wrapper/zed_interfaces/srv/stop_object_detection.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/zed_interfaces
)
_generate_srv_nodejs(zed_interfaces
  "/home/qi/catkin_qi/src/zed-ros-wrapper/zed_interfaces/srv/stop_3d_mapping.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/zed_interfaces
)
_generate_srv_nodejs(zed_interfaces
  "/home/qi/catkin_qi/src/zed-ros-wrapper/zed_interfaces/srv/stop_svo_recording.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/zed_interfaces
)
_generate_srv_nodejs(zed_interfaces
  "/home/qi/catkin_qi/src/zed-ros-wrapper/zed_interfaces/srv/set_pose.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/zed_interfaces
)
_generate_srv_nodejs(zed_interfaces
  "/home/qi/catkin_qi/src/zed-ros-wrapper/zed_interfaces/srv/set_led_status.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/zed_interfaces
)
_generate_srv_nodejs(zed_interfaces
  "/home/qi/catkin_qi/src/zed-ros-wrapper/zed_interfaces/srv/stop_remote_stream.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/zed_interfaces
)
_generate_srv_nodejs(zed_interfaces
  "/home/qi/catkin_qi/src/zed-ros-wrapper/zed_interfaces/srv/toggle_led.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/zed_interfaces
)
_generate_srv_nodejs(zed_interfaces
  "/home/qi/catkin_qi/src/zed-ros-wrapper/zed_interfaces/srv/start_object_detection.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/zed_interfaces
)
_generate_srv_nodejs(zed_interfaces
  "/home/qi/catkin_qi/src/zed-ros-wrapper/zed_interfaces/srv/reset_tracking.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/zed_interfaces
)
_generate_srv_nodejs(zed_interfaces
  "/home/qi/catkin_qi/src/zed-ros-wrapper/zed_interfaces/srv/reset_odometry.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/zed_interfaces
)
_generate_srv_nodejs(zed_interfaces
  "/home/qi/catkin_qi/src/zed-ros-wrapper/zed_interfaces/srv/start_remote_stream.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/zed_interfaces
)
_generate_srv_nodejs(zed_interfaces
  "/home/qi/catkin_qi/src/zed-ros-wrapper/zed_interfaces/srv/start_svo_recording.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/zed_interfaces
)

### Generating Module File
_generate_module_nodejs(zed_interfaces
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/zed_interfaces
  "${ALL_GEN_OUTPUT_FILES_nodejs}"
)

add_custom_target(zed_interfaces_generate_messages_nodejs
  DEPENDS ${ALL_GEN_OUTPUT_FILES_nodejs}
)
add_dependencies(zed_interfaces_generate_messages zed_interfaces_generate_messages_nodejs)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/qi/catkin_qi/src/zed-ros-wrapper/zed_interfaces/srv/start_3d_mapping.srv" NAME_WE)
add_dependencies(zed_interfaces_generate_messages_nodejs _zed_interfaces_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/qi/catkin_qi/src/zed-ros-wrapper/zed_interfaces/srv/stop_3d_mapping.srv" NAME_WE)
add_dependencies(zed_interfaces_generate_messages_nodejs _zed_interfaces_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/qi/catkin_qi/src/zed-ros-wrapper/zed_interfaces/srv/stop_svo_recording.srv" NAME_WE)
add_dependencies(zed_interfaces_generate_messages_nodejs _zed_interfaces_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/qi/catkin_qi/src/zed-ros-wrapper/zed_interfaces/srv/set_pose.srv" NAME_WE)
add_dependencies(zed_interfaces_generate_messages_nodejs _zed_interfaces_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/qi/catkin_qi/src/zed-ros-wrapper/zed_interfaces/msg/object_stamped.msg" NAME_WE)
add_dependencies(zed_interfaces_generate_messages_nodejs _zed_interfaces_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/qi/catkin_qi/src/zed-ros-wrapper/zed_interfaces/srv/set_led_status.srv" NAME_WE)
add_dependencies(zed_interfaces_generate_messages_nodejs _zed_interfaces_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/qi/catkin_qi/src/zed-ros-wrapper/zed_interfaces/srv/start_remote_stream.srv" NAME_WE)
add_dependencies(zed_interfaces_generate_messages_nodejs _zed_interfaces_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/qi/catkin_qi/src/zed-ros-wrapper/zed_interfaces/srv/toggle_led.srv" NAME_WE)
add_dependencies(zed_interfaces_generate_messages_nodejs _zed_interfaces_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/qi/catkin_qi/src/zed-ros-wrapper/zed_interfaces/srv/start_object_detection.srv" NAME_WE)
add_dependencies(zed_interfaces_generate_messages_nodejs _zed_interfaces_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/qi/catkin_qi/src/zed-ros-wrapper/zed_interfaces/srv/reset_tracking.srv" NAME_WE)
add_dependencies(zed_interfaces_generate_messages_nodejs _zed_interfaces_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/qi/catkin_qi/src/zed-ros-wrapper/zed_interfaces/srv/start_svo_recording.srv" NAME_WE)
add_dependencies(zed_interfaces_generate_messages_nodejs _zed_interfaces_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/qi/catkin_qi/src/zed-ros-wrapper/zed_interfaces/msg/objects.msg" NAME_WE)
add_dependencies(zed_interfaces_generate_messages_nodejs _zed_interfaces_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/qi/catkin_qi/src/zed-ros-wrapper/zed_interfaces/srv/reset_odometry.srv" NAME_WE)
add_dependencies(zed_interfaces_generate_messages_nodejs _zed_interfaces_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/qi/catkin_qi/src/zed-ros-wrapper/zed_interfaces/srv/stop_object_detection.srv" NAME_WE)
add_dependencies(zed_interfaces_generate_messages_nodejs _zed_interfaces_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/qi/catkin_qi/src/zed-ros-wrapper/zed_interfaces/srv/stop_remote_stream.srv" NAME_WE)
add_dependencies(zed_interfaces_generate_messages_nodejs _zed_interfaces_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(zed_interfaces_gennodejs)
add_dependencies(zed_interfaces_gennodejs zed_interfaces_generate_messages_nodejs)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS zed_interfaces_generate_messages_nodejs)

### Section generating for lang: genpy
### Generating Messages
_generate_msg_py(zed_interfaces
  "/home/qi/catkin_qi/src/zed-ros-wrapper/zed_interfaces/msg/objects.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Vector3.msg;/opt/ros/melodic/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Point32.msg;/home/qi/catkin_qi/src/zed-ros-wrapper/zed_interfaces/msg/object_stamped.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/zed_interfaces
)
_generate_msg_py(zed_interfaces
  "/home/qi/catkin_qi/src/zed-ros-wrapper/zed_interfaces/msg/object_stamped.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Vector3.msg;/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Point32.msg;/opt/ros/melodic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/zed_interfaces
)

### Generating Services
_generate_srv_py(zed_interfaces
  "/home/qi/catkin_qi/src/zed-ros-wrapper/zed_interfaces/srv/start_3d_mapping.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/zed_interfaces
)
_generate_srv_py(zed_interfaces
  "/home/qi/catkin_qi/src/zed-ros-wrapper/zed_interfaces/srv/stop_object_detection.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/zed_interfaces
)
_generate_srv_py(zed_interfaces
  "/home/qi/catkin_qi/src/zed-ros-wrapper/zed_interfaces/srv/stop_3d_mapping.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/zed_interfaces
)
_generate_srv_py(zed_interfaces
  "/home/qi/catkin_qi/src/zed-ros-wrapper/zed_interfaces/srv/stop_svo_recording.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/zed_interfaces
)
_generate_srv_py(zed_interfaces
  "/home/qi/catkin_qi/src/zed-ros-wrapper/zed_interfaces/srv/set_pose.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/zed_interfaces
)
_generate_srv_py(zed_interfaces
  "/home/qi/catkin_qi/src/zed-ros-wrapper/zed_interfaces/srv/set_led_status.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/zed_interfaces
)
_generate_srv_py(zed_interfaces
  "/home/qi/catkin_qi/src/zed-ros-wrapper/zed_interfaces/srv/stop_remote_stream.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/zed_interfaces
)
_generate_srv_py(zed_interfaces
  "/home/qi/catkin_qi/src/zed-ros-wrapper/zed_interfaces/srv/toggle_led.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/zed_interfaces
)
_generate_srv_py(zed_interfaces
  "/home/qi/catkin_qi/src/zed-ros-wrapper/zed_interfaces/srv/start_object_detection.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/zed_interfaces
)
_generate_srv_py(zed_interfaces
  "/home/qi/catkin_qi/src/zed-ros-wrapper/zed_interfaces/srv/reset_tracking.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/zed_interfaces
)
_generate_srv_py(zed_interfaces
  "/home/qi/catkin_qi/src/zed-ros-wrapper/zed_interfaces/srv/reset_odometry.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/zed_interfaces
)
_generate_srv_py(zed_interfaces
  "/home/qi/catkin_qi/src/zed-ros-wrapper/zed_interfaces/srv/start_remote_stream.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/zed_interfaces
)
_generate_srv_py(zed_interfaces
  "/home/qi/catkin_qi/src/zed-ros-wrapper/zed_interfaces/srv/start_svo_recording.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/zed_interfaces
)

### Generating Module File
_generate_module_py(zed_interfaces
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/zed_interfaces
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(zed_interfaces_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(zed_interfaces_generate_messages zed_interfaces_generate_messages_py)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/qi/catkin_qi/src/zed-ros-wrapper/zed_interfaces/srv/start_3d_mapping.srv" NAME_WE)
add_dependencies(zed_interfaces_generate_messages_py _zed_interfaces_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/qi/catkin_qi/src/zed-ros-wrapper/zed_interfaces/srv/stop_3d_mapping.srv" NAME_WE)
add_dependencies(zed_interfaces_generate_messages_py _zed_interfaces_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/qi/catkin_qi/src/zed-ros-wrapper/zed_interfaces/srv/stop_svo_recording.srv" NAME_WE)
add_dependencies(zed_interfaces_generate_messages_py _zed_interfaces_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/qi/catkin_qi/src/zed-ros-wrapper/zed_interfaces/srv/set_pose.srv" NAME_WE)
add_dependencies(zed_interfaces_generate_messages_py _zed_interfaces_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/qi/catkin_qi/src/zed-ros-wrapper/zed_interfaces/msg/object_stamped.msg" NAME_WE)
add_dependencies(zed_interfaces_generate_messages_py _zed_interfaces_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/qi/catkin_qi/src/zed-ros-wrapper/zed_interfaces/srv/set_led_status.srv" NAME_WE)
add_dependencies(zed_interfaces_generate_messages_py _zed_interfaces_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/qi/catkin_qi/src/zed-ros-wrapper/zed_interfaces/srv/start_remote_stream.srv" NAME_WE)
add_dependencies(zed_interfaces_generate_messages_py _zed_interfaces_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/qi/catkin_qi/src/zed-ros-wrapper/zed_interfaces/srv/toggle_led.srv" NAME_WE)
add_dependencies(zed_interfaces_generate_messages_py _zed_interfaces_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/qi/catkin_qi/src/zed-ros-wrapper/zed_interfaces/srv/start_object_detection.srv" NAME_WE)
add_dependencies(zed_interfaces_generate_messages_py _zed_interfaces_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/qi/catkin_qi/src/zed-ros-wrapper/zed_interfaces/srv/reset_tracking.srv" NAME_WE)
add_dependencies(zed_interfaces_generate_messages_py _zed_interfaces_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/qi/catkin_qi/src/zed-ros-wrapper/zed_interfaces/srv/start_svo_recording.srv" NAME_WE)
add_dependencies(zed_interfaces_generate_messages_py _zed_interfaces_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/qi/catkin_qi/src/zed-ros-wrapper/zed_interfaces/msg/objects.msg" NAME_WE)
add_dependencies(zed_interfaces_generate_messages_py _zed_interfaces_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/qi/catkin_qi/src/zed-ros-wrapper/zed_interfaces/srv/reset_odometry.srv" NAME_WE)
add_dependencies(zed_interfaces_generate_messages_py _zed_interfaces_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/qi/catkin_qi/src/zed-ros-wrapper/zed_interfaces/srv/stop_object_detection.srv" NAME_WE)
add_dependencies(zed_interfaces_generate_messages_py _zed_interfaces_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/qi/catkin_qi/src/zed-ros-wrapper/zed_interfaces/srv/stop_remote_stream.srv" NAME_WE)
add_dependencies(zed_interfaces_generate_messages_py _zed_interfaces_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(zed_interfaces_genpy)
add_dependencies(zed_interfaces_genpy zed_interfaces_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS zed_interfaces_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/zed_interfaces)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/zed_interfaces
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_cpp)
  add_dependencies(zed_interfaces_generate_messages_cpp std_msgs_generate_messages_cpp)
endif()
if(TARGET geometry_msgs_generate_messages_cpp)
  add_dependencies(zed_interfaces_generate_messages_cpp geometry_msgs_generate_messages_cpp)
endif()

if(geneus_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/zed_interfaces)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/zed_interfaces
    DESTINATION ${geneus_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_eus)
  add_dependencies(zed_interfaces_generate_messages_eus std_msgs_generate_messages_eus)
endif()
if(TARGET geometry_msgs_generate_messages_eus)
  add_dependencies(zed_interfaces_generate_messages_eus geometry_msgs_generate_messages_eus)
endif()

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/zed_interfaces)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/zed_interfaces
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_lisp)
  add_dependencies(zed_interfaces_generate_messages_lisp std_msgs_generate_messages_lisp)
endif()
if(TARGET geometry_msgs_generate_messages_lisp)
  add_dependencies(zed_interfaces_generate_messages_lisp geometry_msgs_generate_messages_lisp)
endif()

if(gennodejs_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/zed_interfaces)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/zed_interfaces
    DESTINATION ${gennodejs_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_nodejs)
  add_dependencies(zed_interfaces_generate_messages_nodejs std_msgs_generate_messages_nodejs)
endif()
if(TARGET geometry_msgs_generate_messages_nodejs)
  add_dependencies(zed_interfaces_generate_messages_nodejs geometry_msgs_generate_messages_nodejs)
endif()

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/zed_interfaces)
  install(CODE "execute_process(COMMAND \"/usr/bin/python2\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/zed_interfaces\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/zed_interfaces
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_py)
  add_dependencies(zed_interfaces_generate_messages_py std_msgs_generate_messages_py)
endif()
if(TARGET geometry_msgs_generate_messages_py)
  add_dependencies(zed_interfaces_generate_messages_py geometry_msgs_generate_messages_py)
endif()
