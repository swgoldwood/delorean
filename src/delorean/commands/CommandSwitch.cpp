//
// Created by sebastian on 15/11/15.
//

#include <memory>
#include "CommandSwitch.h"
#include "CreateCommand.h"

std::unique_ptr<Command> CommandSwitch::getCommand(const std::string &inputString) {
    std::unique_ptr<Command> cmd( new CreateCommand(1,2l,"hello") );
    return cmd;
}
