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
        if (selection == 5)
        {
            cct_cls();
            init_cylinders();
            exit_selection(selection);
            continue;
        }
        if (selection == 0)
            return 0;
        get_n(n);
        get_src(src);
        get_dst(src, dst);
        tmp = 'A' + 'B' + 'C' - src - dst;
        if (selection == 4 || selection == 8)
            get_delay(delay_mode);
        switch (selection)
        {
            case 1:
            case 2:
            case 3:
            case 4:
            case 8:
                initial(n, src, tmp, dst, selection, delay_mode);
                hanoi_recur(n, src, tmp, dst, selection, delay_mode);
                exit_selection(selection);
                break;
            case 6:
            case 7:
            case 9:
                initial(n, src, tmp, dst, selection, delay_mode);
                exit_selection(selection);
                break;
        }
    }
    return 0;
}
