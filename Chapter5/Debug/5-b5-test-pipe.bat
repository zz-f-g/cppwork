@echo off
get_input_data 5-b4-test-data.txt [5-b4-01] | 5-b5.exe > 5-b5-myresults.txt
get_input_data 5-b4-test-data.txt [5-b4-02] | 5-b5.exe >> 5-b5-myresults.txt
get_input_data 5-b4-test-data.txt [5-b4-03] | 5-b5.exe >> 5-b5-myresults.txt
get_input_data 5-b4-test-data.txt [5-b4-04] | 5-b5.exe >> 5-b5-myresults.txt
get_input_data 5-b4-test-data.txt [5-b4-05] | 5-b5.exe >> 5-b5-myresults.txt
get_input_data 5-b4-test-data.txt [5-b4-06] | 5-b5.exe >> 5-b5-myresults.txt
get_input_data 5-b4-test-data.txt [5-b4-07] | 5-b5.exe >> 5-b5-myresults.txt
get_input_data 5-b4-test-data.txt [5-b4-08] | 5-b5.exe >> 5-b5-myresults.txt
get_input_data 5-b4-test-data.txt [5-b4-09] | 5-b5.exe >> 5-b5-myresults.txt
get_input_data 5-b4-test-data.txt [5-b4-10] | 5-b5.exe >> 5-b5-myresults.txt
get_input_data 5-b4-test-data.txt [5-b4-11] | 5-b5.exe >> 5-b5-myresults.txt
get_input_data 5-b4-test-data.txt [5-b4-12] | 5-b5.exe >> 5-b5-myresults.txt

get_input_data 5-b4-test-data.txt [5-b4-01] | 5-b5-demo.exe > 5-b5-stdresults.txt
get_input_data 5-b4-test-data.txt [5-b4-02] | 5-b5-demo.exe >> 5-b5-stdresults.txt
get_input_data 5-b4-test-data.txt [5-b4-03] | 5-b5-demo.exe >> 5-b5-stdresults.txt
get_input_data 5-b4-test-data.txt [5-b4-04] | 5-b5-demo.exe >> 5-b5-stdresults.txt
get_input_data 5-b4-test-data.txt [5-b4-05] | 5-b5-demo.exe >> 5-b5-stdresults.txt
get_input_data 5-b4-test-data.txt [5-b4-06] | 5-b5-demo.exe >> 5-b5-stdresults.txt
get_input_data 5-b4-test-data.txt [5-b4-07] | 5-b5-demo.exe >> 5-b5-stdresults.txt
get_input_data 5-b4-test-data.txt [5-b4-08] | 5-b5-demo.exe >> 5-b5-stdresults.txt
get_input_data 5-b4-test-data.txt [5-b4-09] | 5-b5-demo.exe >> 5-b5-stdresults.txt
get_input_data 5-b4-test-data.txt [5-b4-10] | 5-b5-demo.exe >> 5-b5-stdresults.txt
get_input_data 5-b4-test-data.txt [5-b4-11] | 5-b5-demo.exe >> 5-b5-stdresults.txt
get_input_data 5-b4-test-data.txt [5-b4-12] | 5-b5-demo.exe >> 5-b5-stdresults.txt

comp 5-b5-myresults.txt 5-b5-stdresults.txt
