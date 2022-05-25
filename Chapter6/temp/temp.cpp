#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    float f1 = 1.000012f;
    float f2 = 9.999999f;
    cout << "1.000001" << endl;
    cout << setprecision(7) << f1 << endl;
    cout << "9.999999" << endl;
    cout << setprecision(7) << f2 << endl;
    for (int i = 0; i < 5; ++i)
    {
        f1 += 0.000001f;
        cout << setprecision(7) << f1 << endl;
    }
    return 0;
}
