/* 2052110 自动化 郭子瞻 */
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#define MAXSIZE 300 // number of chars input
#define WIDTH 26
#define HEIGHT 10

void input(int mines[], int cnt_mines[])
{
    char tmp;
    int i = 0;
    while ((tmp = getchar()) != EOF)
    {
        if (tmp == '*')
            mines[i] = 1;
        else if (tmp >= '0' && tmp <= '8')
            cnt_mines[i] = (int)(tmp - '0');
        else
            continue;
        ++i;
    }
}

int n_true(const int mines[], const int n_mines)
{
    int cnt = 0;
    for (int i = 0; i < HEIGHT * WIDTH; ++i)
    {
        if (mines[i])
            ++cnt;
    }
    return (cnt == n_mines);
}

int cnt_true(const int mines[], const int cnt_mines[])
{
    for (int i = 0; i < WIDTH * HEIGHT; ++i)
    {
        if (mines[i])
            continue;
        switch (i)
        {
            case 0: // up-left
                if (cnt_mines[i] != mines[i+1]+mines[i+WIDTH]+mines[i+WIDTH+1])
                    return 0;
                break;
            case WIDTH - 1: // up-right
                if (cnt_mines[i] != mines[i-1]+mines[i+WIDTH-1]+mines[i+WIDTH])
                    return 0;
                break;
            case WIDTH * (HEIGHT - 1): // bottom-left
                if (cnt_mines[i] != mines[i-WIDTH]+mines[i-WIDTH+1]+mines[i+1])
                    return 0;
                break;
            case WIDTH * HEIGHT - 1: // bottom-right
                if (cnt_mines[i] != mines[i-WIDTH-1]+mines[i-WIDTH]+mines[i-1])
                    return 0;
                break;
            default:
                if (i < WIDTH) // up
                    if (cnt_mines[i] != mines[i-1]+mines[i+1]+mines[i+WIDTH-1]+mines[i+WIDTH]+mines[i+WIDTH+1])
                        return 0;
                else if (i % WIDTH == 0) // left
                    if (cnt_mines[i] != mines[i-WIDTH]+mines[i-WIDTH+1]+mines[i+1]+mines[i+WIDTH]+mines[i+WIDTH+1])
                        return 0;
                else if (i % WIDTH == WIDTH - 1) // right
                    if (cnt_mines[i] != mines[i-WIDTH-1]+mines[i-WIDTH]+mines[i-1]+mines[i+WIDTH-1]+mines[i+WIDTH])
                        return 0;
                else if (i > WIDTH * (HEIGHT - 1)) // bottom
                    if (cnt_mines[i] != mines[i-WIDTH-1]+mines[i-WIDTH]+mines[i-WIDTH+1]+mines[i-1]+mines[i+1])
                        return 0;
                else // center
                    if (cnt_mines[i] != mines[i-WIDTH-1]+mines[i-WIDTH]+mines[i-WIDTH+1]+mines[i-1]+mines[i+1]+mines[i+WIDTH-1]+mines[i+WIDTH]+mines[i+WIDTH+1])
                        return 0;
        }
    }
    return 1;
}

int main()
{
    int mines[HEIGHT * WIDTH] = { 0 }; // 1D array
    int cnt_mines[HEIGHT * WIDTH] = { 0 }; // 1D array
    const int n_mines = 50;
    input(mines, cnt_mines);
    if (!n_true(mines, n_mines))
        printf("错误1");
    else if (!cnt_true(mines, cnt_mines))
        printf("错误2");
    else
        printf("正确");
    printf("\n");
    return 0;
}