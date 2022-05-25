#pragma once

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
int id_cmp(const char id1[], const char id2[]);

/*copy string
- input:
    str1: destination string
    str2: source string
*/
void str_copy(char str1[], const char str2[]);

/*exchange str
- input:
    char str1[]: string1
    char str2[]: string2
*/
void str_exchange(char str1[], char str2[]);

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
int output_ones_info(const char name[], const char id[], int score, int group);

/*input info and assign the info to arrays
- input:
    char name[][]: name strings of students
    char id[][]: student ID strings of students
    int score[]: scores of students
- output:
    int res: 1 for successful input, 0 for failing input
*/
int input_info(char name[][9], char id[][8], int score[]);

/*sort the arrays according to scores in descending order
- input:
    char name[][]: name strings of students
    char id[][]: student ID strings of students
    int score[]: scores of students
    int key:
        0: key is id
        1: key is score
*/
void sort_grade(char name[][9], char id[][8], int score[], int key);

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
void output_info(const char name[][9], const char id[][8], const int score[], int reverse, int group, int key);
