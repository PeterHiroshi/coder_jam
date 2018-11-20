cmake_minimum_required(VERSION 3.10)
project(beginner)

set(CMAKE_CXX_STANDARD 11)

add_executable(MaximumProfit complexity/MaximumProfit.cpp)
add_executable(InsertionSort sorting/InsertionSort.cpp)
add_executable(BubbleSort sorting/BubbleSort.cpp)
add_executable(SelectionSort sorting/SelectionSort.cpp)