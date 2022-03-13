#include <iostream>
using namespace std;

int main()
{
	cout << (int(3.79 + 0.32) % 3 + (long)1.5 % 7 - 'R' * 3) << endl;
	cout << sizeof(int(3.79 + 0.32) % 3 + (long)1.5 % 7 - 'R' * 3) << endl;
	cout << typeid(int(3.79 + 0.32) % 3 + (long)1.5 % 7 - 'R' * 3).name() << endl;
	return 0;
}
	/*
	cout << 1.3 + 7 % 3 * static_cast<unsigned long>(1.8F + 2.3) % 3 * 4.2 << endl;
	cout << sizeof(1.3 + 7 % 3 * static_cast<unsigned long>(1.8F + 2.3) % 3 * 4.2) << endl;

	cout << (17LL % 3 + 23U % 7 + 1.5F) << endl;
	cout << sizeof(17LL % 3 + 23U % 7 + 1.5F) << endl;

	cout << (2.5F * 2U + 3LU * 5U - 'b') << endl;
	cout << sizeof(2.5F * 2U + 3LU * 5U - 'b') << endl;
	cout << typeid(2.5F * 2U + 3LU * 5U - 'b').name() << endl;

	int a = 1, b = 1, c = 1;
	cout << (a + (b - 3 * (a + c) - 2) % 3) << endl;
	cout << sizeof(a + (b - 3 * (a + c) - 2) % 3) << endl;

	cout << (a = 3 * 5, a = b = 6 * 4) << endl;
	cout << sizeof(a = 3 * 5, a = b = 6 * 4) << endl;
	cout << typeid(3).name() << endl;
	*/