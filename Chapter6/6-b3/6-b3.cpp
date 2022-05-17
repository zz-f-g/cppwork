/* 2052110 郭子瞻 自动化 */

#include <iostream>
using namespace std;

int main()
{
    char tmp;
    unsigned int res = 0;
    cout << "请输入一个0/1组成的字符串，长度不超过32" << endl;
    while ((tmp = getchar()) != '\n')
    {
        res *= 2;
        res += tmp - '0';
    }
    cout << res << endl;
    return 0;
}
