#include <iostream>
#include <fstream>
#include "cmd_console_tools.h"
using namespace std;

/* 定义关键字 */
struct Keyword {
	int bkcolor;
	int fgcolor;
	char kword[15][20]; //没学过指针数组，用二维数组替代，15/20为任意合理值，随时可变（即：后续访问中不要使用15/20等定值，而应该以""做为结束标记判断）
} const kw = {
	COLOR_BLACK,		//背景色
	COLOR_HYELLOW,	//前景色
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
		""		//任意个，以空串结尾
	}
};

/* 定义数据类型 */
struct Datatype {
	int bkcolor;
	int fgcolor;
	char dtype[12][10];//没学过指针数组，用二维数组替代，12/10为任意合理值，随时可变（即：后续访问中不要使用12/10等定值，而应该以""做为结束标记判断）
} const dt = {
	COLOR_BLACK,	//背景色
	COLOR_HPINK,	//前景色
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
		""		//任意个，以空串结尾
	}
};

#if 1 //简化难度，本次不考虑
/* 定义运算符 */
struct Operator {
	int bkcolor;
	int fgcolor;
	char oper[20][4];//没学过指针数组，用二维数组替代，20/4为任意合理值，随时可变（即：后续访问中不要使用20/4等定值，而应该以""做为结束标记判断）
} const op = {
	COLOR_BLACK,	//背景色
	COLOR_BLUE,	//前景色
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
		""		//任意个，以空串结尾
	}
};
#endif

const int notes_bkcolor = COLOR_BLACK;	//注释的背景色
const int notes_fgcolor = COLOR_GREEN;	//注释的前景色

const int normal_bkcolor = COLOR_BLACK;		//除上述关键字、数据类型、运算符、注释外的其它文本的背景色
const int normal_fgcolor = COLOR_HWHITE;	//除上述关键字、数据类型、运算符、注释外的其它文本的前景色


void show(const char* filename, const int row, const int col, const char* fontname, const int high, const int width);

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
 ***************************************************************************/
int main()
{
	const char* fname = "example.cpp";

	show(fname, 30, 120, "新宋体", 16, 0);
//	show(fname, 25, 80, "点阵字体", 16, 8);

	return 0;
}

/* --- 不要在本行的上面加任何东西，上面的内容会被任意替换（包括文件名、关键字/数据类型/运算符的颜色、具体内容、个数等） --- */

/* 此处：
	1、允许添加函数声明、只读全局变量、宏定义等
	2、不允许使用全局变量
	3、允许添加多个自定义函数
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
  函数名称：
  功    能：
  输入参数：const char* filename ：要打开的源程序文件名
            const int row        ：窗口的函数
           const int col        ：窗口的列数
           const char *fontname ：字体名
           const int high       ：字体高度
           const int width      ：字体宽度
  返 回 值：
  说    明：将窗口缓冲区的高度设为row*10，宽度设为col*2
 ***************************************************************************/
void show(const char *filename, const int row, const int col, const char *fontname, const int high, const int width)
{
    cct_setfontsize(fontname, high, width);
    cct_setconsoleborder(col, row, col * 2, row * 10);
    ifstream in(filename, ios::in);
    char row_buf[BUF_SIZE] = {'\0'};
    if (!in.is_open())
    {
        cout << "源程序文件[" << filename << "]打不开." << endl;
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
