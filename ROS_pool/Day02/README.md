# DAY 02 - Piscine Robot Operating System
## Transform coordinate frames
Summary: The tf library  was  designed  to  provide  a  standard way  to  keep  track  of  coordinate  frames  and  transform  data within  an  entire  system  such  that  individual  component  users can  be  confident  that  the  data  is  in  the  coordinate  frame  that they  want  without  requiring  knowledge  of  all  the  coordinate frames  in  the  system.  During  early  development  of  the  RobotOperating  System  (ROS),  keeping  track  of  coordinate  frame was   identified   as   a   common   pain   point   for   developers.   The complexity   of   this   task   made   it   a   common   place   for   bugs when  developers  improperly  applied  transforms  to  data.  The problem  is  also  a  challenge  due  to  the  often  distributed  sources of  information  about  transformations  between  different  sets  of coordinate frames. This paper will explain the complexity of the problem  and  distill  the  requirements.  A few use cases  will  be  presented  to  demonstrate  successful  deployment  of﻿ the library.
## Contents
<!-- TOC -->

- [DAY 02 - Piscine Robot Operating System](#day-02---piscine-robot-operating-system)
    - [Transform coordinate frames](#transform-coordinate-frames)
    - [Contents](#contents)
    - [Chapter I](#chapter-i)
        - [Preamble](#preamble)
    - [Chapter II](#chapter-ii)
        - [Instructions](#instructions)
    - [Chapter III](#chapter-iii)
        - [Exercise 00 : Introduction to tf2](#exercise-00--introduction-to-tf2)
    - [Chapter IV](#chapter-iv)
        - [Exercise 01 : Writing a tf2 broadcaster and listener](#exercise-01--writing-a-tf2-broadcaster-and-listener)
    - [Chapter V](#chapter-v)
        - [Exercise 02 : Time travel with tf2](#exercise-02--time-travel-with-tf2)

<!-- /TOC -->
## Chapter I
### Preamble
A robotic system typically has many 3D coordinate frames that change over time, such as a world frame, base frame, gripper frame, head frame, etc. tf2 keeps track of all these frames over time, and allows you to ask questions like:
Where was the head frame relative to the world frame, 5 seconds ago?
What is the pose of the object in my gripper relative to my base?
What is the current pose of the base frame in the map frame?

tf2 can operate in a distributed system. This means all the information about the coordinate frames of a robot is available to all ROS components on any computer in the system. Tf2 can operate with a central server that contains all transform information, or you can have every component in your distributed system build its own transform information database.

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
### Exercise 00 : Introduction to tf2
Directory to store your solution : ex01/

Files to be in the directory : frames.pdf, transform.txt, last_transform.txt

Authorized functions :

Comments :

In this exercise, you will need to study the documentation tf2 and the tutorial “Introduction to tf2”.
Read and follow this tutorials step by step:
http://wiki.ros.org/tf2
http://wiki.ros.org/tf2/Tutorials/Introduction%20to%20tf2

In the first terminal run turtle_tf2_demo.launch.
In the second terminal, use the tf2_tools utility to save the tf tree to frames.pdf.

Using the tf_echo utility, save the output of the coordinate transformation between the turtle1 and turtle2 frames into a transform.txt file in a few seconds. At the same time, move the turtle using the keyboard.

Open the transform.txt file with a text editor, look at the last coordinate transformation between the turtle1 and turtle2 frames in time, and manually enter three numbers separated by commas into the last_transform.txt file: offset along the X axis, offset along the Y axis, rotation angle in degrees along the Z axis.

Then save the frames.pdf, transform.txt, last_transform.txt files to the ex00 folder.


## Chapter IV
### Exercise 01 : Writing a tf2 broadcaster and listener
Directory to store your solution : ex01/

Files to be in the directory : All package ROS files and carrot.rviz

Authorized functions :

Comments :

In this exercise, you will need to study the tutorials “Writing a tf2 broadcaster and listener”.

Read and follow this tutorial step by step http://wiki.ros.org/tf2/Tutorials/Writing%20a%20tf2%20static%20broadcaster%20%28C%2B%2B%29
http://wiki.ros.org/tf2/Tutorials/Writing%20a%20tf2%20broadcaster%20%28C%2B%2B%29
http://wiki.ros.org/tf2/Tutorials/Writing%20a%20tf2%20listener%20%28C%2B%2B%29
http://wiki.ros.org/tf2/Tutorials/Adding%20a%20frame%20%28C%2B%2B%29

Develop a ROS package that will run two turtles in turtlesim, make them TF frames, add a carrot frame to the first turtle. The carrot should rotate around the first turtle by the distance specified in the launch file parameters (call the argument “radius”) and the direction clockwise or counterclockwise (call the argument “direction_of_rotation”, it should take only two values ​​“1” - if clockwise or “-1” counterclockwise). The second turtle should follow the carrot on its own. The first turtle should be possible to control from the keyboard via teleop_key.

Create a settings file carrot.rviz so that the world, turtle1, turtle2, carrot frames are visible in rviz.

Save all files of your ROS package to ex01 folder.

## Chapter V
### Exercise 02 : Time travel with tf2
Directory to store your solution : ex02/

Files to be in the directory : 

Authorized functions :

Comments :

In this exercise, you will need to study the tutorial “Learning about tf2 and time” and “Time travel with tf2”.

Read and follow this tutorial step by step http://wiki.ros.org/tf2/Tutorials/tf2%20and%20time%20%28C%2B%2B%29
http://wiki.ros.org/tf2/Tutorials/Time%20travel%20with%20tf2%20%28C%2B%2B%29

Write a ROS package that will run two turtles in the simulator. Make the second turtle follow where the first turtle was some time ago. Make it possible to set a time delay in the launch file arguments (call the argument “delay” with the measure in seconds).

Save all files of your ROS package to ex02 folder.
