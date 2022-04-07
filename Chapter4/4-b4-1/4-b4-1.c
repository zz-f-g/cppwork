/* 2052110 自动化 郭子瞻 */

#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <windows.h>

const int MAX_X = 69;	//定义*组成的边框的宽度
const int MAX_Y = 17;	//定义*组成的边框的高度

/***************************************************************************
  函数名称：
  功    能：完成与system("cls")一样的功能，但效率高
  输入参数：
  返 回 值：
  说    明：清除整个屏幕缓冲区，不仅仅是可见窗口区域(使用当前颜色)
***************************************************************************/
void cls(const HANDLE hout)
{
	COORD coord = { 0, 0 };
	CONSOLE_SCREEN_BUFFER_INFO binfo; /* to get buffer info */
	DWORD num;

	/* 取当前缓冲区信息 */
	GetConsoleScreenBufferInfo(hout, &binfo);
	/* 填充字符 */
	FillConsoleOutputCharacter(hout, (TCHAR)' ', binfo.dwSize.X * binfo.dwSize.Y, coord, &num);
	/* 填充属性 */
	FillConsoleOutputAttribute(hout, binfo.wAttributes, binfo.dwSize.X * binfo.dwSize.Y, coord, &num);

	/* 光标回到(0,0) */
	SetConsoleCursorPosition(hout, coord);
	return;
}

/***************************************************************************
  函数名称：gotoxy
  功    能：将光标移动到指定位置
  输入参数：HANDLE hout：输出设备句柄
			int X      ：指定位置的x坐标
			int Y      ：指定位置的y坐标
  返 回 值：无
  说    明：此函数不准修改
***************************************************************************/
void gotoxy(const HANDLE hout, const int X, const int Y)
{
	COORD coord;
	coord.X = X;
	coord.Y = Y;
	SetConsoleCursorPosition(hout, coord);
}

/***************************************************************************
  函数名称：showch
  功    能：在指定位置处打印一个指定的字符
  输入参数：HANDLE hout：输出设备句柄
			int X      ：指定位置的x坐标
			int Y      ：指定位置的y坐标
			char ch    ：要打印的字符
  返 回 值：无
  说    明：此函数不准修改
***************************************************************************/
void showch(const HANDLE hout, const int X, const int Y, const char ch)
{
	gotoxy(hout, X, Y);
	putchar(ch);
}

