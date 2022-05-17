/* 2052110 自动化 郭子瞻 */

#include <iostream>
using namespace std;
#define N_KINDS 4

/* other character */
static const char other[] = "!@#$%^&*-_=+,.?";

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

/*return a random integer
- input:
    int lower_limit
    int upper_limit
- output:
    random interger in [lower_limit, upper_limit]
*/
int get_randint(int lower_limit, int upper_limit)
{
    return lower_limit + rand() % (upper_limit + 1 - lower_limit);
}

/*disorganize the characters in string
- input:
    char str[]
    int len
*/
void str_disorganize(char str[], int len)
{
    int j;
    char tmp;
    for (int i = len - 1; i >= 0; --i) // Knuth Shuffle
    {
        j = get_randint(0, i);
        tmp = str[i];
        str[i] = str[j];
        str[j] = tmp;
    }
}

/*generate key
- input:
    char key[]: key generated
    int len: length of key [12, 16]
    const int n_chars_lwr_limits[]: quantity of 4 kinds of chars
        n_chars_lwr_limits[0]: upper letter (>=2)
        n_chars_lwr_limits[1]: lower letter (>=2)
        n_chars_lwr_limits[2]: numeral (>=2)
        n_chars_lwr_limits[3]: other chars (>=2)
*/
void key_gen(char key[], const int len, const int n_chars_lwr_limits[])
{
    int upper_limits[N_KINDS] = { (int)'Z', (int)'z', (int)'9', sizeof(other) / sizeof(other[0]) - 2 };
    int lower_limits[N_KINDS] = { (int)'A', (int)'a', (int)'0', 0 };
    int n_chars[N_KINDS];
    int lencpy = len;
    int cur = 0;
    for (int i = N_KINDS - 1; i > 0; --i)
    {
        n_chars[i] = get_randint(n_chars_lwr_limits[i], lencpy - getsum(n_chars_lwr_limits, i));
        lencpy -= n_chars[i];
    }
    n_chars[0] = lencpy;
    for (int i = 0; i < N_KINDS; ++i)
    {
        for (int j = 0; j < n_chars[i]; ++j)
        {
            if (i < N_KINDS - 1)
                key[cur + j] = (char)get_randint(lower_limits[i], upper_limits[i]);
            else if (i == N_KINDS - 1)
                key[cur + j] = other[get_randint(lower_limits[i], upper_limits[i])];
        }
        cur += n_chars[i];
    }
    key[cur] = '\0';
    str_disorganize(key, len);
}

int main()
{
    char key[17];
    int tmp;
    int len = 0;
    int n_chars[N_KINDS] = { 0 };
    cout << "请输入密码长度(12-16)， 大写字母个数(≥2)， 小写字母个数(≥2)， 数字个数(≥2)， 其它符号个数(≥2)" << endl;
    cin >> tmp;
    if (cin.fail())
    {
        cout << "输入非法" << endl;
        return 0;
    }
    else if (tmp < 12 || tmp > 16)
    {
        cout << "密码长度[" << tmp << "]不正确" << endl;
        return 0;
    }
    len = tmp;
    for (int i = 0; i < N_KINDS; ++i)
    {
        cin >> tmp;
        if (cin.fail())
        {
            cout << "输入非法" << endl;
            return 0;
        }
        else if (tmp < 2)
        {
            switch (i)
            {
                case 0:
                    cout << "大写字母个数";
                    break;
                case 1:
                    cout << "小写字母个数";
                    break;
                case 2:
                    cout << "数字个数";
                    break;
                case 3:
                    cout << "其它符号个数";
                    break;
            }
            cout << "[" << tmp << "]不正确" << endl;
            return 0;
        }
        n_chars[i] = tmp;
    }
    if (len < getsum(n_chars, N_KINDS))
    {
        cout << "所有字符类型之和[" 
        << n_chars[0] << "+"
        << n_chars[1] << "+"
        << n_chars[2] << "+"
        << n_chars[3] << "]大于总密码长度["
        << len << "]" << endl;
        return 0;
    }
    cout << len;
    for (int i = 0; i < N_KINDS; ++i)
    {
        cout << " ";
        cout << n_chars[i];
    }
    cout << endl;
    for (int i = 0; i < 10; ++i)
    {
        key_gen(key, len, n_chars);
        cout << key << endl;
    }
    return 0;
}
