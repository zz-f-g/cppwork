/* 2052110 �Զ��� ����հ */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int isleap(int year)
{
    return (year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0);
}

int get_day(int month, int date, int dates[])
{
    --month;
    while (month >= 1)
    {
        date += dates[month - 1];
        --month;
    }
    return date;
}

int main()
{
	int year, month, date;
    int dates[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	printf("�������꣬�£���\n");
    scanf("%d%d%d", &year, &month, &date);

    dates[2 - 1] += isleap(year);

    if (month <= 0 || month > 12)
        printf("�������-�·ݲ���ȷ\n");
    else if (date > dates[month - 1] || date <= 0)
        printf("�������-�����µĹ�ϵ�Ƿ�\n");
	else
	    printf("%d-%d-%d��%d��ĵ�%d��\n", year, month, date, year, get_day(month, date, dates));

	return 0;
}
