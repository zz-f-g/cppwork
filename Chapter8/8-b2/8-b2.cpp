/* 2052110 �Զ��� ����հ */

#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;
#define ROW_SIZE 16

void hint()
{
    cerr << "�ļ���������ʽ������:" << endl;
    cerr << "    a.txt                    : ����·����ʽ" << endl;
    cerr << "    ..\\data\\b.dat          : ���·����ʽ" << endl;
    cerr << "    C:\\Windows\\System32\\c.dat : �������·����ʽ" << endl;
    cerr << "�������ļ��� : ";
}

int get_data(ifstream *in, int *data)
{
    int cur;
    int len = 0;
    while ((cur = in->get()) != EOF)
    {
        ++len;
        *data = cur;
        ++data;
        if (len >= ROW_SIZE)
            break;
    }
    return len;
}

int print_row(const int *data, int len, int n_row)
{
    int i = 0;
    if (len == 0)
        return 0;
    cout << hex << setfill('0') << setiosflags(ios::uppercase)
         << setw(8) << n_row * ROW_SIZE << ": ";
    for (; i < ROW_SIZE / 2; ++i)
    {
        if (i < len)
            cout << " " << setw(2) << data[i];
        else
            cout << "   ";
    }
    cout << ((i < len) ? " -" : "  ");
    for (; i < ROW_SIZE; ++i)
    {
        if (i < len)
            cout << " " << setw(2) << data[i];
        else
            cout << "   ";
    }
    cout << "  ";
    for (i = 0; i < ROW_SIZE; ++i)
    {
        if (i >= len)
            return n_row + 1;
        cout << ((data[i] >= 33 && data[i] <= 126) ? (char)(data[i]) : '.');
    }
    return n_row + 1;
}

int main(int argc, char *argv[])
{
    char file_path[50] = {0};
    int n_row = 0;
    int buffer[ROW_SIZE] = {0};
    int len = 0;
    hint();
    cin >> file_path;
    ifstream in(file_path, ios::in | ios::binary);
    if (in.is_open())
    {
        while ((len = get_data(&in, buffer)) == ROW_SIZE)
        {
            n_row = print_row(buffer, len, n_row);
            cout << endl;
        }
        if (len)
        {
            n_row = print_row(buffer, len, n_row);
            cout << endl;
        }
        in.close();
    }
    else
        cout << "�����ļ�" << file_path << "��ʧ��!" << endl;
    return 0;
}
