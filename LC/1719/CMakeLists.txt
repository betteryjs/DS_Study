cmake_minimum_required(VERSION 3.21)
project(1719)

set(CMAKE_CXX_STANDARD 14)

add_executable(1719 main.cpp)

file(GLOB LCA_PLAY "/home/yjs/.config/JetBrains/CLion2021.3/practices/Workspace/Playground.cpp")
add_executable(lca-play ${LCA_PLAY})