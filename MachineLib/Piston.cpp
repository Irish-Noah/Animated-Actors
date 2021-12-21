/**
 * @file Piston.cpp
 * @author Noah O'Bryan
 */

#include "pch.h"
#include "Piston.h"

/// Constant to convert radians to degrees
const double RadConv = 0.1592;

/**
 * Draw the piston component
 * @param graphics Graphics to be rendered
 * @param x X location of the component
 * @param y Y location of the component
 */
void Piston::Draw(std::shared_ptr<wxGraphicsContext> graphics, double x, double y)
{
    Component::Draw(graphics, x, y);
}

/**
 * Negotiate the position between a Piston and a Rod
 * @param rod Rod that is in the negotiation
 */
void Piston::Negotiate(Rod* rod)
{
    double x1 = rod->GetInputPoint().x;
    double y1 = rod->GetInputPoint().y;

    double x2 = GetInputPoint().x;

    double a = rod->GetLength();

    double alpha = asin((x2-x1)/a);
    double beta = M_PI/2 - alpha;

    double b = sqrt(pow(a,2)+pow((x2-x1),2));

    rod->SetRotation(beta * RadConv);

    Component::SetPoint(wxPoint((x2), y1+b));
}

/**
 * Constructor
 */
Piston::Piston()
{
    mRodSink = std::make_shared<RodSink>(this, this);
    mRodSink->SetComponent(this);
}
