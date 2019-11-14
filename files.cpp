#include <string>
#include "TXLib.h"

using namespace std;

int get_height(string adress)
{
    unsigned char info[54];
    FILE* f = fopen(adress.c_str(), "rb");
    fread(info, sizeof(unsigned char), 54, f);
    int height = *(int*)&info[22];

    return height;
}

int get_width(string adress)
{
    unsigned char info[54];
    FILE* f = fopen(adress.c_str (), "rb");
    fread(info, sizeof(unsigned char), 54, f);
    int width = *(int*)&info[18];


    return width;
}

