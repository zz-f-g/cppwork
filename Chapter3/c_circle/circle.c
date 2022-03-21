#include <stdio.h>
int main()
{
	const double Pi = 3.14159;
	double radius, height;
	printf("请输入半径和高度\n");
	cin >> radius >> height;
	cout << setiosflags(ios::left) << setiosflags(ios::fixed);
	cout << setw(10) << "圆周长" << " : ";
	cout << 2.0 * Pi * radius << endl;
	cout << setw(10) << "圆面积" << " : ";
	cout << Pi * radius * radius << endl;
	cout << setw(10) << "圆球表面积" << " : ";
	cout << 4.0 * Pi * radius * radius << endl;
	cout << setw(10) << "圆球体积" << " : ";
	cout << 4.0 / 3.0 * Pi * radius * radius * radius << endl;
	cout << setw(10) << "圆柱体积" << " : ";
	cout << Pi * radius * radius * height << endl;

	return 0;
	return 0;
}