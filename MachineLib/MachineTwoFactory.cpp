/**
 * @file MachineTwoFactory.cpp
 * @author Noah O'Bryan
 */

#include "pch.h"
#include "MachineTwoFactory.h"
#include "ActualMachine.h"
#include "Shape.h"
#include "Gear.h"
#include "Arm.h"
#include "Piston.h"
#include "Lever.h"
#include "Rod.h"

/**
 * This is a factory method that creates our first machine
 * @param imagesDir Directory that contains the images for this application
 * @return Pointer to a Machine object.
 */
std::shared_ptr<ActualMachine> MachineTwoFactory::Create(std::wstring imagesDir)
{
    //std::shared_ptr<ActualMachine> machine1 = std::make_shared<ActualMachine>();

    // The machine itself
    // In this solution the machine number is passed
    // to the working machine constructor, so it knows
    // its number.
    auto machine = std::make_shared<ActualMachine>();

    // The base
    auto base = std::make_shared<Shape>();
    base->AddPoint(-200,-300);
    base->AddPoint(-250, 0);
    base->AddPoint(350,0);
    base->AddPoint(300,-300);
    base->SetImage(imagesDir + L"/rust.png");
    machine->AddComponent(base);

    // The motor
    auto motor = std::make_shared<Motor>(imagesDir);
    motor->SetPoint(wxPoint(-200, -75));
    motor->SetSpeed(1.0);
    machine->AddComponent(motor);
    machine->SetMotor(motor);

    auto leftSupport = std::make_shared<Shape>();
    leftSupport->Rectangle(-300, -0, 200, 35);
    leftSupport->SetImage(imagesDir + L"/base.png");
    machine->AddComponent(leftSupport);

    // The gear driven by the motor
    // Radius = 20 pixels, 10 teeth
    auto gear1 = std::make_shared<Gear>(20,10);
    gear1->SetImage(imagesDir + L"/iron.png");
    gear1->SetPoint(wxPoint(-200, -150/2));
    machine->AddComponent(gear1);

    motor->GetSource()->AddSink(gear1->GetSink());

    // The second gear
    // Radius = 40 pixels, 20 teeth
    auto gear2 = std::make_shared<Gear>(40, 20);
    gear2->SetImage(imagesDir + L"/hammered-copper.png");
    gear2->SetPoint(wxPoint(gear1->GetInputPoint().x + 55, gear1->GetInputPoint().y));
    machine->AddComponent(gear2);

    gear1->Drive(gear2, 0.1);

    // The arm attached to the second gear
    // 50 pixels long
    auto arm = std::make_shared<Arm>(50);
    arm->SetImage(imagesDir + L"/arm1.png");
    arm->SetPoint(gear2->GetInputPoint());
    machine->AddComponent(arm);

    gear2->GetSource()->AddSink(arm->GetSink());

    // The lever
    auto lever = std::make_shared<Lever>(400);
    lever->SetPoint(wxPoint(0, -232));
    lever->SetImage(imagesDir + L"/lever.png");
    lever->SetDriveEnd(185);
    machine->AddComponent(lever);

    // Rod from arm to lever
    // 150 pixels long, 7 pixels wide
    auto rod1 = std::make_shared<Rod>(150, 7);
    int gray = 50;
    rod1->SetColor(wxColour(gray, gray, gray));
    machine->AddComponent(rod1);

    arm->GetSource()->AddSink(rod1->GetPointSink());
    rod1->SetRodSink(lever->GetRodSink());

    // The column that holds the lever
    auto column = std::make_shared<Shape>();
    column->SetColor(wxColour(50, 50, 50));
    column->Rectangle(-15, -215, 200, 40);
    machine->AddComponent(column);

    // column support beam
    auto columnTop = std::make_shared<Shape>();
    columnTop->SetColor(wxColour(50,50,50));
    columnTop->Rectangle(183, -255, 40, -225);
    machine->AddComponent(columnTop);

    // base of the column
    auto rightSupport = std::make_shared<Shape>();
    rightSupport->Rectangle(140, 0, 200, 35);
    rightSupport->SetImage(imagesDir + L"/base.png");
    machine->AddComponent(rightSupport);

    return machine;
}

