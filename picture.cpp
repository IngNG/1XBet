#include "TXLib.h"

struct Picture
{
    string adress;
    int x;
    int y;
    int shirina;
    int vasota;
    string category;
    HDC img;
    int src_shirina;
    int src_vasota;
    bool visible;
    bool clickedBlock;

    bool knopka()
    {
        if (txMouseX() > x and
            txMouseX() < x + shirina and
            txMouseY() > y and
            txMouseY() < y + vasota and
            txMouseButtons() & 1)
        {
            while (txMouseButtons() & 1) {
                txSleep(10);
            }

            return true;
        }

        return false;
    }

    bool knopka2()
    {
        if (txMouseX() > x and
            txMouseX() < x + shirina and
            txMouseY() > y and
            txMouseY() < y + vasota and
            txMouseButtons() & 1)
        {
            return true;
        }

        return false;
    }
};

void drawPic(Picture vk)
{
    Win32::TransparentBlt(txDC(), vk.x, vk.y, vk.shirina, vk.vasota,
                          vk.img, 0, 0, vk.src_shirina, vk.src_vasota,
                          TX_WHITE);
}

void risovatkartinky(string selected_category,int PICT_LEN, Picture pic[])
{
      for (int i = 0; i < PICT_LEN; i++)
            {
                if (pic[i].category == selected_category)
                {
                    drawPic(pic[i]);
                }
            }

}
