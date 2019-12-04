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
    topMenu[0] = {55,20,180,70,"������","Divan" };
    topMenu[1] = {205,20,330,70,"�����", "Krovat"};
    topMenu[2] = {355,20,480,70,"�����", "Wall"};
    topMenu[3] = {505,20,630,70,"������","Chair"};
    topMenu[4] = {655,20,780,70,"�����","Cover"};
    topMenu[5] = {805,20,960,70,"c��������",""};
    topMenu[6] = {1055,20,1180,70,"�����",""};

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
    mainMenu[0] = {500, 270, 680, 320, "������"};
    mainMenu[1] = {500, 320, 680, 370, "����������"};
    mainMenu[2] = {500, 370, 680, 420, "���������",  "��������� ����������", "������"};
    mainMenu[3] = {500, 420, 680, 470, "����������"};
    mainMenu[4] = {500, 470, 680, 520, "�����"};
    mainMenu[5] = {500, 520, 680, 570, "���_off/on"};

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
            txDrawText(300,100,900,150,"������ ���� ��������");

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
            	txMessageBox("��������");
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
					"������");

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
					"����������\n"
					"���������: ������� ������ \n"
					"�������� ������ ������������\n"
					"������ ������� �� ������� ����\n"
					"Sim Siti\n"
					"������ � ���� ������� �� ������ �������������\n"
					"��������, � �� �����\n"
					"�������� ��������������"
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
            txDrawText(300,100,900,150,"������ ");

			//granica
			granica(kartincaUP, last_num_obj, VARIANTS_LEFT);

            txBitBlt(txDC(), 0, 0, txGetExtentX(), txGetExtentY(), background, 0, 0);

            txSetFillColor(TX_GRAY);
			txSetColor(TX_WHITE);
            txRectangle(10, 100, VARIANTS_LEFT, txGetExtentY() - 2);

            //�����
            if (knopka(topMenu[6].x,topMenu[6].y))
            {
               pageNumber = START_PAGE;
               bylo_kartinok = last_num_obj;
               last_num_obj = 0;
            }

            //����������
            if (knopka(topMenu[5].x,topMenu[5].y))
            {
                bylo_kartinok = last_num_obj;
                saveToFile( bylo_kartinok,  kartincaUP);
            }

            if (GetAsyncKeyState(VK_SNAPSHOT))
            {
                ScreenCapture(10,100,1000,700, "1.bmp", txWindow());
                txMessageBox("��������� � 1.bmp");
            }

            // �����������
			if (GetAsyncKeyState(VK_LCONTROL) &&
				GetAsyncKeyState(VK_LEFT) &&
				kartincaUP[vybrannaya_kartinka].category == "Wall")
			{
				kartincaUP[last_num_obj] = kartincaUP[vybrannaya_kartinka];
				kartincaUP[last_num_obj].x = kartincaUP[last_num_obj].x - 100;

				last_num_obj++;
			}

			if (GetAsyncKeyState(VK_LCONTROL) &&
				GetAsyncKeyState(VK_RIGHT) &&
				kartincaUP[vybrannaya_kartinka].category == "Wall")
			{
				kartincaUP[last_num_obj] = kartincaUP[vybrannaya_kartinka];
				kartincaUP[last_num_obj].x = kartincaUP[last_num_obj].x + 100;

				last_num_obj++;
			}

			if (GetAsyncKeyState(VK_LCONTROL) &&
				GetAsyncKeyState(VK_UP) &&
				kartincaUP[vybrannaya_kartinka].category == "Wall")
			{
				kartincaUP[last_num_obj] = kartincaUP[vybrannaya_kartinka];
				kartincaUP[last_num_obj].y = kartincaUP[last_num_obj].y - 100;

				last_num_obj++;
			}

			if (GetAsyncKeyState(VK_LCONTROL) &&
				GetAsyncKeyState(VK_DOWN) &&
				kartincaUP[vybrannaya_kartinka].category == "Wall")
			{
				kartincaUP[last_num_obj] = kartincaUP[vybrannaya_kartinka];
				kartincaUP[last_num_obj].y = kartincaUP[last_num_obj].y + 100;

				last_num_obj++;
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
                        txTextOut(100, 100, "�����������");

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

            //Right pictures�
            risovatkartinky(selected_category, PICT_LEN, pic);

            if (selected_category == "Wall")
            {
				txSelectFont("Arial", 30);
				txDrawText(VARIANTS_LEFT,600,1200,800,
					"�������\n"
					"NUM2, NUM4,\n"
					"NUM6, NUM8\n"
					" � ���� \n"
					"������\n"
					"������");
            }

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

            for (int n = 0; n < COLICHEs; n++)
            {
                if (knopka(topMenu[n].x,topMenu[n].y))
                {
                    selected_category = topMenu[n].category;
                }
            }

            //�������� ����� ��������
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
                bylo_kartinok = last_num_obj;
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

    for (int i = 0; i < bylo_kartinok; i++)
    {
        txDeleteDC(kartincaUP[i].img);
    }

    return 0;
}
