#include "TXLib.h"
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



HDC  background  = txLoadImage ("������\\��� 2.bmp");





bool exitProgram = false;
while(!exitProgram)
{
	txBegin();
          txBitBlt (txDC(), 0, 0, 1200, 800, background, 0, 0);
	   txSetFillColor(TX_WHITE);
	   txSetColor(TX_WHITE);
	   /*Win32::RoundRect (txDC(), 450, 230, 750,730,50,50); */

	   txSelectFont("Arial", 40);
	   txDrawText(300,100,900,150,"������ ���� ��������");

	   txDrawText(500,270,680,320,"������");
	   if(knopka(530,270))
	   {
		txMessageBox("��������");
	   }

	   txDrawText(500,320,680,370,"����������");
	    if(knopka(530,320))
	   {
		txMessageBox("��������");
	   }

	   txDrawText(500,370,680,420,"���������");
	    if(knopka(530,370))
	   {
		txMessageBox("��������� ����������");
	   }

		txDrawText(500,420,680,470,"����������");
		 if(knopka(530,420))
	   {
		txMessageBox("C����� �����");
	   }

	   txDrawText(500,470,680,520,"�����");
	    if(knopka(530,470))
	   {
		exitProgram = true;
	   }

	  /* txSetFillColor (TX_YELLOW);

		txRectangle (425, 270, 775, 382); */


	txSleep(10);
	txEnd();
}
             txDisableAutoPause();
             txDeleteDC(background);


    return 0;
    }
