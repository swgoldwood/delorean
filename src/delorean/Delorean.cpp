//
// Created by sebastian on 15/11/15.
//

#include "Delorean.h"
#include <boost/algorithm/string.hpp>

Delorean::Delorean() {
    inputHandler = InputHandler();
    commandSwitch = CommandSwitch();
    temporalDatastore = TemporalDatastore();
}

int Delorean::start() {
    while(true) {
        std::vector<std::string> args = inputHandler.getUserInput();

        if(args.size() == 1 && boost::to_upper_copy(args[0]) == "exit") {
            std::cout << "exiting..." << std::endl;
            break;
        }

        try {
            std::unique_ptr<Command> command = std::unique_ptr<Command>(commandSwitch.getCommand(args));
            Observation observation = command->run(temporalDatastore);

            std::cout << "OK " << observation.getTs() << " "
                      << observation.getData() << std::endl;
        }
        catch(std::invalid_argument e) {
            std::cout << "ERR " << e.what() << std::endl;
            continue;
        }
    }

    return 0;
}

