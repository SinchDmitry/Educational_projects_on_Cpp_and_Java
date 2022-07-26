# RUSH 00 - Piscine Robot Operating System
## Competition to find a way out of the maze
Summary: This rush will help you to strengthen the skills acquired in the previous days.
## Contents
<!-- TOC -->

- [RUSH 00 - Piscine Robot Operating System](#rush-00---piscine-robot-operating-system)
    - [Competition to find a way out of the maze](#competition-to-find-a-way-out-of-the-maze)
    - [Contents](#contents)
    - [Chapter I](#chapter-i)
        - [Preamble](#preamble)
    - [Chapter II](#chapter-ii)
        - [Instructions](#instructions)
    - [Chapter III](#chapter-iii)
        - [Specific instructions of the day](#specific-instructions-of-the-day)
    - [Chapter IV](#chapter-iv)
        - [Mandatory part](#mandatory-part)
        - [ROS Package](#ros-package)
        - [Report](#report)
    - [Chapter V](#chapter-v)
        - [Turn-in and peer-evaluation](#turn-in-and-peer-evaluation)

<!-- /TOC -->
## Chapter I
### Preamble
A good way to test your knowledge are competitions in which you solve a fairly complex and interesting problem. In this rush, you are offered the task of getting out of an arbitrary maze. This task is interesting in that it will allow you to program an autonomous robot that can be applied not only in the simulator but also in real life. You will also be able to fully apply all the knowledge gained earlier, but you will also have to google and think with your head to solve the problem. To make it more interesting for you, you will participate in a competition with your peers, nothing motivates you more than to take first place and not lose the race to your neighbor.

An important skill of a good programmer is the ability to explain in understandable language the work you have done and the work of the program, so you need to make a good presentation on the result of the work. 

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
### Specific instructions of the day
You can use any C++ libraries in your ROS package. It is forbidden to use such ROS packages as move_base, SLAM and others from the ROS navigation stack.

## Chapter IV
### Mandatory part

In this rush, your goal is to develop a gazebo robot model and program it to autonomously get out of the maze. The checking person will launch the robot on a maze unknown to you.

First you have to develop the xacro and gazebo robot model yourself, it cannot be a robot model copied from the Internet. Restrictions on dimensions and characteristics are introduced on the robot model so that all participants are on an equal footing. You must develop a ROS Node for your robot that will contain the source code of the program you have developed for autonomous control of the robot and finding a way out of the maze. You can independently select and install a set of sensors on the robot from the allowed list.

You are provided with a test maze in Gazebo for testing, similar to the one that will be in the final test. You can also create your own mazes to test the algorithm.

The exit from the maze is indicated by a green cube opposite the exit. The robot is considered to have completed the task if it left the maze with its entire body, stopped in front of the green cube, and then sent a message to the robot_finish topic. If, after the command to the robot_finish topic, the robot continues to move or is not located with its entire body outside the maze, then the task is not counted.
The robot should start moving only after a message was sent to the robot_start topic. If the robot started moving before the command, then the task is not counted.

When checking, no more than 10 minutes are given to complete the task, if the robot does not have time to complete the task during this time, then the check ends.

The task is performed by the robot for a while. The time of all teams is recorded in the table. The team that completes the task in less time from the table leaves the pool.

Checking the execution of the task takes place on the computer of the verifier by downloading from github and compiling via catkin make, if you need to install additional packages, this should be reflected in the instructions in readme.md. If the package compiles with errors, the job is considered failed.

You can download the basic maze example here https://github.com/amburkoff/maze_challenge

You must develop a separate ROS package containing all the necessary files for your robot, the package name must contain your last name and first name. Then copy the maze_2_world.launch file from maze_challenge to your ROS package and replace the paths and names in the file with your own. You can check the operation of your algorithm by running this launch file.

The dimensions of the robot should not exceed the limits of a cylinder with a diameter of 210 centimeters and a height of 250 centimeters. The shape of the robot can be any. It is allowed to use sensors: libgazebo_ros_camera.so, libgazebo_ros_laser.so, libgazebo_ros_openni_kinect.so, realsense, libgazebo_ros_diff_drive.so, libgazebo_ros_bumper.so.

### ROS Package

Remember that the goal of the rush is to strengthen your skills. Try to use as much as you can from what you have learned from the previous days.

### Report

After completing the task, write a detailed presentation explaining the essence of the algorithm of your solution and its uniqueness. If necessary, provide a block diagram.

Your source code of the ROS package should contain detailed comprehensive comments on the work of your algorithm for exiting the maze, this will be taken into account when evaluating.

## Chapter V
### Turn-in and peer-evaluation

Turn in your work using your git repository, as usual. Only the work that’s in your repository will be graded during the evaluation.

During the correction, you will be evaluated on your turn-in (no functions that do all the heavy lifting for you) as well as your ability to present, explain, and justify your choices.

