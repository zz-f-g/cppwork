/* 2052110 �Զ��� ����հ */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	double change;
	int cnt = 0;
	int c50 = 0, c20 = 0, c10 = 0, c5 = 0, c1 = 0;
	int c05 = 0, c01 = 0, c005 = 0, c002 = 0, c001 = 0;

	printf("����������ֵ��\n");
	scanf("%lf", &change);

	switch ((int)((change+0.001) / 50))
	{
		case 1:
			change -= 50;
			c50 = 1;
			++cnt;
			break;
		case 0:
			break;
	}

	switch ((int)((change+0.001) / 20))
	{
		case 2:
			change -= 40;
			c20 = 2;
			cnt += 2;
			break;
		case 1:
			change -= 20;
			c20 = 1;
			++cnt;
			break;
		case 0:
			break;
	}

	switch ((int)((change+0.001) / 10))
	{
		case 1:
			change -= 10;
			c10 = 1;
			++cnt;
			break;
		case 0:
			break;
	}

	switch ((int)((change+0.001) / 5))
	{
		case 1:
			change -= 5;
			c5 = 1;
			++cnt;
			break;
		case 0:
			break;
	}

	switch ((int)((change+0.001) / 1))
	{
		case 4:
			change -= 4;
			c1 = 4;
			cnt += 4;
			break;
		case 3:
			change -= 3;
			c1 = 3;
			cnt += 3;
			break;
		case 2:
			change -= 2;
			c1 = 2;
			cnt += 2;
			break;
		case 1:
			change -= 1;
			c1 = 1;
			++cnt;
			break;
		case 0:
			break;
	}

	switch ((int)((change+0.001) / 0.5))
	{
		case 1:
			change -= 0.5;
			c05 = 1;
			++cnt;
			break;
		case 0:
			break;
	}

	switch ((int)((change+0.001) / 0.1))
	{
		case 4:
			change -= 0.4;
			c01 = 4;
			cnt += 4;
			break;
		case 3:
			change -= 0.3;
			c01 = 3;
			cnt += 3;
			break;
		case 2:
			change -= 0.2;
			c01 = 2;
			cnt += 2;
			break;
		case 1:
			change -= 0.1;
			c01 = 1;
			++cnt;
			break;
		case 0:
			break;
	}

	switch ((int)((change+0.001) / 0.05))
	{
		case 1:
			change -= 0.05;
			c005 = 1;
			++cnt;
			break;
		case 0:
			break;
	}

	switch ((int)((change+0.001) / 0.02))
	{
		case 2:
			change -= 0.04;
			c002 = 2;
			cnt += 2;
			break;
		case 1:
			change -= 0.02;
			c002 = 1;
			++cnt;
			break;
		case 0:
			break;
	}

	switch ((int)((change+0.001) / 0.01))
	{
		case 4:
			change -= 0.04;
			c001 = 4;
			cnt += 4;
			break;
		case 3:
			change -= 0.03;
			c001 = 3;
			cnt += 3;
			break;
		case 2:
			change -= 0.02;
			c001 = 2;
			cnt += 2;
			break;
		case 1:
			change -= 0.01;
			c001 = 1;
			++cnt;
			break;
		case 0:
			break;
	}

	printf("��%d�����㣬�������£�\n",cnt);
	if (c50)
		printf("50Ԫ : %d��\n", c50);
	if (c20)
		printf("20Ԫ : %d��\n", c20);
	if (c10)
		printf("10Ԫ : %d��\n", c10);
	if (c5)
		printf("5Ԫ  : %d��\n", c5);
	if (c1)
		printf("1Ԫ  : %d��\n", c1);
	if (c05)
		printf("5��  : %d��\n", c05);
	if (c01)
		printf("1��  : %d��\n", c01);
	if (c005)
		printf("5��  : %d��\n", c005);
	if (c002)
		printf("2��  : %d��\n", c002);
	if (c001)
		printf("1��  : %d��\n", c001);

	return 0;
}

