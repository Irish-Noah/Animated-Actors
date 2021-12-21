/**
 * @file Shape.h
 * @author Noah O'Bryan
 *
 * The class that creates a shape component for the machine
 */

#ifndef CANADIANEXPERIENCE_SHAPE_H
#define CANADIANEXPERIENCE_SHAPE_H

#include "Component.h"
#include "RotationSink.h"

/**
 * The class that creates a shape component for the machine
 */
class Shape : public Component {
private:
    /// Rotation sink for this component
    RotationSink mSink;

    /// rotation of shape
    double mRotation;
public:
    /// Default constructor (disabled)
    Shape() {mSink.SetComponent(this); }

    /// Copy constructor (disabled)
    Shape(const Shape &) = delete;

    /// Assignment operator
    void operator=(const Shape &) = delete;

    void SetRotation(double rotation) override;
    void Draw(std::shared_ptr<wxGraphicsContext> graphics, double x, double y) override;

    /// Get a pointer to the source object
    /// @return Pointer to RotationSource object
    RotationSink *GetSink() { return &mSink; }
};

#endif //CANADIANEXPERIENCE_SHAPE_H
