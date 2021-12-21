/**
 * @file ActualMachine.cpp
 * @author Noah O'Bryan
 */

#include "pch.h"
#include "ActualMachine.h"
#include "NewMachine.h"

/**
 * Constructor
 */
ActualMachine::ActualMachine()
{
}


/**
 * Draw the machine at the currently specified location
 * @param graphics Graphics object to render in
 */
void ActualMachine::DrawMachine(std::shared_ptr<wxGraphicsContext> graphics, double x, double y)
{
    for (auto component : mComponentsInOrder)
    {
        component->Draw(graphics, x, y);
    }
}

/**
 * Add a component to this machine
 * and set the machine for the new component
 * @param component Component to add to the machine
 */
void ActualMachine::AddComponent(std::shared_ptr<Component> component)
{
    mComponentsInOrder.push_back(component);
    component->SetMachine(this);
}

/**
 * Set the time for the entire machine
 * Pass the time to the motor for the machine
 * @param time Time of the machine
 */
void ActualMachine::SetMachineTime(double time)
{
    mTime = time;
    if (mMotor != nullptr)
    {
        mMotor->SetTime(time);
    }
}



