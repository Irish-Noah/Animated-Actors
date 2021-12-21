/**
 * @file Lever.cpp
 * @author Noah O'Bryan
 */

#include "pch.h"
#include "Lever.h"

/// Conversion from radians to degrees
const double RadConv = 0.1592;

/**
 * Draw the lever using the Polygon class
 * @param graphics Graphics to be rendered
 * @param x X position of the component
 * @param y Y position of the component
 */
void Lever::Draw(std::shared_ptr<wxGraphicsContext> graphics, double x, double y)
{
    Component::Draw(graphics, x, y);
}

/**
 * Negotiate the rotation between a Lever and a Rod
 * @param rod Rod that is in the negotiation
 */
void Lever::Negotiate(Rod* rod)
{
    double x1 = rod->GetInputPoint().x;
    double y1 = rod->GetInputPoint().y;

    double x2 = GetInputPoint().x;
    double y2 = GetInputPoint().y;

    double a = mDriveEnd;
    double b = rod->GetLength();
    double c = sqrt(pow((y2-y1), 2) + pow(x2-x1, 2));

    double delta = atan2(-(y2-y1), x2-x1);
    double alpha = acos((pow(b,2)+ pow(c,2)-pow(a,2))/(2*b*c));
    double theta = delta - alpha;

    double x3 = x1+b*cos(-theta);
    double y3 = y1+b*sin(-theta);

    double phi = atan2((y3-y2), (x3-x2));

    double distX = x3-x2;
    double distY = y2-y3;

    double x4 = x3-2*distX;
    double y4 = y3+2*distY;

    rod->SetRotation(-theta * RadConv);
    Polygon::SetRotation(phi * RadConv);
    mPointSource.UpdateSink(wxPoint(x4,y4));
    mRotationSource.UpdateSink(phi* RadConv);
}

/**
 * Constructor
 * @param length Length of the lever
 */
Lever::Lever(int length) : mLength(length)
{
    mRodSink = std::make_shared<RodSink>(this, this);
    mRodSink->SetComponent(this);
    Rectangle(-mLength/2, 25, mLength, 50);
}
