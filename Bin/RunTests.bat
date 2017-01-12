@echo off
REM set PATH=C:\MinGW\bin;%PATH%
REM 'outputFilename' defines the core name of the output file. e.g., 'result' means that
REM output files are going to have the following format, resultX.txt where X depends on
REM 'testScope'(see comments bellow). 
set outputFilename=result
REM 'inputFilename' defines the core name of the input file. e.g., 'test' means that
REM input files are going to have the following format, testX.csv where X depends on
REM 'testScope'(see comments bellow).
set inputFilename=test
REM 'testScope' defines which files are going to be included into the test run.
REM e.g., '1 10 5' means that %inputFilename%1.csv, %inputFilename%10.csv and %inputFilename%5.csv
REM are going to be called respectively. Generating %outputFilename%1.txt, %outputFilename%10.txt 
REM and %outputFilename%5.txt
set testScope=1 2 3 4 5 6 7 8
FOR %%f IN (%testScope%) DO call BestOrder.exe ..\TestSuite\customer.csv ..\TestSuite\%inputFilename%%%f.csv ..\TestResults\%outputFilename%%%f.txt
pause