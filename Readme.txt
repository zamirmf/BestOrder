README FILE FOR BEST ORDER ALGORITHM
------------------------------------
I- The general structure can be defined as:
 Bin folder: Contains the script files and is the destination place for the main binary file (i.e., BestOrder.exe).
 Source folder: Consists of the header and source files.
 TestResults folder: The destination folder of the result/output of each test/input file.
 TestSuite folder: Contains the file related to the customer order and the testing files.
 ------------------------------------
II- Bin Folder: Contains Build.bat and RunTests.bat.
 Build.bat: Builds the binary executable file from the source files. In this example, g++ was used as part of MinGW. 
 Make sure that the compiler bin folder is added into the PATH variable.
 RunTests.bat: Calls the executable file with its command-line parameters in a loop, so different tests can be called 
 sequentially (see inline comments for more details). In case of MinGW, this file also requires that the compiler bin 
 folder to be added into the PATH variable.
 ------------------------------------
 III- TestSuite folder: Contains customer.csv and testX.csv
 Customer.csv: Contains the customer order information. Five numbers separated by commas with the following meaning: 
   (1)Number of food without any restrictions, 
   (2)Number of vegetarian food,
   (3)Number of gluten-free food,
   (4)Number of nut-free food,
   (5)Number of fish-free food.
 TestX.csv: Where X can be any positive number. In the current version files from 1 to 8 are provided. They consist of 
 a set of restaurant and their respective information. Each of this files are evaluated independently. Each file should 
 have one "row" per restaurant where each row has the following format:
    (1)Name of the restaurant,
    (2)Rating of the restaurant,
    (3)Number of food without any restrictions, 
    (4)Number of vegetarian food,
    (5)Number of gluten-free food,
    (6)Number of nut-free food,
    (7)Number of fish-free food.
*The name of these files can be changed by editing RunTests.bat.
-------------------------------------
IV- Testing the algorithm: The first step is to build the source files into a binary file using Build.bat. BestOrder.exe 
will be generated and then RunTests.bat can be run in order to generate the output files into TestResults folder.
