//
// Created by sebastian on 15/11/15.
//

#include <memory>
#include "CommandSwitch.h"
#include "CreateCommand.h"
#include <boost/algorithm/string.hpp>

std::unique_ptr<Command> CommandSwitch::getCommand(std::vector<std::string> &args) {

    if(args.size() == 0) {
        throw std::invalid_argument("At least 1 argument required");
    }

    const std::string commandType = boost::to_upper_copy<std::string>(args[0]);

    std::unique_ptr<Command> cmd = nullptr;

    if(commandType == "CREATE") {
        cmd = std::unique_ptr<Command>(new CreateCommand(1, 2l, "hello"));
    }
    else {
        throw std::invalid_argument("'" + commandType + "' is not a valid command");
    }

    return cmd;
}
