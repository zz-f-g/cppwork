#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    double d = 123.456789123456;
    cout.setf(ios::scientific);
    cout.precision(10);
    cout << d << '*' << endl;
    cout.unsetf(ios::scientific); //�˴���仰,����cout.������
    cout.setf(ios::fixed);
    cout.precision(10);
    cout << d << '*' << endl;

    return 0;
}
