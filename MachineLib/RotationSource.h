/**
 * @file RotationSource.h
 * @author Noah O'Bryan
 *
 * Class that dictates how rotational sources drive
 * their sinks
 */

#ifndef CANADIANEXPERIENCE_ROTATIONSOURCE_H
#define CANADIANEXPERIENCE_ROTATIONSOURCE_H

#include "RotationSink.h"

/**
 * Class that dictates how rotational sources drive
 * their sinks
 */
class RotationSource {
private:
    /// rotation of the source object
    double mRotation;

    /// Sinks to this source
    std::vector<RotationSink*> mSinks;

public:
    /// Default constructor
    RotationSource() {}

    /// Copy constructor (disabled)
    RotationSource(const RotationSource &) = delete;
    
    /// Assignment operator
    void operator=(const RotationSource &) = delete;

    void UpdateSink(double rotation);
    void AddSink(RotationSink* sink);
};

#endif //CANADIANEXPERIENCE_ROTATIONSOURCE_H
