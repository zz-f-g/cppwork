/* 2051193 �Զ��� ����հ */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <cmath>
int main()
{
	const double Pi = 3.14159;
	int a, b, c;
	float s = 0;
	printf("�����������ε����߼���н�(�Ƕ�)\n");
	scanf("%d %d %d", &a, &b, &c);
	s = (float)(sin(c * Pi / 180.0) * a * b / 2);
	printf("���������Ϊ : %.3f\n", s);

	return 0;
}