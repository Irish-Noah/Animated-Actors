/**
 * @file PointSource.cpp
 * @author Noah O'Bryan
 */

#include "pch.h"
#include "PointSource.h"

/**
 * Update all the sinks connect to this source
 * @param point New point for all the sinks
 */
void PointSource::UpdateSink(wxPoint point)
{
    for (auto sink : mSinks)
    {
        sink->UpdateComponent(point);
    }
}

/**
 * Add a sink for this source
 * @param sink Sink to be added
 */
void PointSource::AddSink(PointSink* sink)
{
    mSinks.push_back(sink);
}

