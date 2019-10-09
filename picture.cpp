#include "TXLib.h"
struct  Picture
{
    int x  ;
    int y ;
    int shirina;
    int vasota;
    HDC img;
    int src_shirina;
    int src_vasota;
    char* category ;

};

void drawPic (Picture vk)
{
    Win32::TransparentBlt (txDC(), vk.x, vk.y, vk.shirina, vk.vasota, vk.img, 0, 0, vk.src_shirina, vk.src_vasota, TX_WHITE);
}



