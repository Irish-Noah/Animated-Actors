/**
 * @file Arm.cpp
 * @author Noah O'Bryan
 */

#include "pch.h"
#include "Arm.h"

/**
 * Draw the arm using the Polygon class
 * @param graphics Graphics to be rendered
 * @param x X position of the machine
 * @param y Y position of the machine
 */
void Arm::Draw(std::shared_ptr<wxGraphicsContext> graphics, double x, double y)
{
    DrawPolygon(graphics, x + GetInputPoint().x, y + GetInputPoint().y);
}


/**
 * Set the rotation for the arm
 * @param rotation Rotation of the arm
 */
void Arm::SetRotation(double rotation)
{
    mRotation = rotation;
    Polygon::SetRotation(mRotation);
    double x = GetInputPoint().x + mLength * cos(mRotation * M_PI * 2);
    double y = GetInputPoint().y + mLength * sin(mRotation * M_PI * 2);
    mSource.UpdateSink(wxPoint(x,y));
}

/**
 * Constructor
 * @param length Length of the arm
 */
Arm::Arm(double length) : mLength(length)
{
    Rectangle(-mLength/(119/28)/2, mLength/(119/28)/2, mLength + 12, mLength/(119/28));
    mSink.SetComponent(this);
}