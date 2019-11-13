#include "TXLib.h"
#include "button.cpp"
#include "picture.cpp"
#include "files.cpp"

//integer constant that mean lenght of pictures array
const int PICT_LEN = 19;
const int START_PAGE = 0;
const int MAIN_PAGE = 1;
const int MENU_INFO = 3;
const int COLICHEs = 6;
const int MENU_OPSHIONS = 1;


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
    int last_num_obj = 0;
    int bylo_kartinok = 0;
    int mysic_vkl_vkl = 0;

    string selected_category = "1";
    int pageNumber = 0;

    Picture kartincaUP[1000];

    Picture pic[PICT_LEN];
    pic[0] = {1090, 110,  75, 190, "Pics\\Divan\\Divan1.bmp"};
    pic[1] = {1090, 320,  75, 190, "Pics\\Divan\\Divan2.bmp"};
    pic[2] = {1090, 110,  75, 190, "Pics\\Cover\\Cover1.bmp"};
    pic[3] = {1090, 320,  75, 190, "Pics\\Cover\\Cover3.bmp"};
    pic[4] = {1070, 580, 120,  50, "Pics\\Divan\\Divan3.bmp"};
    pic[5] = {1070, 640, 120,  50, "Pics\\Divan\\Divan4.bmp"};
    pic[6] = {1090, 110, 100, 100, "Pics\\Chair\\������1.bmp"};
    pic[7] = {1090, 220, 100, 100, "Pics\\Chair\\������2.bmp"};
    pic[8] = {1090, 330, 100, 100, "Pics\\Chair\\������3.bmp"};
    pic[9] = {1090, 440, 100, 100, "Pics\\Chair\\Stul1.bmp"};
    pic[10] ={1090, 550, 100, 100, "Pics\\Chair\\Stul2.bmp"};
    pic[11] ={1090, 110,  75,  75, "Pics\\Wall\\brick.bmp"};
    pic[12] ={1090, 320,  75,  75, "Pics\\Wall\\mel.bmp"};
    pic[13] ={1090, 580,  75,  75, "Pics\\Wall\\wood.bmp"};
    pic[14] ={1090, 110,  100,120, "Pics\\Krovat\\�������.bmp"};
    pic[15] ={1090, 230, 100, 100, "Pics\\Krovat\\bed1.bmp"};
    pic[16] ={1090, 350, 100, 100, "Pics\\Krovat\\bed2.bmp"};
    pic[17] ={1090, 460, 100, 100, "Pics\\Krovat\\bed3.bmp"};
    pic[18] ={1090, 580, 100, 100, "Pics\\Krovat\\bed4.bmp"};


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
    mainMenu[0] = {500, 270, 680, 320, "������"};
    mainMenu[1] = {500, 320, 680, 370, "����������"};
    mainMenu[2] = {500, 370, 680, 420, "���������",  "��������� ����������", "������"};
    mainMenu[3] = {500, 420, 680, 470, "����������"};//, "�� �����",        "�����"};
    mainMenu[4] = {500, 470, 680, 520, "�����"};
    mainMenu[5] = {500, 520, 680, 570, "���_off/on"};

    Knopka topMenu[COLICHEs];
    topMenu[0] = {55,20,180,70,"������","Divan" };
    topMenu[1] = {255,20,380,70,"�����", "Krovat"};
    topMenu[2] = {455,20,580,70,"�����", "Wall"};
    topMenu[3] = {655,20,780,70,"������","Chair"};
    topMenu[4] = {855,20,980,70,"�����","Cover"};
    topMenu[5] = {1055,20,1180,70,"�����",""};


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
                pageNumber = MAIN_PAGE; �����������
            }

			if (knopka(mainMenu[5].x,mainMenu[5].y))
			{
				if (mysic_vkl_v�1kl == 0)
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
					"���������: ������� ������ ��������\n"
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

            //Top buttons
            for (int n = 0; n < COLICHEs; n++)
            {
				txSetColor(TX_WHITE);
                if (topMenu[n].textMessage == selected_category)
                {
					txSetColor(TX_RED);
                }
                topMenu[n].drawButton();
            }

            //Right pictures�
            for (int i = 0; i < PICT_LEN; i++)
            {
                if (pic[i].category == selected_category)
                {
                    drawPic(pic[i]);
                }
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

            for (int n = 0; n < 6; n++)
            {
                if (knopka(topMenu[n].x,topMenu[n].y))
                {
                    selected_category = topMenu[n].textMessage;
                }
            }


            for (int i = 0; i < PICT_LEN; i++)
            {
                if (selected_category == pic[i].category and pic[i].knopka())
                {
                    int x = random (10,  VARIANTS_LEFT - pic[i].shirina);
                    int y = random (100, txGetExtentY() - pic[i].vasota);

                    kartincaUP[last_num_obj] = {
                        x,
                        y,
                        pic[i].shirina,
                        pic[i].vasota,
                        pic[i].adress,
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

    return 0;
}
