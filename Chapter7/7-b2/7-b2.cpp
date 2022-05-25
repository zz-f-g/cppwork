/* 2052110 自动化 郭子瞻 */
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <ctime>
#include <conio.h>  //用getch，因此不需要支持Linux
#include <string.h> //Dev/CB的strlen需要
using namespace std;
#define START 1970

struct tj_time
{
    int tj_year;   //表示年份
    int tj_month;  //表示月(1-12)
    int tj_day;    //表示日(1-28/29/30/31)
    int tj_hour;   //表示小时(0-23)
    int tj_minute; //表示分(0-59)
    int tj_second; //表示秒(0-59)
};
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
int get_day(int year, int month, int day)
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
void tj_day_convert(tj_time *time, int day)
{
    int year = day / 366 + START;
    int month = 1;
    while (get_day(year, 1, 1) > day)
        ++year;
    time->tj_year = --year;
    while (get_day(year, month, 1) > day)
        ++month;
    time->tj_month = --month;
    time->tj_day = day - get_day(year, month, 1) + 1;
}

int main()
{
    struct tj_time time, *tp = &time;
    time.tj_hour = 0;
    time.tj_minute = 0;
    time.tj_second = 0;
    tj_day_convert(&time, 365);
    cout << setfill('0')
         << setw(4) << tp->tj_year << '-'
         << setw(2) << tp->tj_month << '-'
         << setw(2) << tp->tj_day << ' '
         << setw(2) << tp->tj_hour << ':'
         << setw(2) << tp->tj_minute << ':'
         << setw(2) << tp->tj_second << endl;
    return 0;
}