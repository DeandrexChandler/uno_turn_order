cmake_minimum_required(VERSION 3.20)

# Project is named after the folder, so this file never needs editing per-week.
get_filename_component(FOLDER_NAME ${CMAKE_CURRENT_SOURCE_DIR} NAME)
project(${FOLDER_NAME} LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Every .cpp in the project root and in src/ is compiled automatically.
# CONFIGURE_DEPENDS re-scans on each build, so new files are picked up
# without touching this file. The root glob is deliberately NOT recursive --
# recursing would sweep in CMake's own probe files under build/.
file(GLOB ROOT_SOURCES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")
file(GLOB_RECURSE SRC_SOURCES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")
set(SOURCES ${ROOT_SOURCES} ${SRC_SOURCES})

# The executable is always called "main" so the run/debug config is portable.
add_executable(main ${SOURCES})
target_include_directories(main PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}" "${CMAKE_CURRENT_SOURCE_DIR}/src")
target_compile_options(main PRIVATE -Wall -Wextra -Wpedantic)
