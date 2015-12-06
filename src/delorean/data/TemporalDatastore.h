//
// Created by sebastian on 15/11/15.
//

#ifndef DELOREAN_TEMPORAL_DATASTORE_H
#define DELOREAN_TEMPORAL_DATASTORE_H


#include <string>
#include <map>
#include <set>
#include "Observation.h"

class TemporalDatastore {

public:
    bool create(const int id, const long ts, const std::string &data);

private:
    std::map<int, std::set<Observation>> _temporalDataStore;
};


#endif //DELOREAN_TEMPORAL_DATASTORE_H
