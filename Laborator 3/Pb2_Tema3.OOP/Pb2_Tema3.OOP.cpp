#include "Canvas.h"

int main()
{
    Canvas myCanvas(50, 20);

    myCanvas.FillRect(2, 2, 10, 5, '.');
    myCanvas.DrawRect(2, 2, 10, 5, '#');

    myCanvas.FillCircle(35, 10, 4, '+');
    myCanvas.DrawCircle(35, 10, 4, '@');

    myCanvas.DrawLine(0, 0, 49, 19, 'X');
    myCanvas.DrawLine(0, 19, 49, 0, 'X');

    myCanvas.SetPoint(25, 10, 'O');

    myCanvas.Print();

    return 0;
}