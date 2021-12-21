/**
 * @file RodSink.cpp
 * @author Noah O'Bryan
 */

#include "pch.h"
#include "RodSink.h"
#include "Component.h"
#include "Rod.h"
#include "INegotiator.h"

/**
 * Call the negotiator Interface class to negotiate components
 * @param rod Rod to be negotiated
 */
void RodSink::Negotiate(Rod* rod)
{
    mNegotiator->Negotiate(rod);
}
