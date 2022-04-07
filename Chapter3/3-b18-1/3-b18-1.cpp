/* 2052110 �Զ��� ����հ */
#include <iostream>
#include <limits>
#include <iomanip>
using namespace std;

int main()
{
	const int Month = 12;
	const int Lower_limit = 2000;
	const int Upper_limit = 2030;
	const int Week = 7;

	int year;
	int month;
	int leap;
	int day_tot;
	int cnt_week;
	int cnt_day = 1;
	int flag_end = 0;
	int i;

	while (1) {
		cout << "���������(" << Lower_limit << "-" << Upper_limit << ")���·�(1-" << Month << ") : ";
		cin >> year >> month;

		if (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
		}
		else if (year >= Lower_limit && year <= Upper_limit && month > 0 && month <= Month)
			break;
		cout << "����Ƿ�������������" << endl;
	}

	while (1) {
		cout << "������" << year << "��" << month << "��1�յ�����(0-" << Week - 1 << "��ʾ������-������) : ";
		cin >> cnt_week;

		if (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
		}
		else if (cnt_week >= 0 && cnt_week < Week)
			break;
		cout << "����Ƿ�������������" << endl;
	}

	leap = (year % 400 == 0) || ((year % 100 != 0) && (year % 4 == 0));
	day_tot = (month == 2 || month == 4 || month == 6 || month == 9 || month == 11) ? (30 - (2 - leap) * (month == 2)) : 31;

	cout << year << "��" << month << "�µ�����Ϊ:" << endl;
	cout << "������  ����һ  ���ڶ�  ������  ������  ������  ������" << endl;
	
	while (!flag_end)
	{
		for (i = 0; i < cnt_week; ++i)
			cout << "        ";
		cout << setw(4) << cnt_day;
		++cnt_day;
		for (; cnt_week < Week - 1; ++cnt_week)
		{
			cout << setw(8) << cnt_day;
			if (cnt_day >= day_tot)
			{
				flag_end = 1;
				break;
			}
			++cnt_day;
		}
		cout << endl;
		cnt_week = 0;
	}

	return 0;
}
