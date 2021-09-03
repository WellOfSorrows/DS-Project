cmake_minimum_required(VERSION 3.20)
project(DS-Project C)

set(CMAKE_C_STANDARD 99)

add_executable(DS-Project main.c DataStructures.h Queue.h AVL_Tree.h Utilities.h Functions.h)
