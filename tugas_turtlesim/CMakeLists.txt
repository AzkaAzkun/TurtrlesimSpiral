cmake_minimum_required(VERSION 3.8)
project(tugas_turtlesim)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(geometry_msgs REQUIRED)

add_executable(tugas_turtlesim src/publisher_turtlesim.cpp)
ament_target_dependencies(tugas_turtlesim rclcpp geometry_msgs)

install(TARGETS tugas_turtlesim
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()
