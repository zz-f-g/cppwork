/* 2052110 �Զ��� ����հ */

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

void menu(KFC * ptr_K, SPECIAL * ptr_S)
{
    int newline = 0;
    system("cls");
    cout << "=============================================================" << endl;
    cout << "                      KFC 2021�＾�˵�" << endl;
    cout << "=============================================================" << endl;
    cout << setiosflags(ios::left);
    while (ptr_K->id != 0)
    {
        cout << " " << ptr_K->id << " " << setw(21) << ptr_K->name << setw(5) << ptr_K->price
             << (newline ? "\n" : " | ");
        newline = !newline;
        ptr_K++;
    }
    cout << "���Ż���Ϣ����" << endl
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

    cout << "\n���������˵������\n";
    cout << "ANV=�������ȱ�+����(С)+���¿���(С) / akaak=�������ȱ�*3+��������*2" << endl;
    cout << "��ĸ���ִ�Сд������˳�򣬵�������0���˳�����" << endl;
    cout << endl;
    cout << "��㵥��";
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

		cout << "���ĵ��=";
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
		cout << "���ƣ�" << price << "Ԫ" << endl;

		cout << "�����ɣ������������" << endl;
		system("pause");
	}
}
