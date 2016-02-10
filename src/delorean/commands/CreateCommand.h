//
// Created by sebastian on 15/11/15.
//

#ifndef DELOREAN_CREATE_COMMAND_H
#define DELOREAN_CREATE_COMMAND_H


#include "Command.h"

class CreateCommand : public Command {

public:
    CreateCommand(const std::vector<std::string> &args);

    virtual Observation run(TemporalDatastore *temporalDatastore);

protected:
    virtual bool validate(const std::vector<std::string> &args);

private:
    int _id;
    long _ts;
    std::string _data;
};


#endif //DELOREAN_CREATE_COMMAND_H
