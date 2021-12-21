/**
 * @file MachineDrawable.cpp
 * @author Noah O'Bryan
 */

#include "pch.h"
#include "MachineDrawable.h"
#include "Timeline.h"

/**
 * Constructor
 * @param imagesDir Directory for the images in this project
 */
MachineDrawable::MachineDrawable(std::wstring imagesDir) : Drawable(L"Machine")
{
    MachineFactory factory1(imagesDir);
    auto machine = factory1.CreateMachine();
    machine->SetMachineNumber(1);

    MachineFactory factory2(imagesDir);
    auto machine2 = factory2.CreateMachine();
    machine2->SetMachineNumber(2);

    mMachine1 = machine;
    mMachine2 = machine2;

    mMachine1->SetSpeed(1);
    mMachine2->SetSpeed(1);
}

/**
 * Draw the machines to 75% scale and set the state of the machines
 * @param graphics Graphics to be rendered
 */
void MachineDrawable::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{
    // check if the starting frame allows the machines to be able to move
    if (mTimeline->GetCurrentFrame() >= mStartFrame1 )
    {
        mMachine1->SetFrameRate(mTimeline->GetFrameRate());
        mMachine1->SetMachineFrame(mTimeline->GetCurrentFrame());
    }

    if (mTimeline->GetCurrentFrame() >= mStartFrame2 )
    {
        mMachine2->SetFrameRate(mTimeline->GetFrameRate());
        mMachine2->SetMachineFrame(mTimeline->GetCurrentFrame());
    }

    // rescale
    double scale = 0.75f;

    graphics->PushState();
    graphics->Translate(mPlacedPosition.x , mPlacedPosition.y);
    graphics->Scale(scale,scale);
    mMachine1->SetLocation(wxPoint(1000,500));
    mMachine1->DrawMachine(graphics);
    mMachine2->SetLocation(wxPoint(250,600));
    mMachine2->DrawMachine(graphics);
    graphics->PopState();
}

/**
 * Check if the machine has been clicked on
 * @param pos Position of mouse click
 * @return false
 */
bool MachineDrawable::HitTest(wxPoint pos)
{
    return false;
}

/**
 * Set the timeline object for the machines
 * @param timeline Timeline to be set
 */
void MachineDrawable::SetTimeline(Timeline* timeline)
{
    Drawable::SetTimeline(timeline);
    mTimeline = timeline;
}

/**
 * Display the dialog box for the second machine
 * @param parent Pointer to wxFrame object, the main frame for the application
 */
void MachineDrawable::Dialog2(wxWindow* parent)
{
    MachineDialog dlg(parent,mMachine2);
    if (dlg.ShowModal() == wxID_OK)
    {
    }
}

/**
 * Display the dialog box for the first machine
 * @param parent Pointer to wxFrame object, the main frame for the application
 */
void MachineDrawable::Dialog1(wxWindow* parent)
{
    MachineDialog dlg(parent, mMachine1);
    if (dlg.ShowModal() == wxID_OK)
    {
        mMachine1->SetMachineNumber(2);
    }
}

/**
 * Set the number of the first machine
 * @param num Number of the first machine
 */
void MachineDrawable::SetMachineOneNum(int num)
{
    mMachine1Num = num;
    mMachine1->SetMachineNumber(num);
}

/**
 * Set the number of the second machine
 * @param num Number of the second machine
 */
void MachineDrawable::SetMachineTwoNum(int num)
{
    mMachine2Num = num;
    mMachine2->SetMachineNumber(num);
}


