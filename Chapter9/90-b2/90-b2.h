/* 2052110 郭子瞻 自动化 */
#pragma once
#include <Windows.h>
#include <iostream>
#include <iomanip>
#include <conio.h>
#include "cmd_console_tools.h"
#define MAXSIZE 10 // array max size
void enter(int selection);
void data_gen(int data[][10], int n_row, int n_col, int max_val);
void data_show(const int data[][MAXSIZE], int n_row, int n_col);
void adj_gen(int adj[][MAXSIZE], int x, int y, const int data[][MAXSIZE], int n_row, int n_col);
void adj_show(int adj[][MAXSIZE], int n_row, int n_col);
int adj_judge(int adj[][MAXSIZE], int n_row, int n_col);
void data_show_highlight(const int data[][MAXSIZE], const int adj[][MAXSIZE], int n_row, int n_col);
void adj_gen_recur(int adj[][MAXSIZE], int x, int y, const int data[][MAXSIZE], int n_row, int n_col);
int combine(int adj[][MAXSIZE], int x, int y, int data[][MAXSIZE], int n_row, int n_col);
void data_fall(int data[][MAXSIZE], int n_row, int n_col);
int get_max(int data[][MAXSIZE], int n_row, int n_col);
void adj_change(int data[][MAXSIZE], int adj[][MAXSIZE], int n_row, int n_col);
int data_judge(int data[][MAXSIZE], int n_row, int n_col);
void bg_show(int n_col, int n_row, int frame);
void data_block_show(int data[][MAXSIZE], int n_col, int n_row, int frame);
void block_show(int data, int x, int y, int fg_color);
void block_choose(int data[][MAXSIZE], int n_row, int n_col, int &cur_x, int &cur_y, int selection, int adj[][MAXSIZE]);
void adj_block_show(int data[][MAXSIZE], int n_row, int n_col, int adj[][MAXSIZE], int cur_x, int cur_y);
void step(int adj[][MAXSIZE], int x, int y, int data[][MAXSIZE], int n_row, int n_col);
void wait();
