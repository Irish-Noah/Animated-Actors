/**
 * @file PointSink.cpp
 * @author Noah O'Bryan
 */

#include "pch.h"
#include "PointSink.h"
#include "Component.h"

/**
 * Update the position of this sink
 * @param point New position of the sink component
 */
void PointSink::UpdateComponent(wxPoint point)
{
    GetComponent()->SetPoint(point);
}