/* 2052110 自动化 郭子瞻 */
#include <iostream>
using namespace std;
#include <string>
#define N_PPL 10 // number of students
#define TMP_SIZE 10

/*output ones info according to group selection
- input:
    char name[]: name string of the student
    char id[]: student ID string of the student
    int score: score of the student
    int group: the gourp of students output
        0: fail the exam
        1: pass the exam
        2: all
- output:
    1: student is in the group
    1: student is not in the group
*/
int output_ones_info(const string name, const string id, int score, int group)
{
    switch (group)
    {
        case 0:
            if (score < 60)
            {
                cout << name << ' ' << id << ' ' << score << endl;
                return 1;
            }
            else
                return 0;
        case 1:
            if (score >= 60)
            {
                cout << name << ' ' << id << ' ' << score << endl;
                return 1;
            }
            else
                return 0;
        case 2:
            cout << name << ' ' << id << ' ' << score << endl;
            return 1;
        default:
            return 0;
    }
}

/*input info and assign the info to arrays
- input:
    char name[][]: name strings of students
    char id[][]: student ID strings of students
    int score[]: scores of students
- output:
    int res: 1 for successful input, 0 for failing input
*/
int input_info(string name[], string id[], int score[])
{
    for (int i = 0; i < N_PPL; ++i)
    {
        cout << "请输入第" << i + 1 << "个人的学号、姓名、成绩" << endl;
        cin >> id[i] >> name[i] >> score[i];
    }
    return 1;
}

/*sort the arrays according to scores in descending order
- input:
    char name[][]: name strings of students
    char id[][]: student ID strings of students
    int score[]: scores of students
    int key:
        0: key is id
        1: key is score
*/
void sort_grade(string name[], string id[], int score[], int key)
{
    int tmp;
    string tmp_str;
    for (int i = N_PPL - 1; i > 0; --i)
    {
        for (int j = 0; j < i; ++j)
        {
            switch (key)
            {
                case 0:
                    if (id[j] < id[j + 1])
                    {
                        tmp = score[j];
                        score[j] = score[j + 1];
                        score[j + 1] = tmp;
                        tmp_str = name[j];
                        name[j] = name[j + 1];
                        name[j + 1] = tmp_str;
                        tmp_str = id[j];
                        id[j] = id[j + 1];
                        id[j + 1] = tmp_str;
                    }
                    break;
                case 1:
                    if (score[j] < score[j + 1])
                    {
                        tmp = score[j];
                        score[j] = score[j + 1];
                        score[j + 1] = tmp;
                        tmp_str = name[j];
                        name[j] = name[j + 1];
                        name[j + 1] = tmp_str;
                        tmp_str = id[j];
                        id[j] = id[j + 1];
                        id[j + 1] = tmp_str;
                    }
                    break;
            }
        }
    }
}

/*output info
- input:
    const char name[][]: name strings of students
    const char id[][]: student ID strings of students
    const int score[]: scores of students
    int reverse: 0 in descending order, 1 in reverse
    int group: the gourp of students output
        0: fail the exam
        1: pass the exam
        2: all
    int key:
        0: key is id
        1: key is score
*/
void output_info(const string name[], const string id[], const int score[], int reverse, int group, int key)
{
    cout << endl;
    switch (group)
    {
        case 0:
            cout <<  "不及格名单";
            break;
        case 1:
            cout << "及格名单";
            break;
        case 2:
            cout << "全部学生";
            break;
        default:
            return;
    }
    cout << '(' << (key ? "成绩" : "学号") << (reverse ? "升序" : "降序") << ')' << endl;
    switch (reverse)
    {
        case 0:
            for (int i = 0; i < N_PPL; ++i)
                output_ones_info(name[i], id[i], score[i], group);
            break;
        case 1:
            for (int i = N_PPL - 1; i >=0; --i)
                output_ones_info(name[i], id[i], score[i], group);
            break;
    }
}

int main()
{
    string name[N_PPL];
    string id[N_PPL];
    int score[N_PPL] = { 0 }; // integer score from 0 to 100
    if (input_info(name, id, score))
    {
        sort_grade(name, id, score, 0);
        output_info(name, id, score, 1, 2, 0);
    }
    return 0;
}
