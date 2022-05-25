/* 2052110 �Զ��� ����հ */
#define _CRT_SECURE_NO_WARNINGS		//ʹ����VS��Ϊunsafe�ĺ���
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <ctime>
#include <conio.h>	//��getch����˲���Ҫ֧��Linux
#include <string.h>	//Dev/CB��strlen��Ҫ
using namespace std;
#define START 1970

struct tj_time {
	int tj_year;	//��ʾ���
	int tj_month;	//��ʾ��(1-12)
	int tj_day;	//��ʾ��(1-28/29/30/31)
	int tj_hour;	//��ʾСʱ(0-23)
	int tj_minute;	//��ʾ��(0-59)
	int tj_second;	//��ʾ��(0-59)
};

/* �����ڴ˶���������Ҫ�ĺ��� */
/* if the year is leap year
*/
int isleap(int year)
{
	return (year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0);
}

/* get the day from 1970-01-01 00:00:00 to 00:00:00 of this day
- input:
    int year: start from 1970
    int month: 1-12
    int day
*/
int get_day(int year, int month = 1, int day = 1)
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

/* get the date from 1970-01-01
- input:
    int day: number of days from 1970-01-01
- output:
    tj_time * time
*/
void tj_day_convert(tj_time * time, int day)
{
    int year = day / 366 + START;
    int month = 1;
    while (get_day(year) <= day)
        ++year;
    time->tj_year = --year;
    while (get_day(year, month) <= day)
        ++month;
    time->tj_month = --month;
    time->tj_day = day - get_day(year, month) + 1;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�������ʾ���ȴ��س���
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void wait_for_enter(const char *const prompt = NULL)
{
	if ((prompt == NULL) || (strlen(prompt) == 0)) //˼��һ�£�||���������������ܷ񻥻�
		cout << endl << "���س�������";
	else
		cout << endl << prompt << "�����س�������";

	while (_getch() != '\r')
		;
	cout << endl << endl;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�����ϵͳ��ת��������������ֵת��Ϊ�뱾�����ƵĽṹ�岢���
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void system_time_output(const time_t input_time)  //time_t�ı�����64λ�޷�������
{
    struct tm *tt;	//struct tm Ϊϵͳ����Ľṹ��

    tt = localtime(&input_time);	//localtimeΪϵͳ����

    /* tm_*** Ϊstruct tm�еĳ�Ա���ͱ����struct tj_time��������ݲ���ȫ���ϣ����庬���Լ������������ */
    cout << setfill('0') << setw(4) << tt->tm_year+1900 << '-' 
						<< setw(2) << tt->tm_mon + 1 << '-' 
						<< setw(2) << tt->tm_mday << ' ' 
						<< setw(2) << tt->tm_hour << ':' 
						<< setw(2) << tt->tm_min << ':' 
						<< setw(2) << tt->tm_sec << endl;

    return;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ��Զ���ת������������
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void tj_time_output(const struct tj_time *const tp)
{
    /* ʵ���Զ���ṹ������������ʽ��system_time_output��ͬ */
    cout << setfill('0') << setw(4) << tp->tj_year << '-' 
						<< setw(2) << tp->tj_month << '-' 
						<< setw(2) << tp->tj_day << ' '
						<< setw(2) << tp->tj_hour << ':' 
						<< setw(2) << tp->tj_minute << ':'
						<< setw(2) << tp->tj_second << endl;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ��Զ���ת������
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
struct tj_time *tj_time_convert(int input_time)
{
    static struct tj_time result;	//���徲̬�ֲ���������׼��

    /* ʵ�ֹ��̿�ʼ�������������Ӧ�Ķ��弰ִ����伴�� */
    const int sec_in_day = 24 * 60 * 60;
    const int sec_in_hour = 60 * 60;
    const int sec_in_min = 60;
    const int time_zone = 8; // GTM+8
    input_time += time_zone * sec_in_hour;
    result.tj_hour = (input_time % sec_in_day) / sec_in_hour;
    result.tj_minute = (input_time % sec_in_day) % sec_in_hour / sec_in_min;
    result.tj_second = (input_time % sec_in_day) % sec_in_hour % sec_in_min;
    tj_day_convert(&result, input_time / sec_in_day);
    /* ʵ�ֹ��̽��� */

    return &result;	//ע�⣬���ص��Ǿ�̬�ֲ������ĵ�ַ������䲻׼��
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int main()
{
	int read_time;
	struct tj_time *tp;

	for (;;) {
		cin >> read_time; //��Ϊ���������ض��򣬴˴������κ���ʾ

		/* ��������<0���˳�ѭ�� */
		if (cin.good() == 0 || read_time < 0)
			break;

		cout << "����             : " << read_time << endl;
		cout << "ϵͳת���Ľ��   : ";
		system_time_output(read_time);
	
		cout << "�Զ���ת���Ľ�� : ";
		tp = tj_time_convert(read_time);
		tj_time_output(tp);

		wait_for_enter();
		}

	if (1) {
		struct tj_time *tp;
		int t=(int)time(0);		//ϵͳ������ȡ��ǰϵͳʱ�䣨��1970-01-01 00:00:00��ʼ��������

		cout << "��ǰϵͳʱ��     : " << t << endl;
		cout << "ϵͳת���Ľ��   : ";
		system_time_output(t);
	
		cout << "�Զ���ת���Ľ�� : ";
		tp = tj_time_convert(t);
		tj_time_output(tp);

		wait_for_enter();
		}

	return 0;
}
