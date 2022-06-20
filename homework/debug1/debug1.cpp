#include <iostream>
#include <cmath>
using namespace std;

/* calculate x^n
 */
float power(float x, int n)
{
    float res = 1;
    for (int i = 0; i < n; ++i)
        res *= x;
    return res;
}

int main()
{
    int a = 2, *p = &a, &b = a;
    char ch = 'A';
    float f = 1.4f;
    float res;
    cout << ch << endl;
    res = power(f, a);
    cout << sqrt(res) << endl;
    return 0;
}
