cmake_minimum_required(VERSION 2.8.3)
project(irobot_worlds)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS
  geometry_msgs
  roscpp
  rospy
  std_msgs
  tf
  visualization_msgs
)

###################################
## catkin specific configuration ##
###################################
## The catkin_package macro generates cmake config files for your package
## Declare things to be passed to dependent projects
## INCLUDE_DIRS: uncomment this if you package contains header files
## LIBRARIES: libraries you create in this project that dependent projects also need
## CATKIN_DEPENDS: catkin_packages dependent projects also need
## DEPENDS: system dependencies of this project that dependent projects also need
catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES controller
#  CATKIN_DEPENDS geometry_msgs roscpp rospy std_msgs turtlesim
#  DEPENDS system_lib
)

###########
## Build ##
###########


include_directories(
  ${catkin_INCLUDE_DIRS}
)

# A node for control people in the CP map
add_executable(person_move src/person_controller.cpp)
target_link_libraries(person_move ${catkin_LIBRARIES})

# A node for control people in the warehouse map
add_executable(worker_move src/worker_controller.cpp)
target_link_libraries(worker_move ${catkin_LIBRARIES})
