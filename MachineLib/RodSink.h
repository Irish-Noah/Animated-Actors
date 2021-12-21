/**
 * @file RodSink.h
 * @author Noah O'Bryan
 *
 * Class that dictates how a rod sink is driven by
 * their source
 */

#ifndef CANADIANEXPERIENCE_RODSINK_H
#define CANADIANEXPERIENCE_RODSINK_H

/// Forward references to Rod, Component, and INegotiator classes
class Rod;
class Component;
class INegotiator;

/**
 * Class that dictates how a rotational sink is driven by
 * their source
 */
class RodSink {
private:
    /// Component belonging to this sink
    Component *mComponent = nullptr;

    /// Pointer to the Negotiator Interface class
    INegotiator *mNegotiator;
public:
    /// Default constructor
    RodSink() {}

    /**
     * Constructor
     * @param component Component we are connected to.
     * @param negotiator The negotiator we will negotiate with
     */
    RodSink::RodSink(Component *component, INegotiator *negotiator) :
            mComponent(component), mNegotiator(negotiator)
    {
    }

    /// Copy constructor (disabled)
    RodSink(const RodSink &) = delete;

    /// Assignment operator
    void operator=(const RodSink &) = delete;

    /**
     * Set the component for this sink
     * @param component Component to be set for this sink
     */
    void SetComponent(Component *component) { mComponent = component; }

    void Negotiate(Rod *rod);
};

#endif //CANADIANEXPERIENCE_RODSINK_H
