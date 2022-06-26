/* 2052110 郭子瞻 自动化 */

#include "90-b2.h"
using namespace std;

template <typename T>
void input(T &val, T lwr_lmt, T upr_lmt, const char * prompt)
{
    T tmp;
    while (1)
    {
        if (prompt)
            cout << prompt << endl;
        cin >> tmp;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(65536, '\n');
        }
        else if (tmp >= lwr_lmt && tmp <= upr_lmt)
        {
            val = tmp;
            cin.ignore(65536, '\n');
            break;
        }
        cin.ignore(65536, '\n');
    }
}

void input_coor(char *coor, int n_row, int n_col)
{
    int len = 0, x = 0, y = 0;
    cout << endl
         << "请以字母+数字形式[例：c2]输入矩阵坐标：";
    cct_getxy(x, y);
    while (1)
    {
        len = 0;
        cin >> coor;
        while (*(coor + len))
            ++len;
        if (len == 2)
        {
            if (coor[1] >= '0' && coor[1] < (char)('0' + n_col))
            {
                if (coor[0] >= 'A' && coor[0] < (char)('A' + n_row))
                {
                    coor[0] += 'a' - 'A';
                    cout << "输入为" << coor[0] << "行" << coor[1] << "列" << endl;
                    cct_gotoxy(0, y + 3);
                    return;
                }
                else if (coor[0] >= 'a' && coor[0] < (char)('a' + n_row))
                {
                    cout << "输入为" << coor[0] << "行" << coor[1] << "列" << endl;
                    cct_gotoxy(0, y + 3);
                    return;
                }
            }
        }
        cout << "            重新输入.";
        cct_gotoxy(x, y);
        cout << "        ";
        cct_gotoxy(x, y);
    }
}

void end()
{
    char in[100];
    int len = 0;
    while (1)
    {
        cout << "本小题结束，请输入End继续...";
        cin >> in;
        while (*(in + len))
            ++len;
        if (len == 3)
        {
            if (in[0] == 'E' || in[0] == 'e')
            {
                if (in[1] == 'N' || in[1] == 'n')
                {
                    if (in[2] == 'D' || in[2] == 'd')
                        return;
                }
            }
        }
        cout << "输入错误，请重新输入" << endl;
    }
}

void wait()
{
    int ch = '0';
    while (ch != '\r')
        ch = _getche();
}

