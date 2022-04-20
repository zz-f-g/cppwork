/* 2052110 自动化 郭子瞻 */

#include <iostream>
#include <cmath>
using namespace std;

void diff_real_root(double a, double b, double c)
{
    double delta = b * b - 4 * a * c;
    double x1 = (-b + sqrt(delta)) / (2 * a);
    double x2 = (-b - sqrt(delta)) / (2 * a);
    double temp = x1;
    if (x1 < x2)
    {
        x1 = x2;
        x2 = temp;
    }
    if (fabs(x1) < 1e-6)
        x1 = 0;
    if (fabs(x2) < 1e-6)
        x2 = 0;
    cout << "有两个不等实根：" << endl;
    cout << "x1=" << x1 << endl;
    cout << "x2=" << x2 << endl;
}
