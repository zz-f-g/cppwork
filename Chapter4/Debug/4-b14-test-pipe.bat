@echo off
get_input_data 4-b14_data.txt [4-b14-01] | 4-b14.exe > 4-b14-myresult.txt
get_input_data 4-b14_data.txt [4-b14-02] | 4-b14.exe >> 4-b14-myresult.txt
get_input_data 4-b14_data.txt [4-b14-03] | 4-b14.exe >> 4-b14-myresult.txt
get_input_data 4-b14_data.txt [4-b14-04] | 4-b14.exe >> 4-b14-myresult.txt
get_input_data 4-b14_data.txt [4-b14-05] | 4-b14.exe >> 4-b14-myresult.txt
get_input_data 4-b14_data.txt [4-b14-06] | 4-b14.exe >> 4-b14-myresult.txt
get_input_data 4-b14_data.txt [4-b14-07] | 4-b14.exe >> 4-b14-myresult.txt
get_input_data 4-b14_data.txt [4-b14-08] | 4-b14.exe >> 4-b14-myresult.txt
get_input_data 4-b14_data.txt [4-b14-09] | 4-b14.exe >> 4-b14-myresult.txt
get_input_data 4-b14_data.txt [4-b14-10] | 4-b14.exe >> 4-b14-myresult.txt
get_input_data 4-b14_data.txt [4-b14-11] | 4-b14.exe >> 4-b14-myresult.txt
get_input_data 4-b14_data.txt [4-b14-12] | 4-b14.exe >> 4-b14-myresult.txt
get_input_data 4-b14_data.txt [4-b14-13] | 4-b14.exe >> 4-b14-myresult.txt
get_input_data 4-b14_data.txt [4-b14-14] | 4-b14.exe >> 4-b14-myresult.txt
get_input_data 4-b14_data.txt [4-b14-15] | 4-b14.exe >> 4-b14-myresult.txt

get_input_data 4-b14_data.txt [4-b14-01] | 4-b14-demo.exe > 4-b14-stdresult.txt
get_input_data 4-b14_data.txt [4-b14-02] | 4-b14-demo.exe >> 4-b14-stdresult.txt
get_input_data 4-b14_data.txt [4-b14-03] | 4-b14-demo.exe >> 4-b14-stdresult.txt
get_input_data 4-b14_data.txt [4-b14-04] | 4-b14-demo.exe >> 4-b14-stdresult.txt
get_input_data 4-b14_data.txt [4-b14-05] | 4-b14-demo.exe >> 4-b14-stdresult.txt
get_input_data 4-b14_data.txt [4-b14-06] | 4-b14-demo.exe >> 4-b14-stdresult.txt
get_input_data 4-b14_data.txt [4-b14-07] | 4-b14-demo.exe >> 4-b14-stdresult.txt
get_input_data 4-b14_data.txt [4-b14-08] | 4-b14-demo.exe >> 4-b14-stdresult.txt
get_input_data 4-b14_data.txt [4-b14-09] | 4-b14-demo.exe >> 4-b14-stdresult.txt
get_input_data 4-b14_data.txt [4-b14-10] | 4-b14-demo.exe >> 4-b14-stdresult.txt
get_input_data 4-b14_data.txt [4-b14-11] | 4-b14-demo.exe >> 4-b14-stdresult.txt
get_input_data 4-b14_data.txt [4-b14-12] | 4-b14-demo.exe >> 4-b14-stdresult.txt
get_input_data 4-b14_data.txt [4-b14-13] | 4-b14-demo.exe >> 4-b14-stdresult.txt
get_input_data 4-b14_data.txt [4-b14-14] | 4-b14-demo.exe >> 4-b14-stdresult.txt
get_input_data 4-b14_data.txt [4-b14-15] | 4-b14-demo.exe >> 4-b14-stdresult.txt

comp 4-b14-myresult.txt 4-b14-stdresult.txt
