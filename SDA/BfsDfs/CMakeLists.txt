cmake_minimum_required(VERSION 3.25)
project(bfsdfs C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(bfsdfs
        queue_stack.c
        queue_stack.h
        test_queue_stack.c)
