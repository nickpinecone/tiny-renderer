cmake_minimum_required(VERSION 3.31)
project(tiny_renderer)

set(CMAKE_CXX_STANDARD 20)

add_executable(tiny_renderer main.cpp
        tgaimage.cpp
        model.cpp)

file(MAKE_DIRECTORY ${CMAKE_BINARY_DIR}/obj)

file(GLOB OBJ_FILES RELATIVE ${CMAKE_SOURCE_DIR} "obj/*/*")

foreach (file IN LISTS OBJ_FILES)
    configure_file(${file} ${CMAKE_BINARY_DIR}/${file} COPYONLY)
endforeach ()
