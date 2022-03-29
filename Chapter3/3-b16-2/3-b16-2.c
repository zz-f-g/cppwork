/* 2052110 �Զ��� ����հ */

#include <stdio.h>
#include <windows.h> //ȡϵͳʱ��

int main()
{
	LARGE_INTEGER tick, begin, end;

	QueryPerformanceFrequency(&tick);	//��ü�����Ƶ��
	QueryPerformanceCounter(&begin);	//��ó�ʼӲ������������

	/* �˴�����ĳ���ʼ */

	int i, j, k;
	int cnt = 0;
	int a0, a1, a2;
	int b0, b1, b2;
	int c0, c1, c2;

	for (i = 123; i <= 987; i++)
	{
		a0 = i % 10;
		a1 = (i / 10) % 10;
		a2 = i / 100;
		if (a0 == a1 || a1 == a2 || a2 == a0 || a0 == 0 || a1 == 0)
			continue;
		for (j = i + 1; j <= 987; j++)
		{
			b0 = j % 10;
			b1 = (j / 10) % 10;
			b2 = j / 100;
			if (b0 == b1 || b1 == b2 || b2 == b0 || b0 == 0 || b1 == 0
				|| a0 == b0 || a0 == b1 || a0 == b2 || a1 == b0 || a1 == b1
				|| a1 == b2 || a2 == b0 || a2 == b1 || a2 == b2)
				continue;
			for (k = j + 1; k <= 987; k++)
			{
				c0 = k % 10;
				c1 = (k / 10) % 10;
				c2 = k / 100;
				if (c0 == c1 || c1 == c2 || c2 == c0 || c0 == 0 || c1 == 0
					|| a0 == c0 || a0 == c1 || a0 == c2 || a1 == c0 || a1 == c1
					|| a1 == c2 || a2 == c0 || a2 == c1 || a2 == c2
					|| b0 == c0 || b0 == c1 || b0 == c2 || b1 == c0 || b1 == c1
					|| b1 == c2 || b2 == c0 || b2 == c1 || b2 == c2)
					continue;
				if (i + j + k == 1953)
				{
					++cnt;
					printf("No.%3d : %d+%d+%d=%d\n", cnt, i, j, k, i + j + k);
				}
			}
		}
	}

	/* �˴�����ĳ������ */

	QueryPerformanceCounter(&end);		//�����ֹӲ������������

	printf("������Ƶ�� : %lldHz\n", tick.QuadPart);
	printf("���������� : %lld\n", end.QuadPart - begin.QuadPart);
	printf("%.6f��\n", (double)(end.QuadPart - begin.QuadPart) / tick.QuadPart);

	return 0;
}