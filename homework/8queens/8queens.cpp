#include <iostream>
#define MAXSIZE 8

int isattacking(int pos[], int num_queen, int newpos)
{
    int x = 0;
    int y = 0;
    int flag = 0;
    for (x = 0; x < num_queen; x++)
    {
        if ((newpos - pos[x] == 0) || (newpos - pos[x] == x - num_queen) || (newpos - pos[x] == num_queen - x))
        {
            flag = 1;
            break;
        }
    }
    return flag;
}

void Push(int* pos, int n, int x)
{
    n++;
    if (n == MAXSIZE)
    {
        n--;
        std::cout << "FULL!" << std::endl;
    }
    else
    {
        pos[n - 1] = x;
    }
}

void GetNextSln(int* pos, int n)
{
    if (n > 0)
        pos[n - 1]++;
    while (true)
    {
        if (pos[n - 1] > 7)
        {
            n--;
            pos[n - 1]++;
        }
    }
}

int main()
{
    int pos[8] = { 0 };
    pos[1] = 2;
    int n = 2;
    std::cout << isattacking(pos, n, 5) << std::endl;
    return 0;
}