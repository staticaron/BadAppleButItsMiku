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

set(FMOD_DIR "${CMAKE_CURRENT_SOURCE_DIR}/vendor/fmod/linux")
set(FMOD_INC_DIR "${FMOD_DIR}/inc")
set(FMOD_LIB_DIR "${FMOD_DIR}/lib/x86_64")

find_library(FMOD_LIBRARY NAMES fmod PATHS ${FMOD_LIB_DIR})

find_package(OpenCV REQUIRED)

file(GLOB_RECURSE ENGINE_SOURCES
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.h"
)

add_library(MikuEngine SHARED ${ENGINE_SOURCES})

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
    ${OpenCV_INCLUDE_DIR}
    ${FMOD_INC_DIR}
)

target_link_libraries(MikuEngine PUBLIC
    glad
    glfw
    glm
    imgui
    spdlog
    stb_image
    ${OpenCV_LIBS}
    ${FMOD_LIBRARY}
)

set(BIN_DIR "${CMAKE_BINARY_DIR}/bin")
set_target_properties(MikuEngine PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${BIN_DIR}
)

if (DEFINED ME_PLATFORM_WINDOWS)
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${FMOD_LIB_DIR}/fmod.dll"
        ${BIN_DIR}
    COMMENT "Copying FMOD dll files to the bin directory"
)
endif()
