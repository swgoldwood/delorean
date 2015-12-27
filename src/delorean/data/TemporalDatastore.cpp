//
// Created by sebastian on 15/11/15.
//

#include "TemporalDatastore.h"

#include<sstream>
#include <iostream>

Observation TemporalDatastore::create(const int id, const long ts, const std::string &data) {
    std::map<int, std::set<Observation>*>::iterator bucket = _temporalDataStore.find(id);
    Observation observation(ts, data);

    //only create new bucket if it doesn't already exist
    if(bucket == _temporalDataStore.end()) {
        std::set<Observation>* newBucket = new std::set<Observation>();
        newBucket->insert(observation);

        _temporalDataStore.insert(std::pair<int, std::set<Observation>*>(id, newBucket));
    }
    else {
        std::stringstream msg;
        msg << "Bucket for id '" << id << "' already exists";
        throw std::invalid_argument(msg.str());
    }

    return observation;
}

Observation TemporalDatastore::update(const int id, const long ts, const std::string &data) {
    std::map<int, std::set<Observation>*>::iterator bucket = _temporalDataStore.find(id);
    Observation observation(ts, data);

    if(bucket == _temporalDataStore.end()) {
        std::stringstream msg;
        msg << "Bucket for id '" << id << "' doesn't exist";
        throw std::invalid_argument(msg.str());
    }
    else {
        std::set<Observation>* existingBucket = bucket->second;
        std::set<Observation>::iterator existingObservation = existingBucket->find(observation);

        if(existingObservation != existingBucket->end()) {
            existingBucket->erase(existingObservation);
        }

        existingBucket->insert(observation);
    }

    return observation;
}

Observation TemporalDatastore::latest(const int id) const {
    std::map<int, std::set<Observation>*>::const_iterator bucket = _temporalDataStore.find(id);

    if(bucket == _temporalDataStore.end()) {
        std::stringstream msg;
        msg << "Bucket for id '" << id << "' doesn't exist";
        throw std::invalid_argument(msg.str());
    }
    else {
        std::set<Observation>* existingBucket = bucket->second;

        if(existingBucket->empty()) {
            std::stringstream msg;
            msg << "No data found for id '" << id << "'. Bucket is empty.";
            throw std::invalid_argument(msg.str());
        }

        Observation observation = *existingBucket->rbegin();

        return observation;
    }
}

Observation TemporalDatastore::get(const int id, const long ts) const {
    std::map<int, std::set<Observation>*>::const_iterator bucket = _temporalDataStore.find(id);

    if(bucket == _temporalDataStore.end()) {
        std::stringstream msg;
        msg << "Bucket for id '" << id << "' doesn't exist";
        throw std::invalid_argument(msg.str());
    }

    std::set<Observation>* bucketSet = bucket->second;

    if(bucketSet->empty()) {
        std::stringstream msg;
        msg << "No data found for id '" << id << "' and ts '" << ts << "'. Bucket is empty.";
        throw std::invalid_argument(msg.str());
    }

    std::set<Observation>::const_iterator observationIt = bucketSet->upper_bound(Observation(ts, ""));

    if(observationIt == bucketSet->begin()) {
        if(observationIt->getTs() <= ts) {
            return *observationIt;
        }
        else {
            std::stringstream msg;
            msg << "No data found for id '" << id << "' and ts '" << ts << "'";
            throw std::invalid_argument(msg.str());
        }
    }
    else {
        return *(--observationIt);
    }
}

Observation TemporalDatastore::remove(const int id, const long ts) {
    std::map<int, std::set<Observation>*>::const_iterator bucket = _temporalDataStore.find(id);

    if(bucket == _temporalDataStore.end()) {
        std::stringstream msg;
        msg << "Bucket for id '" << id << "' doesn't exist";
        throw std::invalid_argument(msg.str());
    }

    std::set<Observation>* bucketSet = bucket->second;
    std::set<Observation>::reverse_iterator observationIt = bucketSet->rbegin();

    while(observationIt != bucketSet->rend()) {
        if(observationIt->getTs() <= ts) {
            return *(std::next(observationIt).base());
        }
        else {
            bucketSet->erase(std::next(observationIt).base());
        }
    }

    std::stringstream msg;
    msg << "No data found for id '" << id << "' and ts <= '" << ts << "'";
    throw std::invalid_argument(msg.str());
}
