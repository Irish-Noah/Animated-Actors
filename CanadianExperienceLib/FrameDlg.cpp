/**
 * @file FrameDlg.cpp
 * @author Noah O'Bryan
 */

#include "pch.h"
#include <wx/xrc/xmlres.h>
#include <wx/valnum.h>

#include "FrameDlg.h"
#include "Picture.h"

/**
 * Constructor
 * @param parent The parent window to put this dialog box inside
 * @param picture Pointer to the picture we are editing
 */
FrameDlg::FrameDlg(wxWindow* parent, std::shared_ptr<Picture> picture) : mPicture(picture)
{
    wxXmlResource::Get()->LoadDialog(this, parent, L"FrameDlg");

    Bind(wxEVT_BUTTON, &FrameDlg::OnOk, this, wxID_OK);

    auto frame1Ctrl = XRCCTRL(*this, "FrameDlgCurrentFrame1", wxTextCtrl);
    wxIntegerValidator<int> frame1Validator(&mFrame1);
    frame1Validator.SetRange(1,10000);
    frame1Ctrl->SetValidator(frame1Validator);

    auto frame2Ctrl = XRCCTRL(*this, "FrameDlgCurrentFrame2", wxTextCtrl);
    wxIntegerValidator<int> frame2Validator(&mFrame2);
    frame2Validator.SetRange(1,10000);
    frame2Ctrl->SetValidator(frame2Validator);

}

/**
 * Handle an OK button press
 * @param event Button event
 */
void FrameDlg::OnOk(wxCommandEvent& event)
{
    if ( Validate() && TransferDataFromWindow() )
    {
        mPicture->GetMachineDrawable()->SetStartFrame1(mFrame1);
        mPicture->GetMachineDrawable()->SetStartFrame2(mFrame2);

        EndModal(wxID_OK);
    }
}
