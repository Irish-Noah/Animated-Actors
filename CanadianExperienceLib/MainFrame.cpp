/**
 * @file MainFrame.cpp
 * @author Charles B. Owen
 * @author Noah O'Bryan
 */
#include "pch.h"

#include <wx/xrc/xmlres.h>
#include <wx/stdpaths.h>

#include "MainFrame.h"

#include "ViewEdit.h"
#include "ViewTimeline.h"
#include "Picture.h"
#include "PictureFactory.h"
#include "FrameDlg.h"

/// Directory within resources that contains the images.
const std::wstring ImagesDirectory = L"/images";

/**
 * Constructor
 */
MainFrame::MainFrame()
{

}



/**
 * Initialize the MainFrame window.
 */
void MainFrame::Initialize()
{
    wxXmlResource::Get()->LoadFrame(this, nullptr, L"MainFrame");
#ifdef WIN32
    SetIcon(wxIcon(L"mainframe", wxBITMAP_TYPE_ICO_RESOURCE));
#endif

    auto sizer = new wxBoxSizer( wxVERTICAL );

    auto standardPaths = wxStandardPaths::Get();
    auto imagesDir = standardPaths.GetResourcesDir().ToStdWstring() + ImagesDirectory;

    mViewEdit = new ViewEdit(this);
    mViewTimeline = new ViewTimeline(this, imagesDir);

    sizer->Add(mViewEdit,1, wxEXPAND | wxALL );
    sizer->Add(mViewTimeline, 0, wxEXPAND | wxALL);

    SetSizer( sizer );
    Layout();

    Bind(wxEVT_COMMAND_MENU_SELECTED, &MainFrame::OnExit, this, wxID_EXIT);
    Bind(wxEVT_COMMAND_MENU_SELECTED, &MainFrame::OnAbout, this, wxID_ABOUT);
    Bind(wxEVT_COMMAND_MENU_SELECTED, &MainFrame::OnMachineOneDialogue, this, XRCID("MachineOneDialogue"));
    Bind(wxEVT_COMMAND_MENU_SELECTED, &MainFrame::OnMachineTwoDialogue, this, XRCID("MachineTwoDialogue"));
    Bind(wxEVT_COMMAND_MENU_SELECTED, &MainFrame::OnSetMachineFrame, this, XRCID("SetMachineFrame"));


    Bind(wxEVT_CLOSE_WINDOW, &MainFrame::OnClose, this);

    //
    // Create the picture
    //


    // Create our picture
    PictureFactory factory;
    mPicture = factory.Create(imagesDir);

    // Tell the views about the picture
    mViewEdit->SetPicture(mPicture);
    mViewTimeline->SetPicture(mPicture);
}



/**
 * Exit menu option handlers
 * @param event
 */
void MainFrame::OnExit(wxCommandEvent& event)
{
  Close(true);
}

/**
 * Application about box menu handler
 * @param event The menu command event
 */
void MainFrame::OnAbout(wxCommandEvent& event)
{
    wxDialog aboutDlg;
    wxXmlResource::Get()->LoadDialog(&aboutDlg, this, L"AboutDialog");
    aboutDlg.ShowModal();
}


/**
 * Handle a close event. Stop the animation and destroy this window.
 * @param event The Close event
 */
void MainFrame::OnClose(wxCloseEvent& event)
{
    mViewTimeline->Stop();
    Destroy();
}

/**
 * Handle a MachineOne Dialog event. Open the machine dialog box
 * @param event The MachineOne Dialog event
 */
void MainFrame::OnMachineOneDialogue(wxCommandEvent& event)
{
    mPicture->GetMachineDrawable()->Dialog1(this);
}

/**
 * Handle a MachineTwo Dialog event. Open the machine dialog box
 * @param event The MachineTwo Dialog event
 */
void MainFrame::OnMachineTwoDialogue(wxCommandEvent& event)
{
   mPicture->GetMachineDrawable()->Dialog2(this);
}

/**
 * Handle the Set Machine Frame event. Open the Frame Dialog box
 * @param event The SetMachineFrame event
 */
void MainFrame::OnSetMachineFrame(wxCommandEvent& event)
{
    FrameDlg dlg(this, mPicture);
    if (dlg.ShowModal() == wxID_OK)
    {
        wxWindow::Refresh();
    }
}


