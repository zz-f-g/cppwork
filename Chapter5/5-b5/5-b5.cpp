/* 2052110 自动化 郭子瞻 */

#include <iostream>
using namespace std;
#define MAXSIZE 1000
#define MAX_GRD 100

void print_arr(int arr[], int len)
{
    const int n_col = 10;
    int i = 0;
    while (i < len)
    {
        if (i % n_col == 0 && i != 0)
            cout << endl;
        cout << arr[i] << " ";
        ++i;
    }
    cout << endl;
}

int main()
{
    int grades[MAXSIZE] = { 0 };
    int n_grades[MAX_GRD + 1] = { 0 };
    int rank_grades[MAX_GRD + 1] = { 0 };
    int len = 0;
    int cur_rank = 1;
    int tmp;

    cout << "请输入成绩（最多1000个），以-1结束" << endl;
    while (len < MAXSIZE)
    {
        cin >> tmp;
        if (tmp < 0)
        {
            if (len == 0)
            {
                cout << "无有效输入" << endl;
                return 0;
            }
            break;
        }
        grades[len] = tmp;
        ++len;
    }

    cout << "输入的数组为:" << endl;
    print_arr(grades, len);

    for (int i = 0; i < len; ++i)
    {
        ++n_grades[grades[i]];
    }
    for (int i = MAX_GRD; i >= 0; --i)
    {
        if (n_grades[i])
        {
            rank_grades[i] = cur_rank;
            cur_rank += n_grades[i];
        }
    }

    cout << "分数与名次的对应关系为:" << endl;
    for (int i = MAX_GRD; i >= 0; --i)
    {
        for (int j = 0; j < n_grades[i]; ++j)
            printf("%d %d\n", i, rank_grades[i]);
    }
    return 0;
}