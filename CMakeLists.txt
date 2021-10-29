cmake_minimum_required(VERSION 3.0)

project(STL2022)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 11)

aux_source_directory(${CMAKE_SOURCE_DIR} src)

add_library(${PROJECT_NAME} SHARED ${src})

