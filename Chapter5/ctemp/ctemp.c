#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
    int x, w;
    printf("������[1..99999]�����������ʾ���[6..10]\n");
    scanf("%d %d", &x, &w); //�������������
    printf("01234567890123456789\n"); //���

    char fmt[16];
    sprintf(fmt, "%%%dd*\n", w);
    printf(fmt, x);

    return 0;
}
