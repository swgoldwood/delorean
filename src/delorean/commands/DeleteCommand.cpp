//
// Created by sebastian on 27/12/15.
//

#include "DeleteCommand.h"

DeleteCommand::DeleteCommand(const std::vector<std::string> &args) {
    validate(args);

    _id = std::stoi(args[1]);
    _ts = std::stol(args[2]);
}

bool DeleteCommand::validate(const std::vector<std::string> &args) {
    if (args.size() != 3) {
        throw std::invalid_argument("DELETE requires at least 2 arg: <id> <ts>");
    }

    return true;
}

Observation DeleteCommand::run(TemporalDatastore &temporalDatastore) {
    return temporalDatastore.remove(_id, _ts);
}
