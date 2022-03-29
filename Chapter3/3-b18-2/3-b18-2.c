/* 2052110 �Զ��� ����հ */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	const int Month = 12;
	const int Lower_limit = 2000;
	const int Upper_limit = 2030;
	const int Week = 7;

	int year;
	int month;
	int leap;
	int day_tot;
	int cnt_week;
	int cnt_day = 1;
	int flag_end = 0;
	int ret;
	int i;

	while (1) {
		printf("���������(%d-%d)���·�(1-%d) : ", Lower_limit, Upper_limit, Month);
		ret = scanf("%d%d", &year, &month);
		if (ret != 2) {
			scanf("%*[^\n]"); // ����������ʽ���껻�з�֮ǰ�����ݲ�����
			scanf("%*c"); // ��ȡ���з�������
		}
		else if (ret == 2 && (year >= Lower_limit && year <= Upper_limit && month > 0 && month <= Month))
			break;
		printf("����Ƿ�������������\n");
	}

	while (1) {
		printf("������%d��%d��1�յ�����(0-%d��ʾ������-������) : ", year, month, Week - 1);
		ret = scanf("%d", &cnt_week);
		if (ret == 0) {
			scanf("%*[^\n]"); // ����������ʽ���껻�з�֮ǰ�����ݲ�����
			scanf("%*c"); // ��ȡ���з�������
		}
		else if (ret == 1 && (cnt_week >= 0 && cnt_week < Week))
			break;
		printf("����Ƿ�������������\n");
	}

	leap = (year % 400 == 0) || ((year % 100 != 0) && (year % 4 == 0));
	day_tot = (month == 2 || month == 4 || month == 6 || month == 9 || month == 11) ? (30 - 2 * (month == 2) + leap) : 31;

	printf("%d��%d�µ�����Ϊ:\n", year, month);
	printf("������  ����һ  ���ڶ�  ������  ������  ������  ������\n");

	while (!flag_end)
	{
		for (i = 0; i < cnt_week; ++i)
			printf("        ");
		printf("%4d", cnt_day);
		++cnt_day;
		for (; cnt_week < Week - 1; ++cnt_week)
		{
			printf("%8d", cnt_day);
			if (cnt_day >= day_tot)
			{
				flag_end = 1;
				break;
			}
			++cnt_day;
		}
		printf("\n");
		cnt_week = 0;
	}

	return 0;
}