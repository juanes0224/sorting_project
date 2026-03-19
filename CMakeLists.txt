cmake_minimum_required(VERSION 3.20)
project(sorting_project)

set(CMAKE_CXX_STANDARD 17)

add_executable(sorting
    main.cpp
    QuickSort.cpp
    HeapSort.cpp
    AVLTree.cpp
)
