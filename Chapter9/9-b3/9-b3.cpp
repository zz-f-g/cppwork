/* 2052110 郭子瞻 自动化 */
#include <iostream>
#include <conio.h>
using namespace std;

/* --- 如果有需要的宏定义、只读全局变量等，写于此处 --- */
#define START 1900
#define END 2099

/* --- 如果有其它全局函数需要声明，写于此处 --- */

/* 补全Date类的定义，所有成员函数均体外实现，不要在此处体内实现 */
class Date {
private:
	int year;
	int month;
	int day;
	/* 不允许添加数据成员 */
    void illegal_manage(int * p, int y, int m, int d);
    int isleap(int y);
    int get_day(int year, int month, int day);
public:
	/* 根据需要定义所需的成员函数、友元函数等(不允许添加数据成员) */
    Date();
    Date(int day_from_beg);
    Date(int y, int m, int d);
    void set(int y);
    void set(int y, int m);
    void set(int y, int m, int d);
    void get(int &y, int &m, int &d);
    void show();
};

/* --- 给出 Date 类的所有成员函数的体外实现 --- */
int Date::isleap(int y)
{
    return (y % 4 == 0) && (y % 100 != 0) || (y % 400 == 0);
}

void Date::illegal_manage(int * p, int y, int m, int d)
{
    if (y < START || y > END)
        y = 2000;
    const int day_in_month[13] = {
        0, 31, 28 + isleap(y), 31, 30, 31, 30,
        31, 31, 30, 31, 30, 31};
    if (m < 1 || m > 12)
        m = 1;
    if (d < 1 || d > day_in_month[m])
        d = 1;
    *(p++) = y;
    *(p++) = m;
    *(p++) = d;
}

