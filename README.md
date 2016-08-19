
simulation_worlds
===
Some custom gazebo worlds.


Compiling
---
Just clone the repository in the src folder of a catkin workspace. Then run catkin_make.

To simulate the robot in Gazebo you first have to add this lines to your bashrc:

```
source /usr/share/gazebo/setup.sh
export GAZEBO_MODEL_PATH=$GAZEBO_MODEL_PATH:$(rospack find simulation_worlds)/models
export GAZEBO_RESOURCE_PATH=$GAZEBO_RESOURCE_PATH:$(rospack find simulation_worlds)/models
```

Usage
---
---

```
roslaunch simulation_worlds cp_fake_furniture.launch
```
to load a laboratory only with forniture. 
```
roslaunch simulation_worlds cp_fake_furniture_and_people.launch
```
to load a laboratory with forniture and people.
---

```
roslaunch simulation_worlds cp_real_furniture.launch
```
to load the Centro di Ricerca "E. Piaggio" with some forniture.


---
```
roslaunch simulation_worlds warehouse.launch
```
to load a warehouse only with forniture. 

```
roslaunch simulation_worlds warehouse_with_people.launch
```
to load a warehouse with forniture and people.
