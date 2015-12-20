//
// Created by sebastian on 09/12/15.
//

#include "LatestCommand.h"

LatestCommand::LatestCommand(const std::vector<std::string> &args) {
    validate(args);

    _id = std::stoi(args[1]);
}

bool LatestCommand::validate(const std::vector<std::string> &args) {
    if(args.size() != 2) {
        throw std::invalid_argument("LATEST requires 1 arg: <id>");
    }

    return true;
}

Observation LatestCommand::run(TemporalDatastore &temporalDatastore) {
    return temporalDatastore.latest(_id);
}

