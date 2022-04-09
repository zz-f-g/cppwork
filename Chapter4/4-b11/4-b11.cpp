/* 2052110 郭子瞻 自动化 */
#include <iostream>
#include <iomanip>
#include <cstdio>
using namespace std;

/* -----------------------------------------------------------------------------------
        允许   ：1、按需增加一个或多个函数，但是所有增加的函数中不允许任何形式的循环
                 2、定义符号常量
                 3、定义const型变量

        不允许 ：1、定义全局变量和静态局部变量
   ----------------------------------------------------------------------------------- */

/***************************************************************************
  函数名称：print_sign()
  功    能：打印符号
  输入参数：char sign 需要打印的符号
           unsigned int len 需要打印等号的长度
  返 回 值：char ''
  说    明：自行构造函数
***************************************************************************/
char print_sign(char sign, unsigned int len)
{
    if (len - 1)
    {
        cout << sign;
        return print_sign(sign, len - 1);
    }
    else
        return sign;
}

/***************************************************************************
  函数名称：print_ctn_letter()
  功    能：打印连续字母
  输入参数：char start 需要打印的起始字母
           char start 需要打印的中止字母
  返 回 值：void
  说    明：自行构造函数
***************************************************************************/
void print_ctn_letter(char start, char end)
{
    if (start < end)
    {
        cout << start;
        print_ctn_letter(start + 1, end);
    }
    else if (start > end)
    {
        cout << start;
        print_ctn_letter(start - 1, end);
    }
    else
    {
        cout << start;
        return;
    }
}

/***************************************************************************
  函数名称：print_tower
  功    能：打印字母塔
  输入参数：char start 字母塔中最大的字符
           char end 字母塔中最大的字符
           unsigned int len 字母塔每一行的长度
           int flag_upside_down 0: 打印正字母塔
                                1: 打印倒字母塔
  返 回 值：void
  说    明：题目要求函数
***************************************************************************/
void print_tower(char start, char end, unsigned int len, int flag_upside_down)
{
    if (flag_upside_down)
    {
        if (start == end)
        {
            if (len / 2)
                cout << print_sign(' ', len / 2);
            cout << end << endl;
            return;
        }
        if (len / 2 - end + start)
            cout << print_sign(' ', len / 2 - end + start);
        print_ctn_letter(start, end - 1);
        print_ctn_letter(end, start);
        cout << endl;
        print_tower(start + 1, end, len, flag_upside_down);
    }
    else
    {
        if (start == end)
        {
            if (len / 2)
                cout << print_sign(' ', len / 2);
            cout << start << endl;
            return;
        }
        print_tower(start, end - 1, len, flag_upside_down);
        if (len / 2 - end + start)
            cout << print_sign(' ', len / 2 - end + start);
        print_ctn_letter(end, start + 1);
        print_ctn_letter(start, end);
        cout << endl;
    }
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：main函数中的...允许修改，其余位置不准修改
***************************************************************************/
int main()
{
	char end_ch;

	/* 键盘输入结束字符(仅大写有效) */
	cout << "请输入结束字符(A~Z)" << endl;
	end_ch = getchar();			//读缓冲区第一个字符
	if (end_ch < 'A' || end_ch > 'Z') {
		cout << "结束字符不是大写字母" << endl;
		return -1;
	}

	/* 正三角字母塔(中间为A) */
	cout << print_sign('=', 2 * (end_ch - 'A') + 1) << endl; /* 按字母塔最大宽度输出=(不允许用循环) */
	cout << "正三角字母塔" << endl;
	cout << print_sign('=', 2 * (end_ch - 'A') + 1) << endl; /* 按字母塔最大宽度输出=(不允许用循环) */
	print_tower('A', end_ch, 2 * (end_ch - 'A') + 1, 0);
	cout << endl;

	/* 倒三角字母塔(两边为A) */
    cout << print_sign('=', 2 * (end_ch - 'A') + 1) << endl; /* 按字母塔最大宽度输出=(不允许用循环) */
	cout << "倒三角字母塔" << endl;
	cout << print_sign('=', 2 * (end_ch - 'A') + 1) << endl; /* 按字母塔最大宽度输出=(不允许用循环) */
	print_tower('A', end_ch, 2 * (end_ch - 'A') + 1, 1);
	cout << endl;

	return 0;
}
