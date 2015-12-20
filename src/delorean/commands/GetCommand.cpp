//
// Created by sebastian on 13/12/15.
//

#include "GetCommand.h"

GetCommand::GetCommand(const std::vector<std::string> &args) {
    validate(args);

    _id = std::stoi(args[1]);
    _ts = std::stol(args[2]);
}

bool GetCommand::validate(const std::vector<std::string> &args) {
    if (args.size() != 3) {
        throw std::invalid_argument("GET requires 2 args: <id> <ts>");
    }

    return true;
}

Observation GetCommand::run(TemporalDatastore &temporalDatastore) {
    return temporalDatastore.get(_id, _ts);
}
