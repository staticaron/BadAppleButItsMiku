cmake_minimum_required(VERSION 3.18)
project("MikuEngine" CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

add_subdirectory(vendor/glad)
add_subdirectory(vendor/glfw)
add_subdirectory(vendor/glm)
add_subdirectory(vendor/imgui)
add_subdirectory(vendor/stb)
add_subdirectory(vendor/spdlog)

find_package(OpenCV REQUIRED)

file(GLOB_RECURSE ENGINE_SOURCES
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.h"
)

add_library(MikuEngine SHARED ${ENGINE_SOURCES})

set_target_properties(MikuEngine PROPERTIES POSITION_INDEPENDENT_CODE ON)

set_target_properties(MikuEngine PROPERTIES CXX_PRECOMPILE_HEADERS_SUPPORTED TRUE)

target_precompile_headers(MikuEngine PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/src/MikuEngine/pch.h"
)

if (CMAKE_BUILD_TYPE MATCHES "Debug")
    target_compile_definitions(MikuEngine PUBLIC DEBUG)
endif()

target_compile_definitions(MikuEngine PUBLIC
    ME_BUILD_DLL
    IMGUI_FONT="${CMAKE_CURRENT_SOURCE_DIR}/vendor/imgui/fonts/jetbrainsmono.ttf"
    RESOURCE_DIR="${CMAKE_CURRENT_SOURCE_DIR}/resources/"
)

target_include_directories(MikuEngine PUBLIC
    "${CMAKE_CURRENT_SOURCE_DIR}/src"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/MikuEngine"
    "${CMAKE_CURRENT_SOURCE_DIR}/vendor/glm"
    "${CMAKE_CURRENT_SOURCE_DIR}/vendor/stb/include"
    ${OpenCV_INCLUDE_DIRS}
)

target_link_libraries(MikuEngine PUBLIC
    glad
    glfw
    glm
    imgui
    spdlog
    stb_image
    ${OpenCV_LIBS}
    dl
)

set(BIN_DIR "${CMAKE_CURRENT_SOURCE_DIR}/bin")
set_target_properties(MikuEngine PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${BIN_DIR}
)
