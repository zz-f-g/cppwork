// sprintf()
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
    int width_tot = 0, width_dec = 0;
    double value = 0;
    char fmt[100];
    printf("������double�����ݼ���ʾ�ܿ�ȡ�С�����λ��\n");
    scanf("%lf %d %d", &value, &width_tot, &width_dec);
    sprintf(fmt, "%%%d.%dlf*", width_tot, width_dec);
    printf("01234567890123456789\n");
    printf(fmt, value);
    return 0;
}
