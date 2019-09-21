#include "TXLib.h"

int main()
    {
    txCreateWindow (1200, 800);
    txSetFillColor (TX_GRAY);
    txRectangle ( 10 , 100 , 1200 - 150 , 800 - 2 );
  /*
    HDC  pic = txLoadImage ("Диван1.bmp");
    Win32::TransparentBlt (txDC(), 1090, 110, 75, 190, pic, 0, 0, 185, 451, TX_WHITE);
    txDeleteDC(pic);

    HDC  pic2 = txLoadImage ("Диван2.bmp");
    Win32::TransparentBlt (txDC(), 1090, 320, 75, 190, pic2, 0, 0, 185, 451, TX_WHITE);
    txDeleteDC(pic2);

    HDC  pic3 = txLoadImage ("Диван3.bmp");
    Win32::TransparentBlt (txDC(), 1060, 540, 120, 60, pic3, 0, 0, 451, 185, TX_WHITE);
    txDeleteDC(pic3);

    HDC  pic4 = txLoadImage ("Диван4.bmp");
    Win32::TransparentBlt (txDC(), 1060, 630, 120, 60, pic4, 0, 0, 451, 185, TX_WHITE);
    txDeleteDC(pic4);
                       */

    HDC  brick= txLoadImage ("Кирпич.bmp");
    Win32::TransparentBlt (txDC(), 1060, 630, 100, 100, brick, 0, 0, 100, 100, TX_WHITE);
    txDeleteDC(brick);

    HDC wood = txLoadImage ("wood.bmp");
    Win32::TransparentBlt (txDC(), 1060, 520, 100, 100, wood, 0, 0, 100, 100, TX_WHITE);
    txDeleteDC(wood);

    return 0;
    }

