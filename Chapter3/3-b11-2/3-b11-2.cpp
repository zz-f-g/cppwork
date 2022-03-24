/* 2052110 自动化 郭子瞻 */

#include <iostream>
using namespace std;

int main()
{
	int year, month, date, day, leap;
	day = 0;
	int legal_input = 1;

	cout << "请输入年，月，日" << endl;
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
			cout << "输入错误-月份不正确" << endl;
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
		cout << year << "-" << month << "-" << date << "是" << year << "年的第" << day << "天" << endl;
	}
	else if (legal_input == 0)
	{
		cout << "输入错误-日与月的关系非法" << endl;
	}

	return 0;
}
