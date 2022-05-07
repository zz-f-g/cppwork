#include <iostream>
using namespace std;

int main()
{
    char ch;
    const char chnstr[] = "零壹贰叁肆伍陆柒捌玖"; /* 所有输出大写 "零" ~ "玖" 的地方，只允许从这个数组中取值 */
    printf("%c", chnstr[0]);
    printf("%c", chnstr[0]);
    return 0;
}
