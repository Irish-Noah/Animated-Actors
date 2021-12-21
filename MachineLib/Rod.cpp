/**
 * @file Rod.cpp
 * @author Noah O'Bryan
 */

#include "pch.h"
#include "Rod.h"

/**
 * Draw the rod component
 * @param graphics Graphics to be rendered
 * @param x X location of the component
 * @param y Y location of the component
 */
void Rod::Draw(std::shared_ptr<wxGraphicsContext> graphics, double x, double y)
{
    DrawPolygon(graphics, x + GetInputPoint().x, y + GetInputPoint().y);
}

/**
 * Set the point and negotiate the position
 * @param point Point to be set and negotiated
 */
void Rod::SetPoint(wxPoint point)
{
    Component::SetPoint(point);
    mRodSink->Negotiate(this);
}

/**
 * Constructor
 * @param length Length of this rod
 * @param height Height of this rod
 */
Rod::Rod(int length, int height) : mLength(length), mHeight(height)
{
    Rectangle(-5,mHeight-2,mLength+10,mHeight);
    mPointSink.SetComponent(this);
    mRodSource = std::make_shared<RodSource>();
}

/**
 * Rotation for this rod
 * @param rotation Rotation of the rod
 */
void Rod::SetRotation(double rotation)
{
    Polygon::SetRotation(rotation);
}
