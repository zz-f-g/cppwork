/* 2052110 �Զ��� ����հ */

#include <iostream>
using namespace std;

#define N 10 /* �������ת��10������ */

/* �������ٶ�������������ȫ�ֱ��� */

int main()
{
    /* ����в���Ҫ�ı���������ɾ��������������ӻ��滻Ϊ�������͵ı��� */
    char str[256], *p;
    int a[N] = {0}, *pnum, *pa;
    bool is_num;

    /* ����Ķ��岻׼��(ɾ������Ҫ�ı�������)������Ϊ����ľ���ʵ�֣�Ҫ�󲻵��ٶ����κα����������������� */
    p = str;
    pa = a;
    pnum = a;
    is_num = 0;
    cout << "�����������������������ֵ��ַ���" << endl;
    gets_s(str);
    for (; *p != '\0'; ++p)
    {
        if (*p >= '0' && *p <= '9')
        {
            if (pnum - pa >= N)
                break;
            is_num = 1;
            *pnum *= 10;
            *pnum += *p - '0';
        }
        else
        {
            if (is_num)
                ++pnum;
            is_num = 0;
        }
    }
    if (is_num)
        ++pnum;
    cout << "����" << pnum - pa << "������" << endl;
    while (pa != pnum)
    {
        if (pa != a)
            cout << " ";
        cout << *pa;
        ++pa;
    }
    cout << endl;
    return 0;
}
