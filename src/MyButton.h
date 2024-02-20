#pragma once
#include <wx/wx.h>

class MyButton : public wxButton
{
public:
    bool oznacen = false;
    bool flag = false;

    MyButton(wxWindow *parent, wxWindowID id);

    void pratiNule(MyButton ***matrix, int, int, int &);
    void SurroundBomb(MyButton ***matrix, int, int);
    void setValue(int x);
    void incValue();
    int getValue();

private:
    int value;
};