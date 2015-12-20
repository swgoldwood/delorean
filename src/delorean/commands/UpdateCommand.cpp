//
// Created by sebastian on 12/12/15.
//

#include "UpdateCommand.h"

UpdateCommand::UpdateCommand(const std::vector<std::string> &args) {
    validate(args);

    _id = std::stoi(args[1]);
    _ts = std::stol(args[2]);
    _data = args[3];
}

bool UpdateCommand::validate(const std::vector<std::string> &args) {
    if (args.size() != 4) {
        throw std::invalid_argument("UPDATE requires 3 args: <id> <ts> <data>");
    }

    return true;
}

Observation UpdateCommand::run(TemporalDatastore &temporalDatastore) {
    return temporalDatastore.update(_id, _ts, _data);
}

