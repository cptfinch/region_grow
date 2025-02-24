add_library(utils_lib
    rgb_pixel.cpp
)

target_include_directories(utils_lib PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
)

target_link_libraries(utils_lib
    ${CMAKE_SOURCE_DIR}/src/core/core_lib
)

install(TARGETS core_lib utils_lib
    ARCHIVE DESTINATION lib
    LIBRARY DESTINATION lib
)

install(DIRECTORY include/ DESTINATION include)
