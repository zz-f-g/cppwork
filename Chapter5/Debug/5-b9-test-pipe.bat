@echo off
get_input_data 5-b9-test-data.txt [5-b9-1] | 5-b9-demo.exe > 5-b9-stdresults.txt
get_input_data 5-b9-test-data.txt [5-b9-2] | 5-b9-demo.exe >> 5-b9-stdresults.txt
get_input_data 5-b9-test-data.txt [5-b9-3] | 5-b9-demo.exe >> 5-b9-stdresults.txt
get_input_data 5-b9-test-data.txt [5-b9-4] | 5-b9-demo.exe >> 5-b9-stdresults.txt
get_input_data 5-b9-test-data.txt [5-b9-5] | 5-b9-demo.exe >> 5-b9-stdresults.txt
get_input_data 5-b9-test-data.txt [5-b9-6] | 5-b9-demo.exe >> 5-b9-stdresults.txt
get_input_data 5-b9-test-data.txt [5-b9-7] | 5-b9-demo.exe >> 5-b9-stdresults.txt
get_input_data 5-b9-test-data.txt [5-b9-8] | 5-b9-demo.exe >> 5-b9-stdresults.txt
get_input_data 5-b9-test-data.txt [5-b9-9] | 5-b9-demo.exe >> 5-b9-stdresults.txt

get_input_data 5-b9-test-data.txt [5-b9-1] | 5-b9.exe > 5-b9-myresults.txt
get_input_data 5-b9-test-data.txt [5-b9-2] | 5-b9.exe >> 5-b9-myresults.txt
get_input_data 5-b9-test-data.txt [5-b9-3] | 5-b9.exe >> 5-b9-myresults.txt
get_input_data 5-b9-test-data.txt [5-b9-4] | 5-b9.exe >> 5-b9-myresults.txt
get_input_data 5-b9-test-data.txt [5-b9-5] | 5-b9.exe >> 5-b9-myresults.txt
get_input_data 5-b9-test-data.txt [5-b9-6] | 5-b9.exe >> 5-b9-myresults.txt
get_input_data 5-b9-test-data.txt [5-b9-7] | 5-b9.exe >> 5-b9-myresults.txt
get_input_data 5-b9-test-data.txt [5-b9-8] | 5-b9.exe >> 5-b9-myresults.txt
get_input_data 5-b9-test-data.txt [5-b9-9] | 5-b9.exe >> 5-b9-myresults.txt

comp 5-b9-myresults.txt 5-b9-stdresults.txt
