/**
 * @file Motor.cpp
 * @author Noah O'Bryan
 */

#include "pch.h"
#include "Motor.h"

/**
 * Constructor
 * @param imageDir ImageDirectory in the working directory
 */
Motor::Motor(std::wstring imageDir) : mImagesDir(imageDir)
{
    // Create the shaft of the motor
    CenteredSquare(75);
    //SetPosition(wxPoint(120,-90));
    SetImage(mImagesDir + L"/electric-wheel.png");

    // Create the body of the motor
    mBody.Rectangle(-50, 50, 100, 100);
    mBody.SetImage(mImagesDir + L"/motor-frame.png");
}

/**
 * Draw the motor body and shaft
 * @param graphics Graphics to be rendered
 * @param x X location of the machine
 * @param y Y location of the machine
 */
void Motor::Draw(std::shared_ptr<wxGraphicsContext> graphics, double x, double y)
{
    Component::Draw(graphics, x, y);
    mBody.DrawPolygon(graphics, x + GetInputPoint().x, y + GetInputPoint().y);
    SetRotation(mRps * mTime);
}

/**
 * Set the time for the motor
 * @param time New time for the motor
 */
void Motor::SetTime(double time)
{
    Component::SetTime(time);
    mTime = time;
}

/**
 * Set the new rotation for the motor
 * @param rotation Rotation of the motor
 */
void Motor::SetRotation(double rotation)
{
    mRotation = rotation;
    Polygon::SetRotation(mRotation);
    mSource.UpdateSink(rotation);
}