/***************************************************************************
  函数名称：init_border
  功    能：显示初始的边框及随机字符
  输入参数：HANDLE hout：输出设备句柄
  返 回 值：无
  说    明：此函数不准修改
***************************************************************************/
void init_border(const HANDLE hout)
{
	gotoxy(hout, 0, 0);	//光标移回左上角(0,0)
	printf("***********************************************************************\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("***********************************************************************\n");

	/* 随机显示20个大写字母，字母的值、XY坐标都随机显示
	   rand()函数的功能：随机生成一个在 0-32767 之间的整数
	   思考：在什么情况下，下面这个循环执行生成后，你看到的实际字母个数不足20个？ */
	int i;
	for (i = 0; i < 20; i++)
		showch(hout, rand() % MAX_X + 1, rand() % MAX_Y + 1, 'A' + rand() % 26);

	return;
}

/***************************************************************************
  函数名称：menu
  功    能：清屏、打印菜单并选择
  输入参数：HANDLE hout：输出设备句柄
  返 回 值：菜单选项（整型）
  说    明：题目要求函数
***************************************************************************/
int menu(const HANDLE hout)
{
	char choice;
	cls(hout);
	printf("1.用I、J、K、L键控制上下左右(大小写均可，边界停止，允许按左箭头键时向下移动)\n");
	printf("2.用I、J、K、L键控制上下左右(大小写均可，边界回绕，允许按左箭头键时向下移动)\n");
	printf("3.用箭头键控制上下左右，边界停止\n");
	printf("4.用箭头键控制上下左右，边界回绕\n");
	printf("5.用I、J、K、L键控制上下左右(大小写均可，边界停止，不允许按左箭头键时向下移动)\n");
	printf("6.用I、J、K、L键控制上下左右(大小写均可，边界回绕，不允许按左箭头键时向下移动)\n");
	printf("0.退出\n");
	printf("[请选择0-6] ");
	choice = _getche();
	return choice - 48;
}

/***************************************************************************
  函数名称：move
  功    能：移动光标、消除光标位置字符或退出该模式
  输入参数：HANDLE hout：输出设备句柄
           int choice: menu() 函数的返回值
           int x: x 坐标
		   int y: y 坐标
  返 回 值：无
  说    明：题目要求函数
***************************************************************************/
void move(const HANDLE hout, int choice, int x, int y)
{
	char direction;
	int ifloop = ((choice % 2) == 0);

	while (1)
	{
		direction = _getch();

		if (direction == 'q' || direction == 'Q') // quit
			break;

		if (direction == ' ') // cover by <space>
			putchar(' ');

		if ((choice == 3 || choice == 4) && direction == -32) // arrow keys
		{
			direction = _getch();
			switch (direction)
			{
				case 72: // up
					y = ifloop ? ((y - 1 - 1 + MAX_Y) % MAX_Y + 1) : ((y == 1) ? 1 : y - 1);
					break;
				case 80: // down
					y = ifloop ? ((y - 1 + 1) % MAX_Y + 1) : ((y == MAX_Y) ? MAX_Y : y + 1);
					break;
				case 75: // left
					x = ifloop ? ((x - 1 - 1 + MAX_X) % MAX_X + 1) : ((x == 1) ? 1 : x - 1);
					break;
				case 77: // right
					x = ifloop ? ((x - 1 + 1) % MAX_X + 1) : ((x == MAX_X) ? MAX_X : x + 1);
					break;
				default:
					break;
			}
		}
		else if (choice == 1 || choice == 2 || choice == 5 || choice == 6) // i, k, j, l
		{
			if (choice == 5 || choice == 6)
			{
				if (direction == -32)
					_getch();
			}
			switch (direction)
			{
				case 73:
				case 105: // up: i
					y = ifloop ? ((y - 1 - 1 + MAX_Y) % MAX_Y + 1) : ((y == 1) ? 1 : y - 1);
					break;
				case 75:
				case 107: // down: k
					y = ifloop ? ((y - 1 + 1) % MAX_Y + 1) : ((y == MAX_Y) ? MAX_Y : y + 1);
					break;
				case 74:
				case 106: // left: j
					x = ifloop ? ((x - 1 - 1 + MAX_X) % MAX_X + 1) : ((x == 1) ? 1 : x - 1);
					break;
				case 76:
				case 108: // right: l
					x = ifloop ? ((x - 1 + 1) % MAX_X + 1) : ((x == MAX_X) ? MAX_X : x + 1);
					break;
				default:
					break;
			}
		}
		gotoxy(hout, x, y);
	}
}

/***************************************************************************
  函数名称：exit_sys
  功    能：打印提示信息，退出程序
  输入参数：HANDLE hout：输出设备句柄
  返 回 值：无
  说    明：自己添加的函数
***************************************************************************/
void exit_sys(const HANDLE hout)
{
	gotoxy(hout, 0, MAX_Y + 6);
	printf("游戏结束，按回车键退出.\n");
	char ch = '0';
	while (ch != 13) // [RETURN]: 13
	{
		ch = _getch();
	}
}

/***************************************************************************
  函数名称：main()
  功    能：主函数
  输入参数：无
  返 回 值：整型
  说    明：题目要求函数
***************************************************************************/
int main()
{
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE); //取标准输出设备对应的句柄
	/* 生成伪随机数的种子，只需在程序开始时执行一次即可 */
	srand((unsigned int)(time(0)));

	int x = MAX_X / 2 + 1;
	int y = MAX_Y / 2 + 1;
	int choice;

	while (1)
	{
		choice = menu(hout);
		if (choice < 0 || choice > 6)
			continue;
		if (choice)
		{
			cls(hout);
			init_border(hout);
			gotoxy(hout, x, y);
			move(hout, choice, x, y);
			exit_sys(hout);
		}
		else
			break;
	}

	return 0;
}

/*思考题解答：
1. 我的程序能复现此问题，原因是因为左箭头键对应的键码的第二个字节和 'J' 相同，会触发和 'J' 相同的效果。
2. 不一定，如果随机生成的 20 个坐标中有相同的，在框中生成的字母数量将小于 20 个。
*/
