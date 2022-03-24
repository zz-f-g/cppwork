/* 2052110 ×Ô¶¯»¯ ¹ù×ÓÕ° */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main()
{
	printf("ÇëÊäÈë[0-100ÒÚ)Ö®¼äµÄÊý×Ö:\n");
	double n;
	scanf("%lf", &n);

	if (n >= 1e10 || n < 0)
		return 0;

	int d0, d1, d2, d3;
	int d4, d5, d6, d7;
	int d8, d9;
	int d_1, d_2;

	d9 = (int)(n / 1e9);
	n -= d9 * 1e9;
	d8 = (int)(n / 1e8);
	n -= d8 * 1e8;

	d7 = (int)(n / 1e7);
	n -= d7 * 1e7;
	d6 = (int)(n / 1e6);
	n -= d6 * 1e6;
	d5 = (int)(n / 1e5);
	n -= d5 * 1e5;
	d4 = (int)(n / 1e4);
	n -= d4 * 1e4;

	d3 = (int)(n / 1e3);
	n -= d3 * 1e3;
	d2 = (int)(n / 100);
	n -= d2 * 100;
	d1 = (int)(n / 10);
	n -= d1 * 10;
	d0 = (int)n;
	n -= d0;

	d_1 = (int)((n + 0.001) / 0.1);
	n -= 0.1 * d_1;
	d_2 = (int)((n + 0.001) / 0.01);

/*
	printf("Ê®ÒÚÎ» : %d\n", d9);
	printf("ÒÚÎ»   : %d\n", d8);
	printf("Ç§ÍòÎ» : %d\n", d7);
	printf("°ÙÍòÎ» : %d\n", d6);
	printf("Ê®ÍòÎ» : %d\n", d5);
	printf("ÍòÎ»   : %d\n", d4);
	printf("Ç§Î»   : %d\n", d3);
	printf("°ÙÎ»   : %d\n", d2);
	printf("Ê®Î»   : %d\n", d1);
	printf("Ô²     : %d\n", d0);
	printf("½Ç     : %d\n", d_1);
	printf("·Ö     : %d\n", d_2);
*/

	printf("´óÐ´½á¹ûÊÇ:\n");

	if (d_2 == 0 && d_1 == 0
		&& d0 == 0 && d1 == 0 && d2 == 0 && d3 == 0
		&& d4 == 0 && d5 == 0 && d6 == 0 && d7 == 0
		&& d8 == 0 && d9 == 0)
	{
		printf("ÁãÔ²Õû\n");
		return 0;
	}

	int zero_flag = 0;
	int higher_digit = 0;

	//Ê®ÒÚ
	if (d9)
	{
		higher_digit = 1;
		switch (d9)
		{
			case 1:
				printf("Ò¼");
				break;
			case 2:
				printf("·¡");
				break;
			case 3:
				printf("Èþ");
				break;
			case 4:
				printf("ËÁ");
				break;
			case 5:
				printf("Îé");
				break;
			case 6:
				printf("Â½");
				break;
			case 7:
				printf("Æâ");
				break;
			case 8:
				printf("°Æ");
				break;
			case 9:
				printf("¾Á");
				break;
		}
		printf("Ê°");
	}

	//ÒÚ
	if (d8)
	{
		higher_digit = 1;
		switch (d8)
		{
			case 1:
				printf("Ò¼");
				break;
			case 2:
				printf("·¡");
				break;
			case 3:
				printf("Èþ");
				break;
			case 4:
				printf("ËÁ");
				break;
			case 5:
				printf("Îé");
				break;
			case 6:
				printf("Â½");
				break;
			case 7:
				printf("Æâ");
				break;
			case 8:
				printf("°Æ");
				break;
			case 9:
				printf("¾Á");
				break;
		}
	}

	if (d9 > 0 || d8 > 0)
		printf("ÒÚ");

	//Ç§Íò
	if (d7)
	{
		zero_flag = 0;
		higher_digit = 1;
		switch (d7)
		{
			case 1:
				printf("Ò¼");
				break;
			case 2:
				printf("·¡");
				break;
			case 3:
				printf("Èþ");
				break;
			case 4:
				printf("ËÁ");
				break;
			case 5:
				printf("Îé");
				break;
			case 6:
				printf("Â½");
				break;
			case 7:
				printf("Æâ");
				break;
			case 8:
				printf("°Æ");
				break;
			case 9:
				printf("¾Á");
				break;
		}
		printf("Çª");
	}
	else
	{
		if (higher_digit)
			zero_flag = 1;
	}

	//°ÙÍò
	if (d6)
	{
		higher_digit = 1;
		if (zero_flag)
		{
			printf("Áã");
			zero_flag = 0;
		}
		switch (d6)
		{
			case 1:
				printf("Ò¼");
				break;
			case 2:
				printf("·¡");
				break;
			case 3:
				printf("Èþ");
				break;
			case 4:
				printf("ËÁ");
				break;
			case 5:
				printf("Îé");
				break;
			case 6:
				printf("Â½");
				break;
			case 7:
				printf("Æâ");
				break;
			case 8:
				printf("°Æ");
				break;
			case 9:
				printf("¾Á");
				break;
		}
		printf("°Û");
	}
	else
	{
		if (higher_digit) {
			zero_flag = 1;
		}
	}

	//Ê®Íò
	if (d5)
	{
		higher_digit = 1;
		if (zero_flag)
		{
			printf("Áã");
			zero_flag = 0;
		}
		switch (d5)
		{
			case 1:
				printf("Ò¼");
				break;
			case 2:
				printf("·¡");
				break;
			case 3:
				printf("Èþ");
				break;
			case 4:
				printf("ËÁ");
				break;
			case 5:
				printf("Îé");
				break;
			case 6:
				printf("Â½");
				break;
			case 7:
				printf("Æâ");
				break;
			case 8:
				printf("°Æ");
				break;
			case 9:
				printf("¾Á");
				break;
		}
		printf("Ê°");
	}
	else
	{
		if (higher_digit) {
			zero_flag = 1;
		}
	}

	//Íò
	if (d4)
	{
		higher_digit = 1;
		if (zero_flag) {
			printf("Áã");
			zero_flag = 0;
		}
		switch (d4)
		{
			case 1:
				printf("Ò¼");
				break;
			case 2:
				printf("·¡");
				break;
			case 3:
				printf("Èþ");
				break;
			case 4:
				printf("ËÁ");
				break;
			case 5:
				printf("Îé");
				break;
			case 6:
				printf("Â½");
				break;
			case 7:
				printf("Æâ");
				break;
			case 8:
				printf("°Æ");
				break;
			case 9:
				printf("¾Á");
				break;
		}
	}

	if (d7 > 0 || d6 > 0 || d5 > 0 || d4 > 0)
	{
		zero_flag = 0;
		printf("Íò");
	}

	//Ç§
	if (d3)
	{
		zero_flag = 0;
		higher_digit = 1;
		switch (d3)
		{
			case 1:
				printf("Ò¼");
				break;
			case 2:
				printf("·¡");
				break;
			case 3:
				printf("Èþ");
				break;
			case 4:
				printf("ËÁ");
				break;
			case 5:
				printf("Îé");
				break;
			case 6:
				printf("Â½");
				break;
			case 7:
				printf("Æâ");
				break;
			case 8:
				printf("°Æ");
				break;
			case 9:
				printf("¾Á");
				break;
		}
		printf("Çª");
	}
	else
	{
		if (higher_digit)
			zero_flag = 1;
	}

	//°Ù
	if (d2)
	{
		higher_digit = 1;
		if (zero_flag)
		{
			printf("Áã");
			zero_flag = 0;
		}
		switch (d2)
		{
			case 1:
				printf("Ò¼");
				break;
			case 2:
				printf("·¡");
				break;
			case 3:
				printf("Èþ");
				break;
			case 4:
				printf("ËÁ");
				break;
			case 5:
				printf("Îé");
				break;
			case 6:
				printf("Â½");
				break;
			case 7:
				printf("Æâ");
				break;
			case 8:
				printf("°Æ");
				break;
			case 9:
				printf("¾Á");
				break;
		}
		printf("°Û");
	}
	else
	{
		if (higher_digit) {
			zero_flag = 1;
		}
	}

	//Ê®
	if (d1)
	{
		higher_digit = 1;
		if (zero_flag)
		{
			printf("Áã");
			zero_flag = 0;
		}
		switch (d1)
		{
			case 1:
				printf("Ò¼");
				break;
			case 2:
				printf("·¡");
				break;
			case 3:
				printf("Èþ");
				break;
			case 4:
				printf("ËÁ");
				break;
			case 5:
				printf("Îé");
				break;
			case 6:
				printf("Â½");
				break;
			case 7:
				printf("Æâ");
				break;
			case 8:
				printf("°Æ");
				break;
			case 9:
				printf("¾Á");
				break;
		}
		printf("Ê°");
	}
	else
	{
		if (higher_digit) {
			zero_flag = 1;
		}
	}

	//¸ö
	if (d0)
	{
		higher_digit = 1;
		if (zero_flag) {
			printf("Áã");
			zero_flag = 0;
		}
		switch (d0)
		{
			case 1:
				printf("Ò¼");
				break;
			case 2:
				printf("·¡");
				break;
			case 3:
				printf("Èþ");
				break;
			case 4:
				printf("ËÁ");
				break;
			case 5:
				printf("Îé");
				break;
			case 6:
				printf("Â½");
				break;
			case 7:
				printf("Æâ");
				break;
			case 8:
				printf("°Æ");
				break;
			case 9:
				printf("¾Á");
				break;
		}
	}

	higher_digit = d9 || d8 || d7 || d6 || d5 || d4 || d3 || d2 || d1 || d0;
	zero_flag = 0;
	if (higher_digit)
		printf("Ô²");

	if (d_1 == 0 && d_2 == 0)
		printf("Õû");
	else
	{
		//½Ç
		if (d_1)
		{
			switch (d_1)
			{
				case 1:
					printf("Ò¼");
					break;
				case 2:
					printf("·¡");
					break;
				case 3:
					printf("Èþ");
					break;
				case 4:
					printf("ËÁ");
					break;
				case 5:
					printf("Îé");
					break;
				case 6:
					printf("Â½");
					break;
				case 7:
					printf("Æâ");
					break;
				case 8:
					printf("°Æ");
					break;
				case 9:
					printf("¾Á");
					break;
			}
			printf("½Ç");
			if (d_2 == 0)
				printf("Õû");
		}
		else
		{
			if (higher_digit) {
				zero_flag = 1;
			}
		}

		//·Ö
		if (d_2)
		{
			higher_digit = 1;
			if (zero_flag) {
				printf("Áã");
				zero_flag = 0;
			}
			switch (d_2)
			{
				case 1:
					printf("Ò¼");
					break;
				case 2:
					printf("·¡");
					break;
				case 3:
					printf("Èþ");
					break;
				case 4:
					printf("ËÁ");
					break;
				case 5:
					printf("Îé");
					break;
				case 6:
					printf("Â½");
					break;
				case 7:
					printf("Æâ");
					break;
				case 8:
					printf("°Æ");
					break;
				case 9:
					printf("¾Á");
					break;
			}
			printf("·Ö");
		}
	}
	printf("\n");

	return 0;
}

