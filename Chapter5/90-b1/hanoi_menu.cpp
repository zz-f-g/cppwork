/* 2052110 �Զ��� ����հ */
#include "hanoi.h"
#include <conio.h>
#include <iostream>
using namespace std;

/* ----------------------------------------------------------------------------------

     ���ļ����ܣ�
    1���ű� hanoi_main.cpp ���õĲ˵�������Ҫ����ʾ���˵��������ȷ��ѡ��󷵻�

     ���ļ�Ҫ��
    1�����������ⲿȫ�ֱ�����const��#define�������Ʒ�Χ�ڣ�
    2���������徲̬ȫ�ֱ�����ȫ�ֱ�����ʹ��׼���ǣ����á����á��ܲ��þ������ã�
    3����̬�ֲ����������������ƣ���ʹ��׼��Ҳ�ǣ����á����á��ܲ��þ�������
    4���������ϵͳͷ�ļ����Զ���ͷ�ļ��������ռ��

   ----------------------------------------------------------------------------------- */

/*print menu and return user's selection
- input: void
- output: int selection
    0: quit
    1: basic solution
    2: basic solution with step record
    3: with inner array printed in rows
    4: with inner array printed both in rows and in columns
    5: UI-prepare: print 3 cylinders
    6: UI-prepare: print n layers on source cylinder
    7: UI-prepare: first move
    8: UI auto-move
    9: UI game mode
*/
int menu()
{
    char selection = '\0';
    cout << "---------------------------------" << endl;
    cout << "1.������" << endl;
    cout << "2.������(������¼)" << endl;
    cout << "3.�ڲ�������ʾ(����)" << endl;
    cout << "4.�ڲ�������ʾ(����+����)" << endl;
    cout << "5.ͼ�ν�-Ԥ��-������Բ��" << endl;
    cout << "6.ͼ�ν�-Ԥ��-����ʼ���ϻ�n������" << endl;
    cout << "7.ͼ�ν�-Ԥ��-��һ���ƶ�" << endl;
    cout << "8.ͼ�ν�-�Զ��ƶ��汾" << endl;
    cout << "9.ͼ�ν�-��Ϸ�汾" << endl;
    cout << "0.�˳�" << endl;
    cout << "---------------------------------" << endl;
    cout << "[��ѡ��:]";
    while (!(selection >= '0' && selection <= '9'))
    {
        selection = _getch();
    }
    putchar(selection);
    cout << endl << endl;
    return selection - '0';
}
