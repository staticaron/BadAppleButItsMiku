cmake_minimum_required(VERSION 3.18)

project("MikuEngine")

add_subdirectory(vendor/glad)
add_subdirectory(vendor/glfw)
add_subdirectory(vendor/glm)
add_subdirectory(vendor/imgui)
add_subdirectory(vendor/spdlog)
add_subdirectory(vendor/stb)

file(GLOB_RECURSE SOURCES
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.h"
)

set_property(DIRECTORY APPEND PROPERTY CMAKE_CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.h"
)

add_library("MikuEngine" SHARED "${SOURCES}")

target_precompile_headers("MikuEngine" PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/src/MikuEngine/pch.h"
)

target_compile_definitions("MikuEngine" PUBLIC ME_PLATFORM_WINDOWS)
target_compile_definitions("MikuEngine" PUBLIC ME_BUILD_DLL)

target_compile_definitions("MikuEngine" PUBLIC IMGUI_FONT="${CMAKE_CURRENT_SOURCE_DIR}/vendor/imgui/fonts/jetbrainsmono.ttf")
target_compile_definitions("MikuEngine" PUBLIC RESOURCE_DIR="${CMAKE_CURRENT_SOURCE_DIR}/resources/")
# target_compile_definitions("MikuEngine" PUBLIC RESOURCE_DIR="")

target_include_directories("MikuEngine" PUBLIC
    "${CMAKE_CURRENT_SOURCE_DIR}/src/MikuEngine/"
    "${CMAKE_CURRENT_SOURCE_DIR}/src"
    "${CMAKE_CURRENT_SOURCE_DIR}/vendor/glm"
)

target_link_libraries("MikuEngine" PUBLIC
    glad
    glfw
    glm
    imgui
    spdlog
    stb_image
)

set_target_properties("MikuEngine" PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${BIN_DIR}
)