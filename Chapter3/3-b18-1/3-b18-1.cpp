/* 2052110 自动化 郭子瞻 */
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
		cout << "请输入年份(" << Lower_limit << "-" << Upper_limit << ")和月份(1-" << Month << ") : ";
		cin >> year >> month;

		if (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
		}
		else if (year >= Lower_limit && year <= Upper_limit && month > 0 && month <= Month)
			break;
		cout << "输入非法，请重新输入" << endl;
	}

	while (1) {
		cout << "请输入" << year << "年" << month << "月1日的星期(0-" << Week - 1 << "表示星期日-星期六) : ";
		cin >> cnt_week;

		if (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
		}
		else if (cnt_week >= 0 && cnt_week < Week)
			break;
		cout << "输入非法，请重新输入" << endl;
	}

	leap = (year % 400 == 0) || ((year % 100 != 0) && (year % 4 == 0));
	day_tot = (month == 2 || month == 4 || month == 6 || month == 9 || month == 11) ? (30 - (2 - leap) * (month == 2)) : 31;

	cout << year << "年" << month << "月的月历为:" << endl;
	cout << "星期日  星期一  星期二  星期三  星期四  星期五  星期六" << endl;
	
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
