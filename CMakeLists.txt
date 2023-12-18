cmake_minimum_required(VERSION 3.27)
project(os-exam-prep)

set(CMAKE_CXX_STANDARD 17)

add_executable(task-1-1 task-1/main.cpp)

add_executable(task-1-2 task-1/main2.cpp)

add_executable(task-2-sortings task-2-sortings/processes.cpp
        task-2-sortings/processes.h)

add_executable(task-2-sortings-2 task-2-sortings/threads.cpp)

add_executable(task-3-messenger-1-1 task-3-messenger/first-messenger.cpp
        task-3-messenger/common.h)

add_executable(task-3-messenger-1-2 task-3-messenger/second-messenger.cpp)

add_executable(task-3-messenger-2
        task-3-messenger/single-messanger.cpp)

add_executable(task-4-semaphores task-4-semaphores/philosophers.cpp
        task-4-semaphores/utils.h)
add_executable(task-5 task-5-stream-redirection/redirection.cpp
        task-5-stream-redirection/utils.h)
add_executable(test task-3-messenger/test_access.cpp)
add_executable(task-888 task-8-shmemory/shmemory.cpp)
