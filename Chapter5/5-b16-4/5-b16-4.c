/* 2052110 自动化 郭子瞻 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define N_PPL 10 // number of students
#define TMP_SIZE 10

/*compare id string
- input
    char id1[]: id1
    char id2[]: id2
- output
    1: id1 > id2
    2: id1 <= id2
*/
int id_cmp(const char id1[], const char id2[])
{
    for (int i = 0; id1[i] != '\0' && id2[i] != '\0'; ++i)
    {
        if (id1[i] != id2[i])
            return id1[i] - id2[i];
    }
    return 0; //return值可根据需要修改
}

/*copy string
- input:
    str1: destination string
    str2: source string
*/
void str_copy(char str1[], const char str2[])
{
    int len = 0;
    int i = 0;
    while (str2[len])
    {
        ++len;
    }
    for (i = 0; i < len; ++i)
    {
        str1[i] = str2[i];
    }
    str1[i] = '\0';
}

/*exchange str
- input:
    char str1[]: string1
    char str2[]: string2
*/
void str_exchange(char str1[], char str2[])
{
    char tmp[TMP_SIZE];
    str_copy(tmp, str1);
    str_copy(str1, str2);
    str_copy(str2, tmp);
}

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
int output_ones_info(const char name[], const char id[], int score, int group)
{
    switch (group)
    {
        case 0:
            if (score < 60)
            {
                printf("%s %s %d\n", name, id, score);
                return 1;
            }
            else
                return 0;
        case 1:
            if (score >= 60)
            {
                printf("%s %s %d\n", name, id, score);
                return 1;
            }
            else
                return 0;
        case 2:
            printf("%s %s %d\n", name, id, score);
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
int input_info(char name[][9], char id[][8], int score[])
{
    for (int i = 0; i < N_PPL; ++i)
    {
        printf("请输入第%d个人的学号、姓名、成绩\n", i + 1);
        scanf("%s%s%d", id[i], name[i], &score[i]);
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
void sort_grade(char name[][9], char id[][8], int score[], int key)
{
    int tmp;
    for (int i = N_PPL - 1; i > 0; --i)
    {
        for (int j = 0; j < i; ++j)
        {
            switch (key)
            {
                case 0:
                    if (id_cmp(id[j], id[j + 1]) < 0)
                    {
                        tmp = score[j];
                        score[j] = score[j + 1];
                        score[j + 1] = tmp;
                        str_exchange(name[j], name[j + 1]);
                        str_exchange(id[j], id[j + 1]);
                    }
                    break;
                case 1:
                    if (score[j] < score[j + 1])
                    {
                        tmp = score[j];
                        score[j] = score[j + 1];
                        score[j + 1] = tmp;
                        str_exchange(name[j], name[j + 1]);
                        str_exchange(id[j], id[j + 1]);
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
void output_info(const char name[][9], const char id[][8], const int score[], int reverse, int group, int key)
{
    printf("\n");
    switch (group)
    {
        case 0:
            printf("不及格名单");
            break;
        case 1:
            printf("及格名单");
            break;
        case 2:
            printf("全部学生");
            break;
        default:
            return;
    }
    printf("(%s%s):\n", (key ? "成绩" : "学号"), (reverse ? "升序" : "降序"));
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
    char name[N_PPL][9] = { 0 }; // 4 Chinese characters: 8 bytes
    char id[N_PPL][8] = { 0 }; // 7 bits student ID
    int score[N_PPL] = { 0 }; // integer score from 0 to 100
    if (input_info(name, id, score))
    {
        sort_grade(name, id, score, 1);
        output_info(name, id, score, 0, 2, 1);
    }
    return 0;
}
