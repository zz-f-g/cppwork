/* 2052110 �Զ��� ����հ */
#include <iostream>
#include <iomanip>
#include <conio.h>  //��getch����˲���Ҫ֧��Linux
#include <string.h> //Dev/CB��strlen��Ҫ
using namespace std;
#define STRSIZE 30
#define MAXCOMB 20

struct dish
{
    char id;
    char name[STRSIZE];
    double price;
    int number;
};

struct SPECIAL
{
    char ids[MAXCOMB];
    char name[STRSIZE];
    double price;
};

const struct dish list[] = {
    {'A', "�������ȱ�", 18.5},
    {'B', "���༦�ȱ�", 18.5},
    {'C', "�°¶��������ȱ�", 19},
    {'D', "�ϱ��������", 17},
    {'E', "������ţ��", 19.5},
    {'F', "����㱤", 18.5},
    {'G', "˱ָԭζ��(1��)", 11.5},
    {'H', "֥֥����������Ƥ��", 12.5},
    {'I', "�°¶�������(2��)", 12.5},
    {'J', "�������׻�", 11.5},
    {'K', "��������(2��)", 12.0},
    {'L', "�ٽ��޹Ǵ���(2��)", 12.5},
    {'M', "����ɫ��", 13},
    {'N', "����(С)", 9},
    {'O', "����(��)", 12},
    {'P', "����(��)", 14},
    {'Q', "ܽ��������", 9},
    {'R', "ԭζ��Ͳ������", 6},
    {'S', "����������", 7},
    {'T', "�������װ�", 9.0},
    {'U', "��ʽ��̢", 8.0},
    {'V', "���¿���(С)", 7.0},
    {'W', "���¿���(��)", 9.5},
    {'X', "���¿���(��)", 11.5},
    {'Y', "�����֭����", 12.5},
    {'Z', "����������", 11.5},
    {'\0', NULL, 0}};

const struct SPECIAL special[] = {
    //	{"ANV", "�������ȱ����������",  24}, //�������Ҫ���ſ����ע�͵���һ�еġ�BMV���Żݣ��۲��Żݲ˵��Ƿ����˱仯
    {"BMV", "���༦�ȱ���ֵ�ײ�", 26},
    {"ABCGGIIKKOUWWW", "��ֵȫ��Ͱ", 115},
    {"KIIRRJUWW", "�ͷ�С��Ͱ", 65},
    {"JJ", "�������׻�(2��С)", 12.5},
    {NULL, NULL, 0}};

void print_dish(struct KFC dish)
{
    cout << setiosflags(ios::left);
    cout << ' ' << dish.id << ' ' << setw(20) << dish.name << setw(5) << dish.price;
}

void menu(char *order_str)
{
    cout << "=============================================================" << endl;
    cout << "                      KFC 2021�＾�˵�" << endl;
    cout << "=============================================================" << endl;
}

int main()
{
    int ifctn = 1;
    char order_str[MAXCOMB];
    while (ifctn)
    {
        system("cls");
        system("mode con cols=120 lines=35");
        menu(order_str);
    }
    return 0;
}