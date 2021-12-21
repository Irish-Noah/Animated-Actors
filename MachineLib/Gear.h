/**
 * @file Gear.h
 * @author Noah O'Bryan
 *
 * The class that creates a gear component for the machine
 */

#ifndef CANADIANEXPERIENCE_GEAR_H
#define CANADIANEXPERIENCE_GEAR_H

#include "Component.h"
#include "RotationSink.h"
#include "RotationSource.h"

/**
 * The class that creates a gear component for the machine
 */
class Gear : public Component {
private:
    /// Number of teeth the gear has
    int mNumTeeth;

    /// Small adjustment value for calculating
    double mPhase;

    /// Radius of the gear
    double mRadius;

    /// rotation of gear
    double mRotation;

    /// Rotation sink for this component
    RotationSink mSink;

    /// Rotation source for this component
    RotationSource mSource;

public:
    /// Default constructor
    Gear(double radius, int teeth);

    /// Copy constructor (disabled)
    Gear(const Gear &) = delete;

    /// Assignment operator
    void operator=(const Gear &) = delete;

    void Drive(std::shared_ptr<Gear> gear, double phase);
    void SetRotation(double rotation) override;
    void Draw(std::shared_ptr<wxGraphicsContext> graphics, double x, double y) override;

    /// Get a pointer to the source object
    /// @return Pointer to RotationSource object
    RotationSource *GetSource() { return &mSource; }

    /// Get a pointer to the source object
    /// @return Pointer to RotationSource object
    RotationSink *GetSink() { return &mSink; }
};

#endif //CANADIANEXPERIENCE_GEAR_H
