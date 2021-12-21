/**
 * @file ActualMachine.h
 * @author Noah O'Bryan
 *
 * Class to represent a machine
 */

#ifndef CANADIANEXPERIENCE_ACTUALMACHINE_H
#define CANADIANEXPERIENCE_ACTUALMACHINE_H

#include "Component.h"
#include "Motor.h"

// Forward reference to NewMachine class
class NewMachine;

/**
 * Class to draw a machine
 */
class ActualMachine {
private:
    /// Time in the animation
    double mTime;

    /// Location of the machine
    wxPoint mLocation;

    /// Machine number
    int mNumber;

    /// The drawables in drawing order
    std::vector<std::shared_ptr<Component>> mComponentsInOrder;

    /// The motor component for the entire machine
    std::shared_ptr<Motor> mMotor = nullptr;

    /// Speed of the machine
    double mSpeed;

public:
    ActualMachine();

    /// Copy constructor (disabled)
    ActualMachine(const ActualMachine &) = delete;

    /// Assignment operator
    void operator=(const ActualMachine &) = delete;

    void DrawMachine(std::shared_ptr<wxGraphicsContext> graphics, double x, double y);
    void AddComponent(std::shared_ptr<Component> component);

    /**
     * Set the number of the machine
     * @param number New number of the machine
     */
    void SetMachineNumber(int number) { mNumber = number; }

    /**
     * Get the number of the machine
     * @return mNumber Number of the machine
     */
    int GetMachineNumber() const { return mNumber; }

    /**
     * Set the animation time for the machine
     * @param time Time in the animation
     */
    void SetMachineTime(double time);

    /**
     * Get the time for the machine
     * @return mTime Time of the machine
     */
    double GetTime() const { return mTime; }

    /**
     * Set the motor that drives the machine
     * @param motor Motor object that moves the machine
     */
    void SetMotor(std::shared_ptr<Motor> motor) { mMotor = motor; }

    /**
     * Set the speed of the machine
     * @param speed New speed to be set
     */
    void SetSpeed(double speed) { mSpeed = speed; }

};

#endif //CANADIANEXPERIENCE_ACTUALMACHINE_H
