//
// Created by sebastian on 27/12/15.
//

#ifndef DELOREAN_DELETECOMMAND_H
#define DELOREAN_DELETECOMMAND_H

#include "Command.h"

class DeleteCommand : public Command {

public:
    DeleteCommand(const std::vector<std::string> &args);

    virtual Observation run(TemporalDatastore &temporalDatastore);

protected:
    virtual bool validate(const std::vector<std::string> &args);

private:
    int _id;
    long _ts;
};

#endif //DELOREAN_DELETECOMMAND_H
