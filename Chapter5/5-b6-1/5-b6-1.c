/* 2052110 自动化 郭子瞻 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
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
        printf("%2d", stack[i]);
        --top;
        ++i;
    }
    while (i < MAXSIZE)
    {
        printf("  ");
        ++i;
    }
}

void print_state()
{
    printf(" A:");
    print_stack(state[0], tops[0]);
    printf(" B:");
    print_stack(state[1], tops[1]);
    printf(" C:");
    print_stack(state[2], tops[2]);
    printf("\n");
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
    if (n == 1)
    {
        printf("第%4d 步(%2d): %c-->%c", cnt, n, src, dst);
        move_state(src, dst);
        print_state();
        ++cnt;
        return;
    }
    else
    {
        hanoi(n - 1, src, dst, tmp);
        printf("第%4d 步(%2d): %c-->%c", cnt, n, src, dst);
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
            3、为了统一检查，不再允许添加其它函数（输入起始/目标柱的代码不要求统一函数处理，均直接放在main中）
***************************************************************************/
int main()
{
    int n, ret;
    char src, tmp, dst;

    while (1)
    {
        printf("请输入汉诺塔的层数(1-");
        printf("%d", MAXSIZE);
        printf(")\n");
        ret = scanf("%d", &n);
        if (ret == 1 && n >= 1 && n <= MAXSIZE)
        {
            scanf("%*[^\n]");
            scanf("%*c");
            break;
        }
        scanf("%*[^\n]");
        scanf("%*c");
    }

    while (1)
    {
        printf("请输入起始柱(A-C)\n");
        ret = scanf("%c", &src);
        if ((ret == 1) && (src == 'A' || src == 'B' || src == 'C' || src == 'a' || src == 'b' || src == 'c'))
        {
            if (src == 'a' || src == 'b' || src == 'c')
                src += 'A' - 'a';
            scanf("%*[^\n]");
            scanf("%*c");
            break;
        }
        scanf("%*[^\n]");
        scanf("%*c");
    }

    while (1)
    {
        printf("请输入目标柱(A-C)\n");
        ret = scanf("%c", &dst);
        if ((ret == 1) && (dst == 'A' || dst == 'B' || dst == 'C' || dst == 'a' || dst == 'b' || dst == 'c'))
        {
            if (dst == 'a' || dst == 'b' || dst == 'c')
                dst += 'A' - 'a';
            scanf("%*[^\n]");
            scanf("%*c");
            if (dst == src)
            {
                printf("目标柱(%c)不能与起始柱(%c)相同\n", src, src);
                continue;
            }
            break;
        }
        scanf("%*[^\n]");
        scanf("%*c");
    }
 
    tmp = 'A' + 'B' + 'C' - src - dst;

    init_state(n, src);
    printf("初始:               ");
    print_state();
    hanoi(n, src, tmp, dst);

    return 0;
}
