# DAY 04 - Piscine Robot Operating System
## Gazebo
Summary: On this day, you will add sensors to your robot that will allow it to touch the world.
## Contents
<!-- TOC -->

- [DAY 04 - Piscine Robot Operating System](#day-04---piscine-robot-operating-system)
    - [Gazebo](#gazebo)
    - [Contents](#contents)
    - [Chapter I](#chapter-i)
        - [Preamble](#preamble)
    - [Chapter II](#chapter-ii)
        - [Instructions](#instructions)
    - [Chapter III](#chapter-iii)
        - [Exercise 00 : Using Lidar in Gazebo](#exercise-00--using-lidar-in-gazebo)
    - [Chapter IV](#chapter-iv)
        - [Exercise 01 : Using depth camera in Gazebo](#exercise-01--using-depth-camera-in-gazebo)
    - [Chapter V](#chapter-v)
        - [Exercise 02 : Using imu in Gazebo](#exercise-02--using-imu-in-gazebo)
    - [Chapter VI](#chapter-vi)
        - [Exercise 03 : Stopping in front of an obstacle using data from a laser lidar](#exercise-03--stopping-in-front-of-an-obstacle-using-data-from-a-laser-lidar)
    - [Chapter VII](#chapter-vii)
        - [Exercise 04 : Stopping in front of an obstacle using data from the depth camera](#exercise-04--stopping-in-front-of-an-obstacle-using-data-from-the-depth-camera)

<!-- /TOC -->
## Chapter I
### Preamble
To fully emulate the work of the robot, you need the data from the sensors in the simulator to be similar to the real data from the sensors of a real robot. Gazebo allows you to emulate almost all types of sensors in robots, as if you are receiving data from them from a real robot. It allows you to develop and test your algorithms on Gazrbo robots. After that, you can run your algorithms without changes on a real robot with real sensors and they will work. For example, in the DARPA Subterranean Challenge competition, there are simulation competitions that replicate real competitions in caves. The caves were scanned and the resulting 3D models of the caves were transferred to the Gazebo simulator, after which it was possible to test robots and compete in Gazebo. 

## Chapter II
### Instructions
* Use this page as the only reference. Do not listen to any rumors and speculations about how to prepare your solution.
* Here and further we use ROS Melodic and C++.
* Pay attention to the permissions of your files and directories.
* To be assessed your solution must be in your GIT repository.
* Your solutions will be evaluated by your peers.
* You should not leave any additional file in your directory other than those explicitly specified in the subject. It is recommended that you modify your .gitignore to avoid accidents.
* When you need to get a precise output in your program, it is forbidden to display a precalculated output instead of performing the exercise correctly.
* Have a question? Ask your neighbor on the right. Otherwise, try your neighbor on the left.
* Your reference manual: peers / Internet / Google.
* You can ask questions in Slack.
* Read the examples carefully. They could very well call for details that are not explicitly mentioned in the subject...
* And may the Force be with you!

## Chapter III
### Exercise 00 : Using Lidar in Gazebo
Directory to store your solution : ex00/

Files to be in the directory : robot_lidar.launch

Authorized functions : libgazebo_ros_laser.so or libgazebo_ros_gpu_laser.so

Comments :

Read this documentation 
http://gazebosim.org/tutorials?tut=ros_gzplugins#GPULaser

Add a laser lidar to your robot from the previous day. Launch file should launch rviz and gazebo at the same time. In rviz, configure the display of a scan topic of the laserScan type from lidar.

Add some obstacles to gazebo world. When you start robot_lidar.launch, check that the world with obstacles is automatically loaded and these obstacles are visible in rviz on laserScan.

Save all files of your ROS package to the ex00 folder.

## Chapter IV
### Exercise 01 : Using depth camera in Gazebo
Directory to store your solution : ex01/

Files to be in the directory : robot_depth_camera.launch

Authorized functions : libgazebo_ros_openni_kinect.so

Comments :

Read this documentation
http://gazebosim.org/tutorials?tut=ros_gzplugins#DepthCamera

Add to your robot from the previous depth camera task. Launch file should launch rviz and gazebo at the same time. In rviz, set the display of topics with depth camera.

Add some obstacles to gazebo world. Check when launching robot_depth_camera.launch that the world with obstacles is automatically loaded and rviz on PointCloud2 can see these obstacles.

Save all files of your ROS package to ex01 folder.

## Chapter V
### Exercise 02 : Using imu in Gazebo
Directory to store your solution : ex02/

Files to be in the directory : robot_imu.launch

Authorized functions : libgazebo_ros_imu.so

Comments :

Read this documentation 
http://gazebosim.org/tutorials?tut=ros_gzplugins#IMU(GazeboRosImu)

Add to your robot from the previous imu task. Launch file should launch rviz and gazebo at the same time. In rviz, configure the display of topics with imu.

Save all files of your ROS package to ex02 folder.

## Chapter VI
### Exercise 03 : Stopping in front of an obstacle using data from a laser lidar
Directory to store your solution : ex03/

Files to be in the directory : 

Authorized functions :

Comments :

Develop a ROS package that will launch your robot from previous tasks in the Gazebo environment. The robot must carry out autonomous movement with a stop in front of an obstacle using data from a laser lidar.

Create a Gazebo world with an obstacle, spawn your robot in it some distance away. After running the launch file, gazebo and rviz should open with an obstacle and a robot. The robot should start moving automatically and stop on its own some distance in front of the obstacle, using data from the laser lidar. You must write a program that, after starting, will move the robot forward and stop it in front of an obstacle that has arisen in front of the robot. After the disappearance of the obstacle in front of him, the robot must resume movement.

Test your program by moving the Gazebo obstacle away from the robot. The robot must independently resume movement and stop.

Save all files of your ROS package to ex03 folder.

## Chapter VII
### Exercise 04 : Stopping in front of an obstacle using data from the depth camera
Directory to store your solution : ex04/

Files to be in the directory : 

Authorized functions :

Comments :

Develop a ROS package that will launch your robot from previous tasks in the Gazebo environment. The robot must perform autonomous movement with a stop in front of an obstacle using data from the depth camera.

Create a Gazebo world with an obstacle, spawn your robot in it some distance away. After running the launch file, gazebo and rviz should open with an obstacle and a robot. The robot should automatically start moving and stop on its own some distance in front of the obstacle, using data from the depth camera. You must write a program that, after starting, will move the robot forward and stop it in front of an obstacle that has arisen in front of the robot. After the disappearance of the obstacle in front of him, the robot must resume movement.

Test your program by moving the Gazebo obstacle away from the robot. The robot must independently resume movement and stop.

Save all files of your ROS package to ex04 folder.