#include "TXLib.h"
#include "button.cpp"
#include "picture.cpp"

//integer constant that mean lenght of pictures array
const int PICT_LEN = 15;

int main()
{
    txCreateWindow(1200, 800);

    HDC background = txLoadImage("Pics\\Background2.bmp");

    bool exitProgram = false;
    int last_num_obj = 0;

    char* category;
    int pageNumber = 0;

    Picture kartinkaVCentreEkrana[1000];

    Picture pic[PICT_LEN];
    pic[0] = {1090, 110, 75, 190, txLoadImage("Pics\\Furniture\\Divan1.bmp"),  185, 450, "Divan", true};
    pic[1] = {1090, 320, 75, 190, txLoadImage("Pics\\Furniture\\Divan2.bmp"),  185, 451, "Divan", true};
    pic[2] = {1090, 110, 75, 190, txLoadImage("Pics\\Cover\\Cover1.bmp"),      300, 224, "Cover", true};
    pic[3] = {1090, 320, 75, 190, txLoadImage("Pics\\Cover\\Cover3.bmp"),      350, 350, "Cover", true};
    pic[4] = {1070, 580, 120,50,  txLoadImage("Pics\\Furniture\\Divan3.bmp"),  451, 185, "Divan", true};
    pic[5] = {1070, 640, 120,50,  txLoadImage("Pics\\Furniture\\Divan4.bmp"),  451, 185, "Divan", true};
    pic[6] = {1090, 110, 75, 190, txLoadImage("Pics\\Furniture\\кресло1.bmp"), 350, 250, "кресло", true};
    pic[7] = {1090, 320, 75, 190, txLoadImage("Pics\\Furniture\\кресло2.bmp"), 250, 150, "кресло", true};
    pic[8] = {1090, 580, 75, 190, txLoadImage("Pics\\Furniture\\кресло3.bmp"), 150, 150, "кресло", true};
    pic[9] = {1090, 110, 75, 75,  txLoadImage("Pics\\Wall\\brick.bmp"),        100, 100, "стены", true};
    pic[10] = {1090,320, 75, 75,  txLoadImage("Pics\\Wall\\mel.bmp"),          100, 100, "стены", true};
    pic[11] = {1090,580, 75, 75,  txLoadImage("Pics\\Wall\\wood.bmp"),         100, 100, "стены", true};

    Knopka buttons[6];
    buttons[0] = {500, 270, 680, 320, "Начать"};
    buttons[1] = {500, 320, 680, 370, "Продолжить", "Загрузка"};
    buttons[2] = {500, 370, 680, 420, "Настройки",  "Настройки недоступны", "Ошибка"};
    buttons[3] = {500, 420, 680, 470, "Информация", "Cейчас найдём",        "Поиск"};
    buttons[4] = {500, 470, 680, 520, "Выйти"};

    while(!exitProgram)
    {
        txBegin();

        if (pageNumber == 0)
        {
			txBitBlt (txDC(), 0, 0, 1200, 800, background, 0, 0);
			txSetFillColor(TX_WHITE);
			txSetColor(TX_WHITE);

			txSelectFont("Arial", 40);
			txDrawText(300,100,900,150,"Создай свою квартиру");



            for (int n = 0; n < 5; n++)
            {
                buttons[n].drawButton();
                buttons[n].showMessage();
            }

			if (knopka(buttons[0].x + 20,buttons[0].y))
			{
                pageNumber = 1;
			}
			if (knopka(buttons[4].x + 20,buttons[4].y))
			{
				exitProgram = true;
			}
		}

        if (pageNumber == 1)
        {
            txBitBlt(txDC(), 0, 0, 1200, 800, background, 0, 0);

            txSetFillColor(TX_GRAY);
            txRectangle(10, 100, 1200 - 150, 800 - 2);

            //Кнопки сверху
            txDrawText(55,20,180,70,"диваны");
            if(knopka(55,20))
            {
                category = "Divan";
                txSleep(200);
            }

            txDrawText(255,20,380,70,"койка");
            if(knopka(240,40))
            {
                //code
            }

            txDrawText(455,20,580,70,"стены");
            if(knopka(440,40))
            {
                category = "стены";
                txSleep(200);
            }

            txDrawText(655,20,780,70,"кресло");
            if(knopka(640,40))
            {
                category = "кресло";
                txSleep(200);
            }

            txDrawText(855,20,980,70,"ковры");
            if(knopka(840,40))
            {
                txSleep(200);
                category = "Cover";
            }

            //Кнопки справа
            for (int i = 0; i < PICT_LEN; i++)
            {
                if (pic[i].category == category)
                {
                    drawPic(pic[i]);
                }
            }

            for (int i = 0; i < last_num_obj; i++)
            {
                if (kartinkaVCentreEkrana[i].visible)
                {
                    drawPic(kartinkaVCentreEkrana[i]);
                }
            }

            for(int i = 0; i < PICT_LEN; i++)
            {
                if(pic[i].knopka() and category == pic[i].category)
                {
                    int x = random(10, 900);
                    int y = random(70, 600);

                    kartinkaVCentreEkrana[last_num_obj] = {
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

                    last_num_obj++;
                }
            }

            if (GetAsyncKeyState(VK_ESCAPE))
            {
                exitProgram = true;
            }

        }

        txSleep(10);
        txEnd();
    }

    txDisableAutoPause();
    txDeleteDC(background);

    for (int i = 0; i < PICT_LEN; i++)
    {
        txDeleteDC(pic[i].img);
    }

    return 0;
 }

