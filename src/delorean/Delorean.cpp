//
// Created by sebastian on 15/11/15.
//

#include "Delorean.h"
#include <boost/algorithm/string.hpp>
#include <thread>
#include <network/Server.h>
#include <query/ClientQuery.h>

Delorean::Delorean() {
    commandSwitch = CommandSwitch();
    temporalDatastore = TemporalDatastore();
}

void startServer(TemporalDatastore *temporalDatastore) {
    Server server;
    server.start(temporalDatastore);
}

int Delorean::start() {

    std::thread t1 (startServer, &temporalDatastore);

    ClientQuery clientQuery;
    while(true) {
        std::string input;

        if(!std::getline(std::cin, input) || boost::to_upper_copy(input) == "exit") {
            std::cout << "exiting..." << std::endl;
            break;
        }

        std::string result = clientQuery.executeQuery(input, &temporalDatastore);
        std::cout << result << std::endl;
    }

    return 0;
}

