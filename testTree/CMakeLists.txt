cmake_minimum_required(VERSION 3.8)
project(testTree)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp node.h tree.h)
add_executable(testTree ${SOURCE_FILES})