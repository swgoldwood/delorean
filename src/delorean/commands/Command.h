//
// Created by sebastian on 15/11/15.
//

#ifndef DELOREAN_COMMAND_H
#define DELOREAN_COMMAND_H

#include "../data/TemporalDatastore.h"

#include <string>
#include <vector>

class Command {

public:
    virtual Observation run(TemporalDatastore &temporalDatastore) = 0;

protected:
    virtual bool validate(const std::vector<std::string> &args) = 0;
};

#endif //DELOREAN_COMMAND_H

