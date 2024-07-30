# Johnny-Answers-Session09

colcon build
source 
ros2 pkg create --build-type ament_cmake --node-name my_node my_package
ros2 run my_package my_node
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