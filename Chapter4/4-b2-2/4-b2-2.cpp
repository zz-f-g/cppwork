/* 2052110 �Զ��� ����հ */

#include <iostream>
#include <limits>
using namespace std;

int zeller(int y, int m, int d)
{
	int w, c;
	if (m == 1 || m == 2)
	{
		m += 12;
		y -= 1;
	}
	c = y / 100;
	y = y % 100;

	// Zeller Formula
	w = y + y / 4 + c / 4 - 2 * c + 13 * (m + 1) / 5 + d - 1;

	while (w < 0)
	{
		w += 7;
	}
	w = w % 7;

	return w;
}

int main()
{
	const int Lower_Limit = 1900;
	const int Upper_Limit = 2100;
	int y, m, d, w, leap, day_tot;

	while (1)
	{
		cout << "��������[1900-2100]���¡��գ�" << endl;
		cin >> y >> m >> d;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
			cout << "�����������������" << endl;
			continue;
		}
		else if (y > Upper_Limit || y < Lower_Limit)
		{
			cout << "��ݲ���ȷ������������" << endl;
			continue;
		}
		else if (m > 12 || m <= 0)
		{
			cout << "�·ݲ���ȷ������������" << endl;
			continue;
		}

		leap = (y % 400 == 0) || ((y % 100 != 0) && (y % 4 == 0));
		day_tot = (m == 2 || m == 4 || m == 6 || m == 9 || m == 11) ? (30 - (2 - leap) * (m == 2)) : 31;

		if (d > day_tot || d <= 0)
		{
			cout << "�ղ���ȷ������������" << endl;
			continue;
		}
		else
			break;
	}
	
	w = zeller(y, m, d);

	cout << "����";
	switch (w)
	{
		case 0:
	        cout << "��" << endl;
			break;
		case 1:
	        cout << "һ" << endl;
			break;
		case 2:
	        cout << "��" << endl;
			break;
		case 3:
	        cout << "��" << endl;
			break;
		case 4:
	        cout << "��" << endl;
			break;
		case 5:
	        cout << "��" << endl;
			break;
		case 6:
	        cout << "��" << endl;
			break;
	}

	return 0;
}
