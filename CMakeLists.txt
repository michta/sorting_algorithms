cmake_minimum_required(VERSION 3.6)

set(CMAKE_BUILD_TYPE Debufg)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

project(SORT)

add_executable(
    Program
    main.cpp
    QuickSort.hpp
    HeapSort.hpp
)