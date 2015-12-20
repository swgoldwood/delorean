//
// Created by sebastian on 09/12/15.
//

#ifndef DELOREAN_LATESTCOMMAND_H
#define DELOREAN_LATESTCOMMAND_H

#include <string>
#include "Command.h"

class LatestCommand : public Command {

public:
    LatestCommand(const std::vector<std::string> &args);

    virtual Observation run(TemporalDatastore &temporalDatastore);

protected:
    virtual bool validate(const std::vector<std::string> &args);

private:
    int _id;
};


#endif //DELOREAN_LATESTCOMMAND_H
