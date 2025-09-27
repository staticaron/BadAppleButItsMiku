cmake_minimum_required(VERSION 3.18)

project("MikuEngine")

add_subdirectory(vendor/glad)
add_subdirectory(vendor/glfw)
add_subdirectory(vendor/glm)

file(GLOB_RECURSE SOURCES
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.h"
)

set_property(DIRECTORY APPEND PROPERTY CMAKE_CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.h"
)

add_library("MikuEngine" SHARED "${SOURCES}")

target_compile_definitions("MikuEngine" PUBLIC ME_PLATFORM_WINDOWS)
target_compile_definitions("MikuEngine" PUBLIC ME_BUILD_DLL)

target_include_directories("MikuEngine" PUBLIC
    "${CMAKE_CURRENT_SOURCE_DIR}/src/"
)

target_link_libraries("MikuEngine" PUBLIC
    glad
    glfw
    glm
)