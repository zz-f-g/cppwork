// 3.C
#include <iostream>
using namespace std;

int main()
{
    // char s1[] = "\xg321";
    char s2[] = "\x*321";
    // cout << strlen(s1) << endl;
    cout << strlen(s2) << endl;

    return 0;
}