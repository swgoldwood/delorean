//
// Created by sebastian on 10/02/16.
//

#include <iostream>
#include <sstream>
#include <vector>
#include <commands/Command.h>
#include <boost/algorithm/string.hpp>
#include "ClientQuery.h"

std::string ClientQuery::executeQuery(std::string input, TemporalDatastore *temporalDatastore) {
    std::stringstream msg;
    std::istringstream buffer(input);
    std::vector<std::string> args{std::istream_iterator<std::string>{buffer},
                                 std::istream_iterator<std::string>{}};

    try {
        std::unique_ptr<Command> command = std::unique_ptr<Command>(commandSwitch.getCommand(args));
        Observation observation = command->run(temporalDatastore);

        msg << "OK " << observation.getTs() << " " << observation.getData();
    }
    catch(std::invalid_argument e) {
        msg << "ERR " << e.what();
    }

    return msg.str();
}
