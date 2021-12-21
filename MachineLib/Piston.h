/**
 * @file Piston.h
 * @author Noah O'Bryan
 *
 * The class that creates a piston component for the machine
 */

#ifndef CANADIANEXPERIENCE_PISTON_H
#define CANADIANEXPERIENCE_PISTON_H

#include "Component.h"
#include "RodSink.h"
#include "INegotiator.h"
#include "Rod.h"

/**
 * The class that creates a piston component for the machine
 */
class Piston : public Component, public INegotiator {
private:
    /// is the piston horizontal?
    bool mIsHorizontal = false;

    /// opposite point from the origin on the piston
    wxPoint mOppositePoint;

    /// Pointer to RodSink for this piston
    std::shared_ptr<RodSink> mRodSink;

public:
    /// Default constructor
    Piston();

    /// Copy constructor (disabled)
    Piston(const Piston &) = delete;

    /// Assignment operator
    void operator=(const Piston &) = delete;

    /// Get a pointer to the sink object
    /// @return Pointer to RodSink object
    std::shared_ptr<RodSink> GetRodSink() { return mRodSink; }

    void Draw(std::shared_ptr<wxGraphicsContext> graphics, double x, double y) override;
    void Negotiate(Rod *rod) override;
};

#endif //CANADIANEXPERIENCE_PISTON_H
