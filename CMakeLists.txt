cmake_minimum_required(VERSION 3.25)
project(ds C)

set(CMAKE_C_STANDARD 23)

add_executable(ds main.c linked_list/sl/single_linked_list.c linked_list/sl/single_linked_list.h linked_list/dl/double_linked_list.c linked_list/dl/double_linked_list.h)
