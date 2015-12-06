//
// Created by sebastian on 15/11/15.
//

#include "TemporalDatastore.h"

bool TemporalDatastore::create(const int id, const long ts, const std::string &data) {

    std::map<int, std::set<Observation>>::iterator bucket = _temporalDataStore.find(id);

    //create new bucket if it doesn't exist
    if(bucket == _temporalDataStore.end()) {
        std::set<std::string> newBucket;
        Observation observation;
        _temporalDataStore.insert(std::pair<int, std::set<std::string>>(, newBucket));
    }
    else {
        std::set<std::string> existingSet = bucket->second;
        existingSet.insert(data);
    }

    return 1;
}
