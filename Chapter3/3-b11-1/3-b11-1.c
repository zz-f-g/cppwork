/* 2052110 自动化 郭子瞻 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int year, month, date, day, leap;
	day = 0;
	int legal_input = 1;

	printf("请输入年，月，日\n");
    scanf("%d%d%d", &year, &month, &date);

	leap = (year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0);

	switch (month)
	{
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			if (date > 0 && date < 32)
				day = date;
			else
				legal_input = 0;
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			if (date > 0 && date < 31)
				day = date;
			else
				legal_input = 0;
			break;
		case 2:
			if ((leap && date > 0 && date < 30) || (!leap && date > 0 && date < 29))
				day = date;
			else
				legal_input = 0;
			break;
		default:
			printf("输入错误-月份不正确\n");
			legal_input = -1;
			break;
	}

	if (legal_input == 1)
	{
		switch (month)
		{
			case 1:
				break;
			case 2:
				day += 31;
				break;
			case 3:
				day += 59 + leap;
				break;
			case 4:
				day += 90 + leap;
				break;
			case 5:
				day += 120 + leap;
				break;
			case 6:
				day += 151 + leap;
				break;
			case 7:
				day += 181 + leap;
				break;
			case 8:
				day += 212 + leap;
				break;
			case 9:
				day += 243 + leap;
				break;
			case 10:
				day += 273 + leap;
				break;
			case 11:
				day += 304 + leap;
				break;
			case 12:
				day += 334 + leap;
				break;
		}
	    printf("%d-%d-%d是%d年的第%d天\n", year, month, date, year, day);
	}
	else if (legal_input == 0)
	{
	    printf("输入错误-日与月的关系非法\n");
	}

	return 0;
}
