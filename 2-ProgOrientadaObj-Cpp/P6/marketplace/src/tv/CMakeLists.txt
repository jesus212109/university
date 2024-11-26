set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

cmake_minimum_required(VERSION 3.10)
project(Práctica1)
add_library(tv tv.cc tv.h)
target_link_libraries(tv PUBLIC product)
target_include_directories(tv PUBLIC ${CMAKE_CURRENT_LIST_DIR})

add_executable(tv-main tv-main.cc)
target_link_libraries(tv-main PUBLIC tv)