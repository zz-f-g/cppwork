/* 2052110 自动化 郭子瞻 */

#include <iostream>
#include <iomanip>
using namespace std;

/*To check if the year is a leap year
- input:
    int year
- output:
    1 (is a leap year)
    0 (not)
*/
int isleap(int year)
{
    return (year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0);
}

/*Get the week value by giving year, month, date by zeller formula
- input
    int y: year
    int m: month
    int d: date (1 by default)
- output
    0: Sunday
    1: Monday
    2: Tuesday
    3: Wednesday
    4: Thursday
    5: Friday
    6: Saturday
*/
int zeller(int y, int m, int d = 1)
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

/*Print season calendar
- input:
    int year
    int season:
        0: spring
        1: summer
        2: autumn
        3: winter
    const int dates[]: how many days in every month
- output: void
*/
void print_season(int year, int season, const int dates[])
{
    int week_of_date1[3] = { zeller(year, 3 * season + 1), zeller(year, 3 * season + 2), zeller(year, 3 * season + 3) };
    int curr_date[3] = { 1, 1, 1 };
    cout << "           ";
    cout << setiosflags(ios::right);
    cout << setw(2) << 3 * season + 1 << "月                            ";
    cout << setw(2) << 3 * season + 2 << "月                            ";
    cout << setw(2) << 3 * season + 3 << "月" << endl;
    cout << "Sun Mon Tue Wed Thu Fri Sat     Sun Mon Tue Wed Thu Fri Sat     Sun Mon Tue Wed Thu Fri Sat" << endl;
    cout << resetiosflags(ios::right);
    cout << setiosflags(ios::left);
    // print date: first row
    for (int j = 0; j < 3; ++j)
    {
        if (j)
            cout << "    ";
        for (int i = 0; i < week_of_date1[j]; ++i)
            cout << "    ";
        while ((curr_date[j] + week_of_date1[j]) % 7)
        {
            cout << setw(4) << curr_date[j];
            ++curr_date[j];
        }
        cout << setw(4) << curr_date[j];
        ++curr_date[j];
    }
    cout << endl;
    //print date: other row
    while (1)
    {
        if (curr_date[0] > dates[3 * season + 0])
        {
            if (curr_date[1] > dates[3 * season + 1])
            {
                if (curr_date[2] > dates[3 * season + 2])
                    break;
            }
        }
        for (int j = 0; j < 3; ++j)
        {
            if (j)
                cout << "    ";
            while ((curr_date[j] + week_of_date1[j]) % 7)
            {
                if (curr_date[j] > dates[3 * season + j])
                    cout << "    ";
                else
                    cout << setw(4) << curr_date[j];
                ++curr_date[j];
            }
            if (curr_date[j] > dates[3 * season + j])
                cout << "    ";
            else
                cout << setw(4) << curr_date[j];
            ++curr_date[j];
        }
        cout << endl;
    }
    cout << endl;
}

/*Print year calendar
- input:
    int year
- output: void
*/
void print_year(int year)
{
    int dates[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    int season = 0;
    dates[2 - 1] += isleap(year);
    cout << year << "年的日历:" << endl;
    cout << endl;
    for (; season < 4; ++season)
    {
        print_season(year, season, dates);
    }
    cout << endl;
}

int main()
{
    system("mode con cols=120 lines=45");
	int year;
    cout << "请输入年份[1900-2100]" << endl;
    cin >> year;
    print_year(year);
    return 0;
}
