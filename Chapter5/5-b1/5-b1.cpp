/* 2052110 自动化 郭子瞻 */

#include <iostream>
using namespace std;

void print_arr(int arr[], int len)
{
    for (int i = 0; i < len; ++i)
        cout << arr[i] << " ";
    cout << endl;
}

void insert(int arr[], int len, int insertion)
{
    int flag = 0;
    if (insertion >= arr[len-1])
    {
        arr[len] = insertion;
        return;
    }
    else
    {
        arr[len] = arr[len - 1];
        --len;
        while (insertion < arr[len-1] && len > 0)
        {
            arr[len] = arr[len - 1];
            --len;
        }
        arr[len] = insertion;
    }
}

int main()
{
    const int MAXSIZE = 21;
    int arr[MAXSIZE] = { 0 };
    int len = 0;
    int tmp;
    cout << "请输入任意个正整数（升序，最多20个），以-1结束" << endl;
    while (len < MAXSIZE - 1)
    {
        cin >> tmp;
        if (tmp < 0)
        {
            if (len == 0)
            {
                cout << "无有效输入" << endl;
                return 0;
            }
            break;
        }
        arr[len] = tmp;
        ++len;
    }
    cin.ignore(65536, '\n');
    cout << "原数组为：" << endl;
    print_arr(arr, len);
    cout << "请输入要插入的正整数" << endl;
    cin >> tmp;
    insert(arr, len, tmp);
    cout << "插入后的数组为：" << endl;
    print_arr(arr, len + 1);
    return 0;
}