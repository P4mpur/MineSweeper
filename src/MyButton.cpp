#include "MyButton.h"

MyButton::MyButton(wxWindow *parent, wxWindowID id) : wxButton(parent, id)
{
}

void MyButton::pratiNule(MyButton ***matrix, int x, int y, int &total)
{
    matrix[y][x]->oznacen = true;
    matrix[y][x]->SetBackgroundColour(wxColor(40 * (matrix[y][x]->getValue()), 30 * (matrix[y][x]->getValue()), 150));
    matrix[y][x]->Enable(false);

    if (matrix[y][x]->getValue() != 0)
    {
        total--;
        matrix[y][x]->SetLabel(std::to_string(matrix[y][x]->getValue()));
        return;
    }
    matrix[y][x]->SetLabel(" ");

    for (int j = -1; j < 2; j++)
    {
        if (y + j >= 0 && y + j < 10 && !matrix[y + j][x]->oznacen)
        {
            matrix[y + j][x]->pratiNule(matrix, x, y + j, total);
        }
        if (x + j >= 0 && x + j < 10 && !matrix[y][x + j]->oznacen)
        {
            matrix[y][x + j]->pratiNule(matrix, x + j, y, total);
        }
    }
    total--;
}

void MyButton::SurroundBomb(MyButton ***matrix, int x, int y)
{
    for (int i = -1; i < 2; i++)
    {
        for (int j = -1; j < 2; j++)
        {
            if (x + j >= 0 && x + j < 10 && y + i >= 0 && y + i < 10 && matrix[y + i][x + j]->getValue() != -1)
            {
                matrix[y + i][x + j]->incValue();
            }
        }
    }
}

void MyButton::setValue(int x)
{
    this->value = x;
}

void MyButton::incValue()
{
    this->value++;
}

int MyButton::getValue()
{
    return this->value;
}
