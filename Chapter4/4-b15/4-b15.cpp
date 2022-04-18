/* 2052110 郭子瞻 自动化 */

#include <iostream>
using namespace std;

int min(int val1, int val2, int val3 = 0, int val4 = 0)
{
    if (val3)
    {
        if (val4)
        {
            val1 = (val1 < val2) ? val1 : val2;
            val3 = (val3 < val4) ? val3 : val4;
            return (val1 < val3) ? val1 : val3;
        }
        else
        {
            val1 = (val1 < val2) ? val1 : val2;
            return (val1 < val3) ? val1 : val3;
        }
    }
    return (val1 < val2) ? val1 : val2;
}

int main()
{
    int num = 0;
    int val1 = 0;
    int val2 = 0;
    int val3 = 0;
    int val4 = 0;
    int flag = 0;

    while (!flag)
    {
        cout << "输入个数num及num个正整数：" << endl;
        cin >> num;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(65536, '\n');
            continue;
        }
        else if (!(num == 2 || num == 3 || num == 4))
        {
            cout << "个数输入错误" << endl;
            return 0;
        }

        switch(num)
        {
            case 2:
                cin >> val1 >> val2;
                if (cin.good())
                {
                    if (val1 > 0 && val2 > 0)
                    {
                        cout << "min=" << min(val1, val2) << endl;
                        flag = 1;
                    }
                }
                else
                {
                    cin.clear();
                    cin.ignore(65536, '\n');
                }
                break;
            case 3:
                cin >> val1 >> val2 >> val3;
                if (cin.good())
                {
                    if (val1 > 0 && val2 > 0 && val3 > 0)
                    {
                        cout << "min=" << min(val1, val2, val3) << endl;
                        flag = 1;
                    }
                }
                else
                {
                    cin.clear();
                    cin.ignore(65536, '\n');
                }
                break;
            case 4:
                cin >> val1 >> val2 >> val3 >> val4;
                if (cin.good())
                {
                    if (val1 > 0 && val2 > 0 && val3 > 0 && val4 > 0)
                    {
                        cout << "min=" << min(val1, val2, val3, val4) << endl;
                        flag = 1;
                    }
                }
                else
                {
                    cin.clear();
                    cin.ignore(65536, '\n');
                }
                break;
        }
    }
    return 0;
}