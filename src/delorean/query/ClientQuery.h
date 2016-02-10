//
// Created by sebastian on 10/02/16.
//

#ifndef DELOREAN_CLIENTQUERY_H
#define DELOREAN_CLIENTQUERY_H

#include<string>
#include <commands/CommandSwitch.h>

class ClientQuery {

public:
    std::string executeQuery(std::string input, TemporalDatastore *temporalDatastore);

private:
    CommandSwitch commandSwitch;
};


#endif //DELOREAN_CLIENTQUERY_H
