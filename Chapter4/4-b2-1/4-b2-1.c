/* 2052110 �Զ��� ����հ */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int zeller(int y, int m, int d)
{
	int w, c;
	if (m == 1 || m == 2)
	{
		m += 12;
		y -= 1;
	}
	c = y / 100;
	y = y % 100;

	// Zeller Formula
	w = y + y / 4 + c / 4 - 2 * c + 13 * (m + 1) / 5 + d - 1;

	while (w < 0)
	{
		w += 7;
	}
	w = w % 7;

	return w;
}

int main()
{
	const int Lower_Limit = 1900;
	const int Upper_Limit = 2100;
	int y, m, d, w, ret, leap, day_tot;

	while (1)
	{
		printf("��������[1900-2100]���¡��գ�\n");
		ret = scanf("%d%d%d", &y, &m, &d);
		if (ret != 3)
		{
			scanf("%*[^\n]");
			scanf("%*c");
			printf("�����������������\n");
			continue;
		}
		else if (y > Upper_Limit || y < Lower_Limit)
		{
			printf("��ݲ���ȷ������������\n");
			continue;
		}
		else if (m > 12 || m <= 0)
		{
			printf("�·ݲ���ȷ������������\n");
			continue;
		}

		leap = (y % 400 == 0) || ((y % 100 != 0) && (y % 4 == 0));
		day_tot = (m == 2 || m == 4 || m == 6 || m == 9 || m == 11) ? (30 - (2 - leap) * (m == 2)) : 31;

		if (d > day_tot || d <= 0)
		{
			printf("�ղ���ȷ������������\n");
			continue;
		}
		else
			break;
	}
	
	w = zeller(y, m, d);

	printf("����");
	switch (w)
	{
		case 0:
			printf("��");
			break;
		case 1:
			printf("һ");
			break;
		case 2:
			printf("��");
			break;
		case 3:
			printf("��");
			break;
		case 4:
			printf("��");
			break;
		case 5:
			printf("��");
			break;
		case 6:
			printf("��");
			break;
	}
	printf("\n");

	return 0;
}