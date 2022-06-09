# DAY 05 - Piscine Robot Operating System
## Simultaneous localization and mapping
Summary: Use the robot to build a map of the area, and then you will localize the robot on this map.
## Contents
<!-- TOC -->

- [DAY 05 - Piscine Robot Operating System](#day-05---piscine-robot-operating-system)
    - [Simultaneous localization and mapping](#simultaneous-localization-and-mapping)
    - [Contents](#contents)
    - [Chapter I](#chapter-i)
        - [Preamble](#preamble)
    - [Chapter II](#chapter-ii)
        - [Instructions](#instructions)
    - [Chapter III](#chapter-iii)
        - [Exercise 00 : Learning SLAM Gmapping in turtlebot3 simulation](#exercise-00--learning-slam-gmapping-in-turtlebot3-simulation)
    - [Chapter IV](#chapter-iv)
    - [Exercise 01 : Exploring AMCL localization in turtlebot3 simulation](#exercise-01--exploring-amcl-localization-in-turtlebot3-simulation)
    - [Chapter V](#chapter-v)
        - [Exercise 02 : Localization of your robot](#exercise-02--localization-of-your-robot)
    - [Chapter VI](#chapter-vi)
        - [Exercise 03 : Get out of the maze and return to the starting point on your robot](#exercise-03--get-out-of-the-maze-and-return-to-the-starting-point-on-your-robot)

<!-- /TOC -->
## Chapter I
### Preamble
In robotics and unmanned vehicles, to complete the task of moving the robot to a given point in space, you must have a map of the area on which you determine the current location of the robot and its destination. Also, in the process of moving the robot, you need to constantly track the location of the robot on this map. Therefore, the tasks of building a map and localizing a robot are of great importance in robotics. In this day, you will study and test these two concepts.

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
### Exercise 00 : Learning SLAM Gmapping in turtlebot3 simulation
Directory to store your solution : ex00/

Files to be in the directory : map_turtlebot3_house.pgm and map_turtlebot3_house.yaml

Authorized functions : 

Comments :

You need to install the Turtlebot3 packages related to the simulation in Gazebo, for this, check out the following tutorials:
https://emanual.robotis.com/docs/en/platform/turtlebot3/quick-start/
https://emanual.robotis.com/docs/en/platform/turtlebot3/slam/
https://emanual.robotis.com/docs/en/platform/turtlebot3/simulation/
ROS Robot Programming (English, Free PDF)	http://www.robotis.com/service/download.php?no=719 chapters 10.8, 10.9, 11.

Run the turtlebot3 simulation in turtlebot3_house and use the keyboard controls to build the map. Save the map as map_turtlebot3_house.

Copy the map_turtlebot3_house.pgm and map_turtlebot3_house.yaml files to the ex00 folder.


## Chapter IV
## Exercise 01 : Exploring AMCL localization in turtlebot3 simulation
Directory to store your solution : ex01/

Files to be in the directory : All required package files

Authorized functions : 

Comments : 

Reference Information:
https://emanual.robotis.com/docs/en/platform/turtlebot3/navigation
ROS Robot Programming (English, Free PDF)	http://www.robotis.com/service/download.php?no=719 chapters 10.8, 10.9, 11.
Run the turtlebot3 simulation in turtlebot3_house and the robot in AMCL localization mode. Use the keyboard controls to transport the robot to an empty room with no furniture. After that, take a screenshot with the name screenshot_turtlebot3_localization.png of the robot in RVIZ where you can see its localization on the map.

Copy the screenshot_turtlebot3_localization.png file to the ex01 folder.

## Chapter V
### Exercise 02 : Localization of your robot
Directory to store your solution : ex02/

Files to be in the directory: ROS metapackage of your robot with everything you need to run,  map_my_robot_house.pgm, map_my_robot_house.yaml, screenshot_my_robot_localization.png.

Authorized functions :

Comments :

Take your robot from the previous day. Add everything you need to run SLAM and AMCL on it.

Run a simulation of your robot in turtlebot3_house and use the robot's keyboard controls to build a map. Save the map as map_my_robot_house.

Run your robot simulation in turtlebot3_house and the robot in AMCL localization mode. Use the keyboard controls to transport the robot to an empty room with no furniture. After that, take a screenshot with the name screenshot_my_robot_localization.png of the robot in RVIZ where you can see its localization on the map.

Copy the map_my_robot_house.pgm and map_my_robot_house.yaml and screenshot_my_robot_localization.png files to the ex02 folder. Also copy all your packages there to run the robot in a gazebo.

## Chapter VI
### Exercise 03 : Get out of the maze and return to the starting point on your robot
Directory to store your solution : ex03/

Files to be in the directory : Your entire ROS metapackage with instructions in readme.md to run.

Authorized functions : topic /map and /tf published by SLAM, data from all your robot's sensors. 

Comments : You are prohibited from using move_base and scheduler plugins from the Navigation stack ROS, if their use is detected, then the task is not counted.

You can reuse your robot's ROS packs that you made for completing RUSH and the previous task.

You need to develop an additional ROS package to your robot's metapackage that will control the robot autonomously. When starting your package, the robot must perform the following tasks: 1. Get out of the maze and stop at the exit like in RUSH and send a command to the topic about completing the first task; 2. After completing task 1, return to the starting point with an error of no more than 10 centimeters and 60 degrees in angle; 3. The robot must completely stop at the starting point and only after that send a command to the topic that it has successfully completed the task.

During execution, in addition to the data from the sensors of the robot, you can use the topic /map and /tf to which SLAM publishes. You are prohibited from using move_base and scheduler plugins from the Navigation stack ROS, if their use is detected, then the task is not counted.

The robot should start moving only after a message was sent to the robot_start topic. If the robot started moving before the command, then the task is not counted.

The exit from the maze is indicated by a green cube opposite the exit. The robot is considered to have completed task 1 if it left the maze with its entire body, stopped in front of the green cube, and then sent a message to the robot_finish_maze_out topic. If, after the command to the topic, robot_finish_maze_out is not located by the entire body outside the maze, then the task is not counted.

After completing tasks 2 and 3, the robot must send a message to the robot_finish_maze_in topic. If after this command the robot continues to move, then the task is not counted.

The task execution time is calculated by the time of arrival of robot_finish_maze_out - robot_start messages.

The verifier will run your ROS metapackage on a maze unknown to you.

You can download the basic maze example here https://github.com/amburkoff/maze_challenge

In the ex03 folder, copy all the files of your ROS metapackage with instructions for launching in readme.md.