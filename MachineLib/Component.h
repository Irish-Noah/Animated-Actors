/**
 * @file Component.h
 * @author Noah O'Bryan
 *
 * Base class for all machine components
 */

#ifndef CANADIANEXPERIENCE_COMPONENT_H
#define CANADIANEXPERIENCE_COMPONENT_H

#include "Polygon.h"

/// Forward Reference to the ActualMachine class
class ActualMachine;

/**
 * Base class for all machine components
 */
class Component : public Polygon {
private:

    /// Position of component
    wxPoint mPosition;

    /// Rotation of component
    double mRotation;

    /// The machine using this component
    ActualMachine *mMachine = nullptr;

    /// time for rotation
    double mTime;

public:
    /// Default constructor
    Component() {};

    /// Copy constructor (disabled)
    Component(const Component &) = delete;

    /// Assignment operator
    void operator=(const Component &) = delete;

    /**
     * Set the rotation of the component
     * @param rotation New rotation for the component
     */
    virtual void SetRotation(double rotation) { mRotation = rotation; }

    /**
     * Get the rotation of the component
     * @return mRotation Rotation of the component
     */
    double GetInputRotation() { return mRotation; }

    /**
     * Set the position of the component
     * @param point New position of the component
     */
    virtual void SetPoint(wxPoint point) { mPosition = point; }

    /**
     * Get the position of the component
     * @return mPosition Get the position of the component
     */
    wxPoint GetInputPoint() { return mPosition; }

    /**
     * Set the component to the machine that owns it
     * @param machine Machine the component is a part of
     */
    void SetMachine(ActualMachine *machine) { mMachine = machine; }

    /**
     * Virtual function to set the time for components
     * @param time Time to be set
     */
    virtual void SetTime(double time) {mTime = time;}

    virtual void Draw(std::shared_ptr<wxGraphicsContext> graphics, double x, double y);
};

#endif //CANADIANEXPERIENCE_COMPONENT_H
