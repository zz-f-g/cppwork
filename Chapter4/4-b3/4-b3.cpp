/* 2052110 自动化 郭子瞻 */

#include <iostream>
#include <limits>
#include <iomanip>
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

void calendar(int year, int month, int cnt_week)
{
	int leap, day_tot, flag_end, cnt_day, i;
	leap = (year % 400 == 0) || ((year % 100 != 0) && (year % 4 == 0));
	day_tot = (month == 2 || month == 4 || month == 6 || month == 9 || month == 11) ? (30 - (2 - leap) * (month == 2)) : 31;
	flag_end = 0;
	cnt_day = 1;

	cout << year << "年" << month << "月" << endl;
	cout << "======================================================" << endl;
	cout << "星期日  星期一  星期二  星期三  星期四  星期五  星期六" << endl;
	cout << "======================================================" << endl;

	for (i = 0; i < cnt_week; ++i)
		cout << "        ";
	while (cnt_day<=day_tot)
	{
		cout << setw(4) << cnt_day << "    ";
		++cnt_day;
		++cnt_week;
		if (cnt_week == 7)
		{
			cout << endl;
			cnt_week = 0;
		}
	}
	cout << endl;
	cout << endl;
}

int main()
{
	const int Lower_limit = 1900;
	const int Upper_limit = 2100;

	int year, month;

	while (1) {
		cout << "请输入年[1900-2100]、月" << endl;
		cin >> year >> month;

		if (cin.fail())
		{
			cout << "输入错误，请重新输入" << endl;
			cin.clear();
			cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}
		else if (year < Lower_limit || year > Upper_limit)
		{
			cout << "年份不正确，请重新输入" << endl;
			continue;
		}
		else if (month <= 0 || month > 12)
		{
			cout << "月份不正确，请重新输入" << endl;
			continue;
		}
		break;
	}
	cout << endl;

	calendar(year, month, zeller(year, month, 1));

	return 0;
}
