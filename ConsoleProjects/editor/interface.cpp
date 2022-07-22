#include <fstream>
#include <iostream>
#include "cmd_console_tools.h"
#include "interface.h"

void Character::show()
{
    cct_setcolor(this->b_clr, this->f_clr);
    std::cout << this->ch;
}

void mystrcpy(char * dst, const char * src)
{
    while (*src)
    {
        *dst = *src;
        ++dst;
        ++src;
    }
    *dst = '\0';
}

int File::read(const char * path)
{
    mystrcpy(this->filepath, path);
    ;
}
