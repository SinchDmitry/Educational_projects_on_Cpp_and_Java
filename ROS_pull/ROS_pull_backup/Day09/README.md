# Day 09 - Piscine Robot Operating System
## Behavior
Summary: This day will help you acquire skills with creating robot’s behavior into ROS.

## Contents
   1. [Chapter I](#chapter-i)  \
      1.1. [Preamble](#preamble)
   2. [Chapter II](#chapter-ii) \
      2.1. [Instructions](#instructions)
   3. [Chapter III](#chapter-iii) \
      3.1. [Specific instructions of the day](#specific-instructions-of-the-day)
   4. [Chapter IV](#chapter-iv) \
      4.1. [Exercise 00 : Hello Trees](#exercise-00--hello-trees)
   5. [Chapter V](#chapter-v) \
      5.1. [Exercise 01 : Patrol robot](#exercise-01--patrol-robot)
   6. [Chapter VI](#chapter-vi) \
      6.1. [Exercise 02 : The REAL Patrol robot in Gazebo](#exercise-02--the-real-patrol-robot-in-gazebo)

## Chapter I
### Preamble
The first robots did not have complex behavior, but as the tasks they performed became more complex, so did the methods for specifying behavior.

Just imagine how difficult your code becomes when you need to describe 20+ options of a robot's behavior with only “if else” blocks. Have you imagined? Seems terrible, doesn't it? This is the reason why Finite State Machine (FSM) or Behavior Tree (BT) became popular for describing a robot's behavior (the same as describing AI behavior in video games).

There are a couple of advantages and disadvantages in both methods. Using FSM is easier to think over the architecture of behavior but it becomes more and more difficult to display graphically and to understand the full picture as it grows up. The BT, on the other hand, is great for visual presentation even extremely complex algorithms but it is hard to create a robot's behavior architecture. 

There are a lot of debates about whether to use behavior trees or finite state machines. But today we will learn how to create robot’s behavior using BT.


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
* Read the examples carefully. They could very well call for details that are not explicitly mentioned in the subject…

And may the Force be with you!


## Chapter III
### Specific instructions of the day
* Use [BehaviorTree.CPP] for creating behavior
* Use [Groot] for BT visualizing
* Here and below we will denote *ROS Node* as **ROS Node** and *BehaviorTree.CPP Node* as **BT Node**.

## Chapter IV
### Exercise 00 : Hello Trees

Directory to store your solution : ex00

Files to be in the directory : All the necessary files to run your ROS package

Authorized functions : All the necessary functions from BehaviorTree.CPP and ROS to write your node(s)

Comments :

* Read [“Learn the basics”][bt_tutorials_basics] chapter about BT basics
* Write ROS Node using BT with the following action BT nodes (they should be connected with Sequence control node):
  * Listener BT node that 
    * waits message from **/repeat_times** topic of type [std_msgs::Uint16]
    * saves the value of incoming message in *BT blackboard* with key named **times_to_repeat** 
    * returns **SUCCESS** status after it has saved message value
  * Publisher BT node that
    * starts after listener node has returned **SUCCESS** status
    * read value of **times_to_repeat** keeped in the *BT blackboard* by listener node
    * publish `Hello ROS!` message into **/hello_message** topic of type [std_msgs::String] as many times as was send to **/repeat_times** topic
    * return **SUCCESS** status

What you need to achieve as the result is below:
* You should have ROS node with BT with the functionality described above
* You  should have the launch file **day_09_ex_00.launch** that runs your ROS node and has **times_to_repeat** parameter


## Chapter V

### Exercise 01 : Patrol robot

Directory to store your solution : ex01

Files to be in the directory : All the necessary files to run your ROS package

Authorized functions : All the necessary functions from BehaviorTree.CPP and ROS to write your node(s)

Comments :

In this exercise, you will write the behavior of a patrol robot using BT.

The robot has to have the following behaviors:
* Move from one point to another using a list of points from the launch file

    > In this task you will simulate “moving” with text logs.  When robot starts to move there should be written “Moving to <POINT_COORDINATES>” in the console, after that you should wait 2 seconds and then write “Successfully reached <POINT_COORDINATES>”

* Repeat such cycle (from the last waypoint to the first one) as many times as written in the launch file in **times_to_repeat** param (or infinitely if there is -1 times)

What you need to achieve as the result is below:
* You should have ROS node with BT with the functionality described above
* You  should have the launch file **day_09_ex_01.launch** that runs ROS node with BT and has the following parameters:
  * List of points should be 2-dimensional array of type float with the name **waypoints**, e.g
`<param name=”waypoints”	value=”[ [0.0, 0.0, 0.0], [1.0, 1.0, 1.0], [2.0, 2.0, 2.0] ]” />`. Single point has the standard ROS 2-D coordinates [$x$, $y$, $\theta$], where:
    * $x$ - x-coordinate on 2-D plane
    * $y$ - y-coordinate on 2-D plane
    * $\theta$ - angle over z-axis in radians
  * The variable of repeat times should have *int* type and the name **times_to_repeat**. 
    > If it is set to **-1**, then the robot should move over waypoints **infinitely**


## Chapter VI

### Exercise 02 : The REAL Patrol robot in Gazebo

Directory to store your solution : ex02

Files to be in the directory : All the necessary files to run your ROS package

Authorized functions : All the necessary functions from BehaviorTree.CPP and ROS to write your node(s)

Comments :

In this exercise, you will upgrade your  patrol robot.

First of all you need to replace “moving” from the previous exercise to the **REAL MOVING** with [move_base] (you need to add MoveBase ROS action client into your BT Node).

The second thing you need to do is add battery monitoring functionality:
* Your robot has to monitor battery status from topic **/battery_status** of type [std_msgs::Uint16] with battery charge *from 0 to 100 percents*
* If the battery charge drops below **battery_threshold** percent (from the launch file), then the robot must return to the dock station waypoint (**dock_station_pose** param from the launch file), then wait while it is recharging (the robot will be recharged when there will be a new message with the value of **100** in **/battery_status** topic). After that robot must continue its partoling mission **from the point where it has moved before going to the dock station**.

And the last thing you need to do is remember Day04 - Day06 of your course with the Gazebo simulator. You need to start Gazebo simulator world, spawn your robot and enable the robot drive controller.

What you need to achieve as the result is below:
* You should have ROS node with BT with the functionality described above
* You should have configuration of gazebo world and robot model in it
* You  should have the launch file **day_09_ex_02.launch** that runs gazebo simulation, ROS node with BT and has the following parameters:
  * List of points should be 2-dimensional array of type float with the name **waypoints**, e.g `<param name=”waypoints”	value=”[ [0.0, 0.0, 0.0], [1.0, 1.0, 1.0], [2.0, 2.0, 2.0] ]” />`. Single point has the standard ROS 2-D coordinates [$x$, $y$, $\theta$], where:
    * $x$ - x-coordinate on 2-D plane
    * $y$ - y-coordinate on 2-D plane
    * $\theta$ - angle over z-axis in radians
  * The variable of repeat times should have *int* type and the name **times_to_repeat**. 
    > If it is set to **-1**, then the robot should move over waypoints **infinitely**
  * **battery_threshold** that means robot battery is almost discharged
  * **dock_station_pose** in ROS 2-D coordinates for dock station coordinates, e.g `<param name=”dock_station_pose”	value=”[5.0, -7.0, 0.0]” />`





[BehaviorTree.CPP]: https://github.com/BehaviorTree/BehaviorTree.CPP
[Groot]: https://github.com/BehaviorTree/Groot
[bt_tutorials_basics]: https://www.behaviortree.dev/bt_basics/
[std_msgs::Uint16]: http://docs.ros.org/en/lunar/api/std_msgs/html/msg/UInt16.html
[std_msgs::String]: http://docs.ros.org/en/lunar/api/std_msgs/html/msg/String.html
[move_base]: http://wiki.ros.org/move_base