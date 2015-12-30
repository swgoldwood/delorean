//
// Created by sebastian on 15/11/15.
//

#ifndef DELOREAN_TEMPORAL_DATASTORE_H
#define DELOREAN_TEMPORAL_DATASTORE_H


#include <string>
#include <map>
#include <set>
#include <mutex>
#include <memory>
#include "Observation.h"

class TemporalDatastore {

public:
    Observation create(const int id, const long ts, const std::string &data);
    Observation update(const int id, const long ts, const std::string &data);
    Observation get(const int id, const long ts) const;
    Observation latest(const int id) const;
    Observation remove(const int id, const long ts);

private:
    std::map<int, std::set<Observation>*> _temporalDataStore;
    std::map<int, std::mutex*> _bucketMutexes;
};


#endif //DELOREAN_TEMPORAL_DATASTORE_H
