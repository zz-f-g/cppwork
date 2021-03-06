/* 2052110 自动化 郭子瞻 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main()
{
	printf("请输入[0-100亿)之间的数字:\n");
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
	printf("十亿位 : %d\n", d9);
	printf("亿位   : %d\n", d8);
	printf("千万位 : %d\n", d7);
	printf("百万位 : %d\n", d6);
	printf("十万位 : %d\n", d5);
	printf("万位   : %d\n", d4);
	printf("千位   : %d\n", d3);
	printf("百位   : %d\n", d2);
	printf("十位   : %d\n", d1);
	printf("圆     : %d\n", d0);
	printf("角     : %d\n", d_1);
	printf("分     : %d\n", d_2);
*/

	printf("大写结果是:\n");

	if (d_2 == 0 && d_1 == 0
		&& d0 == 0 && d1 == 0 && d2 == 0 && d3 == 0
		&& d4 == 0 && d5 == 0 && d6 == 0 && d7 == 0
		&& d8 == 0 && d9 == 0)
	{
		printf("零圆整\n");
		return 0;
	}

	int zero_flag = 0;
	int higher_digit = 0;

	//十亿
	if (d9)
	{
		higher_digit = 1;
		switch (d9)
		{
			case 1:
				printf("壹");
				break;
			case 2:
				printf("贰");
				break;
			case 3:
				printf("叁");
				break;
			case 4:
				printf("肆");
				break;
			case 5:
				printf("伍");
				break;
			case 6:
				printf("陆");
				break;
			case 7:
				printf("柒");
				break;
			case 8:
				printf("捌");
				break;
			case 9:
				printf("玖");
				break;
		}
		printf("拾");
	}

	//亿
	if (d8)
	{
		higher_digit = 1;
		switch (d8)
		{
			case 1:
				printf("壹");
				break;
			case 2:
				printf("贰");
				break;
			case 3:
				printf("叁");
				break;
			case 4:
				printf("肆");
				break;
			case 5:
				printf("伍");
				break;
			case 6:
				printf("陆");
				break;
			case 7:
				printf("柒");
				break;
			case 8:
				printf("捌");
				break;
			case 9:
				printf("玖");
				break;
		}
	}

	if (d9 > 0 || d8 > 0)
		printf("亿");

	//千万
	if (d7)
	{
		zero_flag = 0;
		higher_digit = 1;
		switch (d7)
		{
			case 1:
				printf("壹");
				break;
			case 2:
				printf("贰");
				break;
			case 3:
				printf("叁");
				break;
			case 4:
				printf("肆");
				break;
			case 5:
				printf("伍");
				break;
			case 6:
				printf("陆");
				break;
			case 7:
				printf("柒");
				break;
			case 8:
				printf("捌");
				break;
			case 9:
				printf("玖");
				break;
		}
		printf("仟");
	}
	else
	{
		if (higher_digit)
			zero_flag = 1;
	}

	//百万
	if (d6)
	{
		higher_digit = 1;
		if (zero_flag)
		{
			printf("零");
			zero_flag = 0;
		}
		switch (d6)
		{
			case 1:
				printf("壹");
				break;
			case 2:
				printf("贰");
				break;
			case 3:
				printf("叁");
				break;
			case 4:
				printf("肆");
				break;
			case 5:
				printf("伍");
				break;
			case 6:
				printf("陆");
				break;
			case 7:
				printf("柒");
				break;
			case 8:
				printf("捌");
				break;
			case 9:
				printf("玖");
				break;
		}
		printf("佰");
	}
	else
	{
		if (higher_digit) {
			zero_flag = 1;
		}
	}

	//十万
	if (d5)
	{
		higher_digit = 1;
		if (zero_flag)
		{
			printf("零");
			zero_flag = 0;
		}
		switch (d5)
		{
			case 1:
				printf("壹");
				break;
			case 2:
				printf("贰");
				break;
			case 3:
				printf("叁");
				break;
			case 4:
				printf("肆");
				break;
			case 5:
				printf("伍");
				break;
			case 6:
				printf("陆");
				break;
			case 7:
				printf("柒");
				break;
			case 8:
				printf("捌");
				break;
			case 9:
				printf("玖");
				break;
		}
		printf("拾");
	}
	else
	{
		if (higher_digit) {
			zero_flag = 1;
		}
	}

	//万
	if (d4)
	{
		higher_digit = 1;
		if (zero_flag) {
			printf("零");
			zero_flag = 0;
		}
		switch (d4)
		{
			case 1:
				printf("壹");
				break;
			case 2:
				printf("贰");
				break;
			case 3:
				printf("叁");
				break;
			case 4:
				printf("肆");
				break;
			case 5:
				printf("伍");
				break;
			case 6:
				printf("陆");
				break;
			case 7:
				printf("柒");
				break;
			case 8:
				printf("捌");
				break;
			case 9:
				printf("玖");
				break;
		}
	}

	if (d7 > 0 || d6 > 0 || d5 > 0 || d4 > 0)
	{
		zero_flag = 0;
		printf("万");
	}

	//千
	if (d3)
	{
		zero_flag = 0;
		higher_digit = 1;
		switch (d3)
		{
			case 1:
				printf("壹");
				break;
			case 2:
				printf("贰");
				break;
			case 3:
				printf("叁");
				break;
			case 4:
				printf("肆");
				break;
			case 5:
				printf("伍");
				break;
			case 6:
				printf("陆");
				break;
			case 7:
				printf("柒");
				break;
			case 8:
				printf("捌");
				break;
			case 9:
				printf("玖");
				break;
		}
		printf("仟");
	}
	else
	{
		if (higher_digit)
			zero_flag = 1;
	}

	//百
	if (d2)
	{
		higher_digit = 1;
		if (zero_flag)
		{
			printf("零");
			zero_flag = 0;
		}
		switch (d2)
		{
			case 1:
				printf("壹");
				break;
			case 2:
				printf("贰");
				break;
			case 3:
				printf("叁");
				break;
			case 4:
				printf("肆");
				break;
			case 5:
				printf("伍");
				break;
			case 6:
				printf("陆");
				break;
			case 7:
				printf("柒");
				break;
			case 8:
				printf("捌");
				break;
			case 9:
				printf("玖");
				break;
		}
		printf("佰");
	}
	else
	{
		if (higher_digit) {
			zero_flag = 1;
		}
	}

	//十
	if (d1)
	{
		higher_digit = 1;
		if (zero_flag)
		{
			printf("零");
			zero_flag = 0;
		}
		switch (d1)
		{
			case 1:
				printf("壹");
				break;
			case 2:
				printf("贰");
				break;
			case 3:
				printf("叁");
				break;
			case 4:
				printf("肆");
				break;
			case 5:
				printf("伍");
				break;
			case 6:
				printf("陆");
				break;
			case 7:
				printf("柒");
				break;
			case 8:
				printf("捌");
				break;
			case 9:
				printf("玖");
				break;
		}
		printf("拾");
	}
	else
	{
		if (higher_digit) {
			zero_flag = 1;
		}
	}

	//个
	if (d0)
	{
		higher_digit = 1;
		if (zero_flag) {
			printf("零");
			zero_flag = 0;
		}
		switch (d0)
		{
			case 1:
				printf("壹");
				break;
			case 2:
				printf("贰");
				break;
			case 3:
				printf("叁");
				break;
			case 4:
				printf("肆");
				break;
			case 5:
				printf("伍");
				break;
			case 6:
				printf("陆");
				break;
			case 7:
				printf("柒");
				break;
			case 8:
				printf("捌");
				break;
			case 9:
				printf("玖");
				break;
		}
	}

	higher_digit = d9 || d8 || d7 || d6 || d5 || d4 || d3 || d2 || d1 || d0;
	zero_flag = 0;
	if (higher_digit)
		printf("圆");

	if (d_1 == 0 && d_2 == 0)
		printf("整");
	else
	{
		//角
		if (d_1)
		{
			switch (d_1)
			{
				case 1:
					printf("壹");
					break;
				case 2:
					printf("贰");
					break;
				case 3:
					printf("叁");
					break;
				case 4:
					printf("肆");
					break;
				case 5:
					printf("伍");
					break;
				case 6:
					printf("陆");
					break;
				case 7:
					printf("柒");
					break;
				case 8:
					printf("捌");
					break;
				case 9:
					printf("玖");
					break;
			}
			printf("角");
			if (d_2 == 0)
				printf("整");
		}
		else
		{
			if (higher_digit) {
				zero_flag = 1;
			}
		}

		//分
		if (d_2)
		{
			higher_digit = 1;
			if (zero_flag) {
				printf("零");
				zero_flag = 0;
			}
			switch (d_2)
			{
				case 1:
					printf("壹");
					break;
				case 2:
					printf("贰");
					break;
				case 3:
					printf("叁");
					break;
				case 4:
					printf("肆");
					break;
				case 5:
					printf("伍");
					break;
				case 6:
					printf("陆");
					break;
				case 7:
					printf("柒");
					break;
				case 8:
					printf("捌");
					break;
				case 9:
					printf("玖");
					break;
			}
			printf("分");
		}
	}
	printf("\n");

	return 0;
}

