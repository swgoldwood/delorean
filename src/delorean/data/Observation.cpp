//
// Created by sebastian on 29/11/15.
//

#include "Observation.h"

Observation::Observation(const long ts, const std::string data) {
    _ts = ts;
    _data = data;
}

std::string Observation::getData() const {
    return _data;
}

long Observation::getTs() const {
    return _ts;
}

bool Observation::operator<(const Observation &observation) const {
    if (_ts < observation.getTs()) {
        return true;
    }
    else {
        return false;
    }
}

