/**
 * @file RotationSource.cpp
 * @author Noah O'Bryan
 */

#include "pch.h"
#include "RotationSource.h"

/**
 * Update all the sinks connected to this source
 * @param rotation New rotation for all the sinks
 */
void RotationSource::UpdateSink(double rotation)
{
    for (auto sink : mSinks)
    {
        sink->UpdateComponent(rotation);
    }
}

/**
 * Add a sink to the for this source
 * @param sink Sink to be added
 */
void RotationSource::AddSink(RotationSink* sink)
{
    mSinks.push_back(sink);
}
