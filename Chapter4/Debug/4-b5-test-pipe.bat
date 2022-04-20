@echo off
get_input_data 4-b5-test-data.txt [4-b5-1] | 4-b5-demo.exe > 4-b5-stdresults.txt
get_input_data 4-b5-test-data.txt [4-b5-2] | 4-b5-demo.exe >> 4-b5-stdresults.txt
get_input_data 4-b5-test-data.txt [4-b5-3] | 4-b5-demo.exe >> 4-b5-stdresults.txt
get_input_data 4-b5-test-data.txt [4-b5-4] | 4-b5-demo.exe >> 4-b5-stdresults.txt
get_input_data 4-b5-test-data.txt [4-b5-5] | 4-b5-demo.exe >> 4-b5-stdresults.txt
get_input_data 4-b5-test-data.txt [4-b5-6] | 4-b5-demo.exe >> 4-b5-stdresults.txt
get_input_data 4-b5-test-data.txt [4-b5-7] | 4-b5-demo.exe >> 4-b5-stdresults.txt

get_input_data 4-b5-test-data.txt [4-b5-1] | 4-b5.exe > 4-b5-myresults.txt
get_input_data 4-b5-test-data.txt [4-b5-2] | 4-b5.exe >> 4-b5-myresults.txt
get_input_data 4-b5-test-data.txt [4-b5-3] | 4-b5.exe >> 4-b5-myresults.txt
get_input_data 4-b5-test-data.txt [4-b5-4] | 4-b5.exe >> 4-b5-myresults.txt
get_input_data 4-b5-test-data.txt [4-b5-5] | 4-b5.exe >> 4-b5-myresults.txt
get_input_data 4-b5-test-data.txt [4-b5-6] | 4-b5.exe >> 4-b5-myresults.txt
get_input_data 4-b5-test-data.txt [4-b5-7] | 4-b5.exe >> 4-b5-myresults.txt
