cmake_minimum_required(VERSION 3.20)
project(95)

set(CMAKE_CXX_STANDARD 14)

add_executable(95 main.cpp)

add_executable(unionFind unionFind.cpp)
add_executable(getmaxmin getmaxmin.cpp)
add_executable(bucketsort bucketsort.cpp)
add_executable(test test.cpp)
add_executable(getKminNumber getKminNumber.cpp)