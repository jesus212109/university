set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

cmake_minimum_required(VERSION 3.10)
project(Práctica1)
add_library(person person.cc person.h)
target_include_directories(person PUBLIC ${CMAKE_CURRENT_LIST_DIR})

add_executable(person-main person-main.cc)
target_link_libraries(person-main PUBLIC person)