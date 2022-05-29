/* 2052110 自动化 郭子瞻 */

#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

struct KFC {
	char id;
	const char* name;
	float price;
};

struct SPECIAL {
	const char* id;
	const char* name;
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

void menu(KFC * ptr_K, SPECIAL * ptr_S)
{
    int newline = 0;
    system("cls");
    cout << "=============================================================" << endl;
    cout << "                      KFC 2021秋季菜单" << endl;
    cout << "=============================================================" << endl;
    cout << setiosflags(ios::left);
    while (ptr_K->id != 0)
    {
        cout << " " << ptr_K->id << " " << setw(21) << ptr_K->name << setw(5) << ptr_K->price
             << (newline ? "\n" : " | ");
        newline = !newline;
        ptr_K++;
    }
    cout << "【优惠信息】：" << endl
         << endl;
    while (ptr_S->id)
    {
        cout << ptr_S->name << "=";
        for (unsigned int i = 0; i < strlen(ptr_S->id); i++)
        {
            cout << "+" << name_info[ptr_S->id[i] - 'A'];
        }
        cout << "=" << ptr_S->price;
        cout << endl;
        ptr_S++;
    }

    cout << "\n【输入规则说明】：\n";
    cout << "ANV=香辣鸡腿堡+薯条(小)+百事可乐(小) / akaak=香辣鸡腿堡*3+香辣鸡翅*2" << endl;
    cout << "字母不分大小写，不限顺序，单独输入0则退出程序" << endl;
    cout << endl;
    cout << "请点单：";
}

int main()
{
	const KFC* kp = list;
	const SPECIAL* sp = special;
	system("mode con cols=120 lines=35");
	char a[1000];
	char name_info[26][100] = { 0 };

    while (kp->id != 0) {
		strcpy(name_info[kp->id - 'A'],kp->name);
		kp++;
	}

	while (1) {
		kp = list;
		sp = special;
        menu(list, special);

        a[0] = 0;
        cin >> a;
		if (a[0] == '0')
			break;

		char* p = a;
		int diandan[26], diandan_ori[26];
		float price = 0;
		for (int i = 0; i < 26; i++) {
			diandan_ori[i] = diandan[i] = 0;
		}

		while (*p != 0) {
			if (*p >= 'a' && *p <= 'z') {
				*p -= 0x20;
			}

			diandan_ori[*p - 'A'] = ++diandan[*p - 'A'];
			p++;
		}


		kp = list;
		sp = special;


		while (sp->id != NULL) {
			while (1) {
				bool flag = true;
				for (unsigned int i = 0; i < strlen(sp->id); i++) {
					diandan[sp->id[i] - 'A']--;
				}

				for (int i = 0; i < 26; i++) {
					if (diandan[i] < 0) {
						flag = false;
					}
				}

				if (flag == true) {
					price += sp->price;
				}
				else {
					for (unsigned int i = 0; i < strlen(sp->id); i++) {
						diandan[sp->id[i] - 'A']++;
					}
					break;
				}
			}
			sp++;
		}

		while (kp->id != 0) {
			while (1) {
				if (diandan[kp->id - 'A'] > 0) {
					diandan[kp->id - 'A']--;
					price += kp->price;
				}
				else {
					break;
				}
			}
			kp++;
		}

		cout << "您的点餐=";
		for (int i = 0; i < 26; i++) {
			if (diandan_ori[i] != 0) {
				if (diandan[i] == 1) {
					cout << "+" << name_info[i];
				}
				else {
					cout <<"+"<<name_info[i] << "*" << diandan_ori[i];
				}
			}
		}
		cout << endl;
		cout << "共计：" << price << "元" << endl;

		cout << "点餐完成，按任意键继续" << endl;
		system("pause");
	}
}
