/* 2052110 �Զ��� ����հ */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int ret, x;
	int lower_limit = 0;
	int upper_limit = 100;

	while (1) {
		printf("������x��ֵ[%d-%d] : ", lower_limit, upper_limit);
		ret = scanf("%d", &x); //����x�ķ�ʽ������scanf�Ҹ�ʽ��Ϊ%d����׼�÷�scanf
		// ���ַ����޷�����һ�ֳ��� int ��Χ�Ĵ��󣬱������룺4294967346(2^32+50)�����Ϊ 50.
		if (ret == 0) {
			scanf("%*[^\n]"); // ����������ʽ���껻�з�֮ǰ�����ݲ�����
			scanf("%*c"); // ��ȡ���з�������
		}
		else if (ret == 1 && (x >= lower_limit && x <= upper_limit))
			break;
	}
	printf("x=%d\n", x);
	return 0;
}
