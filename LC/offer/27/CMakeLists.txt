cmake_minimum_required(VERSION 3.20)
project(27)

set(CMAKE_CXX_STANDARD 14)

add_executable(27 main.cpp)

file(GLOB LCA_PLAY "/home/yjs/.config/JetBrains/CLion2021.3/practices/Workspace/Playground.cpp")
add_executable(lca-play ${LCA_PLAY})