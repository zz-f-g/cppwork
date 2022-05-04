/* 2052110 自动化 郭子瞻 */

#include <iostream>
#include <iomanip>
#include <conio.h>
#include <windows.h>
#include "5-b7.h"
using namespace std;
#define MAXSIZE 10
#define y_bottom 11
#define y_info 17

/* Global variables */
static int topA = 0;
static int topB = 0;
static int topC = 0;
static int stateA[MAXSIZE] = { 0 };
static int stateB[MAXSIZE] = { 0 };
static int stateC[MAXSIZE] = { 0 };
static unsigned int cnt = 1;
static unsigned int delay;
static int ifdisplay;

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
		printf("%2d", stack[i]);
		--top;
		++i;
	}
	while (i < MAXSIZE)
	{
		printf("  ");
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
	switch (src)
	{
		case 'A':
			init_stack(n, stateA);
			topA = n;
			break;
		case 'B':
			init_stack(n, stateB);
			topB = n;
			break;
		case 'C':
			init_stack(n, stateC);
			topC = n;
			break;
	}
}

/*Move state of 3 stacks
- input:
	char src: source stack
	char dst: destination stack
*/
void move_state(char src, char dst)
{
	switch (src)
	{
		case 'A':
			switch (dst)
			{
				case 'B':
					stateB[topB++] = stateA[--topA];
					break;
				case 'C':
					stateC[topC++] = stateA[--topA];
					break;
			}
			break;
		case 'B':
			switch (dst)
			{
				case 'C':
					stateC[topC++] = stateB[--topB];
					break;
				case 'A':
					stateA[topA++] = stateB[--topB];
					break;
			}
			break;
		case 'C':
			switch (dst)
			{
				case 'A':
					stateA[topA++] = stateC[--topC];
					break;
				case 'B':
					stateB[topB++] = stateC[--topC];
					break;
			}
			break;
	}
}

/*print state of 3 stacks in a row
*/
void print_row_state()
{
	printf(" A:");
	print_row_stack(stateA, topA);
	printf(" B:");
	print_row_stack(stateB, topB);
	printf(" C:");
	print_row_stack(stateC, topC);
	printf("\n");
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
	if (ifdisplay)
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
void move_print(char src, char dst)
{
	const int x_ABC[3] = { 10, 20, 30 };
	switch (src)
	{
		case 'A':
			cct_gotoxy(x_ABC[src - 'A'], y_bottom - topA);
			break;
		case 'B':
			cct_gotoxy(x_ABC[src - 'A'], y_bottom - topB);
			break;
		case 'C':
			cct_gotoxy(x_ABC[src - 'A'], y_bottom - topC);
			break;
	}
	cout << "  ";
	switch (dst)
	{
		case 'A':
			cct_gotoxy(x_ABC[dst - 'A'], y_bottom - topA + 1);
			cout << setw(2) << stateA[topA - 1];
			break;
		case 'B':
			cct_gotoxy(x_ABC[dst - 'A'], y_bottom - topB + 1);
			cout << setw(2) << stateB[topB - 1];
			break;
		case 'C':
			cct_gotoxy(x_ABC[dst - 'A'], y_bottom - topC + 1);
			cout << setw(2) << stateC[topC - 1];
			break;
	}
}

/*Wait certain time according to mode input
*/
void wait()
{
	char ch = '0';
	if (delay)
		Sleep(delay);
	else
	{
		while (ch != 13) // [RETURN]: 13
			ch = _getch();
	}
}

/*Simulate hanoi
- input:
	int n：number of layer
	char src：source stack
	char tmp：temporary stack
	char dst：destination stack
*/
void hanoi(int n, char src, char tmp, char dst)
{
	if (n == 1)
	{
		cct_gotoxy(0, y_info);
		wait();
		cout << "第" << setw(4) << cnt << "步(" << n << "#: " << src << "-->" << dst << ") ";
		move_state(src, dst);
		if (ifdisplay)
			print_row_state();
		move_print(src, dst);
		++cnt;
		return;
	}
	else
	{
		hanoi(n - 1, src, dst, tmp);
		cct_gotoxy(0, y_info);
		wait();
		cout << "第" << setw(4) << cnt << "步(" << n << "#: " << src << "-->" << dst << ") ";
		move_state(src, dst);
		if (ifdisplay)
			print_row_state();
		move_print(src, dst);
		++cnt;
		hanoi(n - 1, tmp, src, dst);
	}
}

int main()
{
	int n;
	char src, tmp, dst;
	int delay_mode;
	while (1)
	{
		cout << "请输入汉诺塔的层数(1-" << MAXSIZE << ")" << endl;
		cin >> n;
		if (cin.fail())
			cin.clear();
		else if (n >= 1 && n <= MAXSIZE)
		{
			cin.ignore(32767, '\n');
			break;
		}
		cin.ignore(32767, '\n');
	}
	while (1)
	{
		cout << "请输入起始柱(A-C)" << endl;
		cin >> src;
		if (cin.fail())
			cin.clear();
		else if (src == 'A' || src == 'B' || src == 'C' || src == 'a' || src == 'b' || src == 'c')
		{
			if (src == 'a' || src == 'b' || src == 'c')
				src += 'A' - 'a';
			cin.ignore(32767, '\n');
			break;
		}
		cin.ignore(32767, '\n');
	}
	while (1)
	{
		cout << "请输入目标柱(A-C)" << endl;
		cin >> dst;
		if (cin.fail())
			cin.clear();
		else if (dst == 'A' || dst == 'B' || dst == 'C' || dst == 'a' || dst == 'b' || dst == 'c')
		{
			if (dst == 'a' || dst == 'b' || dst == 'c')
				dst += 'A' - 'a';
			cin.ignore(32767, '\n');
			if (dst == src)
			{
				cout << "目标柱(" << src << ")不能与起始柱(" << src << ")相同" << endl;
				continue;
			}
			break;
		}
		cin.ignore(32767, '\n');
	}
	tmp = 'A' + 'B' + 'C' - src - dst;
	while (1)
	{
		cout << "请输入移动速度(0-5: 0-按回车单步演示 1-延时最长 5-延时最短)" << endl;
		cin >> delay_mode;
		if (cin.fail())
			cin.clear();
		else if (delay_mode >= 0 && delay_mode <= 5)
			break;
		cin.ignore(32767, '\n');
	}
	switch (delay_mode)
	{
		case 0:
			delay = 0;
			break;
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
	}
	while (1)
	{
		cout << "请输入是否显示内部数组值(0-不显示 1-显示)" << endl;
		cin >> ifdisplay;
		if (cin.fail())
			cin.clear();
		else if (ifdisplay == 0 || ifdisplay == 1)
			break;
		cin.ignore(32767, '\n');
	}
	cct_cls();
	cout << "从 " << src << " 移动到 " << dst << "，共 " << n << " 层，";
	cout << "延时设置为 " << delay_mode << "，" << (ifdisplay ? "显示" : "不显示") << "内部数组值" << endl;
	init_state(n, src);
	init_print(n, src);
	hanoi(n, src, tmp, dst);
	cct_gotoxy(0, y_info + 4);
	system("pause");
	return 0;
}
