/* 2052110 郭子瞻 自动化 */

#include "90-b2.h"
using namespace std;

void block_show(int data, int x, int y, int fg_color)
{
    if (data)
    {
        cct_setcolor(data % 16, fg_color);
        cct_gotoxy(x, y);
        cout << "┏━┓";
        cct_gotoxy(x, y + 1);
        cout << "┃  ┃";
        cct_gotoxy(x, y + 2);
        cout << "┗━┛";
        cct_gotoxy(x + 2, y + 1);
        cout << data;
        cct_setcolor();
    }
    else
    {
        cct_setcolor(COLOR_HWHITE);
        cct_gotoxy(x, y);
        cout << "      ";
        cct_gotoxy(x, y + 1);
        cout << "      ";
        cct_gotoxy(x, y + 2);
        cout << "      ";
        cct_setcolor();
    }
}

void bg_show(int n_col, int n_row, int frame)
{
    cout << " ";
    if (frame)
    {
        cout << setw(6) << 1;
        for (int i = 1; i < n_col; i++)
            cout << setw(8) << i + 1;
        for (int i = 0; i < n_row; i++)
        {
            cct_gotoxy(0, i * 4 + 3);
            cout << (char)('A' + i);
        }
        Sleep(10);
        cct_setcolor(COLOR_HWHITE, COLOR_BLACK);
        cct_gotoxy(2, 1);
        cout << "┏";
        for (int i = 0; i < n_col - 1; i++)
            cout << "━━━┳";
        cout << "━━━┓";
        Sleep(10);
        for (int j = 2; j < 4 * n_row + 1; j++)
        {
            cct_gotoxy(2, j);
            if (j % 4 != 1)
            {
                cout << "┃";
                for (int i = 0; i < n_col; i++)
                    cout << "      ┃";
            }
            else
            {
                cout << "┣";
                for (int i = 0; i < n_col - 1; i++)
                    cout << "━━━╋";
                cout << "━━━┫";
            }
            Sleep(10);
        }
        cct_gotoxy(2, 4 * n_row + 1);
        cout << "┗";
        for (int i = 0; i < n_col - 1; i++)
            cout << "━━━┻";
        cout << "━━━┛";
    }
    else
    {
        for (int i = 0; i < n_col; i++)
            cout << setw(6) << i;
        for (int i = 0; i < n_row; i++)
        {
            cct_gotoxy(0, i * 3 + 3);
            cout << char('A' + i);
        }
        Sleep(10);
        cct_setcolor(COLOR_HWHITE, COLOR_BLACK);
        cct_gotoxy(2, 1);
        cout << "┏";
        for (int i = 0; i < n_col; i++)
            cout << "━━━";
        cout << "┓";
        Sleep(10);
        for (int j = 2; j < 3 * n_row + 2; j++)
        {
            cct_gotoxy(2, j);
            cout << "┃";
            for (int i = 0; i < n_col; i++)
            {
                cout << "      ";
                Sleep(10);
            }
            cout << "┃";
            Sleep(10);
        }
        cct_gotoxy(2, 3 * n_row + 2);
        cout << "┗";
        for (int i = 0; i < n_col; i++)
            cout << "━━━";
        cout << "┛";
    }
    cct_setcolor();
}

void data_block_show(int data[][MAXSIZE], int n_col, int n_row, int frame)
{
    for (int i = 0; i < n_col; i++)
    {
        for (int j = 0; j < n_row; j++)
        {
            if (frame)
                block_show(data[i][j], i * 8 + 4, j * 4 + 2, COLOR_BLACK);
            else
                block_show(data[i][j], i * 6 + 4, j * 3 + 2, COLOR_BLACK);
            Sleep(10);
        }
    }
}

void move_choice(int &cur_x, int &cur_y, int delta_x, int delta_y, int n_col, int n_row)
{
    cur_x = (cur_x + n_col + delta_x) % n_col;
    cur_y = (cur_y + n_row + delta_y) % n_row;
}

void adj_block_show(int data[][MAXSIZE], int n_row, int n_col, int adj[][MAXSIZE], int cur_x, int cur_y)
{
    for (int i = 0; i < n_row; ++i)
    {
        for (int j = 0; j < n_col; ++j)
        {
            if (j == cur_x && i == cur_y)
            {
                block_show(data[i][j], j, i, COLOR_HWHITE);
                continue;
            }
            block_show(data[i][j], j, i, COLOR_WHITE);
        }
    }
}

void step(int adj[][MAXSIZE], int x, int y, int data[][MAXSIZE], int n_row, int n_col)
{
    data_block_show(data, n_col, n_row, 1);
    cct_gotoxy(0, 4 * n_row + 3);
    cout << "按回车下落                                       " << endl;
    wait();
    cct_gotoxy(0, 4 * n_row + 3);
    cout << "按回车生成新值                                   " << endl;
    wait();
    data_gen(data, n_row, n_col, get_max(data, n_row, n_col));
    data_block_show(data, n_col, n_row, 1);
    cct_gotoxy(0, 4 * n_row + 3);
}

