/* 2052110 ����հ �Զ��� */

#include "90-b2.h"
using namespace std;

int menu()
{
    int x = 0, y = 0;
    char res;
    cct_cls();
    cout << "---------------------------------------" << endl;
    cout << "1.�������ҳ��ɺϳ����ʶ���ǵݹ飩" << endl;
    cout << "2.�������ҳ��ɺϳ����ʶ���ݹ飩" << endl;
    cout << "3.���������һ�κϳɣ��ֲ�����ʾ��" << endl;
    cout << "4.�����������棨�ֲ�����ʾ��" << endl;
    cout << "5.αͼ�ν�����ʾ��ʼ���飨�޷ָ��ߣ�" << endl;
    cout << "6.αͼ�ν�����ʾ��ʼ���飨�зָ��ߣ�" << endl;
    cout << "7.αͼ�ν������ü�ͷ��/���ѡ��ǰɫ��" << endl;
    // cout << "8.αͼ�ν������һ�κϳɣ��ֲ��裩" << endl;
    // cout << "9.αͼ�ν��������棨֧����꣩" << endl;
    cout << "---------------------------------------" << endl;
    cout << "0.�˳�" << endl;
    cout << "---------------------------------------" << endl;
    cout << "[��ѡ��:] ";
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
