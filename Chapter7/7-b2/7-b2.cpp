/* 2052110 自动化 郭子瞻 */
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>
#include <iomanip>
#include <cstring>
#define MAXSIZE 100
using namespace std;

struct KFC
{
    char id;
    const char *name;
    float price;
};

struct SPECIAL
{
    const char *id;
    const char *name;
    float price;
};

const struct KFC list[] = {
    {'A', "香辣鸡腿堡", 18.5},
    {'B', "劲脆鸡腿堡", 18.5},
    {'C', "新奥尔良烤鸡腿堡", 19},
    {'D', "老北京鸡肉卷", 17},
    {'E', "川辣嫩牛卷", 19.5},
    {'F', "深海鳕鱼堡", 18.5},
    {'G', "吮指原味鸡(1块)", 11.5},
    {'H', "芝芝肉酥热辣脆皮鸡", 12.5},
    {'I', "新奥尔良烤翅(2块)", 12.5},
    {'J', "劲爆鸡米花", 11.5},
    {'K', "香辣鸡翅(2块)", 12.0},
    {'L', "藤椒无骨大鸡柳(2块)", 12.5},
    {'M', "鲜蔬色拉", 13},
    {'N', "薯条(小)", 9},
    {'O', "薯条(中)", 12},
    {'P', "薯条(大)", 14},
    {'Q', "芙蓉蔬荟汤", 9},
    {'R', "原味花筒冰激凌", 6},
    {'S', "醇香土豆泥", 7},
    {'T', "香甜粟米棒", 9.0},
    {'U', "葡式蛋挞", 8.0},
    {'V', "百事可乐(小)", 7.0},
    {'W', "百事可乐(中)", 9.5},
    {'X', "百事可乐(大)", 11.5},
    {'Y', "九珍果汁饮料", 12.5},
    {'Z', "纯纯玉米饮", 11.5},
    {'\0', NULL, 0}};

const struct SPECIAL special[] = {
    //	{"ANV", "香辣鸡腿堡工作日午餐",  24}, //如果有需要，放开此项，注释掉下一行的“BMV”优惠，观察优惠菜单是否发生了变化
    {"BMV", "劲脆鸡腿堡超值套餐", 26},
    {"ABCGGIIKKOUWWW", "超值全家桶", 115},
    {"KIIRRJUWW", "缤纷小吃桶", 65},
    {"JJ", "劲爆鸡米花(2份小)", 12.5},
    {NULL, NULL, 0}};

const int n_dishes = sizeof(list) / sizeof(list[0]);

int get_index(char id)
{
    for (int i = 0; i < n_dishes; ++i)
    {
        if (list[i].id == id)
            return i;
    }
    return -1;
}

void menu()
{
    const KFC *pK = list;
    const SPECIAL *pS = special;
    int newline = 0;
    system("cls");
    cout << "=============================================================" << endl;
    cout << "                      KFC 2021秋季菜单" << endl;
    cout << "=============================================================" << endl;
    cout << setiosflags(ios::left);
    while (pK->id)
    {
        cout << " " << pK->id << " " << setw(21) << pK->name << setw(5) << pK->price;
        cout << (newline ? "\n" : " | ");
        newline = !newline;
        pK++;
    }
    cout << "【优惠信息】：" << endl
         << endl;
    while (pS->id)
    {
        cout << pS->name << "=";
        for (unsigned int i = 0; i < strlen(pS->id); i++)
        {
            cout << (i == 0 ? "" : "+") << list[get_index(pS->id[i])].name;
        }
        cout << "=" << pS->price << endl;
        pS++;
    }
    cout << "\n【输入规则说明】：\n";
    cout << "ANV=香辣鸡腿堡+薯条(小)+百事可乐(小) / akaak=香辣鸡腿堡*3+香辣鸡翅*2" << endl;
    cout << "字母不分大小写，不限顺序，单独输入0则退出程序" << endl;
    cout << endl;
    cout << "请点单：";
}

int cmd_input(char *cmd)
{
    int flag = 1;
    while (1)
    {
        cin >> cmd;
        for (int i = 0; cmd[i]; ++i)
        {
            if (!(cmd[i] >= 'A' && cmd[i] <= 'Z' || cmd[i] >= 'a' && cmd[i] <= 'z'))
            {
                flag = 0;
                break;
            }
        }
        if (flag)
            return 1;
        if (cmd[0] == '0' && cmd[1] == '\0')
            return 0;
        else
        {
            cout << "输入错误，按任意键继续." << endl;
            getchar();
            _getch();
            menu();
        }
    }
}

int main()
{
    const KFC *kp = list;
    const SPECIAL *sp = special;
    system("mode con cols=120 lines=35");
    char cmd[MAXSIZE] = {'\0'}, *p_cmd = cmd;

    while (1)
    {
        cmd[0] = '\0';
        p_cmd = cmd;
        int order[n_dishes] = {0};
        int order_ori[n_dishes] = {0};
        float price_tot = 0;
        kp = list;
        sp = special;
        menu();
        if (!cmd_input(cmd))
        {
            return 0;
        }
        while (*p_cmd)
        {
            *p_cmd += ((*p_cmd >= 'a' && *p_cmd <= 'z') ? 'A' - 'a' : 0);
            order_ori[*p_cmd - 'A'] = ++order[*p_cmd - 'A'];
            p_cmd++;
        }

        while (sp->id)
        {
            while (1)
            {
                bool flag = true;
                for (unsigned int i = 0; i < strlen(sp->id); i++)
                    order[sp->id[i] - 'A']--;
                for (int i = 0; i < n_dishes; i++)
                {
                    if (order[i] < 0)
                        flag = false;
                }

                if (flag)
                {
                    price_tot += sp->price;
                    break;
                }
                else
                {
                    for (unsigned int i = 0; i < strlen(sp->id); i++)
                        order[sp->id[i] - 'A']++;
                    break;
                }
            }
            sp++;
        }

        while (kp->id)
        {
            while (1)
            {
                if (order[kp->id - 'A'] > 0)
                {
                    order[kp->id - 'A']--;
                    price_tot += kp->price;
                }
                else
                    break;
            }
            kp++;
        }

        cout << "您的点餐=";
        for (char i = 'A'; i <= 'Z'; i += (char)1)
        {
            if (order_ori[i - 'A'])
            {
                if (order_ori[i - 'A'] == 1)
                    cout << "+" << list[get_index(i)].name;
                else
                    cout << "+" << list[get_index(i)].name << "*" << order_ori[i - 'A'];
            }
        }
        cout << endl;
        cout << "共计：" << price_tot << "元" << endl;

        cout << "点餐完成，按任意键继续" << endl;
        getchar();
        _getch();
    }
    return 0;
}
