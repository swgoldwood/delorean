//
// Created by sebastian on 15/11/15.
//

#ifndef DELOREAN_COMMAND_SWITCH_H
#define DELOREAN_COMMAND_SWITCH_H

#include <string>
#include <memory>
#include "Command.h"

class CommandSwitch {

public:
    Command* getCommand(const std::vector<std::string> &args);
};

#endif //DELOREAN_COMMAND_SWITCH_H
