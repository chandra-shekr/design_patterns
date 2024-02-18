cmake_minimum_required(VERSION 3.22.1)
list(INSERT CMAKE_MODULE_PATH 0 ${CMAKE_SOURCE_DIR}/cmake)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
set(CODE_SOURCE 
    ${CMAKE_SOURCE_DIR}/src
)


enable_testing()
include(test)