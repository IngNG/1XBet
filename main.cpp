#include "TXLib.h"
#include "button.cpp"
#include "picture.cpp"
#include "shirina and vasota.cpp"

//integer constant that mean lenght of pictures array
const int PICT_LEN = 16;


int main()
{
    txCreateWindow(1200, 800);
    HDC background = txLoadImage("Pics\\Background2.bmp");

    bool exitProgram = false;
    int last_num_obj = 0;

    char* category = "";
    int pageNumber = 0;

    Picture kartinkaVCentreEkrana[1000];

    Picture pic[PICT_LEN];
    pic[0] = {1090, 100, 70, 150, "Pics\\Furniture\\Divan1.bmp", "Divan"};
    pic[5] = {1070, 250, 120,50,  "Pics\\Furniture\\Divan4.bmp","Divan"};
    pic[4] = {1070, 400, 120,50, "Pics\\Furniture\\Divan3.bmp","Divan" };
    pic[1] = {1090, 550, 70, 150, "Pics\\Furniture\\Divan2.bmp",  "Divan"};

    pic[2] = {1090, 110, 70, 150, "Pics\\Cover\\Cover1.bmp", "Cover"};
    pic[3] = {1090, 320, 70, 150, "Pics\\Cover\\Cover3.bmp", "Cover" };

    pic[6] = {1090, 110, 100, 100, "Pics\\Furniture\\������1.bmp","Chair"};
    pic[7] = {1090, 220, 100, 100, "Pics\\Furniture\\������2.bmp","Chair"};
    pic[8] = {1090, 330, 100, 100, "Pics\\Furniture\\������3.bmp","Chair"};
    pic[9] = {1090, 440, 100, 100, "Pics\\Furniture\\Stul1.bmp","Chair"};
    pic[10] ={1090, 550, 100, 100, "Pics\\Furniture\\Stul2.bmp","Chair"};

    pic[11] ={1090, 110, 75, 75,  "Pics\\Wall\\brick.bmp", "Wall"};
    pic[12] ={1090, 320, 75, 75,  "Pics\\Wall\\mel.bmp", "Wall"};
    pic[13] ={1090, 580, 75, 75,  "Pics\\Wall\\wood.bmp", "Wall"};

   pic[14] =


	int sum = 0;
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


    for (int i = 0; i < PICT_LEN; i++)
    {
		pic[i].img = txLoadImage(pic[i].adress.c_str());
		pic[i].src_shirina = get_width(pic[i].adress.c_str());
		pic[i].src_vasota=get_height (pic[i].adress.c_str());
		pic[i].visible = true;
    }

    Knopka buttons[6];
    buttons[0] = {500, 270, 680, 320, "������"};
    buttons[1] = {500, 320, 680, 370, "����������", "��������"};
    buttons[2] = {500, 370, 680, 420, "���������",  "��������� ����������", "������"};
    buttons[3] = {500, 420, 680, 470, "����������", "C����� �����",        "�����"};
    buttons[4] = {500, 470, 680, 520, "�����"};

    Knopka buttons2[6];
    buttons2[0] = {55,20,180,70,"������","Divan" };
    buttons2[1] = {255,20,380,70,"�����", "Divan"};
    buttons2[2] = {455,20,580,70,"�����", "Wall"};
    buttons2[3] = {655,20,780,70,"������","Chair"};
    buttons2[4] = {855,20,980,70,"�����","Cover"};



    int kartinka  = -100;
    while(!exitProgram)
    {
        txBegin();

        if (pageNumber == 0)
        {
            txBitBlt (txDC(), 0, 0, 1200, 800, background, 0, 0);
            txSetFillColor(TX_WHITE);
            txSetColor(TX_WHITE);

            txSelectFont("Arial", 40);
            txDrawText(300,100,900,150,"������ ���� ��������");

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
            //mouse
            for (int i = 0; i < last_num_obj ; i++)
            {
                if(kartinkaVCentreEkrana[i].knopka2())
                {
                    kartinkaVCentreEkrana[i].clickedBlock = true;
                }

                if (!(txMouseButtons() & 1) && kartinkaVCentreEkrana[i].clickedBlock)
                {
                    kartinkaVCentreEkrana[i].x = txMouseX();
                    kartinkaVCentreEkrana[i].y = txMouseY();

                   kartinkaVCentreEkrana[i].clickedBlock = false;
                }
            }


       //granica
            for (int i = 0; i < last_num_obj ; i++)
            {
                  if (kartinkaVCentreEkrana[i].x < 10)
                  {
                   kartinkaVCentreEkrana[i].x = 10 ;
                  }
                  if (kartinkaVCentreEkrana[i].y < 100)
                  {
                  kartinkaVCentreEkrana[i].y = 100;
                   }
        }

            txBitBlt(txDC(), 0, 0, 1200, 800, background, 0, 0);

            txSetFillColor(TX_GRAY);
            txRectangle(10, 100, 1200 - 150, 800 - 2);
            //peremeshenie
           for(int i = 0; i < last_num_obj; i++)
           {
            if(kartinkaVCentreEkrana[i].knopka2())
            {
              kartinka = i;
            }
           }

           if(kartinka >= 0 && GetAsyncKeyState(VK_LEFT))
           {
            kartinkaVCentreEkrana[kartinka].x -= 3;
           }

           if(kartinka >= 0 && GetAsyncKeyState(VK_RIGHT))
           {
            kartinkaVCentreEkrana[kartinka].x += 3;
           }
           if(kartinka >= 0 && GetAsyncKeyState(VK_UP))
           {
            kartinkaVCentreEkrana[kartinka].y -= 3;
           }
           if(kartinka >= 0 && GetAsyncKeyState(VK_DOWN))
           {
            kartinkaVCentreEkrana[kartinka].y += 3;
           }

           if(kartinka >= 0 && GetAsyncKeyState(VK_DELETE))
           {
            kartinkaVCentreEkrana[kartinka] = kartinkaVCentreEkrana[last_num_obj - 1];
            last_num_obj -= 1 ;
            kartinka = - 100 ;
           }



            //Top buttons
            for (int n = 0; n < 5; n++)
            {
                buttons2[n].drawButton();
            }

            //Right pictures�
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

            for (int n = 0; n < 5; n++)
            {
                if (knopka(buttons2[n].x,buttons2[n].y))
                {
                    category = buttons2[n].textMessage;
                }
            }

            for (int i = 0; i < PICT_LEN; i++)
            {
                if (category == pic[i].category and pic[i].knopka())
                {
                    int x = random (10,  1050 - pic[i].shirina);
                    int y = random (100, 800 - pic[i].vasota);

                    kartinkaVCentreEkrana[last_num_obj] = {
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
