/* 2051193 自动化 郭子瞻 */
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int main()
{
	const double Pi = 3.14159;
	cout << "请输入三角形的两边及其夹角(角度)" << endl;
	int a, b, angle;
	float area;
	cin >> a >> b >> angle;
	area = 1.0f / 2.0f * a * b * (float)sin(angle / 180.0f * Pi);
	cout << "三角形面积为 : " << setiosflags(ios::fixed) << setprecision(3) << area << endl;
	return 0;
}