/* -----------------------------------------

     本文件不需要提交、不允许改动

   ----------------------------------------- */
#include <iostream>
#include <iomanip>
#include <ctime>
#include <cmath>
#include <cstdio>
#include <conio.h>
#include <Windows.h>
#include "cmd_console_tools.h"
using namespace std;
#define cmd_buffer_size 19
#define x_cmd 60
#define y_cmd y_info + y_delta + 4
/* macros in menu4 */
#define y_bottom 11
#define y_info 19

/* macros in menu5,6 */
#define CLR_CYLINDERS COLOR_HYELLOW
#define y_delta 15
#define y_uplimit 2
#define y_pedestal 15
#define y_exit 30
#define height_cylinder 12
#define width_half_pedestal 11
#define width_interval 32



void clear_cmd_buffer(int len)
{
    for (int i = 0; i < len; ++i)
        putchar(' ');
    cct_gotoxy(x_cmd, y_cmd);
}

/* input legal command
- output:
    int command: ternary number, src & dst
        -1: Q
        00(0): invalid
        01(1): A -> B
        02(2): A -> C
        10(3): B -> A
        12(5): B -> C
        20(6): C -> A
        21(7): C -> B
*/
int command_input()
{
    char ch = '\0';
    int top = 0;
    char str[cmd_buffer_size] = { 0 };
    while (ch != '\r')
    {
        if (ch <= 32 || ch >= 127)
        {
            ch = _getch();
            continue;
        }
        if (top == cmd_buffer_size)
        {
            cct_gotoxy(x_cmd, y_cmd);
            clear_cmd_buffer(cmd_buffer_size);
            return 0;
        }
        putchar(ch);
        ch = _getch();
        ++top;
    }
    if (top == 2)
    {
        if (str[0] >= 'A' && str[0] <= 'C' || str[0] >= 'a' && str[0] <= 'c')
        {
            str[0] += (str[0] >= 'a' && str[0] <= 'c') ? 'A' - 'a' : 0;
            if (str[1] >= 'A' && str[1] <= 'C' || str[1] >= 'a' && str[1] <= 'c')
            {
                str[1] += (str[1] >= 'a' && str[1] <= 'c') ? 'A' - 'a' : 0;
                if (str[1] != str[0])
                    return (int)(str[0] - 'A') * 3 + (int)(str[1] - 'A');
            }
        }
    }
    else if (top == 1)
    {
        if (str[0] == 'Q' && str[0] == 'q')
        {
            cct_gotoxy(x_cmd, y_cmd);
            clear_cmd_buffer(cmd_buffer_size);
            return -1;
        }
    }
    cct_gotoxy(x_cmd, y_cmd);
    clear_cmd_buffer(cmd_buffer_size);
    return 0;
}

int main()
{
    cct_gotoxy(x_cmd, y_cmd);
    cout << command_input() << endl;
    return 0;
}