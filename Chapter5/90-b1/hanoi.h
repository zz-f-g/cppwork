/* 2052110 自动化 郭子瞻 */
#pragma once

/* ------------------------------------------------------------------------------------------------------

     本文件功能：
	1、为了保证 hanoi_main.cpp/hanoi_menu.cpp/hanoi_multiple_solutions.cpp 能相互访问函数的函数声明
	2、一个以上的cpp中用到的宏定义（#define）或全局只读（const）变量，个数不限
	3、可以参考 cmd_console_tools.h 的写法（认真阅读并体会）
   ------------------------------------------------------------------------------------------------------ */

#define MAXSIZE 10

int menu();
void initial(int selection);
void hanoi_recur(int n, char src, char tmp, char dst, int selection, int delay_mode);
void exit_selection(int selection);
