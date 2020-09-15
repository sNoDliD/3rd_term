cmake_minimum_required(VERSION 3.17)
project(lab1 C)

set(CMAKE_C_STANDARD 11)

add_executable(lab1 main.c scripts/classes.h
        scripts/teacher.h scripts/class.h scripts/choice.h
        scripts/lab.h scripts/user.h scripts/userStatus.h scripts/index.h)