/* 2052110 自动化 郭子瞻 */

#include <iostream>
#include <cmath>
using namespace std;

void not_sq_eq();
void diff_real_root();
void same_real_root();
void complex_root();
double a, b, c;

int main()
{
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
        not_sq_eq();
    else
    {
        if (fabs(delta) < 1e-6)
            same_real_root();
        else if (delta > 0)
            diff_real_root();
        else
            complex_root();
    }
    return 0;
}