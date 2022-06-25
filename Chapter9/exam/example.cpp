#include <iostream>
#include <fstream>
#include "cmd_console_tools.h"
using namespace std;

/* ����ؼ��� */
struct Keyword {
	int bkcolor;
	int fgcolor;
	char kword[15][20]; //ûѧ��ָ�����飬�ö�ά���������15/20Ϊ�������ֵ����ʱ�ɱ䣨�������������в�Ҫʹ��15/20�ȶ�ֵ����Ӧ����""��Ϊ��������жϣ�
} const kw = {
	COLOR_BLACK,		//����ɫ
	COLOR_HYELLOW,	//ǰ��ɫ
	{
		"if",
		"while",
		"do",
		"for",
		"switch",
		"case",
		"break",
		"continue",
		"struct",
		"class",
		"return",
		""		//��������Կմ���β
	}
};

/* ������������ */
struct Datatype {
	int bkcolor;
	int fgcolor;
	char dtype[12][10];//ûѧ��ָ�����飬�ö�ά���������12/10Ϊ�������ֵ����ʱ�ɱ䣨�������������в�Ҫʹ��12/10�ȶ�ֵ����Ӧ����""��Ϊ��������жϣ�
} const dt = {
	COLOR_BLACK,	//����ɫ
	COLOR_HPINK,	//ǰ��ɫ
	{ 
		"bool",
		"char",
		"unsigned",
		"int",
		"short",
		"long",
		"float",
		"double",
		"const",
		""		//��������Կմ���β
	}
};

#if 1 //���Ѷȣ����β�����
/* ��������� */
struct Operator {
	int bkcolor;
	int fgcolor;
	char oper[20][4];//ûѧ��ָ�����飬�ö�ά���������20/4Ϊ�������ֵ����ʱ�ɱ䣨�������������в�Ҫʹ��20/4�ȶ�ֵ����Ӧ����""��Ϊ��������жϣ�
} const op = {
	COLOR_BLACK,	//����ɫ
	COLOR_BLUE,	//ǰ��ɫ
	{
		"+",
		"-",
		"*",
		"/",
		".",
		">",
		"<",
		"=",
		"::",
		""		//��������Կմ���β
	}
};
#endif

const int notes_bkcolor = COLOR_BLACK;	//ע�͵ı���ɫ
const int notes_fgcolor = COLOR_GREEN;	//ע�͵�ǰ��ɫ

const int normal_bkcolor = COLOR_BLACK;		//�������ؼ��֡��������͡��������ע����������ı��ı���ɫ
const int normal_fgcolor = COLOR_HWHITE;	//�������ؼ��֡��������͡��������ע����������ı���ǰ��ɫ


void show(const char* filename, const int row, const int col, const char* fontname, const int high, const int width);

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
 ***************************************************************************/
int main()
{
	const char* fname = "example.cpp";

	show(fname, 30, 120, "������", 16, 0);
//	show(fname, 25, 80, "��������", 16, 8);

	return 0;
}

/* --- ��Ҫ�ڱ��е�������κζ�������������ݻᱻ�����滻�������ļ������ؼ���/��������/���������ɫ���������ݡ������ȣ� --- */

/* �˴���
	1��������Ӻ���������ֻ��ȫ�ֱ������궨���
	2��������ʹ��ȫ�ֱ���
	3��������Ӷ���Զ��庯��
*/
#include <cstring>
#define BUF_SIZE 1000
#define WORD_SIZE 100

int mystrlen(const char *str)
{
    const char *p_char = str;
    if (str)
    {
        while (*p_char)
        {
            ++p_char;
        }
    }
    return (p_char - str);
}

int mystrcmp(const char *s1, const char *s2)
{
    if (s1 && !s2)
        return 1;
    else if (!s1 && s2)
        return -1;
    else if (!s1 && !s2)
        return 0;
    else
    {
        while (*s1 || *s2)
        {
            if (*s1 != *s2)
                return (int)(*s1 - *s2);
            ++s1;
            ++s2;
        }
    }
    return 0;
}

