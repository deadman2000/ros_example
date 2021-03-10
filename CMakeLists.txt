cmake_minimum_required(VERSION 3.0.2)
project(example)

## Compile as C++11, supported in ROS Kinetic and newer
add_compile_options(-std=c++11)

find_package(catkin REQUIRED COMPONENTS
  sensor_msgs
  cv_bridge
  image_transport
  roscpp
)


catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES example
#  CATKIN_DEPENDS other_catkin_pkg
#  DEPENDS system_lib
)

include_directories(
# include
 ${catkin_INCLUDE_DIRS}
)

add_executable(${PROJECT_NAME} src/${PROJECT_NAME}.cpp)
target_link_libraries(${PROJECT_NAME} ${catkin_LIBRARIES})