//
// Created by sebastian on 15/11/15.
//

#include <memory>
#include "CommandSwitch.h"
#include "CreateCommand.h"
#include "UpdateCommand.h"
#include "LatestCommand.h"
#include "GetCommand.h"
#include "DeleteCommand.h"
#include <boost/algorithm/string.hpp>

Command* CommandSwitch::getCommand(const std::vector<std::string> &args) {

    if(args.size() == 0) {
        throw std::invalid_argument("At least 1 argument required");
    }

    const std::string commandType = boost::to_upper_copy<std::string>(args[0]);

    Command* cmd = nullptr;

    if(commandType == "CREATE") {
        cmd = new CreateCommand(args);
    }
    else if(commandType == "UPDATE") {
        cmd = new UpdateCommand(args);
    }
    else if(commandType == "GET") {
        cmd = new GetCommand(args);
    }
    else if(commandType == "LATEST") {
        cmd = new LatestCommand(args);
    }
    else if(commandType == "DELETE") {
        cmd = new DeleteCommand(args);
    }
    else {
        throw std::invalid_argument("'" + commandType + "' is not a valid command");
    }

    return cmd;
}
