/* 2052110 郭子瞻 自动化 */
#include "90-b2.h"
using namespace std;

int get_val(int max_val)
{
    int val = 0;
    switch (max_val)
    {
        case 3:
            val = rand() % 3 + 1;
            break;
        case 4:
            val = rand() % 100;
            if (val < 30)
                val = 1;
            else if (val >= 30 && val < 60)
                val = 2;
            else if (val >= 60 && val < 90)
                val = 3;
            else
                val = 4;
            break;
        case 5:
            val = rand() % 100;
            if (val < 25)
                val = 1;
            else if (val >= 25 && val < 50)
                val = 2;
            else if (val >= 50 && val < 75)
                val = 3;
            else if (val >= 75 && val < 90)
                val = 4;
            else
                val = 5;
            break;
        case 6:
            val = rand() % 100;
            if (val < 20)
                val = 1;
            else if (val >= 20 && val < 40)
                val = 2;
            else if (val >= 40 && val < 60)
                val = 3;
            else if (val >= 60 && val < 80)
                val = 4;
            else if (val >= 80 && val < 95)
                val = 5;
            else
                val = 6;
            break;
        default:
            if (max_val > 6)
            {
                val = rand() % 100;
                if (val < 5)
                    val = max_val;
                else if (val >= 5 && val < 10)
                    val = max_val - 1;
                else if (val >= 10 && val < 20)
                    val = max_val - 2;
                else
                    val = rand() % (max_val - 3) + 1;
            }
    }
    return val;
}

void data_gen(int data[][MAXSIZE], int n_row, int n_col, int max_val)
{
    for (int i = 0; i < n_row; ++i)
    {
        for (int j = 0; j < n_col; ++j)
        {
            if (data[i][j] == 0)
                data[i][j] = get_val(max_val);
        }
    }
}

void data_show(const int data[][MAXSIZE], int n_row, int n_col)
{
    cout << endl
         << "当前数组：" << endl
         << "  |";
    for (int i = 0; i < n_col; i++)
        cout << setw(3) << i;
    cout << endl
         << "--+";
    for (int i = 0; i < n_col; i++)
        cout << "---";
    cout << endl;
    for (int j = 0; j < n_row; j++)
    {
        cout << (char)('A' + j) << " |";
        for (int i = 0; i < n_col; i++)
            cout << setw(3) << data[j][i];
        cout << endl;
    }
}

void adj_gen(int adj[][MAXSIZE], int x, int y, const int data[][MAXSIZE], int n_row, int n_col)
{
    adj[x][y] = 1;
    int flag = 0;
    while (1)
    {
        flag = 0;
        for (int i = 0; i < n_row; i++)
        {
            for (int j = 0; j < n_col; j++)
            {
                if (adj[i][j] == 1) {
                    if (i + 1 < n_row && adj[i + 1][j] == 0 && data[i + 1][j] == data[i][j])
                    {
                        flag = 1;
						adj[i + 1][j] = 1;
                    }
                    if (i - 1 >= 0 && adj[i - 1][j] == 0 && data[i - 1][j] == data[i][j])
                    {
                        flag = 1;
						adj[i - 1][j] = 1;
                    }
                    if (j + 1 < n_col && adj[i][j + 1] == 0 && data[i][j + 1] == data[i][j])
                    {
                        flag = 1;
						adj[i][j + 1] = 1;
                    }
                    if (j - 1 >= 0 && adj[i][j - 1] == 0 && data[i][j - 1] == data[i][j])
                    {
                        flag = 1;
						adj[i][j - 1] = 1;
                    }
                }
            }
        }
        if (0 == flag)
            return;
    }
}

void adj_gen_recur(int adj[][MAXSIZE], int x, int y, const int data[][MAXSIZE], int n_row, int n_col)
{
    if (x + 1 < n_row && adj[x + 1][y] == 0 && data[x + 1][y] == data[x][y])
    {
        adj[x + 1][y] = 1;
        adj_gen_recur(adj, x + 1, y, data, n_row, n_col);
    }
    if (x - 1 >= 0 && adj[x - 1][y] == 0 && data[x - 1][y] == data[x][y])
    {
        adj[x - 1][y] = 1;
        adj_gen_recur(adj, x - 1, y, data, n_row, n_col);
    }
    if (y + 1 < n_col && adj[x][y + 1] == 0 && data[x][y + 1] == data[x][y])
    {
        adj[x][y + 1] = 1;
        adj_gen_recur(adj, x, y + 1, data, n_row, n_col);
    }
    if (y - 1 >= 0 && adj[x][y - 1] == 0 && data[x][y - 1] == data[x][y])
    {
        adj[x][y - 1] = 1;
        adj_gen_recur(adj, x, y - 1, data, n_row, n_col);
    }
}

