//
// Created by sebastian on 22/11/15.
//

#include <string>
#include "Command.h"

Command::Command(int id, long timestamp, std::string data) {
    _id = id;
    _timestamp = timestamp;
    _data = data;
}
