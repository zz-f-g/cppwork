#include <conio.h>
#include <iostream>
using namespace std;
int main()
{
    char ch;
    while ((ch = _getch()) != '\n')
    {
        cout << ch << (int)ch << endl;
    }
    return 0;
}