#pragma once

#include "cmd_console_tools.h"

/* 定义关键字 */
struct Keyword
{
    int bkcolor;
    int fgcolor;
    char kword[15][20]; //没学过指针数组，用二维数组替代，15/20为任意合理值，随时可变（即：后续访问中不要使用15/20等定值，而应该以""做为结束标记判断）
} const kw = {
    COLOR_BLACK,   //背景色
    COLOR_HYELLOW, //前景色
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
        "" //任意个，以空串结尾
    }};

/* 定义数据类型 */
struct Datatype
{
    int bkcolor;
    int fgcolor;
    char dtype[12][10]; //没学过指针数组，用二维数组替代，12/10为任意合理值，随时可变（即：后续访问中不要使用12/10等定值，而应该以""做为结束标记判断）
} const dt = {
    COLOR_BLACK, //背景色
    COLOR_HPINK, //前景色
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
        "" //任意个，以空串结尾
    }};

/* 定义运算符 */
struct Operator
{
    int bkcolor;
    int fgcolor;
    char oper[20][4]; //没学过指针数组，用二维数组替代，20/4为任意合理值，随时可变（即：后续访问中不要使用20/4等定值，而应该以""做为结束标记判断）
} const op = {
    COLOR_BLACK, //背景色
    COLOR_BLUE,  //前景色
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
        "" //任意个，以空串结尾
    }};

const int notes_bkcolor = COLOR_BLACK; //注释的背景色
const int notes_fgcolor = COLOR_GREEN; //注释的前景色

const int normal_bkcolor = COLOR_BLACK;  //除上述关键字、数据类型、运算符、注释外的其它文本的背景色
const int normal_fgcolor = COLOR_HWHITE; //除上述关键字、数据类型、运算符、注释外的其它文本的前景色
