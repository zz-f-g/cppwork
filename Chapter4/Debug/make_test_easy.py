#!/usr/bin/env python3
# -*- coding: utf-8 -*-

'''Make Cpp Test Easy
Launch test data in certain format corresponding with executable provided: get_input_data.
Launch batch file to generate output in result files for both demo and your code.
'''

__author__ = 'zz Guo'

import re

def launch_test(project_name: str, group_size: int = 1) -> tuple:
    str_float = r'^[-+]?[0-9]*\.?[0-9]+$'
    str_char = r'^[A-Za-z]$'
    cnt_group = 0
    data = ''
    while True:
        group = ''
        cnt_group += 1
        cnt_data = 0
        while (cnt_data < group_size):
            cnt_data += 1
            tmp = input(f"data {cnt_data} in group {cnt_group}(';' to quit): ")
            if re.match(str_char, tmp):
                group += tmp + ' '
            else:
                return (data, cnt_group - 1)
        data += f"[{project_name}-{cnt_group}]\n" + group + '\n\n'

def launch_bat(project_name: str, n_groups: int, project_version: int = None, flag_echo: int = 0) -> str:
    str_bat = '@echo off\n'
    if (flag_echo):
        str_bat = ''
    for group in range(n_groups):
        if (group == 0):
            str_bat += f'get_input_data {project_name}-test-data.txt [{project_name}-{group+1}] | {project_name}-demo.exe > {project_name}-stdresults.txt\n'
        else:
            str_bat += f'get_input_data {project_name}-test-data.txt [{project_name}-{group+1}] | {project_name}-demo.exe >> {project_name}-stdresults.txt\n'
    str_bat += '\n'
    project = project_name
    if (project_version != None):
        project = project_name + '-' + str(project_version)
    for group in range(n_groups):
        if (group == 0):
            str_bat += f'get_input_data {project_name}-test-data.txt [{project_name}-{group+1}] | {project}.exe > {project_name}-myresults.txt\n'
        else:
            str_bat += f'get_input_data {project_name}-test-data.txt [{project_name}-{group+1}] | {project}.exe >> {project_name}-myresults.txt\n'
    return str_bat

def main() -> None:
    project_name = '4-b11'
    group_size = int(input("Input the group size: "))

    str_test_data, n_groups = launch_test(project_name, group_size)
    str_bat = launch_bat(project_name, n_groups)

    with open(f'./Chapter4/Debug/{project_name}-test-data.txt', 'w') as f:
        f.write(str_test_data)
    with open(f'./Chapter4/Debug/{project_name}-test-pipe.bat', 'w') as f:
        f.write(str_bat)

if __name__=='__main__':
    main()