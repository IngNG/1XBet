#include "TXLib.h"
#include "button.cpp"
#include "picture.cpp"
#include "files.cpp"
#include <fstream>
#include <iostream>
#include <string>


using namespace std;


const int START_PAGE = 0;
const int MAIN_PAGE = 1;
const int MENU_OPSHIONS = 2;
const int MENU_INFO = 3;

const int COLICHEs = 7;

const bool DEBUG = false;



void drawPeremennya(int x, int y, int perem)
{
	char str[100];
	sprintf(str, "%d", perem);
	txTextOut(x, y, str);
}
void drawPeremennya(int x, int y, bool perem)
{
	if (perem == true)
		txTextOut(x, y, "true");
	else
		txTextOut(x, y, "true");
}

void obrysovat_fon(const int VARIANTS_LEFT, Picture kartincaUP[], int last_num_obj, int vybrannaya_kartinka )
{
		txSetFillColor(TX_GRAY);
		txSetColor(TX_WHITE);
		txRectangle(10, 100, VARIANTS_LEFT, txGetExtentY() - 2);

		for (int k = 0; k < last_num_obj; k++)
		{
			if (kartincaUP[k].visible)
			{
				if (k == vybrannaya_kartinka)
				{
					Picture vk = kartincaUP[k];
					txSetColor(TX_RED, 3);
					txRectangle (vk.x-2, vk.y-2, vk.x + vk.shirina+2, vk.y + vk.vasota+2);
				}
				drawPic(kartincaUP[k]);
			}
		}

}