int get_word(const char *row, int *word, int &comment)
{
    const char *cur = row;
    while (1)
    {
        while (!(*cur >= 'a' && *cur <= 'z'))
        {
            if (*cur == '\0')
            {
                *word = -1;
                comment = -1;
                return 0;
            }
            if (*cur == '/')
            {
                if (*(cur + 1) == '/')
                {
                    *word = -1;
                    comment = cur - row;
                    return 1;
                }
                else if (*(cur + 1) == '*')
                {
                    *word = -1;
                    comment = cur - row;
                    return 2;
                }
            }
            ++cur;
        }
        *word = cur - row;
        ++word;
        while (*cur >= 'a' && *cur <= 'z')
        {
            ++cur;
        }
        *word = cur - row;
        ++word;
    }
}

void print_word(const char *word)
{
    int i = 0;
    int x = 0, y = 0;
    while (*kw.kword[i])
    {
        if (0 == mystrcmp(kw.kword[i], word))
        {
            cct_getxy(x, y);
            cct_showstr(x, y, word, kw.bkcolor, kw.fgcolor);
            cct_setcolor(0, 7);
            return;
        }
        ++i;
    }
    i = 0;
    while (*dt.dtype[i])
    {
        if (0 == mystrcmp(dt.dtype[i], word))
        {
            cct_getxy(x, y);
            cct_showstr(x, y, word, dt.bkcolor, dt.fgcolor);
            cct_setcolor(0, 7);
            return;
        }
        ++i;
    }
    cout << word;
}

/**/
void print_word(char word)
{
    int i = 0;
    int x = 0, y = 0;
    while (*op.oper[i])
    {
        if (*op.oper[i] == word)
        {
            cct_getxy(x, y);
            cct_setcolor(op.bkcolor, op.fgcolor);
            putchar(word);
            cct_setcolor(0, 7);
            return;
        }
        ++i;
    }
    putchar(word);
}

int show_row(const char *row)
{
    int word_index[WORD_SIZE] = {0};
    int comment_index;
    int comment = get_word(row, word_index, comment_index);
    char word[WORD_SIZE] = {'\0'}, *p_cur = word;
    int cur_word = 0;
    const char *cur_char = row;
    while (*cur_char)
    {
        if (word_index[cur_word] == -1 && cur_char - row == comment_index)
        {
            cct_setcolor(0, COLOR_GREEN);
        }
        if (cur_char - row == word_index[cur_word])
        {
            while (cur_char - row != word_index[cur_word + 1])
            {
                *p_cur = *cur_char;
                ++p_cur;
                ++cur_char;
            }
            cur_word += 2;
            *p_cur = '\0';
            print_word(word);
            p_cur = word;
        }
        putchar(*cur_char); // ?
        if (comment == 2)
        {
            if (*(cur_char - 1) == '*' && *cur_char == '/')
            {
                comment = 1;
                cct_setcolor();
            }
        }
        ++cur_char;
    }
    if (comment == 1)
    {
        cct_setcolor();
    }
    if (comment == 2)
    {
        cout << endl;
        return 1;
    }
    cout << endl;
    return 0;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������const char* filename ��Ҫ�򿪵�Դ�����ļ���
            const int row        �����ڵĺ���
           const int col        �����ڵ�����
           const char *fontname ��������
           const int high       ������߶�
           const int width      ��������
  �� �� ֵ��
  ˵    ���������ڻ������ĸ߶���Ϊrow*10�������Ϊcol*2
 ***************************************************************************/
void show(const char *filename, const int row, const int col, const char *fontname, const int high, const int width)
{
    cct_setfontsize(fontname, high, width);
    cct_setconsoleborder(col, row, col * 2, row * 10);
    ifstream in(filename, ios::in);
    char row_buf[BUF_SIZE] = {'\0'};
    if (!in.is_open())
    {
        cout << "Դ�����ļ�[" << filename << "]�򲻿�." << endl;
        return;
    }
    while (!in.eof())
    {
        in.getline(row_buf, BUF_SIZE, '\n');
        if (show_row(row_buf))
        {
            int comment = 1;
            while (comment)
            {
                in.getline(row_buf, BUF_SIZE, '\n');
                if (in.eof())
                    break;
                int len = mystrlen(row_buf);
                for (int i = 0; i < len; ++i)
                {
                    cout << row_buf[i];
                    if (row_buf[i - 1] == '*' && row_buf[i] == '/')
                    {
                        cct_setcolor(0, 7);
                        comment = 0;
                        // row_buf += i + 1;
                        break;
                    }
                }
                cout << endl;
            }
        }
    }
    return;
}
