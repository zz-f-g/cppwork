/* 2052110 �Զ��� ����հ */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main()
{
	printf("������[0-100��)֮�������:\n");
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
	printf("ʮ��λ : %d\n", d9);
	printf("��λ   : %d\n", d8);
	printf("ǧ��λ : %d\n", d7);
	printf("����λ : %d\n", d6);
	printf("ʮ��λ : %d\n", d5);
	printf("��λ   : %d\n", d4);
	printf("ǧλ   : %d\n", d3);
	printf("��λ   : %d\n", d2);
	printf("ʮλ   : %d\n", d1);
	printf("Բ     : %d\n", d0);
	printf("��     : %d\n", d_1);
	printf("��     : %d\n", d_2);
*/

	printf("��д�����:\n");

	if (d_2 == 0 && d_1 == 0
		&& d0 == 0 && d1 == 0 && d2 == 0 && d3 == 0
		&& d4 == 0 && d5 == 0 && d6 == 0 && d7 == 0
		&& d8 == 0 && d9 == 0)
	{
		printf("��Բ��\n");
		return 0;
	}

	int zero_flag = 0;
	int higher_digit = 0;

	//ʮ��
	if (d9)
	{
		higher_digit = 1;
		switch (d9)
		{
			case 1:
				printf("Ҽ");
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
				printf("½");
				break;
			case 7:
				printf("��");
				break;
			case 8:
				printf("��");
				break;
			case 9:
				printf("��");
				break;
		}
		printf("ʰ");
	}

	//��
	if (d8)
	{
		higher_digit = 1;
		switch (d8)
		{
			case 1:
				printf("Ҽ");
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
				printf("½");
				break;
			case 7:
				printf("��");
				break;
			case 8:
				printf("��");
				break;
			case 9:
				printf("��");
				break;
		}
	}

	if (d9 > 0 || d8 > 0)
		printf("��");

	//ǧ��
	if (d7)
	{
		zero_flag = 0;
		higher_digit = 1;
		switch (d7)
		{
			case 1:
				printf("Ҽ");
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
				printf("½");
				break;
			case 7:
				printf("��");
				break;
			case 8:
				printf("��");
				break;
			case 9:
				printf("��");
				break;
		}
		printf("Ǫ");
	}
	else
	{
		if (higher_digit)
			zero_flag = 1;
	}

	//����
	if (d6)
	{
		higher_digit = 1;
		if (zero_flag)
		{
			printf("��");
			zero_flag = 0;
		}
		switch (d6)
		{
			case 1:
				printf("Ҽ");
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
				printf("½");
				break;
			case 7:
				printf("��");
				break;
			case 8:
				printf("��");
				break;
			case 9:
				printf("��");
				break;
		}
		printf("��");
	}
	else
	{
		if (higher_digit) {
			zero_flag = 1;
		}
	}

	//ʮ��
	if (d5)
	{
		higher_digit = 1;
		if (zero_flag)
		{
			printf("��");
			zero_flag = 0;
		}
		switch (d5)
		{
			case 1:
				printf("Ҽ");
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
				printf("½");
				break;
			case 7:
				printf("��");
				break;
			case 8:
				printf("��");
				break;
			case 9:
				printf("��");
				break;
		}
		printf("ʰ");
	}
	else
	{
		if (higher_digit) {
			zero_flag = 1;
		}
	}

	//��
	if (d4)
	{
		higher_digit = 1;
		if (zero_flag) {
			printf("��");
			zero_flag = 0;
		}
		switch (d4)
		{
			case 1:
				printf("Ҽ");
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
				printf("½");
				break;
			case 7:
				printf("��");
				break;
			case 8:
				printf("��");
				break;
			case 9:
				printf("��");
				break;
		}
	}

	if (d7 > 0 || d6 > 0 || d5 > 0 || d4 > 0)
	{
		zero_flag = 0;
		printf("��");
	}

	//ǧ
	if (d3)
	{
		zero_flag = 0;
		higher_digit = 1;
		switch (d3)
		{
			case 1:
				printf("Ҽ");
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
				printf("½");
				break;
			case 7:
				printf("��");
				break;
			case 8:
				printf("��");
				break;
			case 9:
				printf("��");
				break;
		}
		printf("Ǫ");
	}
	else
	{
		if (higher_digit)
			zero_flag = 1;
	}

	//��
	if (d2)
	{
		higher_digit = 1;
		if (zero_flag)
		{
			printf("��");
			zero_flag = 0;
		}
		switch (d2)
		{
			case 1:
				printf("Ҽ");
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
				printf("½");
				break;
			case 7:
				printf("��");
				break;
			case 8:
				printf("��");
				break;
			case 9:
				printf("��");
				break;
		}
		printf("��");
	}
	else
	{
		if (higher_digit) {
			zero_flag = 1;
		}
	}

	//ʮ
	if (d1)
	{
		higher_digit = 1;
		if (zero_flag)
		{
			printf("��");
			zero_flag = 0;
		}
		switch (d1)
		{
			case 1:
				printf("Ҽ");
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
				printf("½");
				break;
			case 7:
				printf("��");
				break;
			case 8:
				printf("��");
				break;
			case 9:
				printf("��");
				break;
		}
		printf("ʰ");
	}
	else
	{
		if (higher_digit) {
			zero_flag = 1;
		}
	}

	//��
	if (d0)
	{
		higher_digit = 1;
		if (zero_flag) {
			printf("��");
			zero_flag = 0;
		}
		switch (d0)
		{
			case 1:
				printf("Ҽ");
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
				printf("½");
				break;
			case 7:
				printf("��");
				break;
			case 8:
				printf("��");
				break;
			case 9:
				printf("��");
				break;
		}
	}

	higher_digit = d9 || d8 || d7 || d6 || d5 || d4 || d3 || d2 || d1 || d0;
	zero_flag = 0;
	if (higher_digit)
		printf("Բ");

	if (d_1 == 0 && d_2 == 0)
		printf("��");
	else
	{
		//��
		if (d_1)
		{
			switch (d_1)
			{
				case 1:
					printf("Ҽ");
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
					printf("½");
					break;
				case 7:
					printf("��");
					break;
				case 8:
					printf("��");
					break;
				case 9:
					printf("��");
					break;
			}
			printf("��");
			if (d_2 == 0)
				printf("��");
		}
		else
		{
			if (higher_digit) {
				zero_flag = 1;
			}
		}

		//��
		if (d_2)
		{
			higher_digit = 1;
			if (zero_flag) {
				printf("��");
				zero_flag = 0;
			}
			switch (d_2)
			{
				case 1:
					printf("Ҽ");
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
					printf("½");
					break;
				case 7:
					printf("��");
					break;
				case 8:
					printf("��");
					break;
				case 9:
					printf("��");
					break;
			}
			printf("��");
		}
	}
	printf("\n");

	return 0;
}

