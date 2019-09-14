#include "TXLib.h"

int main()
    {
    txCreateWindow (1000, 800);
    txSetColor(TX_RED);
    txRectangle(100, 100, 350, 300);
    txRectangle(600, 100, 850, 300);

    return 0;
    }

