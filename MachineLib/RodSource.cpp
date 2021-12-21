/**
 * @file RodSource.cpp
 * @author Noah O'Bryan
 */

#include "pch.h"
#include "RodSource.h"

/**
 * Iterate over all sinks being driven by the rod source and negotiate their
 * positions with the Negotiate function
 * @param rod Rod that is the source for its sinks
 */
void RodSource::Negotiate(Rod *rod)
{
    for (auto sink : mSinks)
    {
        sink->Negotiate(rod);
    }
}
