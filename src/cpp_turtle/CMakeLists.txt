cmake_minimum_required(VERSION 3.8)
project(cpp_turtle)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
# uncomment the following section in order to fill in
# further dependencies manually.
# find_package(<dependency> REQUIRED)

add_executable(initNode src/initNode.cpp)
target_include_directories(initNode PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>)
target_compile_features(initNode PUBLIC c_std_99 cxx_std_17)  # Require C99 and C++17

install(TARGETS initNode
  DESTINATION lib/${PROJECT_NAME})

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # comment the line when a copyright and license is added to all source files
  set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # comment the line when this package is in a git repo and when
  # a copyright and license is added to all source files
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

find_package(rosidl_default_generators REQUIRED)

rosidl_generate_interfaces(${PROJECT_NAME}
  "action/MeasureLapTime.action"
  "srv/FindWall.srv"
)


# Find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(rclcpp_action REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(nav_msgs REQUIRED)
find_package(std_msgs REQUIRED)
find_package(rosidl_default_generators REQUIRED)


# Ensure that dependencies for actions and services are found
find_package(rosidl_typesupport_cpp REQUIRED)
find_package(rosidl_default_runtime REQUIRED)


# Include directories
include_directories(
  include
  ${rclcpp_INCLUDE_DIRS}
  ${geometry_msgs_INCLUDE_DIRS}
  ${sensor_msgs_INCLUDE_DIRS}
  ${nav_msgs_INCLUDE_DIRS}
  ${std_msgs_INCLUDE_DIRS}
)

# Add generated include directory
include_directories(${CMAKE_CURRENT_BINARY_DIR}/rosidl_generator_cpp)


# Add the executable
add_executable(lap_time_action_client src/lap_time_action_client.cpp)
add_executable(lap_time_action_server src/lap_time_action_server.cpp)
add_executable(robot_driver src/robot_driver.cpp)
add_executable(wall_finder src/wall_finder.cpp)


# Link against the necessary libraries
ament_target_dependencies(lap_time_action_client
  rclcpp
  rclcpp_action
  std_msgs
  rosidl_typesupport_cpp
  rosidl_default_runtime
)

ament_target_dependencies(lap_time_action_server
  rclcpp
  rclcpp_action
  nav_msgs
  geometry_msgs
  std_msgs
  rosidl_typesupport_cpp
  rosidl_default_runtime
)

ament_target_dependencies(robot_driver
  rclcpp
  geometry_msgs
  sensor_msgs
  std_msgs
  rosidl_typesupport_cpp
  rosidl_default_runtime
)

ament_target_dependencies(wall_finder
  rclcpp
  geometry_msgs
  sensor_msgs
  std_msgs
  rosidl_typesupport_cpp
  rosidl_default_runtime
)

# Get typesupport targets and link them
rosidl_get_typesupport_target(cpp_turtle__rosidl_typesupport_cpp ${PROJECT_NAME} rosidl_typesupport_cpp)

target_link_libraries(lap_time_action_client ${cpp_turtle__rosidl_typesupport_cpp})
target_link_libraries(lap_time_action_server ${cpp_turtle__rosidl_typesupport_cpp})
target_link_libraries(robot_driver ${cpp_turtle__rosidl_typesupport_cpp})
target_link_libraries(wall_finder ${cpp_turtle__rosidl_typesupport_cpp})



# Install the executables
install(TARGETS
  lap_time_action_client
  lap_time_action_server
  robot_driver
  wall_finder
  DESTINATION lib/${PROJECT_NAME})

# Install launch files
install(DIRECTORY launch/
  DESTINATION share/${PROJECT_NAME}/launch
)




ament_package()
