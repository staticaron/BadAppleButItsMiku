cmake_minimum_required(VERSION 3.18)

project(MikuEnginePlusGame)

add_compile_definitions(DEBUG)

set(BIN_DIR "${CMAKE_BINARY_DIR}/bin") 

add_subdirectory(MikuEngine)

add_subdirectory(Sandbox)
