/* 2052110 ����հ �Զ��� */
#include <iostream>
using namespace std;

/* ----����Ҫ��----
   1����������������ͷ�ļ�
   2������������ȫ�ֱ�������̬�ֲ�����
   3��������������������
   4�������������������κ���ʽ��ѭ��
   --------------------------------------------------------------------- */


/***************************************************************************
  �������ƣ�
  ��    �ܣ���num�ǲ���base����
  ���������
  �� �� ֵ��0 - ����
            1 - ��
  ˵    �������������βΡ��������;���׼��
***************************************************************************/
int is_power(int num, int base)
{
    if (num == 1)
        return 1;
    else if (num % base != 0)
        return 0;
    else
        return is_power(num / base, base);
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����������롢���õݹ麯�������
***************************************************************************/
int main()
{
    int num, base;
    cout << "����������num������base" << endl;
    cin >> num >> base;
    cout << num << (is_power(num, base) ? "��" : "����") << base << "����" << endl;
    return 0;
}