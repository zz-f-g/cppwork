/* 2052110 �Զ��� ����հ */

#include <iostream>
using namespace std;
#define LINE 3
#define LEN 128

int main()
{
    char tmp;
    char str[LINE][LEN] = { 0 };
    unsigned int upper = 0;
    unsigned int lower = 0;
    unsigned int numeral = 0;
    unsigned int space = 0;
    unsigned int other = 0;
    for (int i = 0; i < LINE; ++i)
    {
        cout << "�������" << i + 1 << "��" << endl;
        cin >> str[i];
    }
    for (int i = 0; i < LINE; ++i)
    {
        for (int j = 0; str[i][j] != '\0'; ++j)
        {
            if (j == LEN)
                break;
            tmp = str[i][j];
            if (tmp >= 'A' && tmp <= 'Z')
                ++upper;
            else if (tmp >= 'a' && tmp <= 'z')
                ++lower;
            else if (tmp >= '0' && tmp <= '9')
                ++numeral;
            else if (tmp == ' ')
                ++space;
            else
                ++other;
        }
    }
    cout << "��д : " << upper << end;
    cout << "Сд : " << lower << end;
    cout << "���� : " << numeral << end;
    cout << "�ո� : " << space << end;
    cout << "���� : " << other << end;
    return 0;
}