/* 2052110 �Զ��� ����հ */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAXSIZE 10

int topA = 0;
int topB = 0;
int topC = 0;
int stateA[MAXSIZE] = { 0 };
int stateB[MAXSIZE] = { 0 };
int stateC[MAXSIZE] = { 0 };
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
    switch (src)
    {
        case 'A':
            init_stack(n, stateA);
            topA = n;
            break;
        case 'B':
            init_stack(n, stateB);
            topB = n;
            break;
        case 'C':
            init_stack(n, stateC);
            topC = n;
            break;
    }
}

void move_state(char src, char dst)
{
    switch (src)
    {
        case 'A':
            switch (dst)
            {
                case 'B':
                    stateB[topB++] = stateA[--topA];
                    break;
                case 'C':
                    stateC[topC++] = stateA[--topA];
                    break;
            }
            break;
        case 'B':
            switch (dst)
            {
                case 'C':
                    stateC[topC++] = stateB[--topB];
                    break;
                case 'A':
                    stateA[topA++] = stateB[--topB];
                    break;
            }
            break;
        case 'C':
            switch (dst)
            {
                case 'A':
                    stateA[topA++] = stateC[--topC];
                    break;
                case 'B':
                    stateB[topB++] = stateC[--topC];
                    break;
            }
            break;
    }
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
    print_stack(stateA, topA);
    printf(" B:");
    print_stack(stateB, topB);
    printf(" C:");
    print_stack(stateC, topC);
    printf("\n");
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
    if (n == 1)
    {
        printf("��%4d ��(%2d): %c-->%c", cnt, n, src, dst);
        move_state(src, dst);
        print_state();
        ++cnt;
        return;
    }
    else
    {
        hanoi(n - 1, src, dst, tmp);
        printf("��%4d ��(%2d): %c-->%c", cnt, n, src, dst);
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
            3��Ϊ��ͳһ��飬���������������������������ʼ/Ŀ�����Ĵ��벻Ҫ��ͳһ����������ֱ�ӷ���main�У�
***************************************************************************/
int main()
{
    int n, ret;
    char src, tmp, dst;

    while (1)
    {
        printf("�����뺺ŵ���Ĳ���(1-");
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
        printf("��������ʼ��(A-C)\n");
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
        printf("������Ŀ����(A-C)\n");
        ret = scanf("%c", &dst);
        if ((ret == 1) && (dst == 'A' || dst == 'B' || dst == 'C' || dst == 'a' || dst == 'b' || dst == 'c'))
        {
            if (dst == 'a' || dst == 'b' || dst == 'c')
                dst += 'A' - 'a';
            scanf("%*[^\n]");
            scanf("%*c");
            if (dst == src)
            {
                printf("Ŀ����(%c)��������ʼ��(%c)��ͬ\n", src, src);
                continue;
            }
            break;
        }
        scanf("%*[^\n]");
        scanf("%*c");
    }
 
    tmp = 'A' + 'B' + 'C' - src - dst;

    init_state(n, src);
    printf("��ʼ:               ");
    print_state();
    hanoi(n, src, tmp, dst);

    return 0;
}
