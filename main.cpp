#include "TXLib.h"
#include "button.cpp"
#include "picture.cpp"
#include "files.cpp"
#include <fstream>
#include <iostream>
#include <string>
#include  "dirent.h"


using namespace std;


const int START_PAGE = 0;
const int MAIN_PAGE = 1;
const int MENU_OPSHIONS = 2;
const int MENU_INFO = 3;

const int COLICHEs = 6;

int chtenie(string adress, int PICT_LEN)
{
    DIR *dir;
    struct dirent *ent;
    if ((dir = opendir (adress.c_str())) != NULL)
    {
      while ((ent = readdir (dir)) != NULL)
      {
        if ((string)ent->d_name != "." &&
            (string)ent->d_name != "..`")
        {
            pic[PICT_LEN] = { adress + (string)ent->d_name };
            PICT_LEN = PICT_LEN + 1;
        }
      }
      closedir (dir);
      }

      return PICT_LEN;
}


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

int main()
{
    txCreateWindow(1200, 800);
    HDC background = txLoadImage("Pics\\Background2.bmp");

    const int VARIANTS_LEFT = txGetExtentX() - 150;

    bool exitProgram = false;
    int bylo_kartinok = 0;
    int mysic_vkl_vkl = 0;

    string selected_category = "1";
    int pageNumber = 0;

    Picture kartincaUP[1000];

    int last_num_obj = readFromFile(kartincaUP);


    for (int i = 0; i < last_num_obj; i++)
    {
        string stroka = kartincaUP[i].adress;
        int pos1 = stroka.find("\\") ;
        int pos2 = stroka.find("\\", pos1+ 1) ;
        kartincaUP[i].category=  stroka.substr(pos1 +1, pos2- pos1 - 1);
     	kartincaUP[i].img = txLoadImage(kartincaUP[i].adress.c_str());
		kartincaUP[i].src_shirina = get_width(kartincaUP[i].adress.c_str());
		kartincaUP[i].src_vasota=get_height (kartincaUP[i].adress.c_str());
		kartincaUP[i].visible = true;

		//4to-t0
		if (kartincaUP[i].src_shirina > 1.3* kartincaUP[i].src_vasota)
		{
            kartincaUP[i].shirina = 120;
            kartincaUP[i].vasota = 50;
		}
		else if (1.3 * kartincaUP[i].src_shirina < kartincaUP[i].src_vasota)
		{
            kartincaUP[i].shirina = 75;
            kartincaUP[i].vasota = 190;
		}
		else
		{
            kartincaUP[i].shirina = 100;
            kartincaUP[i].vasota = 100;
		}
    }






    Picture pic[1000];


 int PICT_LEN = 0;

                   PICT_LEN = chtenie("Pics\\Krovat\\") ;
    DIR *dir;
    struct dirent *ent;
    if ((dir = opendir ("Pics\\Krovat")) != NULL)
    {
      while ((ent = readdir (dir)) != NULL)
      {
        if ((string)ent->d_name != "." &&
            (string)ent->d_name != "..`")
        {
            pic[PICT_LEN] = { "Pics\\Krovat\\" + (string)ent->d_name };
            PICT_LEN = PICT_LEN + 1;
        }
      }
      closedir (dir);
    }


    if ((dir = opendir ("Pics\\Divan")) != NULL)
    {
      while ((ent = readdir (dir)) != NULL)
      {
        if ((string)ent->d_name != "." &&
            (string)ent->d_name != "..`")
        {
            pic[PICT_LEN] = { "Pics\\Divan\\" + (string)ent->d_name };
            PICT_LEN = PICT_LEN + 1;
        }
      }
      closedir (dir);
      }


    if ((dir = opendir ("Pics\\Chair")) != NULL)
    {
      while ((ent = readdir (dir)) != NULL)
      {
        if ((string)ent->d_name != "." &&
            (string)ent->d_name != "..`")
        {
            pic[PICT_LEN] = { "Pics\\Chair\\" + (string)ent->d_name };
            PICT_LEN = PICT_LEN + 1;
        }
      }
      closedir (dir);
      }



    if ((dir = opendir ("Pics\\Cover")) != NULL)
    {
      while ((ent = readdir (dir)) != NULL)
      {
        if ((string)ent->d_name != "." &&
            (string)ent->d_name != "..`")
        {
            pic[PICT_LEN] = { "Pics\\Cover\\" + (string)ent->d_name };
            PICT_LEN = PICT_LEN + 1;
        }
      }
      closedir (dir);
      }

    if ((dir = opendir ("Pics\\Wall")) != NULL)
    {
      while ((ent = readdir (dir)) != NULL)
      {
        if ((string)ent->d_name != "." &&
            (string)ent->d_name != "..`")
        {
            pic[PICT_LEN] = { "Pics\\Wall\\" + (string)ent->d_name };
            PICT_LEN = PICT_LEN + 1;
        }
      }
      closedir (dir);
     }

    Knopka topMenu[COLICHEs];
    topMenu[0] = {55,20,180,70,"диваны","Divan" };
    topMenu[1] = {255,20,380,70,"койка", "Krovat"};
    topMenu[2] = {455,20,580,70,"стены", "Wall"};
    topMenu[3] = {655,20,780,70,"кресло","Chair"};
    topMenu[4] = {855,20,980,70,"ковры","Cover"};
    topMenu[5] = {1055,20,1180,70,"выход",""};

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
                    pic[i].y = 100 + topMenu[k].count_pics * 130;
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
    /*int sum = 0;
    for (int i = 0; i < PICT_LEN; i++)
    {
        if (pic[i].category == "Cover")
        sum = sum+1;
    }
    int nomer = 0;
    for (int i = 0; i < PICT_LEN; i++)
    {
        if (pic[i].category == "Cover")
        {
            pic[i].x =  100 + 600 * sum
            nomer = nomer+1;
        }
    }

    cout << sum;
    txSleep(1000);
    */
    Knopka mainMenu[6];
    mainMenu[0] = {500, 270, 680, 320, "Начать"};
    mainMenu[1] = {500, 320, 680, 370, "Продолжить"};
    mainMenu[2] = {500, 370, 680, 420, "Настройки",  "Настройки недоступны", "Ошибка"};
    mainMenu[3] = {500, 420, 680, 470, "Информация"};//, "ну такое",        "Поиск"};
    mainMenu[4] = {500, 470, 680, 520, "Выйти"};
    mainMenu[5] = {500, 520, 680, 570, "муз_off/on"};



    int vybrannaya_kartinka  = -100;
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
					"создатели: Чираков Даниил Павлович\n"
					"Боровков АНдрей Владимирович\n"
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

            txSelectFont("Arial", 40);
            txDrawText(300,100,900,150,"Создай ");


			//granica
			for (int i = 0; i < last_num_obj ; i++)
			{
				if (kartincaUP[i].x < 10)
				{
					kartincaUP[i].x = 10 ;
				}
				if (kartincaUP[i].y < 100)
				{
					kartincaUP[i].y = 100;
				}
				if (kartincaUP[i].x + kartincaUP[i].shirina > VARIANTS_LEFT)
				{
					kartincaUP[i].x = VARIANTS_LEFT - kartincaUP[i].shirina;
				}
				if (kartincaUP[i].y + kartincaUP[i].vasota > txGetExtentY())
				{
					kartincaUP[i].y = txGetExtentY()- kartincaUP[i].vasota;
				}
			}

            txBitBlt(txDC(), 0, 0, txGetExtentX(), txGetExtentY(), background, 0, 0);

            txSetFillColor(TX_GRAY);
			txSetColor(TX_WHITE);
            txRectangle(10, 100, VARIANTS_LEFT, txGetExtentY() - 2);

            if (knopka(VARIANTS_LEFT,30))
            {
               pageNumber = START_PAGE;
               bylo_kartinok = last_num_obj;
               last_num_obj = 0;
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
			if (vybrannaya_kartinka >= 0 && GetAsyncKeyState(VK_LEFT))
			{
				kartincaUP[vybrannaya_kartinka].x -= 3;
			}
			else if (vybrannaya_kartinka >= 0 && GetAsyncKeyState(VK_RIGHT))
			{
				kartincaUP[vybrannaya_kartinka].x += 3;
			}
			if (vybrannaya_kartinka >= 0 && GetAsyncKeyState(VK_UP))
			{
				kartincaUP[vybrannaya_kartinka].y -= 3;
			}
			else if (vybrannaya_kartinka >= 0 && GetAsyncKeyState(VK_DOWN))
			{
				kartincaUP[vybrannaya_kartinka].y += 3;
			}

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
                        txTextOut(100, 100, "столкнулись");

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

            for (int n = 0; n < 6; n++)
            {
                if (knopka(topMenu[n].x,topMenu[n].y))
                {
                    selected_category = topMenu[n].category;
                }
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
                }
            }

            if (GetAsyncKeyState(VK_ESCAPE))
            {
                exitProgram = true;
            }
        }
        /*
       drawPeremennya(100,100,kartincaUP[0].src_shirina );
       drawPeremennya(200,100,kartincaUP[0].clickedBlock );

       drawPeremennya(100,140,kartincaUP[1].src_shirina );
       drawPeremennya(200,140,kartincaUP[1].clickedBlock );
           */

        txSleep(10);
        txEnd();
    }

    txDisableAutoPause();
    txDeleteDC(background);

    for (int i = 0; i < PICT_LEN; i++)
    {
        txDeleteDC(pic[i].img);
    }


    saveToFile( last_num_obj,  kartincaUP);

    return 0;
}
