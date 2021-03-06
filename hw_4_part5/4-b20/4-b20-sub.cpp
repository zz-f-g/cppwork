/* 2052110 自动化 郭子瞻 */

#include <iostream>
#include <cmath>
using namespace std;

extern double a, b, c;

void not_sq_eq()
{
    cout << "不是一元二次方程" << endl;
}

void diff_real_root()
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

void same_real_root()
{
    cout << "有两个相等实根：" << endl;
    double x1 = -b / (2 * a);
    if (fabs(x1) < 1e-6)
        x1 = 0;
    cout << "x1=x2=" << x1 << endl;
}

void complex_root()
{
    double delta = b * b - 4 * a * c;
    double real = -b / (2 * a);
    double imag = sqrt(-delta) / (2 * (a > 0 ? a : -a));
    if (fabs(imag) < 1e-6)
        imag = 0;
    cout << "有两个虚根：" << endl;
    cout << "x1=";
    if (fabs(real) >= 1e-6)
    {
        cout << real;
        cout << "+";
    }
    if (fabs(imag - 1) >= 1e-6)
        cout << imag;
    cout << "i" << endl;
    cout << "x2=";
    if (fabs(real) >= 1e-6)
        cout << real;
    cout << "-";
    if (fabs(imag - 1) >= 1e-6)
        cout << imag;
    cout << "i" << endl;
}
