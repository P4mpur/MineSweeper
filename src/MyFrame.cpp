#include "MyFrame.h"

MyFrame::MyFrame(const wxString &title, const wxPoint &pos, const wxSize &size) : wxFrame(NULL, wxID_ANY, title, pos, size)
{
    wxGridSizer *grid = new wxGridSizer(10, 10, 0, 0);

    matrix = new MyButton **[10];

    for (int y = 0; y < 10; y++)
    {
        matrix[y] = new MyButton *[10];
    }
    for (int y = 0; y < 10; y++)
    {
        for (int x = 0; x < 10; x++)
        {
            matrix[y][x] = new MyButton(this, 100 + (y * 10 + x));
            grid->Add(matrix[y][x], 1, wxEXPAND | wxALL);
            matrix[y][x]->Bind(wxEVT_COMMAND_LEFT_CLICK, &MyFrame::onButtonClick, this);
            matrix[y][x]->Bind(wxEVT_COMMAND_RIGHT_CLICK, &MyFrame::placeAFlag, this);
            matrix[y][x]->setValue(0);
        }
    }
    this->SetSizer(grid);
    grid->Layout();
}

void MyFrame::onButtonClick(wxCommandEvent &event)
{

    int x = event.GetId() % 10;
    int y = (event.GetId() - 100) / 10;

    if (onFirstClick)
    {
        int mine_count = mines;

        while (mine_count)
        {
            int rx = rand() % 10;
            int ry = rand() % 10;

            if (x != rx && y != ry && matrix[ry][rx]->getValue() != -1)
            {
                matrix[ry][rx]->setValue(-1);
                matrix[ry][rx]->SurroundBomb(matrix, rx, ry);
                mine_count--;
            }
        }

        onFirstClick = false;
    }
    else
    {
        if (matrix[y][x]->getValue() == -1)
        {
            wxMessageBox("Kurcinaaa");
            matrix[y][x]->SetBackgroundColour(wxColor(0, 200, 80));
        }
    }

    matrix[y][x]->pratiNule(matrix, x, y, total);

    if (total == mines)
    {
        wxMessageBox("Opravi ga be");
    }
    event.Skip();
}

void MyFrame::placeAFlag(wxCommandEvent &event)
{
    std::cout << event.GetId() << std::endl;
}

MyFrame::~MyFrame()
{
    for (int i = 0; i < 10; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
}

wxBEGIN_EVENT_TABLE(MyFrame, wxFrame)
    EVT_BUTTON(wxID_ANY, MyFrame::onButtonClick)
        EVT_BUTTON(wxID_ANY, MyFrame::placeAFlag)
            wxEND_EVENT_TABLE()
