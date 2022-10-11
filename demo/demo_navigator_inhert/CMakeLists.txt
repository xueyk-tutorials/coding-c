cmake_minimum_required(VERSION 3.5)
project(navigator)

include_directories(
    src
)
aux_source_directory(src SRC)
add_executable(navigator main.c ${SRC})