cmake_minimum_required(VERSION 3.10)

project(hw4 VERSION 1.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
set(CMAKE_CXX_COMPILER "clang++")

set(SOURCES main.cpp)

add_executable(hw4 ${SOURCES})

