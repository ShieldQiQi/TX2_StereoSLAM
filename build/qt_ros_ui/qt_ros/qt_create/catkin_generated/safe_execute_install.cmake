execute_process(COMMAND "/home/qi/catkin_qi/build/qt_ros_ui/qt_ros/qt_create/catkin_generated/python_distutils_install.sh" RESULT_VARIABLE res)

if(NOT res EQUAL 0)
  message(FATAL_ERROR "execute_process(/home/qi/catkin_qi/build/qt_ros_ui/qt_ros/qt_create/catkin_generated/python_distutils_install.sh) returned error code ")
endif()
