/* 2052110 自动化 郭子瞻 */

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
        cout << "请输入第" << i + 1 << "行" << endl;
        cin.getline(str[i], LEN, '\n');
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
    cout << "大写 : " << upper << endl;
    cout << "小写 : " << lower << endl;
    cout << "数字 : " << numeral << endl;
    cout << "空格 : " << space << endl;
    cout << "其它 : " << other << endl;
    return 0;
}