cmake_minimum_required(VERSION 4.3)
project(dataStructures)

set(CMAKE_CXX_STANDARD 20)

add_executable(dataStructures main.cpp
        src/UnionFind.cpp
        src/UnionFind.h
        src/HashMap.cpp
        src/HashMap.h)
