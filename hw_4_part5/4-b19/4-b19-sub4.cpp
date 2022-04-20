/* 2052110 自动化 郭子瞻 */

#include <iostream>
#include <cmath>
using namespace std;

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
