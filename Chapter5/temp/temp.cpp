#include <iostream>
using namespace std;
int main()
{
    char ch1[10], ch2[10];
    cin.getline(ch1, 10, '*');
    cout << ch1 << endl;
    cin.getline(ch2, 10, '*');
    cout << ch2 << endl;
    return 0;
}
