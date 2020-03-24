#!/bin/sh

if [ -n "$DESTDIR" ] ; then
    case $DESTDIR in
        /*) # ok
            ;;
        *)
            /bin/echo "DESTDIR argument must be absolute... "
            /bin/echo "otherwise python's distutils will bork things."
            exit 1
    esac
    DESTDIR_ARG="--root=$DESTDIR"
fi

echo_and_run() { echo "+ $@" ; "$@" ; }

echo_and_run cd "/home/qi/catkin_qi/src/qt_ros_ui/qt_ros/qt_create"

# ensure that Python install destination exists
echo_and_run mkdir -p "$DESTDIR/home/qi/catkin_qi/install/lib/python2.7/dist-packages"

# Note that PYTHONPATH is pulled from the environment to support installing
# into one location when some dependencies were installed in another
# location, #123.
echo_and_run /usr/bin/env \
    PYTHONPATH="/home/qi/catkin_qi/install/lib/python2.7/dist-packages:/home/qi/catkin_qi/build/lib/python2.7/dist-packages:$PYTHONPATH" \
    CATKIN_BINARY_DIR="/home/qi/catkin_qi/build" \
    "/usr/bin/python2" \
    "/home/qi/catkin_qi/src/qt_ros_ui/qt_ros/qt_create/setup.py" \
    build --build-base "/home/qi/catkin_qi/build/qt_ros_ui/qt_ros/qt_create" \
    install \
    $DESTDIR_ARG \
    --install-layout=deb --prefix="/home/qi/catkin_qi/install" --install-scripts="/home/qi/catkin_qi/install/bin"
