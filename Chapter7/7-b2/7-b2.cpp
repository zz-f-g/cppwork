/* 2052110 �Զ��� ����հ */
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
    cout << "                      KFC 2021�＾�˵�" << endl;
    cout << "=============================================================" << endl;
    cout << setiosflags(ios::left);
    while (pK->id)
    {
        cout << " " << pK->id << " " << setw(21) << pK->name << setw(5) << pK->price;
        cout << (newline ? "\n" : " | ");
        newline = !newline;
        pK++;
    }
    cout << "���Ż���Ϣ����" << endl
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
    cout << "\n���������˵������\n";
    cout << "ANV=�������ȱ�+����(С)+���¿���(С) / akaak=�������ȱ�*3+��������*2" << endl;
    cout << "��ĸ���ִ�Сд������˳�򣬵�������0���˳�����" << endl;
    cout << endl;
    cout << "��㵥��";
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
            cout << "������󣬰����������." << endl;
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

        cout << "���ĵ��=";
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
        cout << "���ƣ�" << price_tot << "Ԫ" << endl;

        cout << "�����ɣ������������" << endl;
        getchar();
        _getch();
    }
    return 0;
}
