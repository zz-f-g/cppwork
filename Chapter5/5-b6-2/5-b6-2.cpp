/* 2052110 自动化 郭子瞻 */

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
  函数名称：
  功    能：打印n层汉诺塔的移动顺序
  输入参数：int n：层数
            char src：起始柱
            char tmp：中间柱
            char dst：目标柱
  返 回 值：
  说    明：1、函数名、形参、返回类型均不准动
            2、本函数不允许出现任何形式的循环
***************************************************************************/
void hanoi(int n, char src, char tmp, char dst)
{
    static unsigned int cnt = 1;
    if (n == 1)
    {
        cout << "第" << setw(4) << cnt << " 步(" << setw(2) << n << "): " << src << "-->" << dst;
        move_state(src, dst);
        print_state();
        ++cnt;
        return;
    }
    else
    {
        hanoi(n - 1, src, dst, tmp);
        cout << "第" << setw(4) << cnt << " 步(" << setw(2) << n << "): " << src << "-->" << dst;
        move_state(src, dst);
        print_state();
        ++cnt;
        hanoi(n - 1, tmp, src, dst);
    }
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：1、完成输入、调用递归函数
            2、处理输入错误时，允许使用循环
***************************************************************************/
int main()
{
    int n;
    char src, tmp, dst;

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

    init_state(n, src);
    printf("初始:               ");
    print_state();
    hanoi(n, src, tmp, dst);
    return 0;
}
