from launch import LaunchDescription
import launch_ros.actions


def generate_launch_description():
    return LaunchDescription([
        launch_ros.actions.Node(
            package='demo_nodes_cpp', executable='talker', output='screen'),
        launch_ros.actions.Node(
            package='demo_nodes_cpp', executable='number_processor', output='screen'
        ),
        launch_ros.actions.Node(
            package='demo_nodes_cpp', executable='listener', output='screen'),
    ])
