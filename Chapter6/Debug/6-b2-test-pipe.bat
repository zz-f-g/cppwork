@echo off
get_input_data 6-b2-test-data.txt [6-b2-01] | 6-b2.exe > 6-b2-myresults.txt
get_input_data 6-b2-test-data.txt [6-b2-02] | 6-b2.exe >> 6-b2-myresults.txt

%get_input_data 6-b2-test-data.txt [6-b2-01] | 6-b2-demo.exe > 6-b2-stdresults.txt%
%get_input_data 6-b2-test-data.txt [6-b2-02] | 6-b2-demo.exe >> 6-b2-stdresults.txt%

%comp 6-b1-myresults.txt 6-b1-stdresults.txt%