void block_choose(int data[][MAXSIZE], int n_row, int n_col, int &cur_x, int &cur_y, int selection, int adj[][MAXSIZE])
{
    int flag = 0;
    int x, y, mouse, key1, key2;
    int end_x = 0, end_y = 0;
    int state = 0;
    cct_enable_mouse();
    cct_setcursor(CURSOR_INVISIBLE);
    block_show(data[cur_x][cur_y], 8 * cur_x + 4, 4 * cur_y + 2, COLOR_HWHITE);
    while (!flag)
    {
        switch (cct_read_keyboard_and_mouse(x, y, mouse, key1, key2))
        {
            case CCT_MOUSE_EVENT:
                if (state && cur_x != (x - 4) % 8 && cur_y != (y - 2) % 4)
                {
                    state = 0;
                    data_block_show(data, n_col, n_row, 1);
                }

                if (x < 2 || x > 8 * n_col + 2 || y < 1 || y > 4 * n_row + 1)
                {
                    if ((x - 2) % 8 == 0 || (x - 2) % 8 == 1 || (y - 1) % 4 == 0)
                    {
                        block_show(data[cur_x][cur_y], cur_x * 8 + 4, cur_y * 4 + 2, COLOR_BLACK);
                        cct_gotoxy(0, 4 * n_row + 3);
                        cout << "[无效位置]                                          ";
                    }
                }
                else
                {
                    block_show(data[cur_x][cur_y], cur_x * 8 + 4, cur_y * 4 + 2, COLOR_BLACK);
                    cur_x = (x - 4) / 8;
                    cur_y = (y - 2) / 4;
                    block_show(data[cur_x][cur_y], cur_x * 8 + 4, cur_y * 4 + 2, COLOR_WHITE);
                    cct_gotoxy(0, 4 * n_row + 3);
                    cout << "[当前选择]:" << (char)(cur_y + 'A') << "行" << cur_x + 1 << "列";
                    if (mouse == MOUSE_LEFT_BUTTON_CLICK)
                    {
                        if (selection == 7)
                        {
                            cout << " 选择完毕！" << endl;
                            flag = 1;
                        }
                        else if (selection == 8)
                        {
                            adj_gen_recur(adj, cur_x, cur_y, data, n_row, n_col);
                            if (adj_judge(adj, n_row, n_col))
                            {
                                cout << " 选择完毕！                         " << endl;
                                adj_block_show(data, n_row, n_col, adj, cur_x, cur_y);
                                ++state;
                                if (2 == state)
                                {
                                    combine(adj, cur_x, cur_y, data, n_row, n_col);
                                    step(adj, cur_x, cur_y, data, n_row, n_col);
                                    flag = 1;
                                }
                            }
                            else
                            {
                                cct_gotoxy(0, 4 * n_row + 3);
                                cout << "目标区域没有可合成的方块！                         " << endl;
                            }
                        }
                    }
                }
                break;
            case CCT_KEYBOARD_EVENT:
                block_show(data[cur_x][cur_y], cur_x * 8 + 4, cur_y * 4 + 2, COLOR_BLACK);
                cct_gotoxy(0, 4 * n_row + 3);
                switch (key1)
                {
                    case 224:
                        switch (key2)
                        {
                        case KB_ARROW_UP:
                            cout << "上";
                            move_choice(cur_x, cur_y, 0, -1, n_col, n_row);
                            break;
                        case KB_ARROW_DOWN:
                            cout << "下";
                            move_choice(cur_x, cur_y, 0, 1, n_col, n_row);
                            break;
                        case KB_ARROW_LEFT:
                            cout << "左";
                            move_choice(cur_x, cur_y, -1, 0, n_col, n_row);
                            break;
                        case KB_ARROW_RIGHT:
                            cout << "右";
                            move_choice(cur_x, cur_y, 1, 0, n_col, n_row);
                            break;
                        }
                        cout << "箭头 [当前选择]:" << char(cur_y + 'A') << "行" << setw(2) << cur_x + 1 << "列";
                        cct_getxy(end_x, end_y);
                        block_show(data[cur_x][cur_y], cur_x * 8 + 4, cur_y * 4 + 2, COLOR_WHITE);
                        break;
                    case 13:
                        cct_gotoxy(end_x, end_y);
                        cout << " 选择完毕！" << endl;
                        flag = 1;
                        break;
                }
                break;
        }
    }
    cct_disable_mouse();
    cct_setcursor(CURSOR_VISIBLE_NORMAL);
}
