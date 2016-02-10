//
// Created by sebastian on 13/12/15.
//

#ifndef DELOREAN_GETCOMMAND_H
#define DELOREAN_GETCOMMAND_H

#include <string>
#include "Command.h"

class GetCommand : public Command {

public:
    GetCommand(const std::vector<std::string> &args);

    virtual Observation run(TemporalDatastore *temporalDatastore);

protected:
    virtual bool validate(const std::vector<std::string> &args);

private:
    int _id;
    long _ts;
};

#endif //DELOREAN_GETCOMMAND_H
