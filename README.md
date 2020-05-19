# Path-Planning-Robot
Used ROS packaged such as AMCL, Turtlebot and Slam to create a robot to autonomously navigate to objects and move them around

To run this project clone thsi project into your catkin workspace.

## Setup 
Initialize this repo into a catkin workspace. If you do not have one use the following steps to initialize one:
'''
mkdir -p ~/catkin_ws/src
cd ~/catkin_ws/
git clone ___ src
rosdep install --from-paths src --ignore-src -y
catkin build
source devel/setup.bash

'''

# Running
To map the environment
- run ./scripts/test_slam.sh

To test the navigation using Rviz navigation goals
- run ./scripts/test_navigation.sh

To test the markers
- run ./scripts/add_marker.sh

To run the home-service robot
- run ./scripts/home_service.sh
