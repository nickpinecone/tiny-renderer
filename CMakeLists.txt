cmake_minimum_required(VERSION 3.31)
project(tiny_renderer)

set(CMAKE_CXX_STANDARD 20)

add_executable(tiny_renderer main.cpp
        tgaimage.cpp)
