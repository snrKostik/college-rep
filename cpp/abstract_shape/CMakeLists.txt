cmake_minimum_required(VERSION 3.30)
project(abstract_shape)

set(CMAKE_CXX_STANDARD 26)

add_executable(abstract_shape main.cpp
        Shape.cpp
        Shape.h)
