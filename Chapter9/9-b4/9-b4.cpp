/* 2052110 ����հ �Զ��� */

/* ���������ϵͳ�ĺ궨�塢��Ҫ��ͷ�ļ��� */
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <fstream>
#include <iomanip>
#include <iostream>
using namespace std;

#define MAX_STU_NUM			256	//Լ���������Ϊ256�ˣ����ֵ��ܺͣ�������ѡ����ѡ��
#define MAX_NAME_LEN			32	//ѧ����������󳤶Ȳ�����16������
#define MAX_FILENAME_LEN		256	//�ļ�������󳤶�

class stu_list;
/* stu_info ����ÿ��ѧ������Ϣ������ѧ�š�������������Ҫ��˽����Ϣ���������ݲ�׼�����ɼ����������Ҫ��������� */
class stu_info {
private:
	int  stu_no;			//ѧ��
	char stu_name[MAX_NAME_LEN];	//����

	/* ���������private���ݳ�Ա����Ա�����Լ�������Ҫ������ */
    int select_info[2] = {0};
    char state[MAX_NAME_LEN];
    void update_state();
    friend stu_list;

public:
	/* ���಻�������κεĹ������ݳ�Ա����Ա���� */
};

void stu_info::update_state()
{
    if (this->select_info[0])
    {
        if (this->select_info[1])
            strcpy(this->state, "Y      Y");
        else
            strcpy(this->state, "Y      �˿�");
    }
    else
    {
        if (this->select_info[1])
            strcpy(this->state, "/      ��ѡ");
        else
            strcpy(this->state, "\0");
    }
}

/* stu_list ������ѡ����Ϣ���������ݲ�׼�����ɼ����������Ҫ��������� */
class stu_list {
private:
	stu_info stu[MAX_STU_NUM + 1];

	/* ���������private���ݳ�Ա�ͳ�Ա���� */
    stu_info *top = stu;
    int is_overflow();
    int is_in(int id);
    int push(int id, const char * name);
    void bubble_sort();

public:
	int read(const char* filename, const int append = 0);	//���ļ��ж���ѡ����Ϣ�����д�����2������ֵΪ0��ʾ���Ƿ�ʽ��1��ʾ׷�ӷ�ʽ
	int print(const char *prompt = NULL);			//��ӡ��ǰ�����ѡ������

	/* �������������public��Ա���� */

};

/* --- �˴���������������ĳ�Ա����������ʵ�� --- */
int stu_list::is_overflow()
{
    return (this->top - this->stu) == MAX_STU_NUM;
}

int stu_list::is_in(int id)
{
    for (int i = 0; i < this->top - this->stu; ++i)
    {
        if (this->stu[i].stu_no == id)
            return i;
    }
    return -1;
}

int stu_list::push(int id, const char * name)
{
    int repeat = is_in(id);
    if (is_overflow())
        return -2;
    if (repeat < 0)
    {
        this->top->stu_no = id;
        strcpy(this->top->stu_name, name);
        ++(this->top);
        return -1;
    }
    else
    {
        return repeat;
    }
}

void stu_list::bubble_sort()
{
    int len = this->top - this->stu;
    stu_info tmp;
    for (int i = len - 1; i > 0; --i)
    {
        for (int j = 0; j < i; ++j)
        {
            if ((this->stu + j)->stu_no > (this->stu + j + 1)->stu_no)
            {
                tmp = *(this->stu + j);
                *(this->stu + j) = *(this->stu + j + 1);
                *(this->stu + j + 1) = tmp;
            }
        }
    }
}

int stu_list::read(const char* filename, const int append)
{
    ifstream in(filename, ios::in);
    int id, tmp;
    char name[MAX_NAME_LEN];
    if (!in.is_open())
    {
        cout << "�ļ�[" << filename << "]��ʧ��" << endl;
        return -1; // hint???
    }
    while (1)
    {
        in >> id >> name;
        if (in.fail())
            break;
        tmp = push(id, name);
        switch (tmp)
        {
            case -2:
                return 1; // overflow
            case -1:
                (this->top - 1)->select_info[append] = 1; // new id
                break;
            default: // old id
                if (append)
                {
                    (this->stu + tmp)->select_info[append] = 1;
                }
                break;
        }
    }
    return 0;
}

int stu_list::print(const char *prompt)
{
    bubble_sort();
    for (int i = 0; i < this->top - this->stu; ++i)
    {
        this->stu[i].update_state();
    }
    cout << setiosflags(ios::left);
    if (prompt)
        cout << prompt << endl;
	cout << "===========================================================" << endl;
	cout << "��� ѧ��    ����                             ��һ�� �ڶ���" << endl;
	cout << "===========================================================" << endl;
    for (int i = 0; i < (this->top - this->stu); ++i)
    {
        cout << setw(5) << i + 1
             << setw(8) << (stu + i)->stu_no
             << setw(33) << (stu + i)->stu_name
             << (stu + i)->state
             << endl;
    }
    cout << "===========================================================" << endl;
    return 0;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����main������׼��
***************************************************************************/
int main()
{
	char file1[MAX_FILENAME_LEN], file2[MAX_FILENAME_LEN];

	cout << "������ǰһ��ѡ�ε������ļ� : ";
	cin >> file1;
	cout << "�������һ��ѡ�ε������ļ� : ";
	cin >> file2;

	stu_list list;

	/* �����һ�������ļ� */
	if (list.read(file1) < 0)
		return -1;

	/* ����ڶ��������ļ�������2��ֵΪ1��ʾ׷�ӷ�ʽ */
	if (list.read(file2, 1) < 0)
		return -1;

	list.print("����ѡ������");

	return 0;
}
