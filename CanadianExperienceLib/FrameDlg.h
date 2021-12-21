/**
 * @file FrameDlg.h
 * @author Noah O'Bryan
 *
 * Class that implements a dialog box for frame setting for machines
 */

#ifndef CANADIANEXPERIENCE_FRAMEDLG_H
#define CANADIANEXPERIENCE_FRAMEDLG_H

class Picture;

/**
 * Class that implements a dialog box for frame setting for machines
 */
class FrameDlg final : public wxDialog {
private:
    void OnOk(wxCommandEvent& event);

    /// starting frame for the first machine
    int mFrame1 = 0;

    /// starting frame for the second machine
    int mFrame2 = 0;

    /// Picture object we are editing
    std::shared_ptr<Picture> mPicture;

public:
    FrameDlg(wxWindow* parent, std::shared_ptr<Picture> picture);
};

#endif //CANADIANEXPERIENCE_FRAMEDLG_H
