//
// Created by sebastian on 15/11/15.
//

#include <iostream>
#include "CreateCommand.h"

bool CreateCommand::run(TemporalDatastore &temporalDatastore, std::string &errmsg) {
    errmsg = "CreateCommand: Not implemented yet";

    return temporalDatastore.create(1,1.0, "data");
}

CreateCommand::CreateCommand(int id, long timestamp, std::string data): Command(id, timestamp, data) {

}
