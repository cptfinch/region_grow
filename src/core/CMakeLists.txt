add_library(core_lib
    image_processing/BinaryImage.cpp
    io/bmp_stream.cpp
    io/pnm_stream.cpp
)

target_include_directories(core_lib PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/src/utils>
)

target_link_libraries(core_lib PUBLIC utils_lib)
