cmake_minimum_required(VERSION 3.22)
project(Graphs)

set(CMAKE_CXX_STANDARD 17)

add_executable(Graphs main.cpp
        MyList.cpp
        MyList.h
        Node.cpp
        Node.h
        Graph.cpp
        Graph.h
        Utils.cpp
        Utils.h)
