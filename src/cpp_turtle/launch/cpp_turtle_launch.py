from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='cpp_turtle',
            executable='lap_time_action_client',
            name='lap_time_action_client',
            output='screen'
        ),
        Node(
            package='cpp_turtle',
            executable='lap_time_action_server',
            name='lap_time_action_server',
            output='screen'
        ),
        Node(
            package='cpp_turtle',
            executable='robot_driver',
            name='robot_driver',
            output='screen'
        ),
        Node(
            package='cpp_turtle',
            executable='initNode',
            name='init_node',
            output='screen'
        ),
    ])
