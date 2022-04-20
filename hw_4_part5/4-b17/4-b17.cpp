/* 2052110 自动化 郭子瞻 */

#include <iostream>
#include <cmath>
using namespace std;

void not_sq_eq(double a, double b, double c)
{
    cout << "不是一元二次方程" << endl;
}

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

void same_real_root(double a, double b, double c)
{
    cout << "有两个相等实根：" << endl;
    double x1 = -b / (2 * a);
    if (fabs(x1) < 1e-6)
        x1 = 0;
    cout << "x1=x2=" << x1 << endl;
}

void complex_root(double a, double b, double c)
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