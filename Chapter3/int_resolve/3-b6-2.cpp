/* 2051193 �Զ��� ����հ */
#include <iostream>
using namespace std;
int main()
{
	cout << "������һ��[1..30000]�������:" << endl;
	int a, d0, d1, d2, d3, d4;
	cin >> a;
	d0 = a % 10;
	a /= 10;
	d1 = a % 10;
	a /= 10;
	d2 = a % 10;
	a /= 10;
	d3 = a % 10;
	a /= 10;
	d4 = a % 10;
	cout << "��λ : " << d4 << endl;
	cout << "ǧλ : " << d3 << endl;
	cout << "��λ : " << d2 << endl;
	cout << "ʮλ : " << d1 << endl;
	cout << "��λ : " << d0 << endl;
	return 0;
}
