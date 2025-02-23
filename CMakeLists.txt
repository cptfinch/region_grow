cmake_minimum_required(VERSION 3.15)
project(region_grow 
    VERSION 1.0
    DESCRIPTION "Medical Image Region Analysis Tool"
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Directory structure organization
add_subdirectory(src)
add_subdirectory(apps)
add_subdirectory(tests)  # If adding proper tests