/* 2052110 �Զ��� ����հ */

#include <iostream>
using namespace std;

int main()
{
	double change;
	int cnt = 0;
	int c50 = 0, c20 = 0, c10 = 0, c5 = 0, c1 = 0;
	int c05 = 0, c01 = 0, c005 = 0, c002 = 0, c001 = 0;

	cout << "����������ֵ��" << endl;
	cin >> change;

	switch ((int)((change+0.001) / 50))
	{
		case 1:
			change -= 50;
			c50 = 1;
			++cnt;
			break;
		case 0:
			break;
	}

	switch ((int)((change+0.001) / 20))
	{
		case 2:
			change -= 40;
			c20 = 2;
			cnt += 2;
			break;
		case 1:
			change -= 20;
			c20 = 1;
			++cnt;
			break;
		case 0:
			break;
	}

	switch ((int)((change+0.001) / 10))
	{
		case 1:
			change -= 10;
			c10 = 1;
			++cnt;
			break;
		case 0:
			break;
	}

	switch ((int)((change+0.001) / 5))
	{
		case 1:
			change -= 5;
			c5 = 1;
			++cnt;
			break;
		case 0:
			break;
	}

	switch ((int)((change+0.001) / 1))
	{
		case 4:
			change -= 4;
			c1 = 4;
			cnt += 4;
			break;
		case 3:
			change -= 3;
			c1 = 3;
			cnt += 3;
			break;
		case 2:
			change -= 2;
			c1 = 2;
			cnt += 2;
			break;
		case 1:
			change -= 1;
			c1 = 1;
			++cnt;
			break;
		case 0:
			break;
	}

	switch ((int)((change+0.001) / 0.5))
	{
		case 1:
			change -= 0.5;
			c05 = 1;
			++cnt;
			break;
		case 0:
			break;
	}

	switch ((int)((change+0.001) / 0.1))
	{
		case 4:
			change -= 0.4;
			c01 = 4;
			cnt += 4;
			break;
		case 3:
			change -= 0.3;
			c01 = 3;
			cnt += 3;
			break;
		case 2:
			change -= 0.2;
			c01 = 2;
			cnt += 2;
			break;
		case 1:
			change -= 0.1;
			c01 = 1;
			++cnt;
			break;
		case 0:
			break;
	}

	switch ((int)((change+0.001) / 0.05))
	{
		case 1:
			change -= 0.05;
			c005 = 1;
			++cnt;
			break;
		case 0:
			break;
	}

	switch ((int)((change+0.001) / 0.02))
	{
		case 2:
			change -= 0.04;
			c002 = 2;
			cnt += 2;
			break;
		case 1:
			change -= 0.02;
			c002 = 1;
			++cnt;
			break;
		case 0:
			break;
	}

	switch ((int)((change+0.001) / 0.01))
	{
		case 4:
			change -= 0.04;
			c001 = 4;
			cnt += 4;
			break;
		case 3:
			change -= 0.03;
			c001 = 3;
			cnt += 3;
			break;
		case 2:
			change -= 0.02;
			c001 = 2;
			cnt += 2;
			break;
		case 1:
			change -= 0.01;
			c001 = 1;
			++cnt;
			break;
		case 0:
			break;
	}

	cout << "��" << cnt << "�����㣬�������£�" << endl;
	if (c50)
		cout << "50Ԫ : " << c50 << "��" << endl;
	if (c20)
		cout << "20Ԫ : " << c20 << "��" << endl;
	if (c10)
		cout << "10Ԫ : " << c10 << "��" << endl;
	if (c5)
		cout << "5Ԫ  : " << c5 << "��" << endl;
	if (c1)
		cout << "1Ԫ  : " << c1 << "��" << endl;
	if (c05)
		cout << "5��  : " << c05 << "��" << endl;
	if (c01)
		cout << "1��  : " << c01 << "��" << endl;
	if (c005)
		cout << "5��  : " << c005 << "��" << endl;
	if (c002)
		cout << "2��  : " << c002 << "��" << endl;
	if (c001)
		cout << "1��  : " << c001 << "��" << endl;

	return 0;
}

