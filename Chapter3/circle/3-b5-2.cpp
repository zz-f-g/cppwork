/* 2052110 �Զ��� ����հ */
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	const double Pi = 3.14159;
	double radius, height;
	cout << "������뾶�͸߶�" << endl;
	cin >> radius >> height;
	cout << setiosflags(ios::left) << setiosflags(ios::fixed);
	cout << setw(10) << "Բ�ܳ�" << " : ";
	cout << 2.0 * Pi * radius << endl;
	cout << setw(10) << "Բ���" << " : ";
	cout << Pi * radius * radius << endl;
	cout << setw(10) << "Բ������" << " : ";
	cout << 4.0 * Pi * radius * radius << endl;
	cout << setw(10) << "Բ�����" << " : ";
	cout << 4.0 / 3.0 * Pi * radius * radius * radius << endl;
	cout << setw(10) << "Բ�����" << " : ";
	cout << Pi * radius * radius * height << endl;
	
	return 0;
}