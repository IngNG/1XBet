#include "TXLib.h"
   struct  Picture
   {
    int x  ;
    int y ;
    int shirina;
    int vasota;
    HDC pic;
   };

   void drawPic (Picture vk)
   {
    txBitBlt(txDC(), vk.x, vk.y, vk.shirina, vk.vasota, vk.pic);
   }

bool knopka(int x, int y)
{
    if (txMouseX() > x and
          txMouseX() < x + 100 and
          txMouseY() > y and
          txMouseY() < y + 50 and
          txMouseButtons() &1)
    {
        return true;
    }

    return false;
}


int main()
{
    txCreateWindow (1200, 800);

    HDC  brick= txLoadImage ("Pics\\Wall\\brick.bmp");
    HDC wood = txLoadImage ("Pics\\Wall\\wood.bmp");
    HDC  background  = txLoadImage ("Pics\\��� 2.bmp");

    bool exitProgram = false;

    int pageNumber = 0;


    while(!exitProgram)
    {
        txBegin();

        if (pageNumber == 0)
        {
			txBitBlt (txDC(), 0, 0, 1200, 800, background, 0, 0);
			txSetFillColor(TX_WHITE);
			txSetColor(TX_WHITE);
			/*Win32::RoundRect (txDC(), 450, 230, 750,730,50,50); */

			txSelectFont("Arial", 40);
			txDrawText(300,100,900,150,"������ ���� ��������");

			txDrawText(500,270,680,320,"������");
			if(knopka(530,270))
			{
				 if (pageNumber = 1);
			}

			txDrawText(500,320,680,370,"����������");
			if (knopka(530,320))
			{
				txMessageBox("��������");
			}

			txDrawText(500,370,680,420,"���������");
			if (knopka(530,370))
			{
				txMessageBox("��������� ����������");
			}

			txDrawText(500,420,680,470,"����������");
			if (knopka(530,420))
			{
				txMessageBox("C����� �����");
			}

			txDrawText(500,470,680,520,"�����");
			if (knopka(530,470))
			{
				exitProgram = true;
			}
		}

        /* txSetFillColor (TX_YELLOW);

        txRectangle (425, 270, 775, 382); */

        if (pageNumber == 1 )
        {

				txSetFillColor (TX_GRAY);
				txRectangle ( 10 , 100 , 1200 - 150 , 800 - 2 );


				txDrawText(55,20,180,70,"������");
			if(knopka(55,20))
			{
			}

			  /*
				HDC  pic = txLoadImage ("Pics\\Furniture\\����� 1.bmp");
				Win32::TransparentBlt (txDC(), 1090, 110, 75, 190, pic, 0, 0, 185, 451, TX_WHITE);
				txDeleteDC(pic);

				HDC  pic2 = txLoadImage ("Pics\\Furniture\\����� 2.bmp");
				Win32::TransparentBlt (txDC(), 1090, 320, 75, 190, pic2, 0, 0, 185, 451, TX_WHITE);
				txDeleteDC(pic2);

				HDC  pic3 = txLoadImage ("Pics\\Furniture\\����� 3.bmp");
				Win32::TransparentBlt (txDC(), 1060, 540, 120, 60, pic3, 0, 0, 451, 185, TX_WHITE);
				txDeleteDC(pic3);

				HDC  pic4 = txLoadImage ("Pics\\Furniture\\����� 4.bmp");
				Win32::TransparentBlt (txDC(), 1060, 630, 120, 60, pic4, 0, 0, 451, 185, TX_WHITE);
				txDeleteDC(pic4);
								   */

				Win32::TransparentBlt (txDC(), 1060, 630, 100, 100, brick, 0, 0, 100, 100, TX_WHITE);

				Win32::TransparentBlt (txDC(), 1060, 520, 100, 100, wood, 0, 0, 100, 100, TX_WHITE);
        }



        txSleep(10);
        txEnd();



    }

    txDisableAutoPause();
    txDeleteDC(background);


    txDeleteDC(brick);
    txDeleteDC(wood);
    txSleep(2000);

    return 0;
}
