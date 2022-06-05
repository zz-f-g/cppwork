/* 2052110 自动化 郭子瞻 */
/* 2054111 郑力维 1950751 韩兴晟 2053523 胡鑫烨 2053853 孟星羽 2054205 夏佳幸 */ 

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;

void hint()
{
    cerr << "文件名以下形式均可以:" << endl;
    cerr << "    a.txt                    : 不带路径形式" << endl;
    cerr << "    ..\\data\\b.dat          : 相对路径形式" << endl;
    cerr << "    C:\\Windows\\System32\\c.dat : 绝对相对路径形式" << endl;
}

int is_hex(char ch)
{
    if (ch >= '0' && ch <= '9')
        return 1;
    else if (ch >= 'a' && ch <= 'f')
        return 1;
    else if (ch >= 'A' && ch <= 'F')
        return 1;
    else
        return 0;
}

int get_hex(const char * row, char * row_start)
{
    int i = 0;
    while (is_hex(*row))
    {
        *(row_start++) = *(row++);
        ++i;
    }
    *row_start = '\0';
    return i;
}

int hex2dec(const char * hex_str)
{
    int res = 0;
    int digit = 0;
    while (1)
    {
        if (*hex_str >= '0' && *hex_str <= '9')
            digit = (int)(*hex_str - '0');
        else if (*hex_str >= 'A' && *hex_str <= 'F')
            digit = 10 + (int)(*hex_str - 'A');
        else if (*hex_str >= 'a' && *hex_str <= 'f')
            digit = 10 + (int)(*hex_str - 'a');
        else
            return res;
        res *= 16;
        res += digit;
        ++hex_str;
    }
}

int row_start_judge(int cnt, const char * row_start)
{
    int res = hex2dec(row_start);
    return (16 * cnt == res);
}

int main(int argc, char* argv[])
{
    char file_path_in[50];
    char file_path_out[50];
    hint();
    cerr << "请输入要转换的hex格式文件名 : ";
    cin >> file_path_in;
    cerr << "请输入转换后的文件名        : ";
    cin >> file_path_out;
    ofstream out(file_path_out, ios::out | ios::binary);
    ifstream in(file_path_in, ios::in);
    if (!in.is_open())
    {
        cout << "输入文件" << file_path_in << "打开失败!" << endl;
        out.close();
        return 0;
    }
    int cur;
    int count = 0;
    char row_start[20] = { 0 };
    char cache[100];
    while (!in.eof())
    {
        in.getline(cache, 100);

        if (cache[0] == '\0')
        {
            in.close();
            out.close();
            return 0;
        }
        cur = get_hex(cache, row_start);
        if (!row_start_judge(count, row_start))
        {
            cerr << "最左侧的偏移量0x" << row_start << "不是期望值0x"
                 << setfill('0') << setw(8) << hex << 16 * count << endl;
            in.close();
            out.close();
            return 0;
        }
        for (int i = 0; i < 8; i++) {
            if (cache[i * 3 + 11] == ' ' && cache[i * 3 + 12] == ' ') {
                in.close();
                out.close();
                return 0;
            }
            out << (char)(hex2dec(&cache[3 * i + 11]));
        }
        for (int i = 0; i < 8; i++) {
            if (cache[i * 3 + 37] == ' ' && cache[i * 3 + 38] == ' ') {
                in.close();
                out.close();
                return 0;
            }
            out << (char)(hex2dec(&cache[3 * i + 37]));
        }
        count += 1;
    }
    in.close();
    out.close();
    return 0;
}
