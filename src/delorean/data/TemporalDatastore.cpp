//
// Created by sebastian on 15/11/15.
//

#include "TemporalDatastore.h"

bool TemporalDatastore::create(const int id, const long ts, const std::string &data) {

    std::map<int, std::set<Observation>>::iterator bucket = _temporalDataStore.find(id);

    Observation observation(ts, data);

    //create new bucket if it doesn't exist
    if(bucket == _temporalDataStore.end()) {
        std::set<Observation> newBucket;
        newBucket.insert(observation);

        _temporalDataStore.insert(std::pair<int, std::set<Observation>>(id, newBucket));
    }
    else {
        std::set<Observation> existingSet = bucket->second;
        existingSet.insert(observation);
    }

    return 1;
}
