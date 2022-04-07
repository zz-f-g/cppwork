/* 2052110 �Զ��� ����հ */

#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <windows.h>

const int MAX_X = 69;	//����*��ɵı߿�Ŀ��
const int MAX_Y = 17;	//����*��ɵı߿�ĸ߶�

/***************************************************************************
  �������ƣ�
  ��    �ܣ������system("cls")һ���Ĺ��ܣ���Ч�ʸ�
  ���������
  �� �� ֵ��
  ˵    �������������Ļ���������������ǿɼ���������(ʹ�õ�ǰ��ɫ)
***************************************************************************/
void cls(const HANDLE hout)
{
	COORD coord = { 0, 0 };
	CONSOLE_SCREEN_BUFFER_INFO binfo; /* to get buffer info */
	DWORD num;

	/* ȡ��ǰ��������Ϣ */
	GetConsoleScreenBufferInfo(hout, &binfo);
	/* ����ַ� */
	FillConsoleOutputCharacter(hout, (TCHAR)' ', binfo.dwSize.X * binfo.dwSize.Y, coord, &num);
	/* ������� */
	FillConsoleOutputAttribute(hout, binfo.wAttributes, binfo.dwSize.X * binfo.dwSize.Y, coord, &num);

	/* ���ص�(0,0) */
	SetConsoleCursorPosition(hout, coord);
	return;
}

/***************************************************************************
  �������ƣ�gotoxy
  ��    �ܣ�������ƶ���ָ��λ��
  ���������HANDLE hout������豸���
			int X      ��ָ��λ�õ�x����
			int Y      ��ָ��λ�õ�y����
  �� �� ֵ����
  ˵    �����˺�����׼�޸�
***************************************************************************/
void gotoxy(const HANDLE hout, const int X, const int Y)
{
	COORD coord;
	coord.X = X;
	coord.Y = Y;
	SetConsoleCursorPosition(hout, coord);
}

/***************************************************************************
  �������ƣ�showch
  ��    �ܣ���ָ��λ�ô���ӡһ��ָ�����ַ�
  ���������HANDLE hout������豸���
			int X      ��ָ��λ�õ�x����
			int Y      ��ָ��λ�õ�y����
			char ch    ��Ҫ��ӡ���ַ�
  �� �� ֵ����
  ˵    �����˺�����׼�޸�
***************************************************************************/
void showch(const HANDLE hout, const int X, const int Y, const char ch)
{
	gotoxy(hout, X, Y);
	putchar(ch);
}

/***************************************************************************
  �������ƣ�init_border
  ��    �ܣ���ʾ��ʼ�ı߿�����ַ�
  ���������HANDLE hout������豸���
  �� �� ֵ����
  ˵    �����˺�����׼�޸�
***************************************************************************/
void init_border(const HANDLE hout)
{
	gotoxy(hout, 0, 0);	//����ƻ����Ͻ�(0,0)
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

	/* �����ʾ20����д��ĸ����ĸ��ֵ��XY���궼�����ʾ
	   rand()�����Ĺ��ܣ��������һ���� 0-32767 ֮�������
	   ˼������ʲô����£��������ѭ��ִ�����ɺ��㿴����ʵ����ĸ��������20���� */
	int i;
	for (i = 0; i < 20; i++)
		showch(hout, rand() % MAX_X + 1, rand() % MAX_Y + 1, 'A' + rand() % 26);

	return;
}

/***************************************************************************
  �������ƣ�menu
  ��    �ܣ���������ӡ�˵���ѡ��
  ���������HANDLE hout������豸���
  �� �� ֵ���˵�ѡ����ͣ�
  ˵    ������ĿҪ����
***************************************************************************/
int menu(const HANDLE hout)
{
	char choice;
	cls(hout);
	printf("1.��I��J��K��L��������������(��Сд���ɣ��߽�ֹͣ���������ͷ��ʱ�����ƶ�)\n");
	printf("2.��I��J��K��L��������������(��Сд���ɣ��߽���ƣ��������ͷ��ʱ�����ƶ�)\n");
	printf("3.�ü�ͷ�������������ң��߽�ֹͣ\n");
	printf("4.�ü�ͷ�������������ң��߽����\n");
	printf("5.��I��J��K��L��������������(��Сд���ɣ��߽�ֹͣ�����������ͷ��ʱ�����ƶ�)\n");
	printf("6.��I��J��K��L��������������(��Сд���ɣ��߽���ƣ����������ͷ��ʱ�����ƶ�)\n");
	printf("0.�˳�\n");
	printf("[��ѡ��0-6] ");
	choice = _getche();
	return choice - 48;
}

/***************************************************************************
  �������ƣ�move
  ��    �ܣ��ƶ���ꡢ�������λ���ַ����˳���ģʽ
  ���������HANDLE hout������豸���
           int choice: menu() �����ķ���ֵ
           int x: x ����
		   int y: y ����
  �� �� ֵ����
  ˵    ������ĿҪ����
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
  �������ƣ�exit_sys
  ��    �ܣ���ӡ��ʾ��Ϣ���˳�����
  ���������HANDLE hout������豸���
  �� �� ֵ����
  ˵    �����Լ���ӵĺ���
***************************************************************************/
void exit_sys(const HANDLE hout)
{
	gotoxy(hout, 0, MAX_Y + 6);
	printf("��Ϸ���������س����˳�.\n");
	char ch = '0';
	while (ch != 13) // [RETURN]: 13
	{
		ch = _getch();
	}
}

/***************************************************************************
  �������ƣ�main()
  ��    �ܣ�������
  �����������
  �� �� ֵ������
  ˵    ������ĿҪ����
***************************************************************************/
int main()
{
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE); //ȡ��׼����豸��Ӧ�ľ��
	/* ����α����������ӣ�ֻ���ڳ���ʼʱִ��һ�μ��� */
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

/*˼������
1. �ҵĳ����ܸ��ִ����⣬ԭ������Ϊ���ͷ����Ӧ�ļ���ĵڶ����ֽں� 'J' ��ͬ���ᴥ���� 'J' ��ͬ��Ч����
2. ��һ�������������ɵ� 20 ������������ͬ�ģ��ڿ������ɵ���ĸ������С�� 20 ����
*/
