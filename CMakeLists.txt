cmake_minimum_required(VERSION 3.16)
project(Binary_search_tree VERSION 1.0)
# Default to C++11
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 11)
endif()
add_compile_options(-Wall -g -Wextra -Wpedantic)

add_executable(apk
    main.cpp 
    Tree.h
    Element.h
)

