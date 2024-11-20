cmake_minimum_required(VERSION 3.10)

project(programacion_estructurada2)

set(CMAKE_C_STANDARD 99)

include_directories(${CMAKE_SOURCE_DIR}/include)

add_executable(programacion_estructurada2
            main.c
        main.h
)
