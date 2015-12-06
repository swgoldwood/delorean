//
// Created by sebastian on 15/11/15.
//

#ifndef DELOREAN_DELOREAN_H
#define DELOREAN_DELOREAN_H

#include "InputHandler.h"
#include "commands/CommandSwitch.h"
#include "data/TemporalDatastore.h"

class Delorean {

public:
    Delorean();
    int start();

private:
    InputHandler inputHandler;
    CommandSwitch commandSwitch;
    TemporalDatastore temporalDatastore;
};

#endif //DELOREAN_DELOREAN_H
