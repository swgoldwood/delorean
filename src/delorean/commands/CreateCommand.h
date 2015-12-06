//
// Created by sebastian on 15/11/15.
//

#ifndef DELOREAN_CREATE_COMMAND_H
#define DELOREAN_CREATE_COMMAND_H


#include "Command.h"

class CreateCommand : public Command {

public:
    CreateCommand(int id, long timestamp, std::string data);

    virtual bool run(TemporalDatastore &temporalDatastore, std::string &errmsg);

};


#endif //DELOREAN_CREATE_COMMAND_H
