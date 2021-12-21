/**
 * @file NewMachine.cpp
 * @author Noah O'Bryan
 */

#include "pch.h"
#include "NewMachine.h"
#include "ActualMachine.h"
#include "MachineOneFactory.h"
#include "MachineTwoFactory.h"

/**
 * Constructor
 * @param imageDir Image directory
 */
NewMachine::NewMachine(std::wstring imageDir) : mImagesDir(imageDir)
{
    MachineOneFactory machineFactory;
    mMachine = machineFactory.Create(mImagesDir);
    mNumber = 1;
}

/**
 * Draw the machine
 * @param graphics Graphics to be rendered
 */
void NewMachine::DrawMachine(std::shared_ptr<wxGraphicsContext> graphics)
{
    mMachine->DrawMachine(graphics, mLocation.x, mLocation.y);
}

/**
 * Set the number of the machine
 * @param machine
 */
void NewMachine::SetMachineNumber(int machine)
{
    if (machine == 1)
    {
        MachineOneFactory machineFactory;
        mMachine = machineFactory.Create(mImagesDir);
        mNumber = 1;
    }
    if (machine == 2)
    {
        MachineTwoFactory machineFactory;
        mMachine = machineFactory.Create(mImagesDir);
        mNumber = 2;
    }
}

/**
 * Calculate the time of the machine and pass it to the ActualMachine
 * @param frame Frame in the timeline
 */
void NewMachine::SetMachineFrame(int frame)
{
    mTime = double(frame) / mFrameRate * mSpeed;
    mMachine->SetMachineTime(mTime);
}

/**
 * Set the speed of the machine
 * @param speed Speed to be set
 */
void NewMachine::SetSpeed(double speed)
{
    mSpeed = speed;
}
