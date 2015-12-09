cmake_minimum_required(VERSION 3.3)
project(delorean)

add_definitions(-std=c++11)

set(HEADER_FILES
        Delorean.h
        InputHandler.h
        commands/Command.h
        commands/CommandSwitch.h
        commands/CreateCommand.h
        commands/LatestCommand.h
        data/Observation.h
        data/TemporalDatastore.h
        )

set(SOURCE_FILES
        Delorean.cpp
        InputHandler.cpp
        commands/Command.cpp
        commands/CommandSwitch.cpp
        commands/CreateCommand.cpp
        commands/LatestCommand.cpp
        data/Observation.cpp
        data/TemporalDatastore.cpp
        )

add_library(delorean STATIC ${SOURCE_FILES} ${HEADER_FILES})