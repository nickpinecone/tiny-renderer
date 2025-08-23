cmake_minimum_required(VERSION 3.31)
project(tiny_renderer)

set(CMAKE_CXX_STANDARD 20)

add_executable(tiny_renderer main.cpp
        tgaimage.cpp
        model.cpp)

file(MAKE_DIRECTORY ${CMAKE_BINARY_DIR}/obj)

file(GLOB OBJ_FILES RELATIVE ${CMAKE_SOURCE_DIR} "obj/*/*.obj")
foreach (OBJ_FILE ${OBJ_FILES})
    add_custom_command(
            TARGET ${PROJECT_NAME} POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy
            ${CMAKE_SOURCE_DIR}/${OBJ_FILE}
            ${CMAKE_BINARY_DIR}/${OBJ_FILE}
            COMMENT "Copying ${OBJ_FILE} to build directory"
    )
endforeach ()
