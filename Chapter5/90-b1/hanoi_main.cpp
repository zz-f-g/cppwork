/* 2052110 �Զ��� ����հ */
#include "cmd_console_tools.h"
#include "hanoi.h"
#include <iostream>
using namespace std;

/* ----------------------------------------------------------------------------------

     ���ļ����ܣ�
    1����main����
    2����ʼ����Ļ
    3�����ò˵�������hanoi_menu.cpp�У�������ѡ��
    4������ѡ����ò˵������Ӧ��ִ�к�����hanoi_multiple_solutions.cpp�У�

     ���ļ�Ҫ��
    1����������ȫ�ֱ��������ⲿȫ�ֺ;�̬ȫ�֣�const��#define�������Ʒ�Χ�ڣ�
    2����̬�ֲ����������������ƣ���ʹ��׼��Ҳ�ǣ����á����á��ܲ��þ�������
    3���������ϵͳͷ�ļ����Զ���ͷ�ļ��������ռ��

   ----------------------------------------------------------------------------------- */

int main()
{
    int n, selection, delay_mode = 0;
    char src, tmp, dst;

    /* demo������ִ�д˾䣬��cmd��������Ϊ40��x120�У����������120�У�����9000�У���cmd�����Ҳ���д�ֱ�����ˣ�*/
    cct_setconsoleborder(120, 40, 120, 9000);
    while (1)
    {
        cct_cls();
        selection = menu();
        if (selection == 0)
            return 0;

        while (1)
        {
            cout << "�����뺺ŵ���Ĳ���(1-" << MAXSIZE << ")" << endl;
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
            cout << "��������ʼ��(A-C)" << endl;
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
            cout << "������Ŀ����(A-C)" << endl;
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
                    cout << "Ŀ����(" << src << ")��������ʼ��(" << src << ")��ͬ" << endl;
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
                cout << "�������ƶ��ٶ�(0-5: 0-���س�������ʾ 1-��ʱ� 5-��ʱ���)" << endl;
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
