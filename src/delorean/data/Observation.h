//
// Created by sebastian on 29/11/15.
//

#ifndef DELOREAN_OBSERVATION_H
#define DELOREAN_OBSERVATION_H

#include<string>

class Observation {

public:
    Observation(const long ts, const std::string data);

    std::string getData() const;

    long getTs() const;

    bool operator< (const Observation&) const;
    //bool operator< (const Observation&, const Observation&) const;

private:
    long _ts;
    std::string _data;

};


#endif //DELOREAN_OBSERVATION_H
