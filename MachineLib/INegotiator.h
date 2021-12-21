/**
 * @file INegotiator.h
 * @author Noah O'Bryan
 *
 * Negotiator interface for rod/piston and rod/lever negotiations
 */

#ifndef CANADIANEXPERIENCE_INEGOTIATOR_H
#define CANADIANEXPERIENCE_INEGOTIATOR_H

// Forward reference to the Rod class
class Rod;

/**
 * Negotiator interface for rod/piston and rod/lever negotiations
 */
class INegotiator
{
public:
    /**
     * Negotiate with a rod to come up with a mutual rotation solution
     * @param rod
     */
    virtual void Negotiate(Rod *rod) = 0;
};

#endif //CANADIANEXPERIENCE_INEGOTIATOR_H
