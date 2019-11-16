#include <iostream>
#include <fstream>
#include <TX_LIB>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
   ifstream file ("123.txt");
   string stroka;
   string stroka_x;
   while (file.good())
   {
    getline (file,stroka);
    cout << stroka << endl;
     }
     txSleep(1000);
     txCreateWindow(atoi(stroka_x.c_str()),600);
    file.close();
    return 0;
}
