/* 2052110 郭子瞻 自动化 */

#include <iostream>
using namespace std;

/* 1、不准添加其它头文件
   2、不准添加其它函数
   3、不准使用宏定义、全局变量、静态局部变量
*/

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：给出fun函数的定义及实现
 ***************************************************************************/
template <typename T1, typename T2>
void fun(T1 x, T2 y)
{
    if (sizeof(x) > sizeof(y))
        cout << "参数1所占空间 >  参数2所占空间" << endl;
    else if (sizeof(x) < sizeof(y))
        cout << "参数1所占空间 <  参数2所占空间" << endl;
    else
        cout << "参数1所占空间 == 参数2所占空间" << endl;
}


/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：main函数不准修改
 ***************************************************************************/
int main()
{
	short  s1 = 0, s2 = 0;
	int    i1 = 0;
	long   l1 = 0, l2 = 0;
	float  f1 = 0, f2 = 0;
	double d1 = 0, d2 = 0;

	fun(s1, s2); //期望输出 参数1所占空间 == 参数2所占空间
	fun(i1, l2); //期望输出 参数1所占空间 == 参数2所占空间
	fun(f1, d2); //期望输出 参数1所占空间 <  参数2所占空间
	fun(d1, f2); //期望输出 参数1所占空间 >  参数2所占空间
	fun(d2, l1); //期望输出 参数1所占空间 >  参数2所占空间

	return 0;
}

