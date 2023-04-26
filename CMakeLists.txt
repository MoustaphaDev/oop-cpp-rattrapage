cmake_minimum_required(VERSION 3.24)
project(try_cpp)

set(CMAKE_CXX_STANDARD 23)

add_executable(try_cpp main.cpp lib/classes.h lib/classes.cpp)
