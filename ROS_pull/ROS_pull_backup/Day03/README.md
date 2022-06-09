# DAY 03 - Piscine Robot Operating System
## URDF
Summary: On this day, you will learn how to model robots in the rviz visualizer and the Gazebo simulator. Model your first robot and teach it how to move on its own in the simulator.
## Contents
<!-- TOC -->

- [DAY 03 - Piscine Robot Operating System](#day-03---piscine-robot-operating-system)
    - [URDF](#urdf)
    - [Contents](#contents)
    - [Chapter I](#chapter-i)
        - [Preamble](#preamble)
    - [Chapter II](#chapter-ii)
        - [Instructions](#instructions)
    - [Chapter III](#chapter-iii)
        - [Exercise 00 : Learning URDF](#exercise-00--learning-urdf)
    - [Chapter IV](#chapter-iv)
        - [Exercise 01 : Using Xacro to Clean Up a URDF File](#exercise-01--using-xacro-to-clean-up-a-urdf-file)
    - [Chapter V](#chapter-v)
        - [Exercise 02 : Using a URDF in Gazebo](#exercise-02--using-a-urdf-in-gazebo)
    - [Chapter VI](#chapter-vi)
        - [Exercise 03 : Robot control program in Gazebo](#exercise-03--robot-control-program-in-gazebo)

<!-- /TOC -->
## Chapter I
### Preamble
Modeling a robot in a simulator and visualizing its state in 3D is an important part of robotics. There is not always physical access to the robot, sometimes testing the developed programs on a real robot is complicated by many reasons. Therefore, roboticists make a copy of the robot in the simulator and develop programs for it by testing them in the simulator. Also, when checking the operation of the robot, you will need to visualize its state and see what its sensors see in 3D. All these tasks in ROS can be solved using the Gazebo simulator and the RVIZ visualizer.

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
### Exercise 00 : Learning URDF
Directory to store your solution : ex00/

Files to be in the directory : robot.urdf, robot_dysplay.launch

Authorized functions :

Comments :

In this exercise, you will need to study the documentation URDF and the tutorial “Learning URDF”.
Read and follow this tutorials step by step:
http://wiki.ros.org/urdf
http://wiki.ros.org/urdf/Tutorials/Building%20a%20Visual%20Robot%20Model%20with%20URDF%20from%20Scratch
http://wiki.ros.org/urdf/Tutorials/Building%20a%20Movable%20Robot%20Model%20with%20URDF
http://wiki.ros.org/urdf/Tutorials/Adding%20Physical%20and%20Collision%20Properties%20to%20a%20URDF%20Model

Create an urdf differential drive robot model. The wheels should spin through the GUI of the joint state publisher. The robot must have Physical and Collision Properties to a URDF Model set.

The dimensions of the robot must fit into the following specifications:
The maximum radius of the wheels is 0.065 meters.
The maximum wheel width is 0.015 meters.
The dimensions of the robot must be inscribed in a maximum rectangle of 0.18 by 0.14 meters.
The maximum height of the robot is 0.2 meters.

Also create a launch file called robot_dysplay.launch which will load your robot description and show it in rviz along with the joint state publisher GUI.

Then save the robot.urdf and robot_dysplay.launch file to the ex00 folder.

## Chapter IV
### Exercise 01 : Using Xacro to Clean Up a URDF File
Directory to store your solution : ex01/

Files to be in the directory : robot.urdf.xacro, robot_dysplay.launch

Authorized functions :

Comments :

In this exercise, you will need to study the tutorials “Using Xacro to Clean Up a URDF File”.

Read and follow this tutorial step by step http://wiki.ros.org/urdf/Tutorials/Using%20Xacro%20to%20Clean%20Up%20a%20URDF%20File

Translate the URDF file from the previous task into XACRO.
Your XACRO model should be launched via robot_dysplay.launch which will load your robot description and show it in rviz along with the joint state publisher GUI.

Then save the robot.urdf.xacro and robot_dysplay.launch file to the ex01 folder.

## Chapter V
### Exercise 02 : Using a URDF in Gazebo
Directory to store your solution : ex02/

Files to be in the directory : robot_gazebo.launch, robot.urdf.xacro, robot.gazebo.xacro

Authorized functions : Используйте gazebo_plugins libgazebo_ros_diff_drive.so вместо diff_drive_controller/DiffDriveController.

Comments :

In this exercise, you will need to study the tutorial “Using a URDF in Gazebo”.

Read and follow this tutorial step by step http://wiki.ros.org/urdf/Tutorials/Using%20a%20URDF%20in%20Gazebo
http://gazebosim.org/tutorials?tut=ros_gzplugins#DifferentialDrive

Create a ROS package that runs your differential drive robot from the previous Gazebo challenge.
Use gazebo_plugins libgazebo_ros_diff_drive.so! It must be included in a separate robot.gazebo.xacro file, and this file is included in the robot.urdf.xacro file.
Your robot must ride in Gazebo controlled through the RobotSteering panel and the /cmd_vel topic using the rostopic pub commands.

Check your robot keyboard control via rosrun teleop_twist_keyboard teleop_twist_keyboard.py, the robot should move in gazebo and rviz.

Save all files of your ROS package to ex02 folder.

## Chapter VI
### Exercise 03 : Robot control program in Gazebo
Directory to store your solution : ex03/

Files to be in the directory : the ROS package you created, circle_movement.cpp, circle_movement.launch

Authorized functions :

Comments :

Write your own ROS package with a C++ node that will launch your robot from the previous task and the node you wrote via launch. Your node should control the robot only by posting messages to the /cmd_vel topic. As a result, the robot should autonomously move in a circle in Gazebo and rviz. The tf of the robot must be published, the wheels are spinning, including tf wheels.

Save all files of your ROS package to ex03 folder.