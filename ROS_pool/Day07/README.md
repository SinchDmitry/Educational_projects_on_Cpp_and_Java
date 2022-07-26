# DAY 07 - Piscine Robot Operating System
## Simulating a manipulator in Gazebo with MoveIt
Summary: MoveIt! is an integrated library for manipulators that provides a variety of functions including fast inverse kinematics analysis for motion planning, advanced algorithms for manipulation, robot hand control, dynamics, controllers, and motion planning. It is also easy to use without advanced knowledge of the manipulator because the GUI is offered to assist with various settings needed to use MoveIt!. This is a tool that many ROS users love because it allows visual feedback using RViz. Let’s briefly review the structure of MoveIt!, and then create a MoveIt! package to control the OpenManipulator chain.
## Contents
<!-- TOC -->

- [DAY 07 - Piscine Robot Operating System](#day-07---piscine-robot-operating-system)
    - [Simulating a manipulator in Gazebo with MoveIt](#simulating-a-manipulator-in-gazebo-with-moveit)
    - [Contents](#contents)
    - [Chapter I](#chapter-i)
        - [Preamble](#preamble)
    - [Chapter II](#chapter-ii)
        - [Instructions](#instructions)
    - [Chapter III](#chapter-iii)
        - [Exercise 00 : URDF manipulator model](#exercise-00--urdf-manipulator-model)
    - [Chapter IV](#chapter-iv)
    - [Exercise 01 : Let's MoveIt!](#exercise-01--lets-moveit)
    - [Chapter V](#chapter-v)
        - [Exercise 02 : Simulating a manipulator in Gazebo with MoveIt](#exercise-02--simulating-a-manipulator-in-gazebo-with-moveit)

<!-- /TOC -->
## Chapter I
### Preamble
Manipulator is the most popular type of robot that people use during manufacturing. It helps to make it faster and accurately than usual. Today we will try to model it with ROS package MoveIt! Please, read some information about manipulator's kinematics, joints and direct kinematics problem.

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
### Exercise 00 : URDF manipulator model
Directory to store your solution : ex00/

Files to be in the directory : all ROS files of the package to launch the manipulator in RVIZ.

Authorized functions : 

Comments :

Create a URDF file named manipulator.urdf that will describe the model of a manipulator consisting of four links, three rotational joints and a fixed base.
The generated file should be successfully built using the check_urdf manipulator.urdf command
Successful output example:
```
robot name is: manipulator
---------- Successfully Parsed XML ---------------
root Link: base has 1 child(ren)
child(1): link1
child(1): link2
child(1): link3
child(1): link4
```
In addition, the urdf_to_graphiz manipulator.urdf command should display the following image on the screen:

![manipulator.urdf](misc/images/manipulator_urdf.png)

Wrap it in a ROS package called testbot_description. Make a launch file called testbot.launch that will launch the manipulator you made in RVIZ so that you can control it through the Joint State Publisher GUI.
Your ROS package must be run with the following command:
```
$ roslaunch testbot_description testbot.launch
```
The result of the output of the command should be the launch of the already configured RVIZ as in the image below:

![rviz testbot_description](misc/images/rviz_testbot_description.png)

Reference material for this and subsequent tasks ROS Robot Programming (English, Free PDF) chapter 13 http://www.robotis.com/service/download.php?no=719

In the ex0 folder, copy all the files of your ROS package.

## Chapter IV
## Exercise 01 : Let's MoveIt!
Directory to store your solution : ex01/

Files to be in the directory : all configuration files

Authorized functions : 

Comments : 

It is necessary to configure the manipulator from the open library in the MoveIt! : https://github.com/ROBOTIS-GIT/open_manipulator 
- The manipulator must have two functional groups: gripper and manipulator links (section “Planning groups” in MoveIt!)

![planning_groups](misc/images/planning_groups.png)

- The manipulator must have three positions: open the gripper, raise the manipulator, close the gripper (the degree of opening/closing of the gripper is arbitrary, section “Robot Poses”)
- The End Effector section must be filled with the gripper function group.

Comments : Before starting the task, we recommend that you familiarize yourself with the setup example in 

MoveIt!: http://docs.ros.org/en/melodic/api/moveit_tutorials/html/doc/setup_assistant/setup_assistant_tutorial.html

In the ex1 folder, copy all the configuration files.

## Chapter V
### Exercise 02 : Simulating a manipulator in Gazebo with MoveIt
Directory to store your solution : ex02/

Files to be in the directory: Your ROS package and video recording of lifting the object

Authorized functions :

Comments :

You need to simulate the movement of the manipulator (https://github.com/ROBOTIS-GIT/open_manipulator) in the Gazebo environment using MoveIt. On the Gazebo scene, in addition to the manipulator, you need to add some object that can be picked up by the manipulator.

You need to record a video with Gazebo on the left and RVIZ with MoveIt on the right. The video should capture the following sequence of actions performed through MoveIt:
1) Open the gripper of the manipulator
2) Grab an object with a grip
3) Pick up an item using the manipulator

In the ex2 folder, copy all the files of your ROS metapackage and the video from the screen where you pick up the item with the manipulator.