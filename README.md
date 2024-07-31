# Johnny-Answers-Session09

colcon build
source 
ros2 pkg create --build-type ament_cmake --node-name initNode cpp_turtle
<!-- ros2 run my_package my_node -->

ros2 launch cpp_turtle cpp_turtle_launch.py
--------------------------------------

To Add Message Type:
1- add these in CMakeLists.txt: 

    find_package(rosidl_default_generators REQUIRED)

    rosidl_generate_interfaces(${PROJECT_NAME}
    "action/MeasureLapTime.action"
    "srv/FindWall.srv"
    )

2-add these in package.xml: 

    <buildtool_depend>rosidl_default_generators</buildtool_depend>
    <depend>action_msgs</depend>
    <member_of_group>rosidl_interface_packages</member_of_group>

----------------------------------------

To fix VS code includes error, i added "/opt/ros/humble/include/**"  to the includes in c_cpp_properties.json.

----------------------------------------

To run gazebo turtle: 
    export TURTLEBOT3_MODEL=burger
    ros2 launch turtlebot3_gazebo turtlebot3_dqn_stage1.launch.py

-----------------------------------------

Laser scan msg: 

angle_min: represent the angle of the front view of the robot, 
in my case it is 0 so angle 0 is the front

ranges: represent the distance between the robot and an object on a given angle
so ranges[0], is the distance at angle 0 (the front view of the robot)

angle_increment: represent the "resolution" of the scan, so if it is 1 degree, the scan returns an array of 360 size
each representing a degree, (ig if it is 0,5 degree we would get 360*2 ?)

-------------------------------------------

robot_driver notes: 

i want an +- 10 degree angle in the front.
index = degree/degree increment (example we want the 180 degree of a 0.5 degree increment, the index we want is 180/0.5 = 360)

If start_index is -5 and num_ranges is 360:

    (start_index + num_ranges) = 355.
    355 % 360 is 355 so start_index is set to 355.

If start_index is 365 and num_ranges is 360:

    (start_index + num_ranges) = 725.
    725 % 360 is 5 so start_index is set to 5.

--------------------------------------------
























