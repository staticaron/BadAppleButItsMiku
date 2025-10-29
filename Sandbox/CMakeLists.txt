cmake_minimum_required(VERSION 3.18)

project("Sandbox")

file(GLOB_RECURSE SOURCES
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
)

set_property(DIRECTORY APPEND PROPERTY CMAKE_CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.h"
)

add_executable("Sandbox" "${SOURCES}")

target_link_libraries("Sandbox" PRIVATE "MikuEngine")

target_include_directories("Sandbox" PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/src/")

set_target_properties("Sandbox" PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${BIN_DIR}
)

# add_custom_command(TARGET "Sandbox" POST_BUILD
#     COMMAND ${CMAKE_COMMAND} -E copy_if_different
#         $<TARGET_FILE:MikuEngine>               # DLL path
#         $<TARGET_FILE_DIR:Sandbox>           # Copy destination (exe folder)
# )
