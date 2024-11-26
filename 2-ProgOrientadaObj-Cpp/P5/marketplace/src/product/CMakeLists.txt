set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

cmake_minimum_required(VERSION 3.10)
project(Práctica1)
add_library(product product.cc product.h)
target_include_directories(product PUBLIC ${CMAKE_CURRENT_LIST_DIR})

add_executable(product-main product-main.cc)
target_link_libraries(product-main PUBLIC product)