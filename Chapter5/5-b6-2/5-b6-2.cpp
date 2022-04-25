/* 2052110 �Զ��� ����հ */

#include <iostream>
#include <iomanip>
using namespace std;
#define MAXSIZE 10

int tops[3] = { 0 };
int state[3][MAXSIZE] = { 0 };
unsigned int cnt = 1;

void init_stack(int top, int stack[])
{
    int i = 0;
    while (top > 0)
    {
        stack[i] = top;
        ++i;
        --top;
    }
}

void init_state(int n, char src)
{
    init_stack(n, state[src - 'A']);
    tops[src - 'A'] = n;
}

void move_state(char src, char dst)
{
    state[dst - 'A'][tops[dst - 'A']++] = state[src - 'A'][--tops[src - 'A']];
}

void print_stack(int stack[], int top)
{
    int i = 0;
    while (top > 0)
    {
        cout << setw(2) << stack[i];
        --top;
        ++i;
    }
    while (i < MAXSIZE)
    {
        cout << "  ";
        ++i;
    }
}

void print_state()
{
    cout << " A:";
    print_stack(state[0], tops[0]);
    cout << " B:";
    print_stack(state[1], tops[1]);
    cout << " C:";
    print_stack(state[2], tops[2]);
    cout << endl;
}
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
***************************************************************************/
void hanoi(int n, char src, char tmp, char dst)
{
    static unsigned int cnt = 1;
    if (n == 1)
    {
        cout << "��" << setw(4) << cnt << " ��(" << setw(2) << n << "): " << src << "-->" << dst;
        move_state(src, dst);
        print_state();
        ++cnt;
        return;
    }
    else
    {
        hanoi(n - 1, src, dst, tmp);
        cout << "��" << setw(4) << cnt << " ��(" << setw(2) << n << "): " << src << "-->" << dst;
        move_state(src, dst);
        print_state();
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
***************************************************************************/
int main()
{
    int n;
    char src, tmp, dst;

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

    init_state(n, src);
    printf("��ʼ:               ");
    print_state();
    hanoi(n, src, tmp, dst);
    return 0;
}
