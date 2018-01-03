cmake_minimum_required(VERSION 3.8)
project(region_grow)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        src/BinaryImage.cpp
        src/BinaryImage.h
        src/BinaryImage2.cpp
        src/BinaryImage2.h
        src/blob.cpp
        src/blob.h
        src/blobcounter.cpp
        src/histogram.cpp
        src/iBMPoBMP.cpp
        src/iBMPstream.cpp
        src/iBMPstream.h
        src/iBMPstreamRS1.cpp
        src/iBMPstreamRS1.h
        src/iPNMoBMP.cpp
        src/iPNMstream.cpp
        src/iPNMstream.h
        src/oBMPstream.cpp
        src/oBMPstream.h
        src/oBMPtest.cpp
        src/rgbpixel.cpp
        src/rgbpixel.h
        test/testing.cpp)

add_executable(region_grow ${SOURCE_FILES})