
irobot_worlds
===
Some custom worlds for iRobot Create 2.

Prerequisites
---
* [irobotcreate2]

Compiling
---
Just clone the repository in the src folder of a catkin workspace. Then run catkin_make.

To simulate the robot in Gazebo you first have to add this lines to your bashrc:

```
source /usr/share/gazebo/setup.sh
export GAZEBO_MODEL_PATH=$GAZEBO_MODEL_PATH:$(rospack find irobot_world)
export GAZEBO_RESOURCE_PATH=$GAZEBO_RESOURCE_PATH:$(rospack find irobot_world)
```

Usage
---
---
```
roslaunch irobot_worlds cp_wf_and_people.launch
```
to load a laboratory (Centro Piaggio) with forniture and people. 

```
roslaunch irobot_worlds cp_with_furniture.launch
```
to load a laboratory (Centro Piaggio) with forniture. 

```
roslaunch irobot_worlds one_iRobot_at_CPwf.launch
```
to load a laboratory (Centro Piaggio) with forniture and one iRobot create.

```
roslaunch irobot_worlds one_iRobot_at_CPwf_and_people.launch
```
to load a laboratory (Centro Piaggio) with forniture, people and one iRobot create.

---
```
roslaunch irobot_worlds warehouse.launch
```
to load a warehouse with forniture and one iRobot create. 

```
roslaunch irobot_worlds warehouse_with_people.launch
```
to load a warehouse with forniture, people and one iRobot create. 

