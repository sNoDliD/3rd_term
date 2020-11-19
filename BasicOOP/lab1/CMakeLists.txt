cmake_minimum_required(VERSION 3.17)
project(lab1)

set(CMAKE_CXX_STANDARD 14)

add_executable(lab1 main.cpp classes/DateTime.cpp classes/DateTime.h classes/Graphs.h classes/Randomizer.h)