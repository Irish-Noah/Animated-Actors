/**
 * @file Arm.h
 * @author Noah O'Bryan
 *
 * The class that creates an arm component for the machine
 */

#ifndef CANADIANEXPERIENCE_ARM_H
#define CANADIANEXPERIENCE_ARM_H

#include "Component.h"
#include "RotationSink.h"
#include "PointSource.h"

/**
 * The class that creates an arm component for the machine
 */
class Arm : public Component {
private:
    /// Rotation sink for this component
    RotationSink mSink;

    /// rotation of arm
    double mRotation;

    /// length of the arm
    double mLength;

    /// Point Source for this component
    PointSource mSource;

public:

    Arm(double length);

    /// Copy constructor (disabled)
    Arm(const Arm &) = delete;

    /// Assignment operator
    void operator=(const Arm &) = delete;

    void SetRotation(double rotation) override;
    void Draw(std::shared_ptr<wxGraphicsContext> graphics, double x, double y) override;

    /// Get a pointer to the source object
    /// @return Pointer to RotationSource object
    RotationSink *GetSink() { return &mSink; }

    /// Get a pointer to the source object
    /// @return Pointer to RotationSource object
    PointSource *GetSource() { return &mSource; }
};

#endif //CANADIANEXPERIENCE_ARM_H
