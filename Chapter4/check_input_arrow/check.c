#include <stdio.h>
#include <conio.h>

int main()
{
    char ch = _getch();
    int a = ch;
    printf("%d", a);
    _getch();
    a = _getch();
    printf("%d", a);

    /*
    if (ch == -32)
    {
        ch = _getch();
        printf("%c%d\n", ch, ch);

    }
    else
        printf("%c\n", ch);
    */
    return 0;
}