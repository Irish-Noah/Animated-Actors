/**
 * @file RotationSink.cpp
 * @author Noah O'Bryan
 */

#include "pch.h"
#include "RotationSink.h"
#include "Shape.h"
#include "Component.h"

/**
 * Update the rotation of the component
 * @param rotation New rotation to be sent to the component
 */
void RotationSink::UpdateComponent(double rotation)
{
    GetComponent()->SetRotation(rotation * mSpeed);
}
