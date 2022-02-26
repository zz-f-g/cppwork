#include <iostream>

int isattacking(int pos[], int num_queen, int newpos)
{
    int x = 0;
    int y = 0;
    int flag = 0;
    for (x = 0; x < num_queen; x++)
    {
        if ((newpos - pos[x]==0) || (newpos - pos[x]==x-num_queen) || (newpos - pos[x]==num_queen-x))
        {
            flag = 1;
            break;
        }
    }
    return flag;
}

int main()
{
    int pos[8] = { 0 };
    pos[1] = 2;
    int n = 2;
    std::cout << isattacking(pos,n,5) << std::endl;
    return 0;
}