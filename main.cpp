#include "TXLib.h"
#include "button.cpp"
#include "picture.cpp"


int main()
{
    txBegin();
    txCreateWindow (1200, 800);
    HDC  background  = txLoadImage ("Pics\\Background2.bmp");


    bool exitProgram = false;
    int last_num_obj = 0;
    Picture kartinkaVCentreEkrana[1000];
    /*kartinkaVCentreEkrana[0] = {390, 110, 75, 190, txLoadImage ("Pics\\Furniture\\Divan1.bmp"), 185, 451, "", false};
    kartinkaVCentreEkrana[1] = {390, 320, 75, 190, txLoadImage ("Pics\\Furniture\\Divan2.bmp"), 185, 451, "", false};
    kartinkaVCentreEkrana[2] = {590, 320, 75, 190, txLoadImage ("Pics\\Furniture\\Divan2.bmp"), 185, 451, "", false};
    kartinkaVCentreEkrana[3] = {590, 320, 75, 190, txLoadImage ("Pics\\Furniture\\Divan2.bmp"), 185, 451, "", false};
    kartinkaVCentreEkrana[4] = {190, 320, 75, 190, txLoadImage ("Pics\\Furniture\\Divan2.bmp"), 185, 451, "", false};

            */

    char* category;
    Picture pic[15];
    pic[0] = {1090, 110, 75, 190, txLoadImage ("Pics\\Furniture\\Divan1.bmp"), 185, 450, "Divan", true};
    pic[1] = {1090, 320, 75, 190, txLoadImage ("Pics\\Furniture\\Divan2.bmp"), 185, 451, "Divan", true};
    pic[2] = {1090, 110, 75, 190, txLoadImage ("Pics\\Cover\\Cover1.bmp"), 300, 224, "Cover", true};
    pic[3] = {1090, 320, 75, 190, txLoadImage ("Pics\\Cover\\Cover3.bmp"), 350, 350, "Cover", true};
    pic[4] = {1070, 580, 120,50,  txLoadImage ("Pics\\Furniture\\Divan3.bmp"), 451, 185, "Divan", true};
    pic[5] = {1070, 640, 120,50,  txLoadImage ("Pics\\Furniture\\Divan4.bmp"), 451, 185, "Divan", true};
    pic[6] = {1090, 110, 75, 190, txLoadImage ("Pics\\Furniture\\кресло1.bmp"), 350, 250, "кресло", true};
    pic[7] = {1090, 320, 75, 190, txLoadImage ("Pics\\Furniture\\кресло2.bmp"), 250, 150, "кресло", true};
    pic[8] = {1090, 580, 75, 190, txLoadImage ("Pics\\Furniture\\кресло3.bmp"), 150, 150, "кресло", true};
    pic[9] = {1090, 110, 75, 75, txLoadImage ("Pics\\Wall\\brick.bmp"),100, 100, "стены", true};
    pic[10] = {1090,320, 75, 75, txLoadImage ("Pics\\Wall\\mel.bmp")  ,100, 100, "стены", true};
    pic[11] = {1090,580, 75, 75, txLoadImage ("Pics\\Wall\\wood.bmp") ,100, 100, "стены", true};

    int pageNumber = 0;

    Knopka buttons[6];
    buttons[0] = {500,270,680,320,"Начать","" };
    buttons[1] = {500,320,680,370,"Продолжить", "Загрузка"};
    buttons[2] = {500,370,680,420,"Настройки", "настройки недоступны"};
    buttons[3] = {500,420,680,470,"Информация","Cейчас найдём"};
    buttons[4] = {500,470,680,520,"Выйти",""};


    Knopka buttons2[6];
    buttons2[0] = {55,20,180,70,"диваны","Divan" };
    buttons2[1] = {255,20,380,70,"койка", "Divan"};
    buttons2[2] = {455,20,580,70,"стены", "стены"};
    buttons2[3] = {655,20,780,70,"кресло","кресло"};
    buttons2[4] = {855,20,980,70,"ковры","Cover"};

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
            txBitBlt (txDC(), 0, 0, 1200, 800, background, 0, 0);
            txSetFillColor (TX_GRAY);
            txRectangle ( 10 , 100 , 1200 - 150 , 800 - 2 );

            //Кнопки сверху
            for (int n = 0;   n < 5; n++)
            {
                buttons2[n].drawButton();
                if(knopka(buttons2[n].x,buttons2[n].y))
                {
                    category = buttons2[n].textMessage;
                }
            }


            //Кнопки справа
        for(int i = 0; i < 15; i++)
        {
            if(pic[i].knopka()and category == pic[i].category)
            {
                int x = random (10,  1050 - pic[i].shirina);
                int y = random (100, 800 - pic[i].vasota);

                Picture tmp = {
                    x,
                    y,
                    pic[i].shirina,
                    pic[i].vasota,
                    pic[i].img,
                    pic[i].src_shirina,
                    pic[i].src_vasota,
                    "",
                    true
                };

                kartinkaVCentreEkrana[last_num_obj] = tmp;
                last_num_obj++;
                txSleep(200);
			}
		}


            for (int i = 0; i<15; i++)
            {
                if (pic[i].category == category)
                {
                    drawPic(pic[i]);
                }
            }





            if (GetAsyncKeyState(VK_ESCAPE))
            {
                exitProgram = true;
            }

            for (int i = 0; i < last_num_obj; i++)
            {
                if (kartinkaVCentreEkrana[i].visible)
                {
                    drawPic(kartinkaVCentreEkrana[i]);
                }
            }
        }



        txSleep(10);
        txEnd();
    }

    txDisableAutoPause();
    txDeleteDC(background);


    for (int i = 0; i<15; i++)
    {
        txDeleteDC(pic[i].img);
    }




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
    HDC  brick= txLoadImage ("ГЉГЁГ°ГЇГЁГ·.bmp");
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

    txEnd();

    return 0;
 }
