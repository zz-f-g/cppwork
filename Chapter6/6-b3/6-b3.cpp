/* 2052110 ����հ �Զ��� */

#include <iostream>
using namespace std;

int main()
{
    char tmp;
    unsigned int res = 0;
    cout << "������һ��0/1��ɵ��ַ��������Ȳ�����32" << endl;
    while ((tmp = getchar()) != '\n')
    {
        res *= 2;
        res += tmp - '0';
    }
    cout << res << endl;
    return 0;
}
