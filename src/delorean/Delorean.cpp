//
// Created by sebastian on 15/11/15.
//

#include "Delorean.h"

Delorean::Delorean() {
    inputHandler = InputHandler();
    commandSwitch = CommandSwitch();
    temporalDatastore = TemporalDatastore();
}

int Delorean::start() {
    while(true) {
        std::vector<std::string> args = inputHandler.getUserInput();

        if(args.size() > 0 && args[0] == "exit") {
            std::cout << "exiting..." << std::endl;
            break;
        }
        std::unique_ptr<Command> command = nullptr;

        try {
            command = commandSwitch.getCommand(args);
        }
        catch(std::invalid_argument e) {
            std::cout << "ERR " << e.what() << std::endl;
            continue;
        }

        std::string errmsg;
        if(command->run(temporalDatastore, errmsg)) {
            std::cout << "OK " << std::endl;
        }
        else {
            std::cout << "ERR " << errmsg << std::endl;
        }
    }

    return 0;
}

