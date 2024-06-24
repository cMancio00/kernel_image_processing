cmake_minimum_required(VERSION 3.28)
project(kernel_image_processing)

set(CMAKE_CXX_STANDARD 20)
set(INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
include_directories(${INCLUDE_DIR})

add_executable(kernel_image_processing main.cpp
        Image.h
        Image.cpp
        kernel.h
        convolution.h
        convolution.cpp
        kernel.cpp
)
