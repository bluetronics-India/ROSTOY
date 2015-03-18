# ROSTOY
ROS Toy robot. 

Resources

* [rosserial2arduino](http://wiki.ros.org/rosserial_arduino/Tutorials/Arduino%20IDE%20Setup)

* [Setup ROS workspace](http://wiki.ros.org/catkin/Tutorials/create_a_workspace)
* [Motor Shield](http://playground.arduino.cc/MotorControlShieldV3/0)
* [ROSSerial Python](http://wiki.ros.org/rosserial_python)
* [Joystick](http://wiki.ros.org/joy/Tutorials/ConfiguringALinuxJoystick)
sudo apt-get install ros-indigo-rosserial-python
* [Kinect calibration](http://wiki.ros.org/openni_launch/Tutorials/IntrinsicCalibration)
* sudo apt-get install ros-indigo-usb-cam
* uvcvideo
* v412-ctl
* rosrun camera_calibration cameracalibrator.py image:=/usb_cam/image_raw camera:=/usb_cam --size 5x7 --square 0.03425
* sudo aptitude install ros-indigo-ar-track-alvar
```
kscottz@kscottz-thinkpad:~/Code$ mkdir toy_ws
kscottz@kscottz-thinkpad:~/Code$ source /opt/ros/indigo/setup.bash 
kscottz@kscottz-thinkpad:~/Code$ cd toy_ws/
kscottz@kscottz-thinkpad:~/Code/toy_ws$ mkdir src
kscottz@kscottz-thinkpad:~/Code/toy_ws$ cd src/
kscottz@kscottz-thinkpad:~/Code/toy_ws/src$ ls
kscottz@kscottz-thinkpad:~/Code/toy_ws/src$ catkin_init_workspace 
Creating symlink "/home/kscottz/Code/toy_ws/src/CMakeLists.txt" pointing to "/opt/ros/indigo/share/catkin/cmake/toplevel.cmake"
kscottz@kscottz-thinkpad:~/Code/toy_ws/src$ cd ..
kscottz@kscottz-thinkpad:~/Code/toy_ws$ catkin_make
Base path: /home/kscottz/Code/toy_ws
Source space: /home/kscottz/Code/toy_ws/src
Build space: /home/kscottz/Code/toy_ws/build
Devel space: /home/kscottz/Code/toy_ws/devel
Install space: /home/kscottz/Code/toy_ws/install
####
#### Running command: "cmake /home/kscottz/Code/toy_ws/src -DCATKIN_DEVEL_PREFIX=/home/kscottz/Code/toy_ws/devel -DCMAKE_INSTALL_PREFIX=/home/kscottz/Code/toy_ws/install" in "/home/kscottz/Code/toy_ws/build"
####
-- The C compiler identification is GNU 4.8.2
-- The CXX compiler identification is GNU 4.8.2
-- Check for working C compiler: /usr/bin/cc
-- Check for working C compiler: /usr/bin/cc -- works
-- Detecting C compiler ABI info
-- Detecting C compiler ABI info - done
-- Check for working CXX compiler: /usr/bin/c++
-- Check for working CXX compiler: /usr/bin/c++ -- works
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - done
-- Using CATKIN_DEVEL_PREFIX: /home/kscottz/Code/toy_ws/devel
-- Using CMAKE_PREFIX_PATH: /opt/ros/indigo
-- This workspace overlays: /opt/ros/indigo
-- Found PythonInterp: /usr/bin/python (found version "2.7.6") 
-- Using PYTHON_EXECUTABLE: /usr/bin/python
-- Using Debian Python package layout
-- Using empy: /usr/bin/empy
-- Using CATKIN_ENABLE_TESTING: ON
-- Call enable_testing()
-- Using CATKIN_TEST_RESULTS_DIR: /home/kscottz/Code/toy_ws/build/test_results
-- Looking for include file pthread.h
-- Looking for include file pthread.h - found
-- Looking for pthread_create
-- Looking for pthread_create - not found
-- Looking for pthread_create in pthreads
-- Looking for pthread_create in pthreads - not found
-- Looking for pthread_create in pthread
-- Looking for pthread_create in pthread - found
-- Found Threads: TRUE  
-- Found gtest sources under '/usr/src/gtest': gtests will be built
-- Using Python nosetests: /usr/bin/nosetests-2.7
-- catkin 0.6.9
-- BUILD_SHARED_LIBS is on
-- Configuring done
-- Generating done
-- Build files have been written to: /home/kscottz/Code/toy_ws/build
####
#### Running command: "make -j4 -l4" in "/home/kscottz/Code/toy_ws/build"
####
kscottz@kscottz-thinkpad:~/Code/toy_ws$ 
```

Install rosserail and arduino

```
sudo apt-get install ros-indigo-rosserial-arduino
```


TO RUN

```
roscore
rosrun rosserial_python serial_node.py _port:=/dev/ttyACM0
python cmd_robot.py 0 0 0 255
```