int Date::get_day(int year, int month, int day)
{
    const int day_in_month[13] = {0, 31, 28 + isleap(year), 
    31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int res = 0;
    for (int i = START; i < year; ++i)
        res += 365 + isleap(i);
    for (int i = 1; i < month; ++i)
        res += day_in_month[i];
    return (res += day - 1);
}

Date::Date()
{
    this->year = 2000;
    this->month = 1;
    this->day = 1;
}

Date::Date(int day_from_beg) // ???
{
    if (day_from_beg <= 0)
    {
        this->year = START;
        this->month = 1;
        this->day = 1;
    }
    else if (day_from_beg > get_day(END, 12, 31))
    {
        this->year = END;
        this->month = 12;
        this->day = 31;
    }
    else
    {
        int y = day_from_beg / 366 + START;
        int m = 1, d;
        int date_info[3] = {0};
        while (get_day(y, 1, 1) <= day_from_beg)
            ++y;
        --y;
        while (get_day(y, m, 1) <= day_from_beg)
            ++m;
        --m;
        d = day_from_beg - get_day(y, m, 1);
        illegal_manage(date_info, y, m, d);
        this->year = date_info[0];
        this->month = date_info[1];
        this->day = date_info[2];
    }
}

Date::Date(int y, int m, int d)
{
    int date_info[3] = {0};
    illegal_manage(date_info, y, m, d);
    this->year = date_info[0];
    this->month = date_info[1];
    this->day = date_info[2];
}

void Date::set(int y)
{
    if (y == 0)
        y = this->year;
    int date_info[3] = {0};
    illegal_manage(date_info, y, 1, 1);
    this->year = date_info[0];
}

void Date::set(int y, int m)
{
    if (y == 0)
        y = this->year;
    if (m == 0)
        m = this->month;
    int date_info[3] = {0};
    illegal_manage(date_info, y, m, 1);
    this->year = date_info[0];
    this->month = date_info[1];
}

void Date::set(int y, int m, int d)
{
    if (y == 0)
        y = this->year;
    if (m == 0)
        m = this->month;
    if (d == 0)
        d = this->day;
    int date_info[3] = {0};
    illegal_manage(date_info, y, m, d);
    this->year = date_info[0];
    this->month = date_info[1];
    this->day = date_info[2];
}

void Date::get(int &y, int &m, int &d)
{
    y = this->year;
    m = this->month;
    d = this->day;
}

void Date::show()
{
    cout << this->year << '.' << this->month << '.' << this->day << endl;
}
/* --- 如果有需要的其它全局函数的实现，可以写于此处 --- */


/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void wait_for_enter()
{
	cout << endl << "按回车键继续";
	while (_getch() != '\r')
		;
	cout << endl << endl;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：main函数不准动，测试时会替换
***************************************************************************/
int main()
{
	if (1) {
		Date d1;				//2000.1.1
		Date d2(2022, 6, 10);	//2022.6.10

		cout << "无参及三参构造函数测试（完全正确）" << endl;
		cout << "==================================" << endl;

		cout << "d1应该是2000.1.1， 实际为：";
		d1.show();
		cout << "d2应该是2022.6.10，实际为：";
		d2.show();

		wait_for_enter();
	}

	if (1) {
		Date d1(1870, 3, 15);  //2000.3.15
		Date d2(2112, 3, 4);   //2000.3.4
		Date d3(2005, 13, 15); //2005.1.15
		Date d4(2022, 6, 32);  //2022.6.1

		cout << "三参构造函数测试（年、月、日非法）" << endl;
		cout << "==================================" << endl;

		cout << "d1应该是2000.3.15，实际为：";
		d1.show();
		cout << "d2应该是2000.3.4， 实际为：";
		d2.show();
		cout << "d3应该是2005.1.15，实际为：";
		d3.show();
		cout << "d4应该是2022.6.1， 实际为：";
		d4.show();

		/* 多个错，按年月日顺序处理 */
		Date d5(1899, 2, 29);  //2000.2.29
		Date d6(1899, 2, 30);  //2000.2.1
		Date d7(1899, 13, 31); //2000.1.31
		Date d8(1899, 13, 32); //2000.1.1
		cout << "d5应该是2000.2.29，实际为：";
		d5.show();
		cout << "d6应该是2000.2.1， 实际为：";
		d6.show();
		cout << "d7应该是2000.1.31，实际为：";
		d7.show();
		cout << "d8应该是2000.1.1， 实际为：";
		d8.show();

		wait_for_enter();
	}

	if (1) {
		Date d1(2022, 2, 29); //2022.2.1
		Date d2(2020, 2, 29); //2020.2.29

		cout << "三参构造函数测试（闰年）" << endl;
		cout << "========================" << endl;

		cout << "d1应该是2022.2.1， 实际为：";
		d1.show();
		cout << "d2应该是2020.2.29，实际为：";
		d2.show();

		wait_for_enter();
	}

	if (1) {
		Date d1(1);          //1900.1.1
		Date d2(73049);      //2099.12.31
		Date d3(-100);       //1900.1.1
		Date d4(80000);      //2099.12.31
		Date d5(30000);      //1982.2.19
		Date d6(44721);      //2022.6.10

		cout << "一参构造函数测试，包括合法及非法值" << endl;
		cout << "==================================" << endl;

		cout << "d1应该是1900.1.1，  实际为：";
		d1.show();
		cout << "d2应该是2099.12.31，实际为：";
		d2.show();
		cout << "d3应该是1900.1.1，  实际为：";
		d3.show();
		cout << "d4应该是2099.12.31，实际为：";
		d4.show();
		cout << "d5应该是1982.2.19， 实际为：";
		d5.show();
		cout << "d6应该是2022.6.10， 实际为：";
		d6.show();

		wait_for_enter();
	}


	if (1) {
		Date d1, d2, d3; //都是2000.1.1

		cout << "测试set，带缺省值" << endl;
		cout << "=================" << endl;

		d1.set(2022, 6, 10);	//2022.6.10
		d2.set(2022, 6);		//2022.6.1
		d3.set(2022);			//2022.1.1

		cout << "d1应该是2022.6.10，实际为：";
		d1.show();
		cout << "d2应该是2022.6.1， 实际为：";
		d2.show();
		cout << "d3应该是2022.1.1， 实际为：";
		d3.show();

		wait_for_enter();
	}

	if (1) {
		Date d1, d2, d3, d4;

		cout << "测试set，年、月、日非法" << endl;
		cout << "=======================" << endl;

		d1.set(2112, 2, 29);  //2000.2.29
		d2.set(2019, 2, 29);  //2019.2.1
		d3.set(2022, 5, 32);  //2022.5.1
		d4.set(2022, 13, 12); //2022.1.12

		cout << "d1应该是2000.2.29， 实际为：";
		d1.show();
		cout << "d2应该是2019.2.1，  实际为：";
		d2.show();
		cout << "d3应该是2022.5.1，  实际为：";
		d3.show();
		cout << "d4应该是2022.1.12， 实际为：";
		d4.show();

		/* 多个错+带缺省值，按年月日顺序处理 */
		Date d5(2020, 1, 31), d6(d5), d7(d5), d8(d5), d9(d5), d10(d5), d11(d5);  //2020.1.31

		d5.set(1899, 2, 29);  //2000.2.29
		d6.set(1899, 2, 30);  //2000.2.1
		d7.set(1899, 2, 0);   //2000.2.1
		d8.set(0, 2, 0);      //2020.2.1
		d9.set(0, 13, 32);    //2020.1.1
		d10.set(1899, 13, 31);  //2000.1.31
		d11.set(1899, 13, 32);  //2000.1.1
		cout << "d5应该是2000.2.29， 实际为：";
		d5.show();
		cout << "d6应该是2000.2.1，  实际为：";
		d6.show();
		cout << "d7应该是2000.2.1，  实际为：";
		d7.show();
		cout << "d8应该是2020.2.1，  实际为：";
		d8.show();
		cout << "d9应该是2020.1.1，  实际为：";
		d9.show();
		cout << "d10应该是2000.1.31，实际为：";
		d10.show();
		cout << "d11应该是2000.1.1， 实际为：";
		d11.show();

		wait_for_enter();
	}

	if (1) {
		Date d1(2022, 6, 10);
		int y, m, d;

		cout << "测试get" << endl;
		cout << "=======" << endl;

		d1.get(y, m, d);
		cout << "应该y=2022,m=6,d=10，实际为：";
		cout << "y=" << y << ",m=" << m << ",d=" << d << endl;

		wait_for_enter();
	}

	return 0;
}
