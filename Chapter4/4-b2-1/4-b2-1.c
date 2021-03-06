/* 2052110 自动化 郭子瞻 */

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
		printf("请输入年[1900-2100]、月、日：\n");
		ret = scanf("%d%d%d", &y, &m, &d);
		if (ret != 3)
		{
			scanf("%*[^\n]");
			scanf("%*c");
			printf("输入错误，请重新输入\n");
			continue;
		}
		else if (y > Upper_Limit || y < Lower_Limit)
		{
			printf("年份不正确，请重新输入\n");
			continue;
		}
		else if (m > 12 || m <= 0)
		{
			printf("月份不正确，请重新输入\n");
			continue;
		}

		leap = (y % 400 == 0) || ((y % 100 != 0) && (y % 4 == 0));
		day_tot = (m == 2 || m == 4 || m == 6 || m == 9 || m == 11) ? (30 - (2 - leap) * (m == 2)) : 31;

		if (d > day_tot || d <= 0)
		{
			printf("日不正确，请重新输入\n");
			continue;
		}
		else
			break;
	}
	
	w = zeller(y, m, d);

	printf("星期");
	switch (w)
	{
		case 0:
			printf("日");
			break;
		case 1:
			printf("一");
			break;
		case 2:
			printf("二");
			break;
		case 3:
			printf("三");
			break;
		case 4:
			printf("四");
			break;
		case 5:
			printf("五");
			break;
		case 6:
			printf("六");
			break;
	}
	printf("\n");

	return 0;
}
