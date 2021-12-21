/**
 * @file RodSource.h
 * @author Noah O'Bryan
 *
 * Class that dictates how rod-based sources drive
 * their sinks
 */

#ifndef CANADIANEXPERIENCE_RODSOURCE_H
#define CANADIANEXPERIENCE_RODSOURCE_H

#include "RodSink.h"

/**
 * Class that dictates how rod-based sources drive
 * their sinks
 */
class RodSource {
private:
    /// vector of sinks that are to be driven by this source
    std::vector<std::shared_ptr<RodSink>> mSinks;

public:
    /// Default constructor
    RodSource() {}

    /// Copy constructor (disabled)
    RodSource(const RodSource &) = delete;

    /// Assignment operator
    void operator=(const RodSource &) = delete;

    /**
     * Add a sink to the vector of sinks that this source drives
     * @param sink Sink that is being driven by this source
     */
    void AddSink(std::shared_ptr<RodSink> sink) { mSinks.push_back(sink); }

    void Negotiate(Rod *rod);
};

#endif //CANADIANEXPERIENCE_RODSOURCE_H
