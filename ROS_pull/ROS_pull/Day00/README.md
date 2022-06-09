# DAY 00 - Piscine Robot Operating System
## Writing a Simple Publisher and Subscriber
Summary: On the first day, you will install and configure ROS. Explore terms and some command line utilities. Write nodes for simple communication between programs inside the robot.
## Contents
<!-- TOC -->

- [DAY 00 - Piscine Robot Operating System](#day-00---piscine-robot-operating-system)
    - [Writing a Simple Publisher and Subscriber](#writing-a-simple-publisher-and-subscriber)
    - [Contents](#contents)
    - [Chapter I](#chapter-i)
        - [Preamble](#preamble)
    - [Chapter II](#chapter-ii)
        - [Instructions](#instructions)
    - [Chapter III](#chapter-iii)
        - [Exercise 00 : Install ROS](#exercise-00--install-ros)
    - [Chapter IV](#chapter-iv)
    - [Exercise 01 : Installing and configuring your ROS environment](#exercise-01--installing-and-configuring-your-ros-environment)
    - [Chapter V](#chapter-v)
        - [Exercise 02 : Navigating the ROS Filesystem](#exercise-02--navigating-the-ros-filesystem)
    - [Chapter VI](#chapter-vi)
        - [Exercise 03 : Creating a ROS Package](#exercise-03--creating-a-ros-package)
    - [Chapter VII](#chapter-vii)
        - [Exercise 04 : Building a ROS Package](#exercise-04--building-a-ros-package)
    - [Chapter VIII](#chapter-viii)
        - [Exercise 05 : Understanding ROS Nodes](#exercise-05--understanding-ros-nodes)
    - [Chapter IIX](#chapter-iix)
        - [Exercise 06 : Understanding ROS Topics](#exercise-06--understanding-ros-topics)
    - [Chapter IX](#chapter-ix)
        - [Exercise 07 : Understanding ROS Services and Parameters](#exercise-07--understanding-ros-services-and-parameters)
    - [Chapter X](#chapter-x)
        - [Exercise 08 : Using rqt_console and roslaunch](#exercise-08--using-rqt_console-and-roslaunch)
    - [Chapter XI](#chapter-xi)
        - [Exercise 09 : Creating a ROS msg and srv](#exercise-09--creating-a-ros-msg-and-srv)
    - [Chapter XII](#chapter-xii)
        - [Exercise 10 : Writing and examining a Simple Publisher and Subscriber](#exercise-10--writing-and-examining-a-simple-publisher-and-subscriber)

<!-- /TOC -->
## Chapter I
### Preamble
Robotics used to write all the source code from beginning to end in every new project. By the end of the project, they were tired and lost interest, so they spent most of their time writing bikes instead of focusing on their research. Therefore, modern robotics decided to write reference communication libraries so that they could be reused in every robot. 

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
### Exercise 00 : Install ROS
Directory to store your solution : ex01/

Files to be in the directory : screenshot.png

Authorized functions :

Comments :

In this exercise, you will need to install ROS Melodic. Before that, you must have Ubuntu 18.04 installed on your computer.

Read and follow this tutorial step by step http://wiki.ros.org/melodic/Installation/Ubuntu

To check that you have correctly installed ROS, launch the turtle simulator and control it from the keyboard.

Open three separate terminals.

First enter the command:

```console 
$ roscore
```

In the second, enter the command:
```console
$ rosrun turtlesim turtlesim_node
```

In the third, enter the command:
```console
$ rosrun turtlesim turtle_teleop_key
```

You should see this:

![turtlesim](misc/images/turtlesim.png)

Draw the first letter of your login by moving the turtle.Take a screenshot of the simulator window with the turtle path depicting the first letter of your login and save it to the ex00 folder.

## Chapter IV
## Exercise 01 : Installing and configuring your ROS environment
Directory to store your solution : ex01/

Files to be in the directory : ex01.txt, .bashrc

Authorized functions :

Comments :

In this exercise, you will need to Install and configure your ROS environment

Read and follow this tutorial step by step http://wiki.ros.org/ROS/Tutorials/InstallingandConfiguringROSEnvironment

The .bashrc file must contain the following lines of text at the end of the file:
```bash
# Set ROS Melodic
source /opt/ros/melodic/setup.bash
source ~/catkin_ws/devel/setup.bash
# Set ROS Network
export ROS_HOSTNAME=localhost
export ROS_MASTER_URI=http://${ROS_HOSTNAME}:11311
```
After that you need to execute the command:
```console
$ source .bashrc
``` 

Or open a new terminal window.

After setting the environment variable, execute the command:
```console
printenv | grep ROS > ex01.txt 
```

Then save the ex01.txt and ~/.bashrc files to the ex01 folder.

## Chapter V
### Exercise 02 : Navigating the ROS Filesystem
Directory to store your solution : ex02/

Files to be in the directory : package_path_rostopic.txt, list_files_rospy_tutorials.txt

Authorized functions :

Comments :

In this exercise, you will need to study the tutorial “Navigating the ROS Filesystem”.

Read and follow this tutorial step by step http://wiki.ros.org/ROS/Tutorials/NavigatingTheFilesystem

After completing the tutorial, create the following files:

package_path_rostopic.txt  - must contain the path to the “rostopic” package.

list_files_rospy_tutorials.txt - should contain a list of files in the “rospy_tutorials” package directory.

Then save the package_path_rostopic.txt and list_files_rospy_tutorials.txt files to the ex02 folder.

## Chapter VI
### Exercise 03 : Creating a ROS Package
Directory to store your solution : ex03/

Files to be in the directory : the ROS package you created

Authorized functions :

Comments :

In this exercise, you will need to study the tutorial “Creating a ROS Package”.

Read and follow this tutorial step by step http://wiki.ros.org/ROS/Tutorials/CreatingPackage

Create a ROS package that will contain only your last name in the name and depend on the std_msgs, rospy, roscpp, rostime packages.

Change the info maintainer email to your email in the package.xml file.

Save the package you created to the ex03 folder.

## Chapter VII
### Exercise 04 : Building a ROS Package

Directory to store your solution : ex04/

Files to be in the directory : catkin_make.txt

Authorized functions :

Comments :

In this exercise, you will need to study the tutorial “Building a ROS Package”.

Read and follow this tutorial step by step http://wiki.ros.org/ROS/Tutorials/BuildingPackages

Write the output of your package's catkin_make build from the previous exercise to catkin_make.txt.

Save the catkin_make.txt to the ex04 folder.

## Chapter VIII
### Exercise 05 : Understanding ROS Nodes
Directory to store your solution : ex05/

Files to be in the directory : rosnode_list.txt, rosnode_ping.txt

Authorized functions :

Comments :

In this exercise, you will need to study the tutorial “Understanding ROS Nodes”.

Read and follow this tutorial step by step http://wiki.ros.org/ROS/Tutorials/UnderstandingNodes

Run the turtlesim node by changing its name via Remapping Argument to [your_login]_turtle.

Save the output of the command rosnode list to the file rosnode_list.txt . 

Save the output of the command rosnode ping of your node's for 5 seconds to the file rosnode_ping.txt . 

Save the rosnode_list.txt and rosnode_ping.txt to the ex05 folder.

## Chapter IIX
### Exercise 06 : Understanding ROS Topics
Directory to store your solution : ex06/

Files to be in the directory : cmd_vel.txt, eight.png

Authorized functions :

Comments :

In this exercise, you will need to study the tutorial “Understanding ROS Topics”.

Read and follow this tutorial step by step http://wiki.ros.org/ROS/Tutorials/UnderstandingTopics

Run Turtlesim. Run "rostopic echo /turtle1/cmd_vel > cmd_vel.txt". Using only the "rostopic pub" command sequence, draw the number eight. Save the screenshot of the result turtlesim to file eight.png.

Save the cmd_vel.txt and eight.png to the ex06 folder.

## Chapter IX
### Exercise 07 : Understanding ROS Services and Parameters
Directory to store your solution : ex07

Files to be in the directory : screenshot.png, rosservice_list.txt, parameter_server.txt

Authorized functions :

Comments :

In this exercise, you will need to study the tutorial “Understanding ROS Services and Parameters”.

Read and follow this tutorial step by step http://wiki.ros.org/ROS/Tutorials/UnderstandingServicesParams

Launch the turtlesim and add four turtles with the names Leonardo, Raphael, Donatello, Michelangelo.

Set the parameter /turtlesim/background_g to 124.

Save a screenshot of the simulator window as a screenshot.png file.

Save the output of the rosservice list command to the rosservice_list.txt file.

Save the output of the entire Parameter Server to the parameter_server.txt file.
 
Save the screenshot.png, rosservice_list.txt, parameter_server.txt to the ex07 folder.

## Chapter X
### Exercise 08 : Using rqt_console and roslaunch
Directory to store your solution : ex08

Files to be in the directory : rqt_console.txt, three_turtles.launch

Authorized functions :

Comments :

In this exercise, you will need to study the tutorial “Using rqt_console and roslaunch”.

Read and follow this tutorial step by step http://wiki.ros.org/ROS/Tutorials/UsingRqtconsoleRoslaunch

Create a launch file so that three turtle simulators can be launched simultaneously and the second turtle follows the first and third turtle after the second.
Save the resulting launch file as three_turtles.launch.

Run rqt_console and rqt_logger_level. Set the log level to Warn.
Run your three turtles afterwards.
Control the first turtle for a while from the keyboard, collide with a wall at least once. Then save the output of rqt_console to rqt_console.txt using the Save button in the interface.
 
Save the rqt_console.txt, three_turtles.launch to the ex08 folder.

## Chapter XI
### Exercise 09 : Creating a ROS msg and srv
Directory to store your solution : ex09

Files to be in the directory : All necessary files to compile and run your message description package.

Authorized functions :

Comments :

In this exercise, you will need to study the tutorial “Using rosed to edit files in ROS” and “Creating a ROS msg and srv”.

Read and follow this tutorials step by step

http://wiki.ros.org/ROS/Tutorials/UsingRosEd

http://wiki.ros.org/ROS/Tutorials/CreatingMsgAndSrv

Create a package containing the description of a new message type "full_name_message" consisting of three lines: "last_name", "name", "first_name".

Add to the package a description of a service with the name "full_name_sum_service" receiving three lines: "last_name", "name", "first_name" and returning the line "full_name".

Copy all the necessary files to compile and start your package into the ex9 folder.

## Chapter XII
### Exercise 10 : Writing and examining a Simple Publisher and Subscriber 
Directory to store your solution : ex10

Files to be in the directory : All files required to compile and run your "text_to_cmd_vel" node.

Authorized functions :

Comments :

In this exercise, you will need to study the tutorial “Writing a Simple Publisher and Subscriber” and “Examining the Simple Publisher and Subscriber”.

Read and follow this tutorials step by step
http://wiki.ros.org/ROS/Tutorials/WritingPublisherSubscriber%28c%2B%2B%29
http://wiki.ros.org/ROS/Tutorials/ExaminingPublisherSubscriber

Write a node in C++ with the name "text_to_cmd_vel" which will be subscribed to the "cmd_text" topic where you can send text commands: "turn_right", "turn_left", "move_forward", "move_backward". The node must translate them into speed commands of the message type geometry_msgs/Twist, e.g. 1 metre per second or 1.5 radians per second and publish them in the topic /turtle1/cmd_vel so that the turtle in the turtlesim moves according to the commands.

Copy all the necessary files to compile and start your node "text_to_cmd_vel" into the folder ex10.