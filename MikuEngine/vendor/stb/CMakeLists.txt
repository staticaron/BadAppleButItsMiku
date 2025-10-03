add_library(stb_image)

file(GLOB_RECURSE MY_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")

target_sources(stb_image PRIVATE "${MY_SOURCES}")
target_include_directories(stb_image PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include/")