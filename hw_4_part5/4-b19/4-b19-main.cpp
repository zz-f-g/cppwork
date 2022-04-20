/* 2052110 自动化 郭子瞻 */

#include <iostream>
#include <cmath>
#include "4-b19.h"
using namespace std;

int main()
{
    double a, b, c;
    double delta = 0;
    cout << "请输入一元二次方程的三个系数a,b,c:" << endl;
    cin >> a >> b >> c;
    if (fabs(a) < 1e-6)
        a = 0;
    if (fabs(b) < 1e-6)
        b = 0;
    if (fabs(c) < 1e-6)
        c = 0;
    delta = b * b - 4 * a * c;
    if (fabs(a) < 1e-6)
        not_sq_eq(a, b, c);
    else
    {
        if (fabs(delta) < 1e-6)
            same_real_root(a, b, c);
        else if (delta > 0)
            diff_real_root(a, b, c);
        else
            complex_root(a, b, c);
    }
    return 0;
}