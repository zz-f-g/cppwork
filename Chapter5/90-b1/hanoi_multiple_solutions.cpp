/* 2052110 �Զ��� ����հ */
#include <conio.h>
#include <iomanip>
#include "hanoi.h"
#include "cmd_console_tools.h"
#include <iostream>
using namespace std;
#define y_bottom 11
#define y_info 17

/* ----------------------------------------------------------------------------------

     ���ļ����ܣ�
	1����ű� hanoi_main.cpp �и��ݲ˵�����ֵ���õĸ��˵����Ӧ��ִ�к���

     ���ļ�Ҫ��
	1�����������ⲿȫ�ֱ�����const��#define�������Ʒ�Χ�ڣ�
	2�������徲̬ȫ�ֱ�����������Ҫ��������Ҫ�����ĵ���ʾ��ȫ�ֱ�����ʹ��׼���ǣ����á����á��ܲ��þ������ã�
	3����̬�ֲ����������������ƣ���ʹ��׼��Ҳ�ǣ����á����á��ܲ��þ�������
	4���������ϵͳͷ�ļ����Զ���ͷ�ļ��������ռ��

   ----------------------------------------------------------------------------------- */

/* global variables */
static unsigned int delay;
static unsigned int cnt;
static int tops[3] = { 0 };
static int state[3][MAXSIZE] = { 0 };

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

/*Print initial information
- input:
	int n: number of layers
	char src: source stack
*/
void init_print(int n, char src)
{
	const int x_ABC[3] = { 10, 20, 30 };
	for (int i = 0; i < MAXSIZE; ++i)
		cout << endl;
	cout << endl;
	cout << "         =========================" << endl;
	cout << "           A         B         C" << endl;
	cout << endl << endl << endl;
	if (1) // ??
	{
		cout << "��ʼ:               ";
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
void move_print(char src, char dst)
{
	const int x_ABC[3] = { 10, 20, 30 };
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
	if (delay)
		Sleep(delay);
	else
	{
		while (ch != '\r') // [RETURN]: 13
			ch = _getch();
	}
}

/*action of each step in recursion
- input:
    int n: number of layers
*/
void action_step(int n, char src, char tmp, char dst, int selection, int delay_mode)
{
    cout << "��" << setw(4) << cnt << " ��(" << setw(2) << n << "): " << src << "-->" << dst;
    move_state(src, dst);
    print_row_state();
    ++cnt;
}

/*initial print
- input:
    int selection: selection in menu (1-9)
*/
void initial(int selection)
{
    ;
}

/*hanoi recursion function
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
    static unsigned int cnt = 1;
    if (n == 1)
    {
        action_step(n, src, tmp, dst, selection, delay_mode);
        return;
    }
    else
    {
        hanoi_recur(n - 1, src, dst, tmp);
        action_step(n, src, tmp, dst, selection);
        hanoi_recur(n - 1, tmp, src, dst);
    }
}

/*exit the part of selection
- input:
    int selection: selection in menu (1-9)
*/
void exit_selection(int selection)
{
    system("pause");
}
