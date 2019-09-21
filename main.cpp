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



HDC  background  = txLoadImage ("àíäðåé\\ôîí 2.bmp");





bool exitProgram = false;
while(!exitProgram)
{
	txBegin();
          txBitBlt (txDC(), 0, 0, 1200, 800, background, 0, 0);
	   txSetFillColor(TX_WHITE);
	   txSetColor(TX_WHITE);
	   /*Win32::RoundRect (txDC(), 450, 230, 750,730,50,50); */

	   txSelectFont("Arial", 40);
	   txDrawText(300,100,900,150,"Ñîçäàé ñâîþ êâàðòèðó");

	   txDrawText(500,270,680,320,"Íà÷àòü");
	   if(knopka(530,270))
	   {
		txMessageBox("Çàãðóçêà");
	   }

	   txDrawText(500,320,680,370,"Ïðîäîëæèòü");
	    if(knopka(530,320))
	   {
		txMessageBox("Çàãðóçêà");
	   }

	   txDrawText(500,370,680,420,"Íàñòðîéêè");
	    if(knopka(530,370))
	   {
		txMessageBox("íàñòðîéêè íåäîñòóïíû");
	   }

		txDrawText(500,420,680,470,"Èíôîðìàöèÿ");
		 if(knopka(530,420))
	   {
		txMessageBox("Cåé÷àñ íàéä¸ì");
	   }

	   txDrawText(500,470,680,520,"Âûéòè");
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

  txSetFillColor (TX_GRAY);
    txRectangle ( 10 , 100 , 1200 - 150 , 800 - 2 );
  /*
    HDC  pic = txLoadImage ("Äèâàí1.bmp");
    Win32::TransparentBlt (txDC(), 1090, 110, 75, 190, pic, 0, 0, 185, 451, TX_WHITE);
    txDeleteDC(pic);

    HDC  pic2 = txLoadImage ("Äèâàí2.bmp");
    Win32::TransparentBlt (txDC(), 1090, 320, 75, 190, pic2, 0, 0, 185, 451, TX_WHITE);
    txDeleteDC(pic2);

    HDC  pic3 = txLoadImage ("Äèâàí3.bmp");
    Win32::TransparentBlt (txDC(), 1060, 540, 120, 60, pic3, 0, 0, 451, 185, TX_WHITE);
    txDeleteDC(pic3);

    HDC  pic4 = txLoadImage ("Äèâàí4.bmp");
    Win32::TransparentBlt (txDC(), 1060, 630, 120, 60, pic4, 0, 0, 451, 185, TX_WHITE);
    txDeleteDC(pic4);
                       */

    HDC  brick= txLoadImage ("Êèðïè÷.bmp");
    Win32::TransparentBlt (txDC(), 1060, 630, 100, 100, brick, 0, 0, 100, 100, TX_WHITE);
    txDeleteDC(brick);

    HDC wood = txLoadImage ("wood.bmp");
    Win32::TransparentBlt (txDC(), 1060, 520, 100, 100, wood, 0, 0, 100, 100, TX_WHITE);
    txDeleteDC(wood);

    return 0;
    }
