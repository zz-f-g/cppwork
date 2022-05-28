/* 2052110 自动化 郭子瞻 */
#include <conio.h>
#include <iomanip>
#include "hanoi.h"
#include "cmd_console_tools.h"
#include <iostream>
#include <windows.h>
using namespace std;
#define y_bottom 11
#define y_info 17

/* ----------------------------------------------------------------------------------

     本文件功能：
    1、存放被 hanoi_main.cpp 中根据菜单返回值调用的各菜单项对应的执行函数

     本文件要求：
    1、不允许定义外部全局变量（const及#define不在限制范围内）
    2、允许定义静态全局变量（具体需要的数量不要超过文档显示，全局变量的使用准则是：少用、慎用、能不用尽量不用）
    3、静态局部变量的数量不限制，但使用准则也是：少用、慎用、能不用尽量不用
    4、按需加入系统头文件、自定义头文件、命名空间等

   ----------------------------------------------------------------------------------- */

/* global variables */
static unsigned int cnt = 1;
static int tops[3] = {0};
static int state[3][MAXSIZE] = {0};

/* functions for menu3
init_stack
print_row_stack
init_state
move_state
print_row_state
*/

/*Initialize the stack by giving top ptr
- input:
    int top
    int stack[]
*/
void init_stack(int top, int stack[])
{
    int i = 0;
    while (top > 0)
    {
        stack[i] = top;
        ++i;
        --top;
    }
}

/*print stack in a row
- input:
    int stack[]
    int top
*/
void print_row_stack(int stack[], int top)
{
    int i = 0;
    while (top > 0)
    {
        cout << setw(2) << stack[i];
        --top;
        ++i;
    }
    while (i < MAXSIZE)
    {
        cout << "  ";
        ++i;
    }
}

/*Initialize the state
- input:
    int n: number of layers
    char src: source stack
- calling:
    init_stack()
*/
void init_state(int n, char src)
{
    init_stack(n, state[src - 'A']);
    tops[src - 'A'] = n;
}

/*Move state of 3 stacks
- input:
    char src: source stack
    char dst: destination stack
*/
void move_state(char src, char dst)
{
    state[dst - 'A'][tops[dst - 'A']++] = state[src - 'A'][--tops[src - 'A']];
}

/*print state of 3 stacks in a row
 */
void print_row_state()
{
    cout << " A:";
    print_row_stack(state[0], tops[0]);
    cout << " B:";
    print_row_stack(state[1], tops[1]);
    cout << " C:";
    print_row_stack(state[2], tops[2]);
    cout << endl;
}

/* functions for menu4
init_col_print
move_col_print
wait
*/

/*Print initial information
- input:
    int n: number of layers
    char src: source stack
*/
void init_col_print(int n, char src)
{
    const int x_ABC[3] = {10, 20, 30};
    for (int i = 0; i < MAXSIZE; ++i)
        cout << endl;
    cout << endl;
    cout << "         =========================" << endl;
    cout << "           A         B         C" << endl;
    cout << endl
         << endl
         << endl;
    if (1) // ??
    {
        cout << "初始:               ";
        print_row_state();
    }
    for (int i = 0; i < n; ++i)
    {
        cct_gotoxy(x_ABC[src - 'A'], y_bottom - i);
        cout << setw(2) << n - i;
    }
}

/*Change print info when moving
- input:
    char src: source stack
    char dst: destination stack
*/
void move_col_print(char src, char dst)
{
    const int x_ABC[3] = {10, 20, 30};
    cct_gotoxy(x_ABC[src - 'A'], y_bottom - tops[src - 'A']);
    cout << "  ";
    cct_gotoxy(x_ABC[dst - 'A'], y_bottom - tops[dst - 'A'] + 1);
    cout << setw(2) << state[dst - 'A'][tops[dst - 'A'] - 1];
}

/*Wait certain time according to mode input
- int delay_mode: delay mode (0-5)
*/
void wait(int delay_mode)
{
    char ch = '0';
    int delay;
    if (delay_mode)
    {
        switch (delay_mode)
        {
            case 1:
                delay = 1000;
                break;
            case 2:
                delay = 500;
                break;
            case 3:
                delay = 100;
                break;
            case 4:
                delay = 50;
                break;
            case 5:
                delay = 10;
                break;
            default:
                break;
        }
        Sleep(delay);
    }
    else
    {
        while (ch != '\r') // [RETURN]: 13
            ch = _getch();
    }
}

/* recursion function and its subsidary
action_step
hanoi_recur
*/

/*action of each step in recursion
- input:
    int n: number of layers
    char src: source cylinder (A/a, B/b, C/c)
    char dst: destination cylinder (A/a, B/b, C/c)
    int selection: selection in menu (1-4, 8)
    int delay_mode: delay mode in wait()
*/
void action_step(int n, char src, char dst, int selection, int delay_mode)
{
    switch (selection)
    {
        case 1:
            cout << setw(2) << n << "# " << src << "-->" << dst << endl;
            break;
        case 2:
            cout << setw(5) << cnt << ": " << setw(2) << n << "# "
                 << src << "-->" << dst << endl;
            break;
        case 3:
            move_state(src, dst);
            cout << "第" << setw(4) << cnt << " 步(" << setw(2) << n << "): "
                 << src << "-->" << dst;
            print_row_state();
            break;
        case 4:
            cct_gotoxy(0, y_info);
            wait(delay_mode);
            cout << "第" << setw(4) << cnt << " 步(" << setw(2) << n << "): "
                 << src << "-->" << dst;
            move_state(src, dst);
            print_row_state();
            move_col_print(src, dst);
            cct_gotoxy(0, y_info + 4);
            break;
        default:
            break;
    }
    ++cnt;
}

/*hanoi recursion function
- call:
    action_step(): action each step according to selection
    static var: counter
- input:
    int n: number of layers
    char src: source cylinder (A/a, B/b, C/c)
    char tmp: temporary cylinder (A/a, B/b, C/c)
    char dst: destination cylinder (A/a, B/b, C/c)
    int selection: selection in menu (1-4, 8)
    int delay_mode: delay mode in wait()
*/
void hanoi_recur(int n, char src, char tmp, char dst, int selection, int delay_mode)
{
    if (n == 1)
    {
        action_step(n, src, dst, selection, delay_mode);
        return;
    }
    else
    {
        hanoi_recur(n - 1, src, dst, tmp, selection, delay_mode);
        action_step(n, src, dst, selection, delay_mode);
        hanoi_recur(n - 1, tmp, src, dst, selection, delay_mode);
    }
}

/* basic function called in hanoi_main.cpp
initial
exit_selection
*/

/*initial print
- input:
    int selection: selection in menu (1-9)
*/
void initial(int n, char src, char dst, int selection, int delay_mode)
{
    switch (selection)
    {
        case 3:
            init_state(n, src);
            cout << "初始:               ";
            print_row_state();
            break;
        case 4:
            cct_cls();
            cout << "从 " << src << " 移动到 " << dst << "，共 " << n << " 层，";
            cout << "延时设置为 " << delay_mode << endl;
            init_state(n, src);
            init_col_print(n, src);
            break;
        default:
            break;
    };
}

/*exit the part of selection
- input:
    int selection: selection in menu (1-9)
*/
void exit_selection(int selection)
{
    cnt = 1;
    tops[0] = 0;
    tops[1] = 0;
    tops[2] = 0;
    cout << "按回车键继续";
    wait(0);
}
