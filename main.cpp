#include "Lib\\TXLib.h"

int main()
{
    txCreateWindow (1000, 800);

    txSetColor(TX_RED);
    txRectangle(100, 200, 350, 400);
    txRectangle(600, 200, 850, 400);
    txRectangle(100, 500, 350, 700);
    txRectangle(600, 500, 850, 700);

    return 0;
}

