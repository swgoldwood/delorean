cmake_minimum_required(VERSION 3.3)
project(delorean)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES src/delorean/main.cpp src/delorean/InputHandler.h src/delorean/InputHandler.cpp src/delorean/Delorean.cpp src/delorean/Delorean.h src/delorean/commands/CommandSwitch.cpp src/delorean/commands/CommandSwitch.h src/delorean/commands/Command.h src/delorean/commands/CreateCommand.cpp src/delorean/commands/CreateCommand.h src/delorean/data/TemporalDatastore.cpp src/delorean/data/TemporalDatastore.h src/delorean/commands/Command.cpp src/delorean/data/Observation.cpp src/delorean/data/Observation.h)
add_executable(delorean ${SOURCE_FILES})