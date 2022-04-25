/* 2052110 �Զ��� ����հ */

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

    cout << "������ɼ������1000��������-1����" << endl;
    while (len < MAXSIZE)
    {
        cin >> tmp;
        if (tmp < 0)
        {
            if (len == 0)
            {
                cout << "����Ч����" << endl;
                return 0;
            }
            break;
        }
        grades[len] = tmp;
        ++len;
    }

    cout << "���������Ϊ:" << endl;
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

    cout << "���������εĶ�Ӧ��ϵΪ:" << endl;
    for (int i = MAX_GRD; i >= 0; --i)
    {
        for (int j = 0; j < n_grades[i]; ++j)
            printf("%d %d\n", i, rank_grades[i]);
    }
    return 0;
}