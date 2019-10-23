#include "TXLib.h"

bool knopka(int x, int y)
{
    if (txMouseX() > x       and
        txMouseX() < x + 180 and
        txMouseY() > y       and
        txMouseY() < y + 50  and
        txMouseButtons() & 1)
    {

        return true;
    }

    return false;
}

struct Knopka
{
	int x;
	int y;
	int x2;
	int y2;
	const char* text;
	char* textMessage;
	const char* headerMessage;

    void drawButton()
    {
        txDrawText(x, y, x2, y2, text);
    }

    void showMessage()
    {
        if (knopka(x,y) and textMessage != "" and textMessage != nullptr)
        {
            if (headerMessage != "" and headerMessage != nullptr)
            {
                txMessageBox(textMessage, headerMessage);
            }
            else
            {
                txMessageBox(textMessage);
            }
        }
    }
};
