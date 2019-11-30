#include "TXLib.h"
#include "dirent.h"
#include "files.cpp"

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

void zapolnitKartinki(int last_num_obj, Picture kartincaUP[])
{
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
}

int readFromFile(Picture kartincaUP[], Picture pic[],int PICT_LEN)
{
    int last_num_obj = 0;

	string filename = selectFile(txWindow(), false);
    ifstream file (filename);
    string stroka_x;
    string stroka_y;
    string stroka_adress;

    while (file.good())
    {
        getline(file,stroka_x);

        if (stroka_x.size() > 1)
        {
            getline(file,stroka_y);
            getline(file,stroka_adress);

             kartincaUP[last_num_obj] = {
                stroka_adress,
                atoi(stroka_x.c_str()),
                atoi(stroka_y.c_str()),
                0,
                0,
                "",
                nullptr,
                0,
                0,
                true
            };

            //Пробежаться по всем pic
            //Если совпал адрес

            for (int i = 0; i < PICT_LEN; i++)
            {
                if (pic[i].adress == kartincaUP[last_num_obj].adress)
                {
                    kartincaUP[last_num_obj].img = pic[i].img;
                }
            }

            last_num_obj = last_num_obj + 1;
        }
    }

    file.close();

    return last_num_obj;
}

void saveToFile(int last_num_obj, Picture kartincaUP[])
{
    ofstream file1 (selectFile(txWindow(), true));

    for (int i = 0; i < last_num_obj; i++)
    {
        file1 << kartincaUP[i].x << endl;
        file1 << kartincaUP[i].y << endl;
        file1 << kartincaUP[i].adress << endl;
    }

    file1.close();
}


void granica(Picture kartincaUP[], int last_num_obj, int VARIANTS_LEFT)
{
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
}


void dvigatStrelkami(Picture kartincaUP[], int vybrannaya_kartinka )
{
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
}

int chtenie(string adress, int PICT_LEN, Picture pic[])
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
