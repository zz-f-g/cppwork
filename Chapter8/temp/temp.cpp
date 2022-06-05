#include <iostream>
#include <fstream>
using namespace std;

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


int main(int argc, char *argv[])
{
    cout << hex2dec("1a");
    return 0;
}
