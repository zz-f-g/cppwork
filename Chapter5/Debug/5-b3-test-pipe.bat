@echo off
get_input_data 5-b3-test-data.txt [5-b3-01] | 5-b3.exe > 5-b3-myresults.txt
get_input_data 5-b3-test-data.txt [5-b3-02] | 5-b3.exe >> 5-b3-myresults.txt
get_input_data 5-b3-test-data.txt [5-b3-03] | 5-b3.exe >> 5-b3-myresults.txt
get_input_data 5-b3-test-data.txt [5-b3-04] | 5-b3.exe >> 5-b3-myresults.txt
get_input_data 5-b3-test-data.txt [5-b3-05] | 5-b3.exe >> 5-b3-myresults.txt
get_input_data 5-b3-test-data.txt [5-b3-06] | 5-b3.exe >> 5-b3-myresults.txt
get_input_data 5-b3-test-data.txt [5-b3-07] | 5-b3.exe >> 5-b3-myresults.txt
get_input_data 5-b3-test-data.txt [5-b3-08] | 5-b3.exe >> 5-b3-myresults.txt
get_input_data 5-b3-test-data.txt [5-b3-09] | 5-b3.exe >> 5-b3-myresults.txt
get_input_data 5-b3-test-data.txt [5-b3-10] | 5-b3.exe >> 5-b3-myresults.txt
get_input_data 5-b3-test-data.txt [5-b3-11] | 5-b3.exe >> 5-b3-myresults.txt
get_input_data 5-b3-test-data.txt [5-b3-12] | 5-b3.exe >> 5-b3-myresults.txt
get_input_data 5-b3-test-data.txt [5-b3-13] | 5-b3.exe >> 5-b3-myresults.txt
get_input_data 5-b3-test-data.txt [5-b3-14] | 5-b3.exe >> 5-b3-myresults.txt
get_input_data 5-b3-test-data.txt [5-b3-15] | 5-b3.exe >> 5-b3-myresults.txt
get_input_data 5-b3-test-data.txt [5-b3-16] | 5-b3.exe >> 5-b3-myresults.txt
get_input_data 5-b3-test-data.txt [5-b3-17] | 5-b3.exe >> 5-b3-myresults.txt
get_input_data 5-b3-test-data.txt [5-b3-18] | 5-b3.exe >> 5-b3-myresults.txt
get_input_data 5-b3-test-data.txt [5-b3-19] | 5-b3.exe >> 5-b3-myresults.txt
get_input_data 5-b3-test-data.txt [5-b3-20] | 5-b3.exe >> 5-b3-myresults.txt

get_input_data 5-b3-test-data.txt [5-b3-01] | 5-b3-demo.exe > 5-b3-stdresults.txt
get_input_data 5-b3-test-data.txt [5-b3-02] | 5-b3-demo.exe >> 5-b3-stdresults.txt
get_input_data 5-b3-test-data.txt [5-b3-03] | 5-b3-demo.exe >> 5-b3-stdresults.txt
get_input_data 5-b3-test-data.txt [5-b3-04] | 5-b3-demo.exe >> 5-b3-stdresults.txt
get_input_data 5-b3-test-data.txt [5-b3-05] | 5-b3-demo.exe >> 5-b3-stdresults.txt
get_input_data 5-b3-test-data.txt [5-b3-06] | 5-b3-demo.exe >> 5-b3-stdresults.txt
get_input_data 5-b3-test-data.txt [5-b3-07] | 5-b3-demo.exe >> 5-b3-stdresults.txt
get_input_data 5-b3-test-data.txt [5-b3-08] | 5-b3-demo.exe >> 5-b3-stdresults.txt
get_input_data 5-b3-test-data.txt [5-b3-09] | 5-b3-demo.exe >> 5-b3-stdresults.txt
get_input_data 5-b3-test-data.txt [5-b3-10] | 5-b3-demo.exe >> 5-b3-stdresults.txt
get_input_data 5-b3-test-data.txt [5-b3-11] | 5-b3-demo.exe >> 5-b3-stdresults.txt
get_input_data 5-b3-test-data.txt [5-b3-12] | 5-b3-demo.exe >> 5-b3-stdresults.txt
get_input_data 5-b3-test-data.txt [5-b3-13] | 5-b3-demo.exe >> 5-b3-stdresults.txt
get_input_data 5-b3-test-data.txt [5-b3-14] | 5-b3-demo.exe >> 5-b3-stdresults.txt
get_input_data 5-b3-test-data.txt [5-b3-15] | 5-b3-demo.exe >> 5-b3-stdresults.txt
get_input_data 5-b3-test-data.txt [5-b3-16] | 5-b3-demo.exe >> 5-b3-stdresults.txt
get_input_data 5-b3-test-data.txt [5-b3-17] | 5-b3-demo.exe >> 5-b3-stdresults.txt
get_input_data 5-b3-test-data.txt [5-b3-18] | 5-b3-demo.exe >> 5-b3-stdresults.txt
get_input_data 5-b3-test-data.txt [5-b3-19] | 5-b3-demo.exe >> 5-b3-stdresults.txt
get_input_data 5-b3-test-data.txt [5-b3-20] | 5-b3-demo.exe >> 5-b3-stdresults.txt

comp 5-b3-myresults.txt 5-b3-stdresults.txt
