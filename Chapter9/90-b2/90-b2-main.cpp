/* 2052110 郭子瞻 自动化 */

#include "90-b2.h"
using namespace std;

int menu()
{
    int x = 0, y = 0;
    char res;
    cct_cls();
    cout << "---------------------------------------" << endl;
    cout << "1.命令行找出可合成项并标识（非递归）" << endl;
    cout << "2.命令行找出可合成项并标识（递归）" << endl;
    cout << "3.命令行完成一次合成（分步骤显示）" << endl;
    cout << "4.命令行完整版（分步骤显示）" << endl;
    cout << "5.伪图形界面显示初始数组（无分隔线）" << endl;
    cout << "6.伪图形界面显示初始数组（有分隔线）" << endl;
    cout << "7.伪图形界面下用箭头键/鼠标选择当前色块" << endl;
    // cout << "8.伪图形界面完成一次合成（分步骤）" << endl;
    // cout << "9.伪图形界面完整版（支持鼠标）" << endl;
    cout << "---------------------------------------" << endl;
    cout << "0.退出" << endl;
    cout << "---------------------------------------" << endl;
    cout << "[请选择:] ";
    while (1)
    {
        res = _getche();
        if (res >= '0' && res <= '9')
        {
            Sleep(100);
            return res - '0';
        }
        else
        {
            cct_getxy(x, y);
            cct_gotoxy(10, y);
            cout << ' ';
            cct_gotoxy(10, y);
        }
    }
}

int main()
{
    cct_setconsoleborder(120, 40, 120, 9000);
    int selection = menu();
    while (selection)
    {
        cct_cls();
        enter(selection);
        selection = menu();
    }
    cout << endl
         << endl
         << endl;
    system("pause");
    return 0;
}
