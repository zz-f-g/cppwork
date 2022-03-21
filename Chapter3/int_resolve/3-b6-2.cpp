/* 2051193 自动化 郭子瞻 */
#include <iostream>
using namespace std;
int main()
{
	cout << "请输入一个[1..30000]间的整数:" << endl;
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
	cout << "万位 : " << d4 << endl;
	cout << "千位 : " << d3 << endl;
	cout << "百位 : " << d2 << endl;
	cout << "十位 : " << d1 << endl;
	cout << "个位 : " << d0 << endl;
	return 0;
}
