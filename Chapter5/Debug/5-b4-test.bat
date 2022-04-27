@echo off
5-b4-demo < score.dat > 5-b4-stdresults.txt

5-b4 < score.dat > 5-b4-myresults.txt

comp 5-b4-stdresults.txt 5-b4-myresults.txt