int main()
{
    txCreateWindow(1200, 800);
    HDC background = txLoadImage("Pics\\Background2.bmp");



    const int VARIANTS_LEFT = txGetExtentX() - 150;

    bool exitProgram = false;
    int mysic_vkl_vkl = 0;

    string selected_category = "1";
    int pageNumber = 0;

    Picture kartincaUP[1000];

    int last_num_obj = 0;
    int bylo_kartinok = last_num_obj;


    Picture pic[1000];


    int PICT_LEN = 0;
    PICT_LEN = chtenie("Pics\\Krovat\\", PICT_LEN, pic);
    PICT_LEN = chtenie("Pics\\Divan\\", PICT_LEN,pic);
    PICT_LEN = chtenie("Pics\\Wall\\", PICT_LEN,pic);
    PICT_LEN = chtenie("Pics\\Cover\\", PICT_LEN,pic);
    PICT_LEN = chtenie("Pics\\Chair\\", PICT_LEN,pic);


    Knopka topMenu[COLICHEs];
    topMenu[0] = {55,20,180,70,"диваны","Divan" };
    topMenu[1] = {205,20,330,70,"койка", "Krovat"};
    topMenu[2] = {355,20,480,70,"стены", "Wall"};
    topMenu[3] = {505,20,630,70,"кресло","Chair"};
    topMenu[4] = {655,20,780,70,"ковры","Cover"};
    topMenu[5] = {805,20,960,70,"cохранить",""};
    topMenu[6] = {1055,20,1180,70,"выход",""};

    for (int i = 0; i < PICT_LEN; i++)
    {
        string stroka = pic[i].adress;
        int pos1 = stroka.find("\\") ;
        int pos2 = stroka.find("\\", pos1+ 1) ;
        pic[i].category=  stroka.substr(pos1 +1, pos2- pos1 - 1);
     	pic[i].img = txLoadImage(pic[i].adress.c_str());
		pic[i].src_shirina = get_width(pic[i].adress.c_str());
		pic[i].src_vasota=get_height (pic[i].adress.c_str());
		pic[i].visible = true;

        for (int k = 0; k < COLICHEs; k = k + 1)
        {
            if(pic[i].category == topMenu[k].category)
            {
                pic[i].y = 10 + topMenu[k].count_pics * 130;
                topMenu[k].count_pics = topMenu[k].count_pics + 1;
            }
		}

		//4to-t0
		if (pic[i].src_shirina > 1.3* pic[i].src_vasota)
		{
            pic[i].shirina = 120;
            pic[i].vasota = 50;
            pic[i].x = 1070;
		}
		else if (1.3 * pic[i].src_shirina < pic[i].src_vasota)
		{
            pic[i].shirina = 50;
            pic[i].vasota = 120;
            pic[i].x = 1090;
		}
		else
		{
            pic[i].shirina = 100;
            pic[i].vasota = 100;
            pic[i].x = 1090;
		}
    }

    Knopka mainMenu[6];
    mainMenu[0] = {500, 270, 680, 320, "Начать"};
    mainMenu[1] = {500, 320, 680, 370, "Продолжить"};
    mainMenu[2] = {500, 370, 680, 420, "Настройки",  "Настройки недоступны", "Ошибка"};
    mainMenu[3] = {500, 420, 680, 470, "Информация"};
    mainMenu[4] = {500, 470, 680, 520, "Выйти"};
    mainMenu[5] = {500, 520, 680, 570, "муз_off/on"};

    int vybrannaya_kartinka  = -100;
    int kol_sten = 0;
	bool vybrana_stena = false;

    bool clicked = false;
    while(!exitProgram)
    {
        txBegin();

        if (pageNumber == START_PAGE)
        {
            txBitBlt (txDC(), 0, 0, txGetExtentX(), txGetExtentY(), background, 0, 0);
            txSetFillColor(TX_WHITE);
            txSetColor(TX_WHITE);

            txSelectFont("Arial", 40);
            txDrawText(300,100,900,150,"Создай свою квартиру");

            for (int n = 0; n < 6; n++)
            {
                mainMenu[n].drawButton();
                mainMenu[n].showMessage();
            }

            if (knopka(mainMenu[0].x + 20,mainMenu[0].y))
            {
                pageNumber = MAIN_PAGE;
                last_num_obj = readFromFile(kartincaUP, pic, PICT_LEN);
                bylo_kartinok =  pageNumber;
                zapolnitKartinki(last_num_obj, kartincaUP);
            }
            if (knopka(mainMenu[3].x + 20,mainMenu[3].y))
            {
            	txMessageBox("уверенны");
                pageNumber = MENU_INFO;
            }
            if (knopka(mainMenu[4].x + 20,mainMenu[4].y))
            {
                exitProgram = true;
            }
            //continued
            if (knopka(mainMenu[1].x + 20,mainMenu[1].y))
            {
                last_num_obj = bylo_kartinok;
                pageNumber = MAIN_PAGE;
            }

			if (knopka(mainMenu[5].x,mainMenu[5].y))
			{
				if (mysic_vkl_vkl == 0)
				{
					txPlaySound("on_fon.wav");
					mysic_vkl_vkl = 1;
					txSleep(200);
				}
				else if (mysic_vkl_vkl == 1)
				{
					txPlaySound(NULL);
					mysic_vkl_vkl = 0;
					txSleep(200);
				}
			}
        }

        else if (pageNumber == MENU_OPSHIONS)
        {
            txBitBlt (txDC(), 0, 0, txGetExtentX(), txGetExtentY(), background, 0, 0);
            txSetFillColor(TX_WHITE);
            txSetColor(TX_BLACK);

			txSelectFont("Arial", 40);
			txRectangle(300, 100, 900, 470);
            txDrawText(300,100,900,700,
					"музыка");

            txSetColor(TX_WHITE);
			mainMenu[3].drawButton();
            if (knopka(mainMenu[3].x + 20,mainMenu[3].y))
            {
                pageNumber = MAIN_PAGE;
            }
        }



		else if (pageNumber == MENU_INFO)
        {
            txBitBlt (txDC(), 0, 0, txGetExtentX(), txGetExtentY(), background, 0, 0);
            txSetFillColor(TX_WHITE);
            txSetColor(TX_BLACK);

			txSelectFont("Arial", 40);
			txRectangle(300, 100, 900, 470);
            txDrawText(300,100,900,700,
					"информация\n"
					"создатели: Чираков Даниил \n"
					"Боровков Андрей Владимирович\n"
					"проект написан по мативам игры\n"
					"Sim Siti\n"
					"только в этом проекте вы будете редактировать\n"
					"квартиру, а не город\n"
					"УДАЧНОГО РЕДАКТИРОВАНИЯ"
					);

            txSetColor(TX_WHITE);
			mainMenu[4].drawButton();
            if (knopka(mainMenu[4].x + 20,mainMenu[4].y))
            {
                pageNumber = MAIN_PAGE;
            }
        }

        else if (pageNumber == MAIN_PAGE)
        {
            //mouse
            if (vybrannaya_kartinka >= 0 && kartincaUP[vybrannaya_kartinka].knopka2() && !clicked)
            {
                kartincaUP[vybrannaya_kartinka].clickedBlock = true;
                clicked = true;
            }

            if (vybrannaya_kartinka >= 0 && (txMouseButtons() & 1) && kartincaUP[vybrannaya_kartinka].clickedBlock)
            {
                kartincaUP[vybrannaya_kartinka].x = txMouseX() - kartincaUP[vybrannaya_kartinka].shirina/2;
                kartincaUP[vybrannaya_kartinka].y = txMouseY() - kartincaUP[vybrannaya_kartinka].vasota/2;

                drawPic(kartincaUP[vybrannaya_kartinka]);
            }

            if (vybrannaya_kartinka >= 0 && !(txMouseButtons() & 1) && kartincaUP[vybrannaya_kartinka].clickedBlock)
            {
                kartincaUP[vybrannaya_kartinka].clickedBlock = false;
                clicked = false;
            }

            txBitBlt (txDC(), 0, 0, txGetExtentX(), txGetExtentY(), background, 0, 0);
            txSetFillColor(TX_WHITE);
            txSetColor(TX_WHITE);

			//granica
			granica(kartincaUP, last_num_obj, VARIANTS_LEFT);

            txBitBlt(txDC(), 0, 0, txGetExtentX(), txGetExtentY(), background, 0, 0);

            txSetFillColor(TX_GRAY);
			txSetColor(TX_WHITE);
            txRectangle(10, 100, VARIANTS_LEFT, txGetExtentY() - 2);

            //Выход
            if (knopka(topMenu[6].x,topMenu[6].y))
            {
               pageNumber = START_PAGE;
               bylo_kartinok = last_num_obj;
               last_num_obj = 0;
            }

            //Сохранение
            if (knopka(topMenu[5].x,topMenu[5].y))
            {
                bylo_kartinok = last_num_obj;
                saveToFile( bylo_kartinok,  kartincaUP);
            }

            //Скриншот
            if (GetAsyncKeyState(VK_SNAPSHOT))
            {
                ScreenCapture(10,100,1000,700, "1.bmp", txWindow());
                txMessageBox("Сохранено в 1.bmp");
            }

            //peremeshenie
			for(int i = 0; i < last_num_obj; i++)
			{
				if (kartincaUP[i].knopka2())
				{
					vybrannaya_kartinka = i;
				}
			}

			//peremeshenie strelkami
			dvigatStrelkami(kartincaUP, vybrannaya_kartinka);

			if(vybrannaya_kartinka >= 0 && GetAsyncKeyState(VK_DELETE))
			{
				kartincaUP[vybrannaya_kartinka] = kartincaUP[last_num_obj - 1];
				last_num_obj -= 1 ;
				vybrannaya_kartinka = - 100 ;
				clicked = false;
			}


            //granica kartinok
			for (int i = 0; i < last_num_obj ; i++)
			{
                for (int k = 0; k < last_num_obj ; k++)
                {
                    if (k != i &&
                        kartincaUP[i].x < kartincaUP[k].x + kartincaUP[k].shirina  &&
                        kartincaUP[k].x < kartincaUP[i].x + kartincaUP[i].shirina  &&
                        kartincaUP[i].y < kartincaUP[k].y + kartincaUP[k].vasota &&
                        kartincaUP[k].y < kartincaUP[i].y + kartincaUP[i].vasota)
                    {
                        //Пишем, но не всегда
						if (DEBUG)
						{
							txTextOut(100, 100, "столкнулись");
						}

                        if (kartincaUP[i].x < kartincaUP[k].x)
                        {
                            kartincaUP[k].x = kartincaUP[i].x + kartincaUP[i].shirina;
                        }
                        else if (kartincaUP[i].x > kartincaUP[k].x)
                        {
                            kartincaUP[i].x = kartincaUP[k].x + kartincaUP[k].shirina;
                        }
                        else if (kartincaUP[i].y < kartincaUP[k].y)
                        {
                            kartincaUP[k].y = kartincaUP[i].y + kartincaUP[i].vasota;
                        }
                        else if (kartincaUP[i].y > kartincaUP[k].y)
                        {
                            kartincaUP[i].y = kartincaUP[k].y + kartincaUP[k].vasota;
                        }
                    }
                }
			}


            //Top buttons
            risovatKnopki(COLICHEs, topMenu,selected_category);

            //Right pictures 
            risovatkartinky(selected_category, PICT_LEN, pic);


            // тут рисуются выбранные картинки
            for (int i = 0; i < last_num_obj; i++)
            {
                if (kartincaUP[i].visible)
                {
					if (i == vybrannaya_kartinka)
					{
						Picture vk = kartincaUP[i];
						txSetColor(TX_RED, 3);
						txRectangle (vk.x-2, vk.y-2, vk.x + vk.shirina+2, vk.y + vk.vasota+2);
					}
                    drawPic(kartincaUP[i]);
                }
            }

            //Выбор категории
            for (int n = 0; n < COLICHEs; n++)
            {
                if (knopka(topMenu[n].x,topMenu[n].y))
                {
                    selected_category = topMenu[n].category;
                }
            }

            //Подсказка для стен
            if (selected_category == "Wall")
            {
				txSelectFont("Arial", 30);
				txDrawText(VARIANTS_LEFT,600,1200,800,
					"Нажмите\n"
					"NUM2, NUM4,\n"
					"NUM6, NUM8\n"
					" и стен \n"
					"станет\n"
					"больше");
            }

            for (int i = 0; i < PICT_LEN; i++)
            {
                if (selected_category == pic[i].category and pic[i].knopka())
                {
                    int x = random (10,  VARIANTS_LEFT - pic[i].shirina);
                    int y = random (100, txGetExtentY() - pic[i].vasota);

                    kartincaUP[last_num_obj] = {
                        pic[i].adress,
                        x,
                        y,
                        pic[i].shirina,
                        pic[i].vasota,
                        pic[i].category,
                        pic[i].img,
                        pic[i].src_shirina,
                        pic[i].src_vasota,
                        true
                    };

                    last_num_obj++;

					kol_sten = 0;
                    if (selected_category == "Wall")
					{
						//const char* text = txInputBox("выберите кол-во стен");
						//kol_sten = atoi(text);
						vybrana_stena = true;
					}
                }
            }



            if (vybrana_stena &&
				(	GetAsyncKeyState(VK_NUMPAD2) ||
					GetAsyncKeyState(VK_NUMPAD4) ||
					GetAsyncKeyState(VK_NUMPAD6) ||
					GetAsyncKeyState(VK_NUMPAD8)))
			{
					int i = 1;
					while(GetAsyncKeyState(VK_NUMPAD6))
					{
						obrysovat_fon (VARIANTS_LEFT, kartincaUP, last_num_obj, vybrannaya_kartinka);

						kartincaUP[last_num_obj] = kartincaUP[vybrannaya_kartinka];
						kartincaUP[last_num_obj].x = kartincaUP[last_num_obj].x + 100 * i;
						last_num_obj++;
						i = i + 1;
						txSleep(500);
					}

						while(GetAsyncKeyState(VK_NUMPAD4))
						{
						obrysovat_fon (VARIANTS_LEFT, kartincaUP, last_num_obj, vybrannaya_kartinka);

						kartincaUP[last_num_obj] = kartincaUP[vybrannaya_kartinka];
						kartincaUP[last_num_obj].x = kartincaUP[last_num_obj].x - 100 * i;
						last_num_obj++;
						i = i + 1;
						txSleep(500);
						 }

						while(GetAsyncKeyState(VK_NUMPAD8))
					{
						obrysovat_fon (VARIANTS_LEFT, kartincaUP, last_num_obj, vybrannaya_kartinka);

						kartincaUP[last_num_obj] = kartincaUP[vybrannaya_kartinka];
						kartincaUP[last_num_obj].y = kartincaUP[last_num_obj].y - 100 * i;
						last_num_obj++;
						i = i + 1;
						txSleep(500);
					}

						while(GetAsyncKeyState(VK_NUMPAD2))
					{
						obrysovat_fon (VARIANTS_LEFT, kartincaUP, last_num_obj, vybrannaya_kartinka);

						kartincaUP[last_num_obj] = kartincaUP[vybrannaya_kartinka];
						kartincaUP[last_num_obj].y = kartincaUP[last_num_obj].y + 100 * i;
						last_num_obj++;
						i = i + 1;
						txSleep(500);

					}

					vybrana_stena = false;
			}

            if (GetAsyncKeyState(VK_ESCAPE))
            {
                exitProgram = true;
                bylo_kartinok = last_num_obj;
            }
        }

        if (DEBUG)
		{
			drawPeremennya(100, 100, txMouseX());
			drawPeremennya(100, 150, txMouseY());
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

    for (int i = 0; i < bylo_kartinok; i++)
    {
        txDeleteDC(kartincaUP[i].img);
    }

    return 0;
}
