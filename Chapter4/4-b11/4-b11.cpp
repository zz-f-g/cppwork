/* 2052110 ����հ �Զ��� */
#include <iostream>
#include <iomanip>
#include <cstdio>
using namespace std;

/* -----------------------------------------------------------------------------------
        ����   ��1����������һ�����������������������ӵĺ����в������κ���ʽ��ѭ��
                 2��������ų���
                 3������const�ͱ���

        ������ ��1������ȫ�ֱ����;�̬�ֲ�����
   ----------------------------------------------------------------------------------- */

/***************************************************************************
  �������ƣ�print_sign()
  ��    �ܣ���ӡ����
  ���������char sign ��Ҫ��ӡ�ķ���
           unsigned int len ��Ҫ��ӡ�Ⱥŵĳ���
  �� �� ֵ��char ''
  ˵    �������й��캯��
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
  �������ƣ�print_ctn_letter()
  ��    �ܣ���ӡ������ĸ
  ���������char start ��Ҫ��ӡ����ʼ��ĸ
           char start ��Ҫ��ӡ����ֹ��ĸ
  �� �� ֵ��void
  ˵    �������й��캯��
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
  �������ƣ�print_tower
  ��    �ܣ���ӡ��ĸ��
  ���������char start ��ĸ���������ַ�
           char end ��ĸ���������ַ�
           unsigned int len ��ĸ��ÿһ�еĳ���
           int flag_upside_down 0: ��ӡ����ĸ��
                                1: ��ӡ����ĸ��
  �� �� ֵ��void
  ˵    ������ĿҪ����
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
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����main�����е�...�����޸ģ�����λ�ò�׼�޸�
***************************************************************************/
int main()
{
	char end_ch;

	/* ������������ַ�(����д��Ч) */
	cout << "����������ַ�(A~Z)" << endl;
	end_ch = getchar();			//����������һ���ַ�
	if (end_ch < 'A' || end_ch > 'Z') {
		cout << "�����ַ����Ǵ�д��ĸ" << endl;
		return -1;
	}

	/* ��������ĸ��(�м�ΪA) */
	cout << print_sign('=', 2 * (end_ch - 'A') + 1) << endl; /* ����ĸ����������=(��������ѭ��) */
	cout << "��������ĸ��" << endl;
	cout << print_sign('=', 2 * (end_ch - 'A') + 1) << endl; /* ����ĸ����������=(��������ѭ��) */
	print_tower('A', end_ch, 2 * (end_ch - 'A') + 1, 0);
	cout << endl;

	/* ��������ĸ��(����ΪA) */
    cout << print_sign('=', 2 * (end_ch - 'A') + 1) << endl; /* ����ĸ����������=(��������ѭ��) */
	cout << "��������ĸ��" << endl;
	cout << print_sign('=', 2 * (end_ch - 'A') + 1) << endl; /* ����ĸ����������=(��������ѭ��) */
	print_tower('A', end_ch, 2 * (end_ch - 'A') + 1, 1);
	cout << endl;

	return 0;
}
