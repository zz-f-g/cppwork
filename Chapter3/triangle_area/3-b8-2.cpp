/* 2051193 �Զ��� ����հ */
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int main()
{
	const double Pi = 3.14159;
	cout << "�����������ε����߼���н�(�Ƕ�)" << endl;
	int a, b, angle;
	float area;
	cin >> a >> b >> angle;
	area = 1.0f / 2.0f * a * b * (float)sin(angle / 180.0f * Pi);
	cout << "���������Ϊ : " << setiosflags(ios::fixed) << setprecision(3) << area << endl;
	return 0;
}