void enter(int selection)
{
    srand((unsigned int)(time(0)));
    int n_row = 0, n_col = 0;
    int data[MAXSIZE][MAXSIZE] = {0};
    char coor[MAXSIZE] = {'\0'};
    int max_val = 3;
    input(n_row, 5, 8, "请输入行数(5-8)：");
    input(n_col, 5, 10, "请输入列数(5-10)：");
    data_gen(data, n_row, n_col, max_val);
    if (selection == 1)
    {
        int coor_x;
        int coor_y;
        int adj[MAXSIZE][MAXSIZE] = {0};
        data_show(data, n_row, n_col);
        while (1)
        {
            input_coor(coor, n_row, n_col);
            coor_x = coor[0] - 'a';
            coor_y = coor[1] - '0';
            adj_gen(adj, coor_x, coor_y, data, n_row, n_col);
            if (adj_judge(adj, n_row, n_col))
                break;
            else
            {
                cout << "输入矩阵坐标位置处无连续相同值，请重新输入" << endl;
                adj[coor_x][coor_y] = 0;
            }
        }
        adj_show(adj, n_row, n_col);
        data_show_highlight(data, adj, n_row, n_col);
        end();
    }
    else if (selection == 2)
    {
        int coor_x;
        int coor_y;
        int adj[MAXSIZE][MAXSIZE] = {0};
        data_show(data, n_row, n_col);
        while (1)
        {
            input_coor(coor, n_row, n_col);
            coor_x = coor[0] - 'a';
            coor_y = coor[1] - '0';
            adj_gen_recur(adj, coor_x, coor_y, data, n_row, n_col);
            if (adj_judge(adj, n_row, n_col))
                break;
            else
            {
                cout << "输入矩阵坐标位置处无连续相同值，请重新输入" << endl;
                adj[coor_x][coor_y] = 0;
            }
        }
        adj_show(adj, n_row, n_col);
        data_show_highlight(data, adj, n_row, n_col);
        end();
    }
    else if (selection == 3)
    {
        int coor_x;
        int coor_y;
        int adj[MAXSIZE][MAXSIZE] = {0};
        int goal;
        int score = 0;
        input(goal, 5, 20, "请输入合成目标(5-20)");
        data_show(data, n_row, n_col);
        while (1)
        {
            input_coor(coor, n_row, n_col);
            coor_x = coor[0] - 'a';
            coor_y = coor[1] - '0';
            adj_gen_recur(adj, coor_x, coor_y, data, n_row, n_col);
            if (adj_judge(adj, n_row, n_col))
                break;
            else
            {
                cout << "输入矩阵坐标位置处无连续相同值，请重新输入" << endl;
                adj[coor_x][coor_y] = 0;
            }
        }
        adj_show(adj, n_row, n_col);
        data_show_highlight(data, adj, n_row, n_col);
        cout << "请确认是否把相邻的相同值合并到" << coor << "中(Y/N/Q)：";
        char choice;
        while (1)
        {
            choice = _getche();
            if (choice != 'y' && choice != 'n' && choice != 'q' && choice != 'Y' && choice != 'N' && choice != 'Q')
            {
                cout << '\b';
                continue;
            }
            else
                break;
        }
        if (choice == 'y' || choice == 'Y')
        {
            int tmp = combine(adj, coor_x, coor_y, data, n_row, n_col);
            score += tmp;
            cout << endl
                 << "相同值归并后的数组(不同色标识)：" << endl;
            data_show_highlight(data, adj, n_row, n_col);
            cout << " 本次得分：" << tmp << " 总得分：" << score << " 合成目标：" << goal << endl
                 << endl
                 << "按回车键进行数组下落除0操作..." << endl;
            wait();
            data_fall(data, n_row, n_col);
            data_show_highlight(data, adj, n_row, n_col);
            adj_change(data, adj, n_row, n_col);
            cout << endl
                 << "按回车键进行新值填充..." << endl;
            wait();
            max_val = get_max(data, n_row, n_col);
            data_gen(data, n_row, n_col, max_val);
            data_show_highlight(data, adj, n_row, n_col);
        }
        end();
    }
    else if (selection == 4)
    {
        int coor_x;
        int coor_y;
        int adj[MAXSIZE][MAXSIZE] = {0};
        int goal;
        int score = 0;
        input(goal, 5, 20, "请输入合成目标(5-20)");
        while (1)
        {
            data_show(data, n_row, n_col);
            if (!data_judge(data, n_row, n_col))
            {
                cout << "输入任何矩阵坐标都没有连续相同值，游戏失败" << endl;
                break;
            }
            while (1)
            {
                input_coor(coor, n_row, n_col);
                coor_x = coor[0] - 'a';
                coor_y = coor[1] - '0';
                adj_gen_recur(adj, coor_x, coor_y, data, n_row, n_col);
                if (adj_judge(adj, n_row, n_col))
                    break;
                else
                {
                    cout << "输入矩阵坐标位置处无连续相同值，请重新输入" << endl;
                    adj[coor_x][coor_y] = 0;
                }
            }
            adj_show(adj, n_row, n_col);
            data_show_highlight(data, adj, n_row, n_col);
            cout << "请确认是否把相邻的相同值合并到" << coor << "中(Y/N/Q)：";
            char choice;
            while (1)
            {
                choice = _getche();
                if (choice != 'y' && choice != 'n' && choice != 'q' && choice != 'Y' && choice != 'N' && choice != 'Q')
                {
                    cout << '\b';
                    continue;
                }
                else
                    break;
            }
            if (choice == 'q' || choice == 'Q')
            {
                cout << endl;
                break;
            }
            if (choice == 'n' || choice == 'N')
                continue;
            if (choice == 'y' || choice == 'Y')
            {
                int tmp = combine(adj, coor_x, coor_y, data, n_row, n_col);
                score += tmp;
                cout << endl
                     << "相同值归并后的数组(不同色标识)：" << endl;
                data_show_highlight(data, adj, n_row, n_col);
                cout << " 本次得分：" << tmp << " 总得分：" << score << " 合成目标：" << goal << endl
                     << endl
                     << "按回车键进行数组下落除0操作..." << endl;
                wait();
                data_fall(data, n_row, n_col);
                data_show_highlight(data, adj, n_row, n_col);
                adj_change(data, adj, n_row, n_col);
                cout << endl
                     << "按回车键进行新值填充..." << endl;
                wait();
                max_val = get_max(data, n_row, n_col);
                data_gen(data, n_row, n_col, max_val);
                data_show_highlight(data, adj, n_row, n_col);
                adj_change(data, adj, n_row, n_col);
                cout << "本次合成结束，按回车键进行一次新的合成" << endl;
                wait();
                if (max_val == goal)
                {
                    cout << "已经合成到" << goal << endl
                         << "按回车键继续向更高的目标进发" << endl;
                }
            }
        }
        end();
    }
    else if (selection == 5)
    {
        cct_cls();
        cct_setconsoleborder(6 * n_col + 7, 3 * n_row + 8);

        int frame = 0;
        bg_show(n_col, n_row, frame);
        data_block_show(data, n_col, n_row, frame);

        cct_gotoxy(0, 3 * n_row + 3);
        end();
    }
    else if (selection == 6)
    {
        cct_cls();
		cct_setconsoleborder(8 * n_col + 7, 4 * n_row + 8);

        int frame = 1;
        bg_show(n_col, n_row, frame);
        data_block_show(data, n_col, n_row, frame);

        cct_gotoxy(0, 4 * n_row + 3);
        end();
    }
    else if (selection == 7)
    {
        cct_cls();
		cct_setconsoleborder(8 * n_col + 7, 4 * n_row + 8);
        int frame = 1;
        int cur_x = 0, cur_y = 0;
        int adj[MAXSIZE][MAXSIZE] = {0};
        bg_show(n_col, n_row, frame);
        data_block_show(data, n_col, n_row, frame);
        block_choose(data, n_row, n_col, cur_x, cur_y, selection, adj);
        cct_gotoxy(0, 4 * n_row + 5);
        end();
    }
}