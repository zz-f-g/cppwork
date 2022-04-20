/* 2052110 自动化 郭子瞻 */

#include <iostream>
#include <cmath>
using namespace std;

void same_real_root(double a, double b, double c)
{
    cout << "有两个相等实根：" << endl;
    double x1 = -b / (2 * a);
    if (fabs(x1) < 1e-6)
        x1 = 0;
    cout << "x1=x2=" << x1 << endl;
}
