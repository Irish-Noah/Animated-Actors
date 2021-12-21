/**
 * @file MachineOneFactory.cpp
 * @author Noah O'Bryan
 */

#include "pch.h"
#include "MachineOneFactory.h"
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
std::shared_ptr<ActualMachine> MachineOneFactory::Create(std::wstring imagesDir)
{
    // The machine itself
    // In this solution the machine number is passed
    // to the working machine constructor, so it knows
    // its number.
    auto machine = std::make_shared<ActualMachine>();

    // The base
    auto base = std::make_shared<Shape>();
    int wid = 550;
    base->Rectangle(-wid/2, -1, wid, 40);
    base->SetImage(imagesDir + L"/base.png");
    machine->AddComponent(base);

    // The motor
    auto motor = std::make_shared<Motor>(imagesDir);
    motor->SetPoint(wxPoint(100, -38 - 50));
    motor->SetSpeed(1.0);
    machine->AddComponent(motor);
    machine->SetMotor(motor);

    // The gear driven by the motor
    // Radius=20pixels, 10 teeth
    auto gear1 = std::make_shared<Gear>(20,10);
    gear1->SetImage(imagesDir + L"/iron.png");
    gear1->SetPoint(wxPoint(100, -38 - 100 / 2));
    machine->AddComponent(gear1);

    motor->GetSource()->AddSink(gear1->GetSink());

    // A post that holds the larger gear
    auto gear2post = std::make_shared<Shape>();
    gear2post->Rectangle(-10, 0, 20, 30);
    gear2post->SetPoint(wxPoint(gear1->GetInputPoint().x + 55, -40));
    gear2post->SetColor(wxColour(0, 128, 0));
    machine->AddComponent(gear2post);

    // The second gear
    // Radius=40pixels, 20 teeth
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

    // The column that holds the lever
    auto column = std::make_shared<Shape>();
    column->Rectangle(-20, -40, 40, 220);
    column->SetImage(imagesDir + L"/column.png");

    // The lever
    auto lever = std::make_shared<Lever>(400);
    lever->SetPoint(wxPoint(0, -232));
    lever->SetImage(imagesDir + L"/lever.png");
    lever->SetDriveEnd(185);
    machine->AddComponent(lever);

    // The flag attached to the lever
    // Adding the points allows (0,0) be at the end
    // of the flagpole, so it rotates around that point.
    auto flag = std::make_shared<Shape>();
    flag->AddPoint(-50, 0);
    flag->AddPoint(-50, -100);
    flag->AddPoint(5, -100);
    flag->AddPoint(5, 0);
    flag->SetImage(imagesDir + L"/flag.png");
    flag->SetPoint(lever->GetInputPoint());
    machine->AddComponent(flag);
    lever->GetRotationSource()->AddSink(flag->GetSink());


    machine->AddComponent(column);

    // Rod from arm to lever
    // 150 pixels long, 7 pixels wide
    auto rod1 = std::make_shared<Rod>(150, 7);
    int gray = 50;
    rod1->SetColor(wxColour(gray, gray, gray));
    machine->AddComponent(rod1);

    arm->GetSource()->AddSink(rod1->GetPointSink());
    rod1->SetRodSink(lever->GetRodSink());

    // Rod from lever to Piston
    // 50 pixels long, 5 pixels wide
    auto rod2 = std::make_shared<Rod>(50, 5);
    rod2->SetColor(wxColour(gray, gray, gray));

    lever->GetPointSource()->AddSink(rod2->GetPointSink());

    // Piston (IS ADDED, JUST INSIDE CYLINDER)
    // The points are added so that (0,0) is
    // the attachment point for the rod.
    auto piston = std::make_shared<Piston>();
    double pistonH = 90;
    double pistonW = 0.386 * pistonH;
    double pistonC = 13.0 / 215.0 * pistonH;
    piston->AddPoint(-pistonW / 2, -pistonC);
    piston->AddPoint(pistonW / 2, -pistonC);
    piston->AddPoint(pistonW / 2, -pistonC + pistonH);
    piston->AddPoint(-pistonW / 2, -pistonC + pistonH);
    piston->SetImage(imagesDir + L"/piston.png");
    piston->SetPoint(wxPoint(-175, -150));

    machine->AddComponent(piston);
    rod2->SetRodSink(piston->GetRodSink());

    machine->AddComponent(rod2);

    // Cylinder
    auto cylinder = std::make_shared<Shape>();
    cylinder->Rectangle(-30, 0, 60, 120);
    cylinder->SetPoint(wxPoint(-175, -38));
    cylinder->SetImage(imagesDir + L"/cylinder.png");
    machine->AddComponent(cylinder);

    return machine;
}
