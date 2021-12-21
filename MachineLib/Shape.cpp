/**
 * @file Shape.cpp
 * @author Noah O'Bryan
 */

#include "pch.h"
#include "Shape.h"

/**
 * Draw the shape using the Polygon class
 * @param graphics Graphics to be rendered
 * @param x X position of the machine
 * @param y Y position of the machine
 */
void Shape::Draw(std::shared_ptr<wxGraphicsContext> graphics, double x, double y)
{
    DrawPolygon(graphics, GetInputPoint().x + x, GetInputPoint().y + y);
}

/**
 * Set the rotation for the shape
 * @param rotation Rotation of the shape
 */
void Shape::SetRotation(double rotation)
{
    mRotation = rotation;
    Polygon::SetRotation(mRotation);
}
