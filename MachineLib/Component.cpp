/**
 * @file Component.cpp
 * @author Noah O'Bryan
 */

#include "pch.h"
#include "Component.h"
#include "ActualMachine.h"

/**
 * Draw the component using the Polygon class
 * @param graphics Graphic to be rendered
 * @param x X location of the machine
 * @param y Y location of the machine
 */
void Component::Draw(std::shared_ptr<wxGraphicsContext> graphics, double x, double y)
{
    DrawPolygon(graphics, mPosition.x + x, mPosition.y + y);
}

