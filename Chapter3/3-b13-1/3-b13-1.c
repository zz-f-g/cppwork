/* 2052110 自动化 郭子瞻 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	double change;
	int cnt = 0;
	int c50 = 0, c20 = 0, c10 = 0, c5 = 0, c1 = 0;
	int c05 = 0, c01 = 0, c005 = 0, c002 = 0, c001 = 0;

	printf("请输入找零值：\n");
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

	printf("共%d张找零，具体如下：\n",cnt);
	if (c50)
		printf("50元 : %d张\n", c50);
	if (c20)
		printf("20元 : %d张\n", c20);
	if (c10)
		printf("10元 : %d张\n", c10);
	if (c5)
		printf("5元  : %d张\n", c5);
	if (c1)
		printf("1元  : %d张\n", c1);
	if (c05)
		printf("5角  : %d张\n", c05);
	if (c01)
		printf("1角  : %d张\n", c01);
	if (c005)
		printf("5分  : %d张\n", c005);
	if (c002)
		printf("2分  : %d张\n", c002);
	if (c001)
		printf("1分  : %d张\n", c001);

	return 0;
}

