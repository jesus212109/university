set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

cmake_minimum_required(VERSION 3.10)
project(Práctica1)
add_library(client client.cc client.h)
target_link_libraries(client PUBLIC person basket)
target_include_directories(client PUBLIC ${CMAKE_CURRENT_LIST_DIR})

add_executable(client-main client-main.cc)
target_link_libraries(client-main PUBLIC client)