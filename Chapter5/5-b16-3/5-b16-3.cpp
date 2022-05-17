/* 2052110 自动化 郭子瞻 */
#include <iostream>
using namespace std;

int main()
{
    char name[N_PPL][9] = { 0 }; // 4 Chinese characters: 8 bytes
    char id[N_PPL][8] = { 0 }; // 7 bits student ID
    int score[N_PPL] = { 0 }; // integer score from 0 to 100
    if (input_info(name, id, score))
    {
        sort_grade(name, id, score, 0);
        output_info(name, id, score, 1, 2, 0);
    }
    return 0;
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
