cmake_minimum_required(VERSION 3.17)
project(lab1 C)

set(CMAKE_C_STANDARD 11)

add_executable(lab1 main.c scripts/index.h scripts/master.h scripts/slave.h scripts/common.h)