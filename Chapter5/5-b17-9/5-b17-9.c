// sprintf()
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main()
{
    unsigned int ret = 0, width = 0;
    char str[100];
    char fmt[100];
    printf("�����볤��[3..12]����ַ�������ʾ���[len+1..20]\n");
    ret = scanf("%s %d", str, &width);
    width = (width > strlen(str)) ? width : strlen(str) + 1;
    sprintf(fmt, "%%-%ds*", width);
    printf("01234567890123456789\n");
    printf(fmt, str);
    return 0;
}