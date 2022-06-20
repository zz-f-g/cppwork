#include <iostream>
using namespace std;

static int static_integer = 314;
extern int external_integer;

int main()
{
    static_integer++;
    external_integer++;
    cout << "static:   " << static_integer << endl;
    cout << "external: " << external_integer << endl;
    return 0;
}