#include "TXLib.h"
#include "button.cpp"
#include "picture.cpp"







int main()
{
    txCreateWindow (1200, 800);

    HDC  brick= txLoadImage ("Pics\\Wall\\brick.bmp");
    HDC wood = txLoadImage ("Pics\\Wall\\wood.bmp");
    HDC  background  = txLoadImage ("Pics\\фон 2.bmp");

    HDC  pic1 = txLoadImage ("Pics\\Furniture\\Диван1.bmp");
    HDC  pic2 = txLoadImage ("Pics\\Furniture\\Диван2.bmp");
    HDC  pic3 = txLoadImage ("Pics\\Furniture\\Диван3.bmp");
    HDC  pic4 = txLoadImage ("Pics\\Furniture\\Диван4.bmp");
	HDC  pic5 = txLoadImage ("Pics\\Wall\\brick.bmp");
	HDC  pic6 = txLoadImage ("Pics\\Wall\\mel.bmp");
	HDC  pic7 = txLoadImage ("Pics\\Wall\\wood.bmp");


    bool exitProgram = false;
    Picture kartinkaVCentreEkrana[5];
    kartinkaVCentreEkrana[0] = {390, 110, 75, 190, pic1, 185, 451, false};
    kartinkaVCentreEkrana[1] = {390, 320, 75, 190, pic2, 185, 451,false};
    bool mapvisible = false;
    bool mapvisible2 = false;

    Picture wall1 [5];
    wall1[0] = {1090, 110, 100, 100,  txLoadImage ("Pics\\Wall\\brick.bmp"), 60, 60};
    wall1[1] = {1090, 210, 100, 100,  txLoadImage ("Pics\\Wall\\mel.bmp"), 60, 60};
    wall1[2] = {1090, 310, 100, 100,  txLoadImage ("Pics\\Wall\\wood.bmp"), 100, 100};
    bool wall3 = true;





    Picture pic[4];
    pic[0] = {1090, 110, 75, 190, pic1, 185, 451};
    pic[1] = {1090, 320, 75, 190, pic2, 185, 451};
    bool visible = false;

    Picture cover[5];
    cover[0] = {1090, 110, 100, 100,  txLoadImage ("Pics\\ковёр1.bmp"), 300, 224};
    cover[1] = {1090, 320, 75, 190,  txLoadImage ("Pics\\ковёр3.bmp"), 350, 350};
    bool visible2 = false;

    int pageNumber = 0;

    Knopka buttons[6];
    buttons[0] = {500,270,680,320,"Начать","" };
    buttons[1] = {500,320,680,370,"Продолжить", "Загрузка"};
    buttons[2] = {500,370,680,420,"Настройки", "настройки недоступны"};
    buttons[3] = {500,420,680,470,"Информация","Cейчас найдём"};
    buttons[4] = {500,470,680,520,"Выйти",""};


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
			txDrawText(300,100,900,150,"Создай свою квартиру");



            for (int n = 0;   n < 5; n++)
            {
                buttons[n].drawButton();
                buttons[n].showMessage();
            }

			if(knopka(buttons[0].x + 20,buttons[0].y))
			{
                pageNumber = 1;
			}
			if (knopka(buttons[4].x + 20,buttons[4].y))
			{
				exitProgram = true;
			}
		}

        if (pageNumber == 1 )
        {
            txSetFillColor (TX_GRAY);
            txRectangle ( 10 , 100 , 1200 - 150 , 800 - 2 );

            //Кнопки сверху
            {
            txDrawText(55,20,180,70,"диваны");
            if(knopka(55,20))
            {
            visible = true;
            visible2 = false;
            txSleep(200);
            }

            txDrawText(255,20,380,70,"койка");
            if(knopka(240,40))
            {
            }

            txDrawText(455,20,580,70,"стены");
            if(knopka(440,40))
            {
            visible = false;
            visible2 = false;
            wall3 = true;
            txSleep(200);
            }

            txDrawText(655,20,780,70,"техника");
            if(knopka(640,40))
            {

            }

            txDrawText(855,20,980,70,"ковры");
            if(knopka(840,40))
            {
            visible2 = true;
            visible = false;
            txSleep(200);
            }
            }

			//Кнопки справа
            if(knopka(1090,200))
            {
            kartinkaVCentreEkrana[0].visible = !kartinkaVCentreEkrana[0].visible;
            txSleep(200);
            }
              if(knopka(1090,600))
            {
            kartinkaVCentreEkrana[2].visible = !kartinkaVCentreEkrana[2].visible;
            txSleep(200);
            }
            if(knopka(1090,400))
            {
            kartinkaVCentreEkrana[1].visible = !kartinkaVCentreEkrana[1].visible;
            txSleep(200);
            }




            if (GetAsyncKeyState(VK_ESCAPE))
            {
                exitProgram = true;
            }
             if (visible)
             {
            drawPic(pic[0]);
            drawPic(pic[1]);
            }
             if (visible2)
             {
            drawPic(cover[0]);
            drawPic(cover[1]);
            }

             if (wall3)
             {
            drawPic(wall1[0]);
            drawPic(wall1[1]);
            drawPic(wall1[2]);
            }

             if (kartinkaVCentreEkrana[0].visible)
             {
            drawPic(kartinkaVCentreEkrana[0]);
            }
             if (kartinkaVCentreEkrana[1].visible)
             {
            drawPic(kartinkaVCentreEkrana[1]);
            }
             if (kartinkaVCentreEkrana[2].visible)
             {
            drawPic(kartinkaVCentreEkrana[2]);
            }
             if (kartinkaVCentreEkrana[3].visible)
             {
            drawPic(kartinkaVCentreEkrana[3]);
            }
        }



        txSleep(10);
        txEnd();



    }

    txDisableAutoPause();
    txDeleteDC(background);


    txDeleteDC(brick);
    txDeleteDC(wood);

    txDeleteDC(pic1);
    txDeleteDC(pic2);
    txDeleteDC(pic3);
    txDeleteDC(pic4);



  /*
    Win32::TransparentBlt (txDC(), 1090, 110, 75, 190, pic, 0, 0, 185, 451, TX_WHITE);
    txDeleteDC(pic);

    Win32::TransparentBlt (txDC(), 1090, 320, 75, 190, pic2, 0, 0, 185, 451, TX_WHITE);
    txDeleteDC(pic2);

    Win32::TransparentBlt (txDC(), 1060, 540, 120, 60, pic3, 0, 0, 451, 185, TX_WHITE);
    txDeleteDC(pic3);

    Win32::TransparentBlt (txDC(), 1060, 630, 120, 60, pic4, 0, 0, 451, 185, TX_WHITE);
    txDeleteDC(pic4);
                       */
    /*
    HDC  brick= txLoadImage ("Кирпич.bmp");
    Win32::TransparentBlt (txDC(), 1060, 630, 100, 100, brick, 0, 0, 100, 100, TX_WHITE);
    txDeleteDC(brick);

    HDC wood = txLoadImage ("wood.bmp");
    Win32::TransparentBlt (txDC(), 1060, 520, 100, 100, wood, 0, 0, 100, 100, TX_WHITE);
    txDeleteDC(wood);


    HDC mel = txLoadImage ("mel.bmp");
    Win32::TransparentBlt (txDC(), 1060, 410, 100, 100, mel, 0, 0, 100, 100, TX_WHITE);
    txDeleteDC(mel);
*/
/*
   HDC bed = txLoadImage ("bed1.bmp");
   Win32::TransparentBlt (txDC(), 1060, 110, 100,100, bed , 0,0,100, 100, TX_WHITE);
   txDeleteDC(bed);

   HDC bed2 = txLoadImage ("bed2.bmp");
   Win32::TransparentBlt (txDC(), 1060, 270, 100,100, bed2, 0,0, 100,100, TX_WHITE);
   txDeleteDC(bed2);

   HDC bed3 = txLoadImage ("bed3.bmp");
   Win32::TransparentBlt (txDC(), 1060, 430, 100,100, bed3, 0,0, 100,100, TX_WHITE);
   txDeleteDC(bed3);

   HDC bed4 = txLoadImage ("bed4.bmp");
   Win32::TransparentBlt (txDC(), 1060, 590, 100,100, bed4, 0,0, 100,100, TX_WHITE);
   txDeleteDC(bed4);
   */
/*
   HDC carpet = txLoadImage ("carpet1.bmp");
   Win32::TransparentBlt (txDC(), 1060,110,100,100, carpet,0,0,100,100, TX_WHITE);
   txDeleteDC(carpet);

   HDC carpet2 = txLoadImage ("carpet2.bmp");
   Win32::TransparentBlt (txDC(),  1060,270,100,100, carpet2,0,0,100,100, TX_WHITE);
   txDeleteDC(carpet2);

   HDC carpet3 = txLoadImage ("carpet3.bmp");
   Win32::TransparentBlt (txDC(),  1060,430,100,100, carpet3,0,0,100,100, TX_WHITE);
   txDeleteDC(carpet3);
   */


    return 0;
 }
