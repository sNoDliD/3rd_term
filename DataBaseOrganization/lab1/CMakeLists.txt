cmake_minimum_required(VERSION 3.17)
project(lab1 C)

set(CMAKE_C_STANDARD 11)

add_executable(lab1 main.c scripts/classes.h scripts/common.h
        scripts/teacher.c scripts/class.c scripts/userStatus.c
        scripts/lab.c scripts/user.c scripts/choice.c)