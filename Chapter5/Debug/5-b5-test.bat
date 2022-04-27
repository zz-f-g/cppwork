@echo off
5-b5-demo < score.dat > 5-b5-stdresults.txt

5-b5 < score.dat > 5-b5-myresults.txt

comp 5-b5-stdresults.txt 5-b5-myresults.txt
