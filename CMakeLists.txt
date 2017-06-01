cmake_minimum_required(VERSION 3.7)
project(data_structure)

set(CMAKE_C_STANDARD 11)

set(SOURCE_FILES main.c list/List.c list/TwoStacks.c)
add_executable(data_structure ${SOURCE_FILES})