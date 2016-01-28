#    File:    CMakeLists.txt
#    Author:  Marvin Smith
#    Date:    1/27/2016
#
#    Purpose: Construct the MapServiceConnector API
#


#   Set CMake Version
cmake_minimum_required( VERSION 2.8 FATAL_ERROR )

#  Set the Project Name
project(MapServiceConnector)


#   Force use of C++11
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")


#  Add Sub-Projects
add_subdirectory(src)

