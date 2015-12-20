//
// Created by sebastian on 15/11/15.
//

#include <iostream>
#include "CreateCommand.h"

CreateCommand::CreateCommand(const std::vector<std::string> &args): Command() {
    validate(args);

    _id = std::stoi(args[1]);
    _ts = std::stol(args[2]);
    _data = args[3];
}

bool CreateCommand::validate(const std::vector<std::string> &args) {
    if (args.size() != 4) {
        throw std::invalid_argument("CREATE requires 3 args: <id> <ts> <data>");
    }

    return true;
}

Observation CreateCommand::run(TemporalDatastore &temporalDatastore) {
    return temporalDatastore.create(_id, _ts, _data);
}
