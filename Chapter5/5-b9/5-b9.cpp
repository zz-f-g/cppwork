/* 2052110 �Զ��� ����հ */

#include <iostream>
using namespace std;

/*To check if there is not repeated 1, ..., 9 in array
- input:
    int arr[]: the array to be checked
- output:
    int: 1 (not repeated), 0 (else)
*/
int if1to9(const int arr[])
{
    int n_1to9[9] = { 0 };
    for (int i = 0; i < 9; ++i)
    {
        if (n_1to9[arr[i]-1])
            return 0;
        else
            ++n_1to9[arr[i]-1];
    }
    return 1;
}

/*To check if a 9*9 matrix is a solution of sokudo
- input:
    int sokudo[]: 9*9 matrix to be checked
- output:
    int: 1 (it is a solution), 0 (not)
*/
int ifsokudo(const int sokudo[][9])
{
    int unit[9] = { 0 };
    for (int i = 0; i < 9; i += 3) // square
    {
        for (int j = 0; j < 9; j += 3)
        {
            unit[0] = sokudo[i  ][j  ];
            unit[1] = sokudo[i  ][j+1];
            unit[2] = sokudo[i  ][j+2];
            unit[3] = sokudo[i+1][j  ];
            unit[4] = sokudo[i+1][j+1];
            unit[5] = sokudo[i+1][j+2];
            unit[6] = sokudo[i+2][j  ];
            unit[7] = sokudo[i+2][j+1];
            unit[8] = sokudo[i+2][j+2];
            if (!if1to9(unit))
                return 0;
        }
    }
    for (int i = 0; i < 9; ++i) // row
    {
        if (!if1to9(sokudo[i]))
            return 0;
    }
    for (int i = 0; i < 9; ++i) // column
    {
        unit[0] = sokudo[0][i];
        unit[1] = sokudo[1][i];
        unit[2] = sokudo[2][i];
        unit[3] = sokudo[3][i];
        unit[4] = sokudo[4][i];
        unit[5] = sokudo[5][i];
        unit[6] = sokudo[6][i];
        unit[7] = sokudo[7][i];
        unit[8] = sokudo[8][i];
        if (!if1to9(unit))
            return 0;
    }
    return 1;
}

int main()
{
    int tmp;
    int matrix[9][9] = { 0 };
    cout << "������9*9�ľ���ֵΪ1-9֮��" << endl;
    for (int i = 0; i < 9; ++i)
    {
        for (int j = 0; j < 9; ++j)
        {
            while (1)
            {
                cin >> tmp;
                if (cin.fail())
                {
                    cin.clear();
                    cin.ignore(65536, '\n');
                }
                else if(tmp >= 1 && tmp <= 9)
                    break;
                cout << "�����������" << i << "��" << j << "��(���о���1��ʼ����)��ֵ";
            }
            matrix[i][j] = tmp;
        }
    }
    cout << (ifsokudo(matrix) ? "��" : "����") << "�����Ľ�" << endl;
    return 0;
}
