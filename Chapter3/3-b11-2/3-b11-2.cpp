/* 2052110 �Զ��� ����հ */

#include <iostream>
using namespace std;

int main()
{
	int year, month, date, day, leap;
	day = 0;
	int legal_input = 1;

	cout << "�������꣬�£���" << endl;
	cin >> year >> month >> date;

	leap = (year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0);

	switch (month)
	{
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			if (date > 0 && date < 32)
				day = date;
			else
				legal_input = 0;
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			if (date > 0 && date < 31)
				day = date;
			else
				legal_input = 0;
			break;
		case 2:
			if ((leap && date > 0 && date < 30) || (!leap && date > 0 && date < 29))
				day = date;
			else
				legal_input = 0;
			break;
		default:
			cout << "�������-�·ݲ���ȷ" << endl;
			legal_input = -1;
			break;
	}

	if (legal_input == 1)
	{
		switch (month)
		{
			case 1:
				break;
			case 2:
				day += 31;
				break;
			case 3:
				day += 59 + leap;
				break;
			case 4:
				day += 90 + leap;
				break;
			case 5:
				day += 120 + leap;
				break;
			case 6:
				day += 151 + leap;
				break;
			case 7:
				day += 181 + leap;
				break;
			case 8:
				day += 212 + leap;
				break;
			case 9:
				day += 243 + leap;
				break;
			case 10:
				day += 273 + leap;
				break;
			case 11:
				day += 304 + leap;
				break;
			case 12:
				day += 334 + leap;
				break;
		}
		cout << year << "-" << month << "-" << date << "��" << year << "��ĵ�" << day << "��" << endl;
	}
	else if (legal_input == 0)
	{
		cout << "�������-�����µĹ�ϵ�Ƿ�" << endl;
	}

	return 0;
}