int adj_judge(int adj[][MAXSIZE], int n_row, int n_col)
{
    int res = 0;
    for (int i = 0; i < n_row; ++i)
    {
        for (int j = 0; j < n_col; ++j)
            res += adj[i][j];
    }
    if (1 == res)
        return 0;
    else
        return 1;
}

void adj_show(int adj[][MAXSIZE], int n_row, int n_col)
{
    cout << endl;
    cout << "查找结果数组：" << endl;
    cout << "  |";
    for (int i = 0; i < n_col; i++)
        cout << setw(3) << i;
    cout << endl;
    cout << "--+";
    for (int i = 0; i < n_col; i++)
        cout << "---";
    cout << endl;
    for (int j = 0; j < n_row; j++)
    {
        cout << (char)('A' + j) << " |";
        for (int i = 0; i < n_col; i++)
            cout << setw(3) << ((adj[j][i] == 1) ? '*' : '0');
        cout << endl;
    }
}

void data_show_highlight(const int data[][MAXSIZE], const int adj[][MAXSIZE], int n_row, int n_col)
{
    cout << endl;
    cout << "当前数组(不同色标识)：" << endl;
    cout << "  |";
    for (int i = 0; i < n_col; i++)
        cout << setw(3) << i;
    cout << endl;
    cout << "--+";
    for (int i = 0; i < n_col; i++)
        cout << "---";
    cout << endl;
    for (int j = 0; j < n_row; j++)
    {
        cout << char('A' + j) << " |";
        for (int i = 0; i < n_col; i++)
        {
            if (adj[j][i] == 1)
            {
                if (data[j][i] >= 10)
                    cout << " ";
                if (data[j][i] < 10)
                    cout << "  ";
                cct_setcolor(COLOR_HYELLOW, COLOR_BLACK);
                cout << data[j][i];
                cct_setcolor();
            }
            else
                cout << setw(3) << data[j][i];
        }
        cout << endl;
    }
}

int combine(int adj[][MAXSIZE], int x, int y, int data[][MAXSIZE], int n_row, int n_col)
{
    int score = 0;
    for (int i = 0; i < n_row; i++)
    {
        for (int j = 0; j < n_col; j++)
        {
            if (adj[i][j] == 1)
            {
                if (!(i == x && j == y))
                    data[i][j] = 0;
                score++;
            }
        }
    }
    score *= 3 * (data[x][y]++);
    return score;
}

void col_fall(int data[][MAXSIZE], int n_row, int col)
{
    for (int i = n_row - 1; i > 0; --i)
    {
        for (int j = 0; j < i; ++j)
        {
            if (data[j + 1][col] == 0 && data[j][col] != 0)
            {
                data[j + 1][col] = data[j][col];
                data[j][col] = 0;
            }
        }
    }
}

void data_fall(int data[][MAXSIZE], int n_row, int n_col)
{
    int tmp = 0;
    for (int j = 0; j < n_col; ++j)
        col_fall(data, n_row, j);
}

void adj_change(int data[][MAXSIZE], int adj[][MAXSIZE], int n_row, int n_col)
{
    for (int i = 0; i < n_row; ++i)
    {
        for (int j = 0; j < n_col; ++j)
            adj[i][j] = (data[i][j] == 0) ? 1 : 0;
    }
}

int get_max(int data[][MAXSIZE], int n_row, int n_col)
{
    int max_val = 0;
    for (int i = 0; i < n_row; ++i)
    {
        for (int j = 0; j < n_col; ++j)
        {
            if (max_val < data[i][j])
                max_val = data[i][j];
        }
    }
    return max_val;
}

int data_judge(int data[][MAXSIZE], int n_row, int n_col)
{
    for (int i = 0; i < n_row; ++i)
    {
        for (int j = 0; j < n_col; ++j)
        {
            int adj[MAXSIZE][MAXSIZE] = {0};
            adj_gen_recur(adj, i, j, data, n_row, n_col);
            if (adj_judge(adj, n_row, n_col))
                return 1;
        }
    }
    return 0;
}