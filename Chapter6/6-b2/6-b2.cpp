/* 2052110 ����հ �Զ��� */

#include <iostream>
using namespace std;
#define MAXLEN 80

int ispalindrome(const char *str, unsigned int len)
{
    if (len == 0 || len == 1)
        return 1;
    else
    {
        if (*str != *(str + len - 1))
            return 0;
        else
            return ispalindrome(str + 1, len - 2);
    }
}

int main()
{
    char str[MAXLEN + 2] = { 0 }; // 81 or 82?
    unsigned int len = 0;
    cout << "������һ������С��80���ַ��������Ĵ���" << endl;
    fgets(str, MAXLEN + 2, stdin); // 81 or 82?
    while (str[len] != '\n')
        ++len;
    str[len] = '\0'; // unnecessary
    cout << (ispalindrome(str, len) ? "yes" : "no") << endl;
    return 0;
}
