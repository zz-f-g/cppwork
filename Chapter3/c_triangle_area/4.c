/* 2051193 自动化 郭子瞻 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <cmath>
int main()
{
	const double Pi = 3.14159;
	int a, b, c;
	float s = 0;
	printf("请输入三角形的两边及其夹角(角度)\n");
	scanf("%d %d %d", &a, &b, &c);
	s = (float)(sin(c * Pi / 180.0) * a * b / 2);
	printf("三角形面积为 : %.3f\n", s);

	return 0;
}