#pragma once
#include "MyButton.h"

class MyFrame : public wxFrame
{
public:
    MyFrame(const wxString &title, const wxPoint &pos, const wxSize &size);
    void onButtonClick(wxCommandEvent &event);
    void placeAFlag(wxCommandEvent &event);

    wxDECLARE_EVENT_TABLE();

    ~MyFrame();

private:
    int total = 100;
    int mines = 20;
    bool onFirstClick = true;
    MyButton ***matrix;
};
