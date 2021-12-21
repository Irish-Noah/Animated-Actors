/**
 * @file PointSource.h
 * @author Noah O'Bryan
 *
 * Class that dictates how non-rotational sources drive
 * their sinks
 */

#ifndef CANADIANEXPERIENCE_POINTSOURCE_H
#define CANADIANEXPERIENCE_POINTSOURCE_H

#include "PointSink.h"
#include "Component.h"


/**
 * Class that dictates how non-rotational sources drive
 * their sinks
 */
class PointSource {
private:
    /// Position of the source object
    wxPoint mPosition;

    /// Sinks of this source
    std::vector<PointSink*> mSinks;

public:
    /// Default constructor
    PointSource() {}

    /// Copy constructor (disabled)
    PointSource(const PointSource &) = delete;

    /// Assignment operator
    void operator=(const PointSource &) = delete;

    /**
     * Get the position of this source
     * @return mPosition Position of this sink
     */
    wxPoint GetSourcePoint() { return mPosition; }
    void UpdateSink(wxPoint point);
    void AddSink(PointSink* sink);
};

#endif //CANADIANEXPERIENCE_POINTSOURCE_H
