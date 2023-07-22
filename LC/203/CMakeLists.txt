cmake_minimum_required(VERSION 3.20)
project(203)

set(CMAKE_CXX_STANDARD 14)

add_executable(203 main.cpp)

add_executable(cutlist cutlist.cpp)
add_executable(testbuild testbuild.cpp)
add_executable(buildlist buildlist.cpp)