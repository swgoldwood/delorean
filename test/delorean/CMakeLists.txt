include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(runDeloreanTests
        basic_check.cpp)

target_link_libraries(runDeloreanTests gtest gtest_main)
target_link_libraries(runDeloreanTests delorean)