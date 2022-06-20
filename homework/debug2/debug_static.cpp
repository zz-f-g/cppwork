#include <iostream>
using namespace std;
#define SIZE 10

void increment()
{
    static int cnt = 0;
    ++cnt;
    cout << "counter: " << cnt << endl;
}

void display(const int * arr, int len)
{
    const int *p = arr;
    while (p < arr + len)
    {
        cout << *p << ' ';
        ++p;
    }
}

int main()
{
    const char *p_ch = "asdf";
    int arr[SIZE] = {0}, *p = arr;
    int matrix[SIZE][SIZE] = {0};
    for (int i = 0; i < SIZE; ++i)
    {
        matrix[i][i] = 1; // identity matrix
    }
    int len = 5;
    for (int i = 0; i < len; ++i)
    {
        arr[i] = i;
        increment();
    }
    display(arr, len);
    p += (SIZE); // overflow!
    return 0;
}
