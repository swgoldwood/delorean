//
// Created by sebastian on 29/11/15.
//

#ifndef DELOREAN_OBSERVATION_H
#define DELOREAN_OBSERVATION_H

#include<string>

class Observation {
private:
    long _ts;
    std::string data;

public:
    Observation(long ts, std::string data);

    std::string getData() const;

    long getTs() const;

    bool std::operator< (const Observation) const;
};


#endif //DELOREAN_OBSERVATION_H
