/* 2052110 ����հ �Զ��� */
#include <iostream>
#include <conio.h>
using namespace std;

/* --- �������Ҫ�ĺ궨�塢ֻ��ȫ�ֱ����ȣ�д�ڴ˴� --- */
#define START 1900
#define END 2099

/* --- ���������ȫ�ֺ�����Ҫ������д�ڴ˴� --- */

/* ��ȫDate��Ķ��壬���г�Ա����������ʵ�֣���Ҫ�ڴ˴�����ʵ�� */
class Date {
private:
	int year;
	int month;
	int day;
	/* ������������ݳ�Ա */
    void illegal_manage(int * p, int y, int m, int d);
    int isleap(int y);
    int get_day(int year, int month, int day);
public:
	/* ������Ҫ��������ĳ�Ա��������Ԫ������(������������ݳ�Ա) */
    Date();
    Date(int day_from_beg);
    Date(int y, int m, int d);
    void set(int y);
    void set(int y, int m);
    void set(int y, int m, int d);
    void get(int &y, int &m, int &d);
    void show();
};

/* --- ���� Date ������г�Ա����������ʵ�� --- */
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
/* --- �������Ҫ������ȫ�ֺ�����ʵ�֣�����д�ڴ˴� --- */


/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void wait_for_enter()
{
	cout << endl << "���س�������";
	while (_getch() != '\r')
		;
	cout << endl << endl;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����main������׼��������ʱ���滻
***************************************************************************/
int main()
{
	if (1) {
		Date d1;				//2000.1.1
		Date d2(2022, 6, 10);	//2022.6.10

		cout << "�޲μ����ι��캯�����ԣ���ȫ��ȷ��" << endl;
		cout << "==================================" << endl;

		cout << "d1Ӧ����2000.1.1�� ʵ��Ϊ��";
		d1.show();
		cout << "d2Ӧ����2022.6.10��ʵ��Ϊ��";
		d2.show();

		wait_for_enter();
	}

	if (1) {
		Date d1(1870, 3, 15);  //2000.3.15
		Date d2(2112, 3, 4);   //2000.3.4
		Date d3(2005, 13, 15); //2005.1.15
		Date d4(2022, 6, 32);  //2022.6.1

		cout << "���ι��캯�����ԣ��ꡢ�¡��շǷ���" << endl;
		cout << "==================================" << endl;

		cout << "d1Ӧ����2000.3.15��ʵ��Ϊ��";
		d1.show();
		cout << "d2Ӧ����2000.3.4�� ʵ��Ϊ��";
		d2.show();
		cout << "d3Ӧ����2005.1.15��ʵ��Ϊ��";
		d3.show();
		cout << "d4Ӧ����2022.6.1�� ʵ��Ϊ��";
		d4.show();

		/* �������������˳���� */
		Date d5(1899, 2, 29);  //2000.2.29
		Date d6(1899, 2, 30);  //2000.2.1
		Date d7(1899, 13, 31); //2000.1.31
		Date d8(1899, 13, 32); //2000.1.1
		cout << "d5Ӧ����2000.2.29��ʵ��Ϊ��";
		d5.show();
		cout << "d6Ӧ����2000.2.1�� ʵ��Ϊ��";
		d6.show();
		cout << "d7Ӧ����2000.1.31��ʵ��Ϊ��";
		d7.show();
		cout << "d8Ӧ����2000.1.1�� ʵ��Ϊ��";
		d8.show();

		wait_for_enter();
	}

	if (1) {
		Date d1(2022, 2, 29); //2022.2.1
		Date d2(2020, 2, 29); //2020.2.29

		cout << "���ι��캯�����ԣ����꣩" << endl;
		cout << "========================" << endl;

		cout << "d1Ӧ����2022.2.1�� ʵ��Ϊ��";
		d1.show();
		cout << "d2Ӧ����2020.2.29��ʵ��Ϊ��";
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

		cout << "һ�ι��캯�����ԣ������Ϸ����Ƿ�ֵ" << endl;
		cout << "==================================" << endl;

		cout << "d1Ӧ����1900.1.1��  ʵ��Ϊ��";
		d1.show();
		cout << "d2Ӧ����2099.12.31��ʵ��Ϊ��";
		d2.show();
		cout << "d3Ӧ����1900.1.1��  ʵ��Ϊ��";
		d3.show();
		cout << "d4Ӧ����2099.12.31��ʵ��Ϊ��";
		d4.show();
		cout << "d5Ӧ����1982.2.19�� ʵ��Ϊ��";
		d5.show();
		cout << "d6Ӧ����2022.6.10�� ʵ��Ϊ��";
		d6.show();

		wait_for_enter();
	}


	if (1) {
		Date d1, d2, d3; //����2000.1.1

		cout << "����set����ȱʡֵ" << endl;
		cout << "=================" << endl;

		d1.set(2022, 6, 10);	//2022.6.10
		d2.set(2022, 6);		//2022.6.1
		d3.set(2022);			//2022.1.1

		cout << "d1Ӧ����2022.6.10��ʵ��Ϊ��";
		d1.show();
		cout << "d2Ӧ����2022.6.1�� ʵ��Ϊ��";
		d2.show();
		cout << "d3Ӧ����2022.1.1�� ʵ��Ϊ��";
		d3.show();

		wait_for_enter();
	}

	if (1) {
		Date d1, d2, d3, d4;

		cout << "����set���ꡢ�¡��շǷ�" << endl;
		cout << "=======================" << endl;

		d1.set(2112, 2, 29);  //2000.2.29
		d2.set(2019, 2, 29);  //2019.2.1
		d3.set(2022, 5, 32);  //2022.5.1
		d4.set(2022, 13, 12); //2022.1.12

		cout << "d1Ӧ����2000.2.29�� ʵ��Ϊ��";
		d1.show();
		cout << "d2Ӧ����2019.2.1��  ʵ��Ϊ��";
		d2.show();
		cout << "d3Ӧ����2022.5.1��  ʵ��Ϊ��";
		d3.show();
		cout << "d4Ӧ����2022.1.12�� ʵ��Ϊ��";
		d4.show();

		/* �����+��ȱʡֵ����������˳���� */
		Date d5(2020, 1, 31), d6(d5), d7(d5), d8(d5), d9(d5), d10(d5), d11(d5);  //2020.1.31

		d5.set(1899, 2, 29);  //2000.2.29
		d6.set(1899, 2, 30);  //2000.2.1
		d7.set(1899, 2, 0);   //2000.2.1
		d8.set(0, 2, 0);      //2020.2.1
		d9.set(0, 13, 32);    //2020.1.1
		d10.set(1899, 13, 31);  //2000.1.31
		d11.set(1899, 13, 32);  //2000.1.1
		cout << "d5Ӧ����2000.2.29�� ʵ��Ϊ��";
		d5.show();
		cout << "d6Ӧ����2000.2.1��  ʵ��Ϊ��";
		d6.show();
		cout << "d7Ӧ����2000.2.1��  ʵ��Ϊ��";
		d7.show();
		cout << "d8Ӧ����2020.2.1��  ʵ��Ϊ��";
		d8.show();
		cout << "d9Ӧ����2020.1.1��  ʵ��Ϊ��";
		d9.show();
		cout << "d10Ӧ����2000.1.31��ʵ��Ϊ��";
		d10.show();
		cout << "d11Ӧ����2000.1.1�� ʵ��Ϊ��";
		d11.show();

		wait_for_enter();
	}

	if (1) {
		Date d1(2022, 6, 10);
		int y, m, d;

		cout << "����get" << endl;
		cout << "=======" << endl;

		d1.get(y, m, d);
		cout << "Ӧ��y=2022,m=6,d=10��ʵ��Ϊ��";
		cout << "y=" << y << ",m=" << m << ",d=" << d << endl;

		wait_for_enter();
	}

	return 0;
}
