/**
 * @file Lever.h
 * @author Noah O'Bryan
 *
 * The class that creates the lever component for the machine
 */

#ifndef CANADIANEXPERIENCE_LEVER_H
#define CANADIANEXPERIENCE_LEVER_H

#include "Component.h"
#include "RotationSource.h"
#include "INegotiator.h"
#include "RodSink.h"
#include "Rod.h"
#include "PointSource.h"

/**
 * The class that creates the lever component for the machine
 */
class Lever : public Component, public INegotiator {
private:

    /// Driving end of the lever
    int mDriveEnd;

    /// length of the lever
    int mLength;

    /// Rotation source for the lever
    RotationSource mRotationSource;

    /// Rod sink for the lever
    std::shared_ptr<RodSink> mRodSink;

    /// Point source for the lever
    PointSource mPointSource;

public:
    /// Default constructor
    Lever(int length);

    /// Copy constructor (disabled)
    Lever(const Lever &) = delete;

    /// Assignment operator
    void operator=(const Lever &) = delete;

    /**
     * Set the driving end of the lever, offset by the center point
     * @param point Offset from center of the lever
     */
    void SetDriveEnd(int point) { mDriveEnd = point; }

    /// Get a pointer to the source object
    /// @return Pointer to RotationSource object
    RotationSource *GetRotationSource() { return &mRotationSource; }

    /// Get a pointer to the source object
    /// @return Pointer to the PointSource object
    PointSource *GetPointSource() { return &mPointSource; }

    /// Get a pointer to the sink object
    /// @return Pointer to RodSink object
    std::shared_ptr<RodSink> GetRodSink() { return mRodSink; }

    void Negotiate(Rod *rod) override;
    void Draw(std::shared_ptr<wxGraphicsContext> graphics, double x, double y) override;
};

#endif //CANADIANEXPERIENCE_LEVER_H
