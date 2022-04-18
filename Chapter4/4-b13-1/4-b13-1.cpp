/* 2052110 ����հ �Զ��� */
#include <iostream>
#include <iomanip>
using namespace std;

/* ----����Ҫ��----
   1���������������ͷ�ļ�
   2����������ȫ�ֱ�����������hanoi�ж���һ����̬�ֲ�����
   3�������������������
   4��main�����������룬����ѭ��
   --------------------------------------------------------------------- */

/***************************************************************************
  �������ƣ�
  ��    �ܣ���ӡn�㺺ŵ�����ƶ�˳��
  ���������int n������
            char src����ʼ��
            char tmp���м���
            char dst��Ŀ����
  �� �� ֵ��
  ˵    ����1�����������βΡ��������;���׼��
            2������������������κ���ʽ��ѭ��
            3��������һ����̬�ֲ�����
***************************************************************************/
void hanoi(int n, char src, char tmp, char dst)
{
    static unsigned int cnt = 1;
    if (n == 1)
    {
        cout << setw(5) << cnt << ": " <<  setw(2) << n << "# " << src << "-->" << dst << endl;
        ++cnt;
        return;
    }
    else
    {
        hanoi(n - 1, src, dst, tmp);
        cout << setw(5) << cnt << ": " <<  setw(2) << n << "# " << src << "-->" << dst << endl;
        ++cnt;
        hanoi(n - 1, tmp, src, dst);
    }
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����1��������롢���õݹ麯��
            2�������������ʱ������ʹ��ѭ��
            3��Ϊ��ͳһ��飬���������������������������ʼ/Ŀ�����Ĵ��벻Ҫ��ͳһ����������ֱ�ӷ���main�У�
***************************************************************************/
int main()
{
    int n;
    char src, tmp, dst;

    while (1)
    {
        cout << "�����뺺ŵ���Ĳ���(1-16)" << endl;
        cin >> n;
        if (cin.fail())
			cin.clear();
        else if (n >= 1 && n <= 16)
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

    cout << "�ƶ�����Ϊ:" << endl;
    hanoi(n, src, tmp, dst);
    return 0;

}
