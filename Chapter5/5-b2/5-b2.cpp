/* 2052110 自动化 郭子瞻 */

#include <iostream>
using namespace std;

void change_mod(int arr[], int pos)
{
    switch (arr[pos])
    {
        case 0:
            arr[pos] = 1;
            break;
        case 1:
            arr[pos] = 0;
            break;
    }
}

int main()
{
    const int MAXSIZE = 100;
    int lights[MAXSIZE] = { 0 };
    int people = 1;
    int start = 1;
    int i;
    while (people <= MAXSIZE)
    {
        for (i = 1; i <= MAXSIZE / people; ++i)
            change_mod(lights, i * people - 1);
        ++people;
    }
    i = 0;
    while (i < MAXSIZE)
    {
        if (lights[i])
        {
            if (start == 0)
                cout << " ";
            cout << i + 1;
            start = 0;
        }
        ++i;
    }
    cout << endl;
    return 0;
}