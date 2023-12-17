cmake_minimum_required(VERSION 3.27)
project(os-exam-prep)

set(CMAKE_CXX_STANDARD 17)

add_executable(task-1-1 task-1/main.cpp)

add_executable(task-1-2 task-1/main2.cpp)

add_executable(task-2-sortings task-2-sortings/processes.cpp
        task-2-sortings/processes.h)
add_executable(task-3-sortings-2 task-2-sortings/threads.cpp)
