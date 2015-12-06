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
        std::string inputString = inputHandler.getUserInput();

        if(inputString == "exit") {
            std::cout << "exiting..." << std::endl;
            break;
        }

        std::unique_ptr<Command> command = commandSwitch.getCommand(inputString);

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

