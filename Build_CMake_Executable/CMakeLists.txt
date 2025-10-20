cmake_minimum_required(VERSION 3.10)

project(starter_project VERSION 1.0.0 LANGUAGES CXX)

message(STATUS "Building ${PROJECT_NAME} version ${PROJECT_VERSION}")

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add executable first
add_executable(main src/main.cpp)

# Configure version header
configure_file(config.h.in ${CMAKE_SOURCE_DIR}/include/config.h)

# Add include directories
target_include_directories(main PUBLIC
    ${CMAKE_BINARY_DIR}/include
    ${CMAKE_SOURCE_DIR}/include
)