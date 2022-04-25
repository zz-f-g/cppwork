/* 2052110 自动化 郭子瞻 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAXSIZE 1000
#define MAX_GRD 100

void print_arr(int arr[], int len)
{
    const int n_col = 10;
    int i = 0;
    while (i < len)
    {
        if (i % n_col == 0 && i != 0)
            printf("\n");
        printf("%d ", arr[i]);
        ++i;
    }
    printf("\n");
}

int main()
{
    int grades[MAXSIZE] = { 0 };
    int n_grades[MAX_GRD + 1] = { 0 };
    int len = 0;
    int tmp;
    printf("请输入成绩（最多1000个），以-1结束\n");
    while (len < MAXSIZE)
    {
        scanf("%d", &tmp);
        if (tmp < 0)
        {
            if (len == 0)
            {
                printf("无有效输入");
                return 0;
            }
            break;
        }
        grades[len] = tmp;
        ++len;
    }
    printf("输入的数组为:\n");
    print_arr(grades, len);
    printf("分数与人数的对应关系为:\n");
    for (int i = 0; i < len; ++i)
    {
        ++n_grades[grades[i]];
    }
    for (int i = MAX_GRD; i >= 0; --i)
    {
        if (n_grades[i])
            printf("%d %d\n", i, n_grades[i]);
    }
    return 0;
}