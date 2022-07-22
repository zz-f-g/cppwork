#pragma once

#include <cmd_console_tools.h>
#include <cppsyntax.h>
#define FILE_SIZE (65536)
#define PATH_SIZE (256)

class File;

class Character
{
private:
    char ch;
    int b_clr;
    int f_clr;
public:
    void set_char(char ch);
    void set_color(int bg_color, int fg_color);
    void show();
};

class File
{
private:
    char filepath[PATH_SIZE] = {'\0'};
    Character content[FILE_SIZE];
public:
    int read(const char * path);
    void setcolor();
    void show();
};
