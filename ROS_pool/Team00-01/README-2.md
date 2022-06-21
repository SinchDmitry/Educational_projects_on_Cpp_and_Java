# RUSH 01 - Piscine Robot Operating System
## Competition AutoRace
![autorace.urdf](misc/images/autorace.png)
Summary: This rush will help you to strengthen the skills acquired in the previous days.
## Contents
<!-- TOC -->

- [RUSH 01 - Piscine Robot Operating System](#rush-01---piscine-robot-operating-system)
    - [Competition AutoRace](#competition-autorace)
    - [Contents](#contents)
    - [Chapter I](#chapter-i)
        - [Preamble](#preamble)
    - [Chapter II](#chapter-ii)
        - [Instructions](#instructions)
    - [Chapter III](#chapter-iii)
        - [Specific instructions of the day](#specific-instructions-of-the-day)
    - [Chapter IV](#chapter-iv)
        - [Mandatory part](#mandatory-part)
            - [Competition judging rules:](#competition-judging-rules)
            - [Mission scoring:](#mission-scoring)
            - [Mission score:](#mission-score)
            - [Evaluation:](#evaluation)
        - [ROS Package](#ros-package)
        - [Report](#report)
    - [Chapter V](#chapter-v)
        - [Turn-in and peer-evaluation](#turn-in-and-peer-evaluation)

<!-- /TOC -->

## Chapter I
### Preamble
A good way to test your knowledge is through competitions in which you solve quite a complex and interesting task. In this rush, you are challenged to pass a track with different elements and tasks. This competition will prepare you for the development of an advanced robot, such as an indoor, outdoor or unmanned car. The conditions and rules of the competition imply a variety of problem solving options in which you can show your creativity and ingenuity. Feel free to use google, other people's ROS packages and write your own ROS packages to win the contest.

An important skill of a good programmer is the ability to explain in clear language the work you have done and the work of the program, so you need to make a good presentation at the end of the work.

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
You can use any C++ or Python libraries in your ROS metapackage. You can use any third party ROS packages in any programming languages.

## Chapter IV
### Mandatory part

In this rush, your goal is to win the AutoRace challenge version 2019 https://emanual.robotis.com/docs/en/platform/turtlebot3/autonomous_driving_autorace/ . The reviewer will run your ROS metapackage on the turtlebot3 burger robot in the Gazebo AutoRace scene from the repositories:
```
https://github.com/ROBOTIS-GIT/turtlebot3 branch melodic-devel
https://github.com/ROBOTIS-GIT/turtlebot3_msgs branch melodic-devel
https://github.com/ROBOTIS-GIT/turtlebot3_simulations branch melodic-devel
```
It is allowed to use only the standard turtlebot3 burger robot model and a set of sensors from the official repository, without making changes to the robot model.

The same Gazebo AutoRace scene from the official repository must be used for testing the code by you during development and during the competition.

The robot is considered to have completed the race if it left the tunnel with its entire body, stopped on the road and then sent a message to the robot_finish topic. If, after the command to the robot_finish topic, the robot continues to move or is not located with its entire body outside the tunnel, then the run is not counted.

The robot can only start moving after a message has been sent to the robot_start topic. If the robot started moving before the command, then the race is not counted.

When checking, no more than 10 minutes are given to complete the task, if the robot does not have time to complete the mission during this time, then the race ends.

Check-in is performed by a robot for a time and a set of points. Points of all teams are recorded in the table. The team that completed the task for fewer points from the table is eliminated from the piscine.

Checking the execution of the task takes place on the computer of the verifier by downloading from github and compiling via catkin make, if you need to install additional packages, this should be written in the instructions in readme.md. If the package compiles with errors, the rush is considered failed.

Baseline can be downloaded here:
```
https://github.com/ROBOTIS-GIT/turtlebot3_autorace branch melodic-devel
```
You must develop a separate ROS metapackage containing all the necessary control files for the turtlebot3 burger robot, the package name must contain your last name and first name. The launch must be done with the command:
```
$ roslaunch [your last name]_[your first name]_autorace_core autorace_core.launch
$ rostopic pub -1 /robot_start
```
When developing your ROS metapackage, you can use the baseline code and any other ROS packages you find on the internet. Third party ROS packages should be installed via sudo apt-get install ros-melodic-[...], unofficial repositories via git clone to the catkin_ws/src folder. In the presentation, you should detail what third-party ROS packages you have used and what you have developed yourself.

During the competition, the verifier downloads the following repositories to the catkin_ws/src folder from the official links:
```
git clone -b melodic-devel https://github.com/ROBOTIS-GIT/turtlebot3
git clone -b melodic-devel https://github.com/ROBOTIS-GIT/turtlebot3_msgs
git clone -b melodic-devel https://github.com/ROBOTIS-GIT/turtlebot3_simulations
git clone -b melodic-devel https://github.com/ROBOTIS-GIT/turtlebot3_autorace
```
The reviewer then downloads your ROS metapackage from your repository to the catkin_ws/src folder.

If the readme.md file contains instructions for installing additional official packages via sudo apt-get install ros-melodic-[...] or unofficial repositories via git clone, then they will be executed.

After that, the verifier will execute the catkin_make command. If your packages do not compile, then the job is considered failed.

The contest reviewer will run your metapackage along with the launch files from the official repository as follows:

Terminal 1:
```
$ roscore
```
Terminal 2:
```
$ roslaunch turtlebot3_gazebo turtlebot3_autorace.launch
```
Terminal 3:
```
roslaunch turtlebot3_gazebo turtlebot3_autorace_mission.launch
```
Terminal 4:
```
roslaunch [your last name]_[your first name]_autorace_core autorace_core.launch
```
Terminal 5:
```
rostopic pub -1 /robot_start
```

#### Competition judging rules:

Your robot will have no more than 10 minutes to complete the race.

When the robot stops for more than 30 seconds, the robot ends the run.

The execution of the race consists of missions.

#### Mission scoring:
- Traffic light - 20 points
- Parking - 20 points
- Barrier - 20 points
- Tunnel - 20 points
- Points for time - 20 points

The team's rank in the winners' table is determined based on the results of the mission, time and penalty points.

A tied score will be judged according to the following priority: more successful missions; by time.

#### Mission score:

1. Traffic lights

After the robot starts moving, the color of the traffic light is switched on.
The traffic light alternately changes three colors: green, yellow, red.
The robot is considered to have successfully completed the mission only if it crossed the traffic light on the green light.

2. Parking

The mission is to drive into an empty parking lot for 1 second and then exit the parking lot onto the road.
The completion of the mission is counted only if the robot drove into an empty parking lot with the whole body.
If the robot drove into the parking lot occupied by another robot, then the mission is considered failed.

3. Barrier

The robot is allowed to move through the barrier only if the barrier is in the open position. When the barrier is closed, the robot in front of it must stop.
The mission is only counted if the robot crossed the road with the barrier in the open state.

4. Tunnel

The tunnel is a room without light with randomly placed obstacles.
The mission is considered completed if the robot was able to leave the tunnel from the exit side by leaving it with the whole body.
The mission is considered failed if the robot could not enter the tunnel or could not leave it.

5. Points for time

Time points are awarded only to teams that have successfully completed all previous missions.

The time is calculated from the moment the command was sent to the robot_start topic.

If the robot starts moving before the command is sent to the robot_start topic, then the 
mission is considered failed.

The time is calculated until the robot stops completely and sends a command to the robot_finish topic. If the robot continues moving after sending the command to the robot_finish topic, then the mission is considered failed. If the robot did not leave the exit of the tunnel with the whole body, then the mission is considered failed.

The mission completion time is calculated by the time when messages arrive in topics, according to the formula robot_finish - robot_start.

20 points for first place.

Each subsequent less time the team has in the table minus one point.

Below 20th place 0 points.

Time more than 10 minutes - 0 points.

#### Evaluation:
You have only one chance for each mission. If you clear each mission, you get a score accordingly.

Every mission has a starting point and finishing point. In each mission stage, touching the robot leads to a mission failure.

If the robot started moving before receiving the command in the robot_start topic, then the robot is removed from the race and no points are awarded to it.

If the robot has stopped for more than 30 seconds, then the race for it stops before 10 minutes have passed.

If the robot has left the road with its body behind the white or yellow line, then the race for it stops before 10 minutes have passed.

Total score is determined based on mission score, time score, and penalty points.

### ROS Package

Remember that the goal of the rush is to strengthen your skills. Try to use as much as you can from what you have learned from the previous days.

### Report

After completing the task, write a detailed presentation explaining the essence of the algorithm of your solution and its uniqueness. If necessary, provide a block diagram.

Your source code of the ROS package should contain detailed comprehensive comments on the work of your algorithm for exiting the maze, this will be taken into account when evaluating.

## Chapter V
### Turn-in and peer-evaluation

Turn in your work using your git repository, as usual. Only the work that’s in your repository will be graded during the evaluation.

During the correction, you will be evaluated on your turn-in (no functions that do all the heavy lifting for you) as well as your ability to present, explain, and justify your choices.

