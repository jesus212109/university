set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

cmake_minimum_required(VERSION 3.10)
project(Práctica1)
add_library(seller seller.cc seller.h)
target_link_libraries(seller PUBLIC person basket)
target_include_directories(seller PUBLIC ${CMAKE_CURRENT_LIST_DIR})

add_executable(seller-main seller-main.cc)
target_link_libraries(seller-main PUBLIC seller)