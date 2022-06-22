/* 2052110 郭子瞻 自动化 */

/* 允许按需加入系统的宏定义、需要的头文件等 */
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <fstream>
#include <iomanip>
#include <iostream>
using namespace std;

#define MAX_STU_NUM			256	//约定最大人数为256人（两轮的总和，包括退选、补选）
#define MAX_NAME_LEN			32	//学生姓名的最大长度不超过16个汉字
#define MAX_FILENAME_LEN		256	//文件名的最大长度

class stu_list;
/* stu_info 类存放每个学生的信息，包括学号、姓名、其它需要的私有信息，已有内容不准动，可加入符合限制要求的新内容 */
class stu_info {
private:
	int  stu_no;			//学号
	char stu_name[MAX_NAME_LEN];	//姓名

	/* 允许按需加入private数据成员、成员函数以及其它需要的内容 */
    int select_info[2] = {0};
    char state[MAX_NAME_LEN];
    void update_state();
    friend stu_list;

public:
	/* 本类不允许定义任何的公有数据成员、成员函数 */
};

void stu_info::update_state()
{
    if (this->select_info[0])
    {
        if (this->select_info[1])
            strcpy(this->state, "Y      Y");
        else
            strcpy(this->state, "Y      退课");
    }
    else
    {
        if (this->select_info[1])
            strcpy(this->state, "/      补选");
        else
            strcpy(this->state, "\0");
    }
}

/* stu_list 类整个选课信息，已有内容不准动，可加入符合限制要求的新内容 */
class stu_list {
private:
	stu_info stu[MAX_STU_NUM + 1];

	/* 允许按需加入private数据成员和成员函数 */
    stu_info *top = stu;
    int is_overflow();
    int is_in(int id);
    int push(int id, const char * name);
    void bubble_sort();

public:
	int read(const char* filename, const int append = 0);	//从文件中读入选课信息并进行处理，第2个参数值为0表示覆盖方式，1表示追加方式
	int print(const char *prompt = NULL);			//打印当前读入的选课名单

	/* 允许按需加入其它public成员函数 */

};

/* --- 此处给出上面两个类的成员函数的体外实现 --- */
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
        cout << "文件[" << filename << "]打开失败" << endl;
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
	cout << "序号 学号    姓名                             第一轮 第二轮" << endl;
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
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：main函数不准动
***************************************************************************/
int main()
{
	char file1[MAX_FILENAME_LEN], file2[MAX_FILENAME_LEN];

	cout << "请输入前一轮选课的数据文件 : ";
	cin >> file1;
	cout << "请输入后一轮选课的数据文件 : ";
	cin >> file2;

	stu_list list;

	/* 读入第一个数据文件 */
	if (list.read(file1) < 0)
		return -1;

	/* 读入第二个数据文件，参数2的值为1表示追加方式 */
	if (list.read(file2, 1) < 0)
		return -1;

	list.print("最终选课名单");

	return 0;
}
