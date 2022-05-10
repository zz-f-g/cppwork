/* 2052110 自动化 郭子瞻 */
/* 2050558 马超毅 1950995 高远霆 2051643 胡育杰 2053053 江俊杰 2051193 马羽 */

#include <iostream>
#include <time.h>
using namespace std;
#define WIDTH 26
#define HEIGHT 10

unsigned int get_randint(int upper_limit)
{
    return rand() % upper_limit;
}

void mine_generate(int mines[], const int n_mines)
{
    int j;
    int tmp;
    for (int i = 0; i < n_mines; ++i)
    {
        mines[i] = 1; // 1: mine; 0: no mine
    }
    for (int i = WIDTH * HEIGHT- 1; i >= 0; --i) // Knuth Shuffle
    {
        j = get_randint(i + 1);
        tmp = mines[i];
        mines[i] = mines[j];
        mines[j] = tmp;
    }
}

void mine_count(const int mines[], int cnt_mines[])
{
    for (int i = 0; i < WIDTH * HEIGHT; ++i)
    {
        switch (i)
        {
            case 0: // up-left
                cnt_mines[i] = mines[i+1]+mines[i+WIDTH]+mines[i+WIDTH+1];
                break;
            case WIDTH - 1: // up-right
                cnt_mines[i] = mines[i-1]+mines[i+WIDTH-1]+mines[i+WIDTH];
                break;
            case WIDTH * (HEIGHT - 1): // bottom-left
                cnt_mines[i] = mines[i-WIDTH]+mines[i-WIDTH+1]+mines[i+1];
                break;
            case WIDTH * HEIGHT - 1: // bottom-right
                cnt_mines[i] = mines[i-WIDTH-1]+mines[i-WIDTH]+mines[i-1];
                break;
            default:
                if (i < WIDTH) // up
                    cnt_mines[i] = mines[i-1]+mines[i+1]+mines[i+WIDTH-1]+mines[i+WIDTH]+mines[i+WIDTH+1];
                else if (i % WIDTH == 0) // left
                    cnt_mines[i] = mines[i-WIDTH]+mines[i-WIDTH+1]+mines[i+1]+mines[i+WIDTH]+mines[i+WIDTH+1];
                else if (i % WIDTH == WIDTH - 1) // right
                    cnt_mines[i] = mines[i-WIDTH-1]+mines[i-WIDTH]+mines[i-1]+mines[i+WIDTH-1]+mines[i+WIDTH];
                else if (i > WIDTH * (HEIGHT - 1)) // bottom
                    cnt_mines[i] = mines[i-WIDTH-1]+mines[i-WIDTH]+mines[i-WIDTH+1]+mines[i-1]+mines[i+1];
                else // center
                    cnt_mines[i] = mines[i-WIDTH-1]+mines[i-WIDTH]+mines[i-WIDTH+1]+mines[i-1]+mines[i+1]+mines[i+WIDTH-1]+mines[i+WIDTH]+mines[i+WIDTH+1];
        }
    }
}

void mine_print(const int mines[], const int cnt_mines[])
{
    for (int i = 0; i < WIDTH * HEIGHT; ++i)
    {
        if (mines[i])
            cout << "* ";
        else
            cout << cnt_mines[i] << " ";
        if (i % WIDTH == WIDTH - 1)
            cout << endl;
    }
}

int main()
{
    int mines[HEIGHT * WIDTH] = { 0 }; // 1D array
    int cnt_mines[HEIGHT * WIDTH] = { 0 }; // 1D array
    const int n_mines = 50;
	srand((unsigned int)(time(0)));
    mine_generate(mines, n_mines);
    mine_count(mines, cnt_mines);
    mine_print(mines, cnt_mines);
    return 0;
}