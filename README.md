
irobot_worlds
===
Some custom gazebo worlds.


Compiling
---
Just clone the repository in the src folder of a catkin workspace. Then run catkin_make.

To simulate the robot in Gazebo you first have to add this lines to your bashrc:

```
source /usr/share/gazebo/setup.sh
export GAZEBO_MODEL_PATH=$GAZEBO_MODEL_PATH:$(rospack find irobot_worlds)/models
export GAZEBO_RESOURCE_PATH=$GAZEBO_RESOURCE_PATH:$(rospack find irobot_worlds)/models
```

Usage
---
---

```
roslaunch irobot_worlds cp_with_furniture.launch
```
to load a laboratory only with forniture. 
```
roslaunch irobot_worlds cp_with_furniture_and_people.launch
```
to load a laboratory with forniture and people.
---

```
roslaunch irobot_worlds CentroPiaggio.launch
```
to load the Centro di Ricerca "E. Piaggio" with some forniture.


---
```
roslaunch irobot_worlds warehouse.launch
```
to load a warehouse only with forniture. 

```
roslaunch irobot_worlds warehouse_with_people.launch
```
to load a warehouse with forniture, people and one iRobot create.