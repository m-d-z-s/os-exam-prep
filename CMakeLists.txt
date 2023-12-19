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

add_executable(task-3-messenger-2 task-3-messenger/single-messenger.cpp)

add_executable(task-4-semaphores-philosophers task-4-semaphores-philosophers/philosophers.cpp
        task-4-semaphores-philosophers/utils.h
        task-4-semaphores-philosophers/semaphores_i.h)

add_executable(philosophers-pugachev-variant task-4-semaphores-philosophers/philosophers-pugachev-variant.cpp)

add_executable(task-5 task-5-stream-redirection/redirection.cpp
        task-5-stream-redirection/utils.h)

add_executable(task-6 task-6-copy-paste/duplicator.cpp)

add_executable(task-7 task-7-dir-info/dir-info.cpp)

add_executable(task-8 task-8-shmemory-semaphores/shmemory.cpp
        task-8-shmemory-semaphores/semaphores_i.h)
