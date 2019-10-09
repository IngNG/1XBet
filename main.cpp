#include "TXLib.h"
#include "button.cpp"
#include "picture.cpp"







int main()
{
    txCreateWindow (1200, 800);
    HDC  background  = txLoadImage ("Pics\\��� 2.bmp");

    char* category;
    Picture pic[15];
    pic[0] = {1090, 110, 75, 190, txLoadImage ("Pics\\Furniture\\�����1.bmp"), 185, 450, "�����"};
    pic[1] = {1090, 320, 75, 190, txLoadImage ("Pics\\Furniture\\�����2.bmp"), 185, 451, "�����"};
    pic[2] = {1090, 110, 75, 190, txLoadImage ("Pics\\����1.bmp"), 300, 224, "�����"};
    pic[3] = {1090, 320, 75, 190, txLoadImage ("Pics\\����3.bmp"), 350, 350, "�����"};
    pic[4] = {1070, 580, 120,50,  txLoadImage ("Pics\\Furniture\\�����3.bmp"), 451, 185, "�����"};
    pic[5] = {1070, 640, 120,50,  txLoadImage ("Pics\\Furniture\\�����4.bmp"), 451, 185, "�����"};
    pic[6] = {1090, 110, 75, 190, txLoadImage ("Pics\\Furniture\\������1.bmp"), 350, 250, "������"};
    pic[7] = {1090, 320, 75, 190, txLoadImage ("Pics\\Furniture\\������2.bmp"), 250, 150, "������"};
    pic[8] = {1090, 580, 75, 190, txLoadImage ("Pics\\Furniture\\������3.bmp"), 150, 150, "������"};
    pic[9] = {1090, 110, 75, 75, txLoadImage ("Pics\\Wall\\brick.bmp"),100, 100, "�����"};
    pic[10] = {1090,320, 75, 75, txLoadImage ("Pics\\Wall\\mel.bmp")  ,100, 100, "�����"};
    pic[11] = {1090,580, 75, 75, txLoadImage ("Pics\\Wall\\wood.bmp") ,100, 100, "�����"};
    int pageNumber = 0;

    Knopka buttons[6];
    buttons[0] = {500,270,680,320,"������","" };
    buttons[1] = {500,320,680,370,"����������", "��������"};
    buttons[2] = {500,370,680,420,"���������", "��������� ����������"};
    buttons[3] = {500,420,680,470,"����������","C����� �����"};
    buttons[4] = {500,470,680,520,"�����",""};

    bool exitProgram = false;

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
			txDrawText(300,100,900,150,"������ ���� ��������");



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

            //������ ������
            {
            txDrawText(55,20,180,70,"������");
            if(knopka(55,20))
            {
            category = "�����";
            txSleep(200);
            }

            txDrawText(255,20,380,70,"�����");
            if(knopka(240,40))
            {
            }

            txDrawText(455,20,580,70,"�����");
            if(knopka(440,40))
            {
            category = "�����";
            txSleep(200);
            }

            txDrawText(655,20,780,70,"������");
            if(knopka(640,40))
            {
            category = "������";
            txSleep(200);
            }

            txDrawText(855,20,980,70,"�����");
            if(knopka(840,40))
            {
            txSleep(200);
            category = "�����";
            }
            }


			//������ ������

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
        }



        txSleep(10);
        txEnd();



    }

    txDisableAutoPause();
    txDeleteDC(background);


    txDeleteDC(pic[0].img);
    txDeleteDC(pic[1].img);
    txDeleteDC(pic[2].img);
    txDeleteDC(pic[3].img);
    txDeleteDC(pic[4].img);
    txDeleteDC(pic[5].img);
    txDeleteDC(pic[6].img);
    txDeleteDC(pic[7].img);
    txDeleteDC(pic[8].img);
    txDeleteDC(pic[9].img);
    txDeleteDC(pic[10].img);
    txDeleteDC(pic[11].img);
                              ;




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
    HDC  brick= txLoadImage ("������.bmp");
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
