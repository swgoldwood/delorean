cmake_minimum_required(VERSION 2.8)
project(delorean)

add_definitions(-std=c++11)

set(HEADER_FILES
        Delorean.h
        commands/Command.h
        commands/CommandSwitch.h
        commands/CreateCommand.h
        commands/LatestCommand.h
        commands/UpdateCommand.h
        commands/GetCommand.h
        commands/DeleteCommand.h
        data/Observation.h
        data/TemporalDatastore.h
        network/Server.h
        query/ClientQuery.h
        )

set(SOURCE_FILES
        Delorean.cpp
        commands/CommandSwitch.cpp
        commands/CreateCommand.cpp
        commands/LatestCommand.cpp
        commands/UpdateCommand.cpp
        commands/GetCommand.cpp
        commands/DeleteCommand.cpp
        data/Observation.cpp
        data/TemporalDatastore.cpp
        network/Server.cpp
        query/ClientQuery.cpp
        )

add_library(delorean STATIC ${SOURCE_FILES} ${HEADER_FILES})