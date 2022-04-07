/* 2052110 自动化 郭子瞻 */

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
		cout << "请输入年[1900-2100]、月、日：" << endl;
		cin >> y >> m >> d;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
			cout << "输入错误，请重新输入" << endl;
			continue;
		}
		else if (y > Upper_Limit || y < Lower_Limit)
		{
			cout << "年份不正确，请重新输入" << endl;
			continue;
		}
		else if (m > 12 || m <= 0)
		{
			cout << "月份不正确，请重新输入" << endl;
			continue;
		}

		leap = (y % 400 == 0) || ((y % 100 != 0) && (y % 4 == 0));
		day_tot = (m == 2 || m == 4 || m == 6 || m == 9 || m == 11) ? (30 - (2 - leap) * (m == 2)) : 31;

		if (d > day_tot || d <= 0)
		{
			cout << "日不正确，请重新输入" << endl;
			continue;
		}
		else
			break;
	}
	
	w = zeller(y, m, d);

	cout << "星期";
	switch (w)
	{
		case 0:
	        cout << "日" << endl;
			break;
		case 1:
	        cout << "一" << endl;
			break;
		case 2:
	        cout << "二" << endl;
			break;
		case 3:
	        cout << "三" << endl;
			break;
		case 4:
	        cout << "四" << endl;
			break;
		case 5:
	        cout << "五" << endl;
			break;
		case 6:
	        cout << "六" << endl;
			break;
	}

	return 0;
}
