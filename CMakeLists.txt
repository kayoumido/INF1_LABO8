cmake_minimum_required(VERSION 3.12)
project(Labo08)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wconversion -Wextra -pedantic")

set(CMAKE_CXX_STANDARD 11)

add_executable(Labo08 main.cpp display.cpp display.h  global.h help.h help.cpp)