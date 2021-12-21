/**
 * @file PointSink.h
 * @author Noah O'Bryan
 *
 * Class that dictates how non-rotational sink is driven by
 * their source
 */

#ifndef CANADIANEXPERIENCE_POINTSINK_H
#define CANADIANEXPERIENCE_POINTSINK_H

/// Forward reference to the Component class
class Component;

/**
 * Class that dictates how a rotational sink is driven by
 * their source
 */
class PointSink {
private:
    /// Point of the sink
    wxPoint mPosition;

    /// Component that is a sink
    Component *mComponent;

public:
    /// Default constructor
    PointSink() {}

    /// Copy constructor (disabled)
    PointSink(const PointSink &) = delete;

    /// Assignment operator
    void operator=(const PointSink &) = delete;

    void UpdateComponent(wxPoint point);

    /**
     * Set the component for this sink
     * @param component Component to be assigned to this sink
     */
    void SetComponent(Component *component) { mComponent = component; }

    /**
     * Get the component belonging to this sink
     * @return mComponent Component object assigned to this sink
     */
    Component* GetComponent() { return mComponent; }
};

#endif //CANADIANEXPERIENCE_POINTSINK_H
