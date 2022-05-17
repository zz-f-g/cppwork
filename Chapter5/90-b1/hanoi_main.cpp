/* 2052110 自动化 郭子瞻 */
#include "cmd_console_tools.h"
#include "hanoi.h"
#include <iostream>
using namespace std;

/* ----------------------------------------------------------------------------------

     本文件功能：
    1、放main函数
    2、初始化屏幕
    3、调用菜单函数（hanoi_menu.cpp中）并返回选项
    4、根据选项调用菜单各项对应的执行函数（hanoi_multiple_solutions.cpp中）

     本文件要求：
    1、不允许定义全局变量（含外部全局和静态全局，const及#define不在限制范围内）
    2、静态局部变量的数量不限制，但使用准则也是：少用、慎用、能不用尽量不用
    3、按需加入系统头文件、自定义头文件、命名空间等

   ----------------------------------------------------------------------------------- */

int main()
{
    int n, selection, delay_mode = 0;
    char src, tmp, dst;

    /* demo中首先执行此句，将cmd窗口设置为40行x120列（缓冲区宽度120列，行数9000行，即cmd窗口右侧带有垂直滚动杆）*/
    cct_setconsoleborder(120, 40, 120, 9000);
    while (1)
    {
        cct_cls();
        selection = menu();
        if (selection == 0)
            return 0;

        while (1)
        {
            cout << "请输入汉诺塔的层数(1-" << MAXSIZE << ")" << endl;
            cin >> n;
            if (cin.fail())
                cin.clear();
            else if (n >= 1 && n <= MAXSIZE)
            {
                cin.ignore(32767, '\n');
                break;
            }
            cin.ignore(32767, '\n');
        }
        while (1)
        {
            cout << "请输入起始柱(A-C)" << endl;
            cin >> src;
            if (cin.fail())
                cin.clear();
            else if (src == 'A' || src == 'B' || src == 'C' || src == 'a' || src == 'b' || src == 'c')
            {
                if (src == 'a' || src == 'b' || src == 'c')
                    src += 'A' - 'a';
                cin.ignore(32767, '\n');
                break;
            }
            cin.ignore(32767, '\n');
        }
        while (1)
        {
            cout << "请输入目标柱(A-C)" << endl;
            cin >> dst;
            if (cin.fail())
                cin.clear();
            else if (dst == 'A' || dst == 'B' || dst == 'C' || dst == 'a' || dst == 'b' || dst == 'c')
            {
                if (dst == 'a' || dst == 'b' || dst == 'c')
                    dst += 'A' - 'a';
                cin.ignore(32767, '\n');
                if (dst == src)
                {
                    cout << "目标柱(" << src << ")不能与起始柱(" << src << ")相同" << endl;
                    continue;
                }
                break;
            }
            cin.ignore(32767, '\n');
        }
        tmp = 'A' + 'B' + 'C' - src - dst;
        if (selection == 4 || selection == 8)
        {
            while (1)
            {
                cout << "请输入移动速度(0-5: 0-按回车单步演示 1-延时最长 5-延时最短)" << endl;
                cin >> delay_mode;
                if (cin.fail())
                    cin.clear();
                else if (delay_mode >= 0 && delay_mode <= 5)
                    break;
                cin.ignore(32767, '\n');
            }
        }
        if (selection <= 4)
        {
            initial(selection);
            hanoi_recur(n, src, tmp, dst, selection, delay_mode);
            exit_selection(selection);
        }
    }
}
