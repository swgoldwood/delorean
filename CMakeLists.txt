cmake_minimum_required(VERSION 2.8)
project(delorean)

add_definitions(-std=c++11)
set(SOURCE_FILES src/delorean/main.cpp)
add_executable(delorean_run ${SOURCE_FILES})

include_directories(src/delorean)
add_subdirectory(src/delorean)
add_subdirectory(test)

target_link_libraries(delorean_run delorean)