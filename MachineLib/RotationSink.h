/**
 * @file RotationSink.h
 * @author Noah O'Bryan
 *
 * Class that dictates how a rotational sink is driven by
 * their source
 */

#ifndef CANADIANEXPERIENCE_ROTATIONSINK_H
#define CANADIANEXPERIENCE_ROTATIONSINK_H

class Shape;
class Component;

/**
 * Class that dictates how a rotational sink is driven by
 * their source
 */
class RotationSink {
private:
    /// rotation of the sink before update
    double mRotation;

    /// Small adjustment value for calculating rotation among components
    double mPhase;

    /// Component that is a sink
    Component *mComponent;

    /// Speed of the sink
    double mSpeed = 1;

public:

    /// Default constructor
    RotationSink() {}

    /// Copy constructor (disabled)
    RotationSink(const RotationSink &) = delete;

    /// Assignment operator
    void operator=(const RotationSink &) = delete;

    void UpdateComponent(double rotation);

    /**
     * Set the component for this sink
     * @param component Sink component to be set
     */
    void SetComponent(Component *component) { mComponent = component; }

    /**
     * Get the component for this sink
     * @return Component that is a sink
     */
    Component* GetComponent() { return mComponent; }

    /**
     * Set the speed of the sink
     * @param speed Speed of the sink
     */
    void SetSpeed(double speed) { mSpeed = speed; }

    /**
     * Set the phase for this rotation sink (mostly used for gears)
     * @param phase Small amount to help mesh components together
     */
    void SetPhase(double phase) { mPhase = phase; }

};

#endif //CANADIANEXPERIENCE_ROTATIONSINK_H
