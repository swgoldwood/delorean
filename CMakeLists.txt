cmake_minimum_required(VERSION 2.8)
project(delorean)

add_definitions(-std=c++11)
set(SOURCE_FILES src/delorean/main.cpp)
find_package (Threads)
SET(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-pthread")
add_executable(delorean_run ${SOURCE_FILES})
target_link_libraries (delorean_run ${CMAKE_THREAD_LIBS_INIT})

include_directories(src/delorean)
add_subdirectory(src/delorean)
add_subdirectory(test)

target_link_libraries(delorean_run delorean)