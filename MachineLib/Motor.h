/**
 * @file Motor.h
 * @author Noah O'Bryan
 *
 * The class that creates the Motor component object
 */

#ifndef CANADIANEXPERIENCE_MOTOR_H
#define CANADIANEXPERIENCE_MOTOR_H

#include "Component.h"
#include "RotationSource.h"

/**
 * The class that creates the Motor component object
 */
class Motor : public Component {
private:
    /// speed of the motor in revolutions per second
    double mRps;

    /// is the motor on
    bool mIsOn = false;

    /// time of the motor
    double mTime;

    /// body of the motor
    Polygon mBody;

    /// Image directory
    std::wstring mImagesDir;

    /// Center point for the
    wxPoint mLocation;

    /// Rotation of the motor
    double mRotation;

    /// Rotation source for this component
    RotationSource mSource;

public:
    /// Default constructor (disabled)
    Motor(std::wstring imageDir);

    /// Copy constructor (disabled)
    Motor(const Motor &) = delete;

    /// Assignment operator
    void operator=(const Motor &) = delete;

    /**
     * Set the time
     * @param time Time to be set
     */
    void SetTime(double time);

    /**
     * Set the speed of the motor
     * @param speed New speed based on time
     */
    void SetSpeed(double speed) { mRps = speed; }

    /**
     * Set the new center point for the motor
     * @param position New center point
     */
    void SetPosition(wxPoint position) { mLocation = position; }

    /// Get a pointer to the source object
    /// @return Pointer to RotationSource object
    RotationSource *GetSource() { return &mSource; }

    void Draw(std::shared_ptr<wxGraphicsContext> graphics, double x, double y) override;
    void SetRotation(double rotation) override;
};

#endif //CANADIANEXPERIENCE_MOTOR_H
