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
    Command(int id, long timestamp, std::string data);
    virtual bool run(TemporalDatastore &temporalDatastore, std::string &errmsg) = 0;

private:
    int _id;
    long _timestamp;
    std::string _data;
    std::vector<std::string> _args;
};

#endif //DELOREAN_COMMAND_H

