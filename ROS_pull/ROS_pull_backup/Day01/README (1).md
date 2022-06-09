# DAY 01 - Piscine Robot Operating System
## Writing a service and action
Summary: Write nodes for advanced communication between programs inside the robot.
## Contents
<!-- TOC -->

- [DAY 01 - Piscine Robot Operating System](#day-01---piscine-robot-operating-system)
    - [Writing a service and action](#writing-a-service-and-action)
    - [Contents](#contents)
    - [Chapter I](#chapter-i)
        - [Preamble](#preamble)
    - [Chapter II](#chapter-ii)
        - [Instructions](#instructions)
    - [Chapter III](#chapter-iii)
        - [Exercise 00 : Writing a Simple Service and Client C++](#exercise-00--writing-a-simple-service-and-client-c)
    - [Chapter IV](#chapter-iv)
        - [Exercise 01 : Writing a Simple Action Server and Action Client C++](#exercise-01--writing-a-simple-action-server-and-action-client-c)
    - [Chapter V](#chapter-v)
        - [Exercise 02 : Recording and playing back data](#exercise-02--recording-and-playing-back-data)
    - [Chapter VI](#chapter-vi)
        - [Exercise 03 : Getting started with roswtf](#exercise-03--getting-started-with-roswtf)
    - [Chapter VII](#chapter-vii)
        - [Exercise 04 : Navigating the ROS wiki](#exercise-04--navigating-the-ros-wiki)

<!-- /TOC -->
## Chapter I
### Preamble
Communication methods are important both for programs in one robot and between several robots or between different computers of one robot. With ROS, it becomes easy to create a robot brain with distributed in the local network calculations, processing sensors. Finished, advanced ROS communication mechanisms will allow you to quickly develop robots. 

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
### Exercise 00 : Writing a Simple Service and Client (C++)
Directory to store your solution : ex00/

Files to be in the directory : All necessary package files

Authorized functions : The package name must be "service_full_name". Nodes should be called and run by the "service_name" and "client_name" via rosrun. The service name must be "summ_full_name".

Comments :

In this exercise, you will need to study the tutorial “Writing a Simple Service and Client (C++)” and “Examining the Simple Service and Client”. 

Read and follow this tutorials step by step:
http://wiki.ros.org/ROS/Tutorials/WritingServiceClient%28c%2B%2B%29
http://wiki.ros.org/ROS/Tutorials/ExaminingServiceClient

Write a node that will consist of two programs. “service_name” will receive three strings with the last name, first name and patronymic through the service, add them into one string and send the result back to the client. “client_name” will receive the last name, first name, patronymic through arguments and glue them into one string through the service. The service name must be summ_full_name.

In the EX00 folder, copy all the necessary files to compile and run your package.


## Chapter IV
### Exercise 01 : Writing a Simple Action Server and Action Client (C++)
Directory to store your solution : ex01/

Files to be in the directory : All necessary package files

Authorized functions : The package name is “action_turtle_commands”, the nodes should be named and run by the names “action_turtle_server” and “action_turtle_client” via rosrun. The name of the action must be execute_turtle_commands. turtle simulator. You can only send commands to the turtle in the cmd_vel topic and subscribe to the pose topic.

Comments : Tepeport cannot be used!

Reference information http://wiki.ros.org/actionlib_tutorials/Tutorials

Write a package that will consist of two programs. The “action_server” node will receive a command to move through Action and control the turtle, returning the result only after the turtle has performed the action. Actions that Action must perform: drive forward a specified distance specified in meters or turn through a specified angle specified in degrees. The "action_client" node should be designed to send a sequence of Action commands so that the turtle travels forward 2 meters, turns right 90 degrees, and travels another meter. During execution, the Action must return the current distance traveled since the start of the command.

Message structure Action:
```
message_turtle_commands.action
#goal definition
string command - “forward”,”turn_left”, “turn_right”
int s - distance in meters that the turtle must travel.
int angle - the angle, in degrees, that the turtle should turn.
---
#result definition
bool result - true - the turtle was able to execute the command, false - the turtle could not execute the command, for example, because the execution of the command was interrupted.
---
#feedback
int odom - the distance traveled by the turtle in meters since the start of the command.
```
In the ex01 folder, copy all the necessary files to compile and run your package.

## Chapter V
### Exercise 02 : Recording and playing back data
Directory to store your solution : ex02/

Files to be in the directory : turtle_cmd_vel.bag, pose_speed_x1.yaml, pose_speed_x2.yaml

Authorized functions :

Comments :

In this exercise, you will need to study the tutorials “Recording and playing back data” and “Reading messages from a bag file”.

Read and follow this tutorials step by step
http://wiki.ros.org/ROS/Tutorials/Recording%20and%20playing%20back%20data
http://wiki.ros.org/ROS/Tutorials/reading%20msgs%20from%20a%20bag%20file

After completing the tutorial:

Run turtlesim and write the speed command file from the /cmd_vel topic to the ros bag while controlling the turtle via teleop_key. The turtle should start moving from the lower left corner around the perimeter at a distance from the borders of the simulator and approximately return to the same place. Only one topic /turtle1/cmd_vel should be recorded. Bag file should be named turtle_cmd_vel.bag.

Play the ros bag turtle_cmd_vel.bag file and save the turtle movement coordinates from the /turtle1/pose topic to the pose_speed_x1.yaml file.

Play the ros bag turtle_cmd_vel.bag file at twice the playback speed and save the turtle movement coordinates from the /turtle1/pose topic to the pose_speed_x2.yaml file.

Then save the turtle_cmd_vel.bag, pose_speed_x1.yaml, pose_speed_x2.yaml files to the ex02 folder.


## Chapter VI
### Exercise 03 : Getting started with roswtf
Directory to store your solution : ex03/

Files to be in the directory : roswtf.txt

Authorized functions :

Comments :

In this exercise, you will need to study the tutorial “Getting started with roswtf”.

Read and follow this tutorial step by step http://wiki.ros.org/ROS/Tutorials/Getting%20started%20with%20roswtf

Check the status of your ROS system and save it to the roswtf.txt file.
If there are problems, then fix them.

Then save the roswtf.txt file to the ex03 folder.

## Chapter VII
### Exercise 04 : Navigating the ROS wiki
Directory to store your solution : ex04/

Files to be in the directory : All necessary package files

Authorized functions : turtleX/cmd_vel and turtleX/pose topics.
Forbidden topics: turtleX/teleport_absolute, turtleX/teleport_relative. You cannot use turtle keyboard controls.

Comments : Your package, node and cpp file must be named move_to_goal. It should be run via rosrun with three parameters indicating the coordinates of the target the turtle should travel to.

In this exercise, you will need to study the tutorial “Navigating the ROS wiki”.

Read and follow this tutorial step by step http://wiki.ros.org/ROS/Tutorials/NavigatingTheWiki

On http://wiki.ros.org/, find the turtlesim documentation page, then find the turtlesim tutorial page. Carefully read, watch and study the documentation and tutorials.

Then write a ros node that will move the turtle to the given coordinates. Target coordinates must be given via command line options to your cpp executable as x, y, theta. The turtle must be moved autonomously by your program only using velocity send to the cmd_vel topic, the turtleX/teleport_absolute and turtleX/teleport_relative commands cannot be used.

Your package, node and cpp file must be named move_to_goal. It should be run via rosrun with three parameters indicating the coordinates of the target the turtle should travel to.

In the ex04 folder, copy all the necessary files to compile and run your package.
