#include <iostream>
using namespace std;
int main()
{
	int a = 3, n = 4;
	a *= a += a /= a;
	cout << a << ' ' << n << endl;
	return 0;
}
	// a -= a + n;
	// a += n += 7;