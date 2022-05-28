/* 2052110 自动化 郭子瞻 */

#include <iostream>
using namespace std;
#define N_KINDS 4

int is_in_array(const char arr[], char ch, int len)
{
    for (int i = 0; i < len; ++i)
    {
        if (ch == arr[i])
            return 1;
    }
    return 0;
}

/*get the sum of a slice of certain integer array
- input:
    int arr[]
    int len
- output:
    int sum
*/
int getsum(const int arr[], int len)
{
    int sum = 0;
    for (int i = 0; i < len; ++i)
    {
        sum += arr[i];
    }
    return sum;
}

/*get the info of the key
-input:
    const int str_info[]: quantity of 4 kinds of chars
        str_info[0]: upper letter (>=2)
        str_info[1]: lower letter (>=2)
        str_info[2]: numeral (>=2)
        str_info[3]: other chars (>=2)
- output:
    int: 1 for no other chars
*/
int getinfo(int str_info[], const char key[])
{
    const char other[] = "!@#$%^&*-_=+,.?";
    for (int i = 0; i < N_KINDS; ++i)
        str_info[i] = 0;
    for (int i = 0; key[i]; ++i)
    {
        if (key[i] >= 'A' && key[i] <= 'Z')
            ++str_info[0];
        else if (key[i] >= 'a' && key[i] <= 'z')
            ++str_info[1];
        else if (key[i] >= '0' && key[i] <= '9')
            ++str_info[2];
        else if (is_in_array(other, key[i], 15))
            ++str_info[3];
        else
            return 0;
    }
    return 1;
}

int checkinfo(const int str_info[], const int n_chars[], int len)
{
    int flag = 1;
    for (int i = 0; i < N_KINDS; ++i)
    {
        flag = (str_info[i] >= n_chars[i]);
        if (!flag)
            return 0;
    }
    return (len == getsum(str_info, N_KINDS));
}

int main()
{
    int flag = 1;
    char key[17];
    int len = 0;
    int n_chars[N_KINDS] = { 0 };
    int str_info[N_KINDS] = { 0 };
    cin.ignore(65536, '\n');
    cin >> len;
    if (cin.fail() || len < 12 || len > 16)
    {
        cout << "错误" << endl;
        return 0;
    }
    for (int i = 0; i < N_KINDS; ++i)
    {
        cin >> n_chars[i];
        if (cin.fail() || n_chars[i] < 2)
        {
            cout << "错误" << endl;
            return 0;
        }
    }
    for (int i = 0; i < 10; ++i)
    {
        cin >> key;
        getinfo(str_info, key);
        if (!checkinfo(str_info, n_chars, len))
        {
            cout << "错误" << endl;
            return 0;
        }
    }
    cout << "正确" << endl;
    return 0;
}
