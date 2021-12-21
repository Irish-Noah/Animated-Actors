/**
 * @file MachineDrawable.h
 * @author Noah O'Bryan
 *
 * Encapsulating adapter class to bring MachineLib into CanadianExperienceLib
 */

#ifndef CANADIANEXPERIENCE_MACHINEDRAWABLE_H
#define CANADIANEXPERIENCE_MACHINEDRAWABLE_H

#include <machine-api.h>
#include "Drawable.h"

/**
 * Encapsulating adapter class to bring MachineLib into CanadianExperienceLib
 */
class MachineDrawable : public Drawable {
private:
    /// Machine object for the first machine that we want to bring into this library
    std::shared_ptr<Machine> mMachine1;

    /// Machine object for the second machine that we want to bring into this library
    std::shared_ptr<Machine> mMachine2;

    /// Pointer to the timeline object
    Timeline* mTimeline;

    /// Start frame of Machine one
    int mStartFrame1 = 0;

    /// Start frame of Machine two
    int mStartFrame2 = 0;

    /// Machine number for the first machine
    int mMachine1Num = 1;

    /// Machine number for the second machine
    int mMachine2Num = 2;

public:
    MachineDrawable(std::wstring imagesDir);
    void Draw(std::shared_ptr<wxGraphicsContext> graphics) override;
    bool HitTest(wxPoint pos) override;
    void SetTimeline(Timeline *timeline) override;

    /**
     * Get the machine number for the first machine on screen
     * @return mMachine1Num Number of the first machine
     */
    int GetMachineOneNum() { return mMachine1->GetMachineNumber(); }

    /**
     * Get the machine number for the second machine on screen
     * @return mMachine2Num Number of the second machine
     */
    int GetMachineTwoNum() { return mMachine2->GetMachineNumber(); }

    void Dialog1(wxWindow *parent);
    void Dialog2(wxWindow *parent);

    /**
     * Set the starting frame for the first machine
     * @param frame Starting frame for the first machine
     */
    void SetStartFrame1 (int frame) { mStartFrame1 = frame; }

    /**
     * Set the starting frame for the second machine
     * @param frame Starting frame for the second machine
     */
    void SetStartFrame2 (int frame) { mStartFrame2 = frame; }

    /**
     * Get the the starting frame for the first machine
     * @return mStartFrame1 Starting frame for the first machine
     */
    int GetStartFrame1 () { return mStartFrame1; }

    /**
     * Get the starting frame for the second machine
     * @return mStartingFrame2 Starting frame for the second machine
     */
    int GetStartFrame2 () { return mStartFrame2; }

    void SetMachineOneNum(int num);
    void SetMachineTwoNum(int num);
};

#endif //CANADIANEXPERIENCE_MACHINEDRAWABLE_H
