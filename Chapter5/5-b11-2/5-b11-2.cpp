/* 2052110 自动化 郭子瞻 */
#include <iostream>
#include <string>
using namespace std;

const char chnstr[] = "零壹贰叁肆伍陆柒捌玖"; /* 所有输出大写 "零" ~ "玖" 的地方，只允许从这个数组中取值 */
string result;  /* 除result外，不再允许定义任何形式的全局变量 */

/*append digit to result string
- input
    int top: top ptr of result string
    const int num: the num of this digit
    const int zeroflag: whether put 0 at this digit
- return
    int top: top ptr after append
*/
int append_digit(int top, const int num, const int zeroflag)
{
    if (num != 0 || num == 0 && zeroflag)
    {
        result = result + chnstr[2 * num] + chnstr[2 * num + 1]; // 2: 1 Chinese character takes up 2 bytes
        top += 2;
    }
    return top;
}

/*append other Chinese character to result string
- input
    int top: top ptr of result string
    const int index: the index of this Chinese character
        分: 0
        角: 1
        圆: 2
        拾: 3
        佰: 4
        仟: 5
        万: 6
        亿: 7
        整: 8
- return
    int top: top ptr after append
*/
int append_other(int top, const int index)
{
    const char tenstr[] = "分角圆拾佰仟万亿整";
    result = result + tenstr[2 * index] + tenstr[2 * index + 1];
    top += 2;
    return top;
}

int main()
{
    int top = 0;
    int zero_flag = 0;
    int higher_flag = 0;
    int ret = 0;
    double value;
    int d0, d1, d2, d3;
    int d4, d5, d6, d7;
    int d8, d9;
    int d_1, d_2;
    while (1)
    {
        cout << "请输入[0-100亿)之间的数字:" << endl;
        cin >> value;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(65536, '\n');
        }
        else if (value >= 0 && value < 1e10)
            break;
    }

    d9 = (int)(value / 1e9);
    value -= d9 * 1e9;
    d8 = (int)(value / 1e8);
    value -= d8 * 1e8;

    d7 = (int)(value / 1e7);
    value -= d7 * 1e7;
    d6 = (int)(value / 1e6);
    value -= d6 * 1e6;
    d5 = (int)(value / 1e5);
    value -= d5 * 1e5;
    d4 = (int)(value / 1e4);
    value -= d4 * 1e4;

    d3 = (int)(value / 1e3);
    value -= d3 * 1e3;
    d2 = (int)(value / 100);
    value -= d2 * 100;
    d1 = (int)(value / 10);
    value -= d1 * 10;
    d0 = (int)value;
    value -= d0;

    d_1 = (int)((value + 0.001) / 0.1);
    value -= 0.1 * d_1;
    d_2 = (int)((value + 0.001) / 0.01);

    //十亿
    top = append_digit(top, d9, zero_flag);
    if (d9)
        top = append_other(top, 3);

    //亿
    top = append_digit(top, d8, zero_flag);
    if (d8 + d9 > 0)
    {
        top = append_other(top, 7);
        higher_flag = 1;
    }

    //千万
    zero_flag = (higher_flag && (d6 || d5 || d4)) ? 1 : 0;
    top = append_digit(top, d7, zero_flag);
    if (d7)
        top = append_other(top, 5);

    //百万
    zero_flag = (d7 && (d5 || d4)) ? 1 : 0;
    top = append_digit(top, d6, zero_flag);
    if (d6)
        top = append_other(top, 4);

    //十万
    zero_flag = (d6 && d4) ? 1 : 0;
    top = append_digit(top, d5, zero_flag);
    if (d5)
        top = append_other(top, 3);

    //万
    zero_flag = 0;
    top = append_digit(top, d4, zero_flag);
    if (d7 || d6 || d5 || d4)
        top = append_other(top, 6);

    higher_flag = higher_flag || (d7 != 0) || (d6 != 0) || (d5 != 0) || (d4 != 0);

    //千
    zero_flag = (higher_flag && (d2 || d1 || d0)) ? 1 : 0;
    top = append_digit(top, d3, zero_flag);
    if (d3)
        top = append_other(top, 5);

    //百
    zero_flag = (d3 && (d1 || d0)) ? 1 : 0;
    top = append_digit(top, d2, zero_flag);
    if (d2)
        top = append_other(top, 4);

    //十
    zero_flag = (d2 && d0) ? 1 : 0;
    top = append_digit(top, d1, zero_flag);
    if (d1)
        top = append_other(top, 3);

    //个
    zero_flag = 0;
    top = append_digit(top, d0, zero_flag);

    higher_flag = higher_flag || (d3 != 0) || (d2 != 0) || (d1 != 0) || (d0 != 0);

    if (higher_flag)
        top = append_other(top, 2);

    if (d_1 == 0 && d_2 == 0)
    {
        if (higher_flag == 0)
        {
            top = append_digit(top, 0, 1);
            top = append_other(top, 2);
        }
        top = append_other(top, 8);
    }
    else
    {
        //角
        top = append_digit(top, d_1, ((higher_flag != 0) && (d_2 != 0)));
        if (d_1)
            top = append_other(top, 1);

        //分
        if (d_2)
        {
            top = append_digit(top, d_2, 0);
            top = append_other(top, 0);
        }
        else
            top = append_other(top, 8);
    }
    cout << "大写结果是:" << endl;
    cout << result << endl;  /* 转换得到的大写结果，只允许用本语句输出，其它地方不允许以任何形式对大写结果进行全部/部分输出 */
    return 0;
}
