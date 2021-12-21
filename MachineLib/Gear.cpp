/**
 * @file Gear.cpp
 * @author Noah O'Bryan
 */

#include "pch.h"
#include "Gear.h"

const double ToothDepth = 5;     ///< Depth of a tooth in pixels
const double ToothWidth = 0.33;  ///< Width of a tooth at the top as fraction of tooth pitch
const double ToothSlope = 0.1;   ///< Fraction of pitch where the tooth slopes up or down
const double PI2 = M_PI * 2;   ///< PI * 2 constant


/**
 * Draw the shape using the Polygon class
 * @param graphics Graphics to be rendered
 * @param x X position of the machine
 * @param y Y position of the machine
 */
void Gear::Draw(std::shared_ptr<wxGraphicsContext> graphics, double x, double y)
{
    double toothStart = 1.0 - ToothWidth - ToothSlope * 2;
    double innerRadius = mRadius - ToothDepth;

    for (int t = 0; t < mNumTeeth; t++)
    {
        double angle1 = double(t) / double(mNumTeeth) * PI2;
        double angle2 = double(t + toothStart) / double(mNumTeeth) * PI2;
        double angle3 = double(t + toothStart + ToothSlope) / double(mNumTeeth) * PI2;
        double angle4 = double(t + toothStart + ToothSlope + ToothWidth) / double(mNumTeeth) * PI2;
        double angle5 = double(t + toothStart + ToothSlope * 2 + ToothWidth) / double(mNumTeeth) * PI2;

        AddPoint(innerRadius * cos(angle1), innerRadius * sin(angle1));
        AddPoint(innerRadius * cos(angle2), innerRadius * sin(angle2));
        AddPoint(mRadius * cos(angle3), mRadius * sin(angle3));
        AddPoint(mRadius * cos(angle4), mRadius * sin(angle4));
        AddPoint(innerRadius * cos(angle5), innerRadius * sin(angle5));
    }
    DrawPolygon(graphics, GetInputPoint().x + x, GetInputPoint().y + y);
}

/**
 * Set the rotation for the gear and update the sinks
 * @param rotation Rotation of the gear
 */
void Gear::SetRotation(double rotation)
{
    mRotation = rotation;
    Polygon::SetRotation(mRotation);
    mSource.UpdateSink(rotation);
}

/**
 * Constructor
 * @param radius Radius of the gear
 * @param teeth Number of teeth the gear has
 */
Gear::Gear(double radius, int teeth) : mNumTeeth(teeth), mRadius(radius)
{
    mSink.SetComponent(this);
}

/**
 * Move the other gears that are connected to this gear
 * @param gear Gear connected to this gear
 * @param phase Small value to help gears mesh on screen
 */
void Gear::Drive(std::shared_ptr<Gear> gear, double phase)
{
    auto sink = gear->GetSink();

    mSource.AddSink(sink);
    sink->SetSpeed(-(double)mNumTeeth / (double)gear->mNumTeeth);
    sink->SetPhase(phase);
}
