//
// Created by sebastian on 12/12/15.
//

#ifndef DELOREAN_UPDATECOMMAND_H
#define DELOREAN_UPDATECOMMAND_H

#include <string>
#include "Command.h"

class UpdateCommand : public Command {

public:
    UpdateCommand(const std::vector<std::string> &args);

    virtual Observation run(TemporalDatastore &temporalDatastore);

protected:
    virtual bool validate(const std::vector<std::string> &args);

private:
    int _id;
    long _ts;
    std::string _data;
};

#endif //DELOREAN_UPDATECOMMAND_H
