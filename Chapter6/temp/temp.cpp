#include <iostream>
using namespace std;
void tj_strlen(const char* str)
{
    char* p_char = str;
    *p_char = '0';
}
int main()
{
    char str[] = "aasdf";
    tj_strlen(str);
    cout << str << endl;
    return 0;
}