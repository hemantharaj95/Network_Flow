cmake_minimum_required(VERSION 3.16.2)

project(network_flow)
add_compile_options(-std=c++17)

include_directories(./include/)
add_executable(output main.cpp)