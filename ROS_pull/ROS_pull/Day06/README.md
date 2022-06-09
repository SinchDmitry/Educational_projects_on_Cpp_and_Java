# DAY 06 - Piscine Robot Operating System
## Robot navigation using move_base
Summary: Move_base is a ROS metapackage that allows you to add your robot to plan a path around the map and follow that path while avoiding dynamic obstacles.
## Contents
<!-- TOC -->

- [DAY 06 - Piscine Robot Operating System](#day-06---piscine-robot-operating-system)
    - [Robot navigation using move_base](#robot-navigation-using-move_base)
    - [Contents](#contents)
    - [Chapter I](#chapter-i)
        - [Preamble](#preamble)
    - [Chapter II](#chapter-ii)
        - [Instructions](#instructions)
    - [Chapter III](#chapter-iii)
        - [Exercise 00 : Learning Navigation in turtlebot3 simulation](#exercise-00--learning-navigation-in-turtlebot3-simulation)
    - [Chapter IV](#chapter-iv)
    - [Exercise 01 : Applying the Navigation ROS stack to your robot](#exercise-01--applying-the-navigation-ros-stack-to-your-robot)
    - [Chapter V](#chapter-v)
        - [Exercise 02 : Applying both SLAM and ROS of the Navigation stack to your robot](#exercise-02--applying-both-slam-and-ros-of-the-navigation-stack-to-your-robot)
    - [Chapter VI](#chapter-vi)
        - [Exercise 03 : Get out of the maze and return to the starting point on your robot using move_base](#exercise-03--get-out-of-the-maze-and-return-to-the-starting-point-on-your-robot-using-move_base)

<!-- /TOC -->
## Chapter I
### Preamble
Now that you've learned how to build a map and locate the robot's position on that map, the next step is to build a global robot route and send the robot along that route. This problem is already quite old, and many algorithms have been invented by other roboticists. In order not to write bicycles, the ROS community has collected all these developments and made a large Navigation ROS metapackage, which contains the move_base node and plugins for it. In this ROS package and plugins implemented: global path planners, local path planners, Costmap2D - patency map, etc. These nodes are actively developed by the ROS community and you can use them for your robots.

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
### Exercise 00 : Learning Navigation in turtlebot3 simulation
Directory to store your solution : ex00/

Files to be in the directory : map_turtlebot3_world.pgm and map_turtlebot3_world.yaml, 2D_Nav_Goal.bag.

Authorized functions : 

Comments :

Reference material https://emanual.robotis.com/docs/en/platform/turtlebot3/navigation/
ROS Robot Programming (English, Free PDF) http://www.robotis.com/service/download.php?no=719 chapter 11.
Run a simulation of turtlebot3 in turtlebot3_world in Gazebo and use the robot keyboard controls to build a map. Save the map as map_turtlebot3_world.

After that, run the turtlebot3 simulation in turtlebot3_world in Gazebo with the map previously saved in AMCL mode and move_base running. Test navigation by sending targets through the RVIZ 2D Nav Goal tool.

Examine the settings of the local DWA planner and Costmap2D layers. Experiment with changing the settings while the robot is following its destination with http://wiki.ros.org/rqt_reconfigure .

Write the ROSbag file for about 10-20 seconds while sending the 2D Nav Goal and following the route. The file name should be 2D_Nav_Goal.bag.

Copy the map_turtlebot3_world.pgm, map_turtlebot3_world.yaml and 2D_Nav_Goal.bag files to the ex00 folder.

## Chapter IV
## Exercise 01 : Applying the Navigation ROS stack to your robot
Directory to store your solution : ex01/

Files to be in the directory : ROS metapackage of your robot with everything you need to run, map_my_robot.pgm, map_my_robot.yaml and 2D_Nav_Goal.bag.

Authorized functions : 

Comments : 

Grab your robot's ROS metapackage from the previous pool day. Add to it everything you need to run move_base for Navigation on your robot.

Run a simulation of your robot in the turtlebot3_house Gazebo scene and use the robot's keyboard controls to build a map. Save the map as map_my_robot_house.

After that, run your robot simulation in the Gazebo scene turtlebot3_house with the previously saved map in AMCL mode and running move_base. Test navigation by sending targets through the RVIZ 2D Nav Goal tool.

Experiment with changing the DWA and Costmap2D layers settings while the robot is following its destination with rqt_reconfigure.

Create and test in your ROS package my_robot_navigation_AMCL_in_house.launch file which will launch gazebo, RVIZ, your robot, AMCL and move_base at the same time.

Launch my_robot_navigation_AMCL_in_house.launch. After that, write the ROSbag file for about 10-20 seconds while sending the 2D Nav Goal and following the route by the robot. The file name should be 2D_Nav_Goal.bag.

In the ex01 folder, copy the files map_my_robot.pgm, map_my_robot.yaml and 2D_Nav_Goal.bag, as well as the ROS metapackage of your robot with all the necessary files to run.

## Chapter V
### Exercise 02 : Applying both SLAM and ROS of the Navigation stack to your robot
Directory to store your solution : ex02/

Files to be in the directory: ROS metapackage of your robot with everything you need to run, map_my_robot_house.pgm, map_my_robot_house.yaml.

Authorized functions :

Comments :

Take your robot's ROS metapackage from the previous task. Add everything you need to it to run SLAM and move_base for Navigation on your robot at the same time.

Run your robot simulation in the turtlebot3_house Gazebo scene in SLAM mode with move_base running. Test navigation by sending targets through the RVIZ 2D Nav Goal tool. Simultaneously with the movement of the robot, a map must be built.

Create and test in your ROS package my_robot_navigation_SLAM_in_house.launch file which will launch gazebo, RVIZ, your robot, SLAM and move_base at the same time.

Launch my_robot_navigation_SLAM_in_house.launch. After that, write the ROSbag file for about 10-20 seconds while sending the 2D Nav Goal and following the route by the robot. The file name should be 2D_Nav_Goal.bag.

In the ex02 folder, copy the files map_my_robot.pgm, map_my_robot.yaml and 2D_Nav_Goal.bag, as well as the ROS metapackage of your robot with all the necessary files to run.


## Chapter VI
### Exercise 03 : Get out of the maze and return to the starting point on your robot using move_base
Directory to store your solution : ex03/

Files to be in the directory : Your entire ROS metapackage with instructions in readme.md to run.

Authorized functions : topic /map and /tf published by SLAM, data from all sensors of your robot, move_base. 

Comments : Unlike the previous day, you can use move_base and path planning plugins from Navigation stack ROS.

You can reuse your robot's ROS packs that you made for completing RUSH and the previous task.

You need to develop an additional ROS package to your robot's metapackage that will control the robot autonomously. When starting your package, the robot must perform the following tasks: 1. Get out of the maze and stop at the exit like in RUSH and send a command to the topic about completing the first task; 2. After completing task 1, return to the starting point with an error of no more than 10 centimeters and 60 degrees in angle; 3. The robot must completely stop at the starting point and only after that send a command to the topic that it has successfully completed the task.

During execution, in addition to the data from the sensors of the robot, you can use the topic / map and / tf to which SLAM publishes. Unlike the previous day, you can use move_base and path planning plugins from Navigation stack ROS.

The robot should start moving only after a message was sent to the robot_start topic. If the robot started moving before the command, then the task is not counted.

The exit from the maze is indicated by a green cube opposite the exit. The robot is considered to have completed task 1 if it left the maze with its entire body, stopped in front of the green cube, and then sent a message to the robot_finish_maze_out topic. If, after the command to the topic, robot_finish_maze_out is not located by the entire body outside the maze, then the task is not counted.

After completing tasks 2 and 3, the robot must send a message to the robot_finish_maze_in topic. If after this command the robot continues to move, then the task is not counted.

The task execution time is calculated by the time of arrival of robot_finish_maze_out - robot_start messages.



The verifier will run your ROS metapackage on a maze unknown to you.

You can download the basic maze example here https://github.com/amburkoff/maze_challenge

In the ex03 folder, copy all the files of your ROS metapackage with instructions for launching in readme.md.
