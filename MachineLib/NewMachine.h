/**
 * @file NewMachine.h
 * @author Noah O'Bryan
 *
 * Derived class that represents a machine
 */

#ifndef CANADIANEXPERIENCE_NEWMACHINE_H
#define CANADIANEXPERIENCE_NEWMACHINE_H

#include "Machine.h"

class ActualMachine;

/**
 * Derived class that represents a machine
 */
class NewMachine : public Machine {
private:

    /// time in the animation
    double mTime;

    /// frame we are on
    int mFrame;

    /// frame rate of animation
    double mFrameRate;

    /// speed of the motor
    double mSpeed;

    /// location of the machine
    wxPoint mLocation;

    /// machine number
    int mNumber;

    /// machine we are pointing at
    std::shared_ptr<ActualMachine> mMachine;

    /// directory path to the image directory
    std::wstring mImagesDir;

public:
    /// Default constructor
    NewMachine(std::wstring imageDir);

    /// Destructor
    virtual ~NewMachine() = default;

    /// Copy constructor (disabled)
    NewMachine(const NewMachine &) = delete;

    /// Assignment operator
    void operator=(const NewMachine &) = delete;

    /**
     * Set the frame that the machine is on
     * @param frame New frame that the machine is on
     */
    void SetMachineFrame(int frame) override;

    /**
     * Set the frame rate for the machine
     * @param rate New framerate for the machine
     */
    void SetFrameRate(double rate) override { mFrameRate = rate; }

    /**
     * Set the machine number
     * @param machine The number of the machine
     */
    void SetMachineNumber(int machine) override;

    /**
     * Get the number of the machine
     * @return mNumber Number of the machine
     */
    int GetMachineNumber() override { return mNumber; }

    /**
     * Set the location of the speed
     * @param location New location of the machine
     */
    void SetLocation(wxPoint location) override { mLocation = location; }

    /**
     * Get the location of the machine
     * @return mLocation location of the machine
     */
    wxPoint GetLocation() override { return mLocation; }

    /**
    * Set the speed of the machine
    * @param speed Speed from -1 to 1, where 1 is full speed
    */
    void SetSpeed(double speed) override;

    /**
     * Get the running time of the machine
     * @return mTime Running time of the machine
     */
    double GetMachineTime() override { return mTime; }

    void DrawMachine(std::shared_ptr<wxGraphicsContext> graphics) override;
};

#endif //CANADIANEXPERIENCE_NEWMACHINE_H
