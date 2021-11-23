Name of program: Sorting.cpp Sorting.h main.cpp
----------------------------------------
This program uses different algorithms such as selection sort, merge sort, and quick sort in order to sort data from
both .txt files and randomly generated integers. More about program can be found in the report.
----------------------------------------
The main functions of the code are within the Sorting.cpp. A header file was made, which outlines the different
functions and instance variables within the .cpp.
The program file main.cpp acts as a driver for the others, with some interface functionality. It handles the functions
from Sorting.cpp in a way that allows the user to sort different text files, sort random lists of integers, and see the
number of comparisons from each algorithm after finishing.
----------------------------------------
Coders: Nathan Joseph Jacobi, John Taylor Wetterhan
Emails: njj67229@uga.edu, jtw93843@uga.edu
Section: CRN 17504, csci-2720a
Date: November 21, 2021
Credit: A few sections of code were inspired by the man pages of functions on cplusplus.com. Many of the algorithms
were based on the notes from the lecture.
----------------------------------------
Sorting.cpp and Sorting.h were mainly written by Nathan Jacobi, while main.cpp and README.txt were mainly written
by Taylor Wetterhan. There were decent amounts of collaboration on these, while the Makefile and the report were a joint
effort. The testing and debugging was done together, which resulted in specific, marked sections of Sorting.cpp to be 
written by Taylor Wetterhan and main.cpp to be written by Nathan Jacobi. This project collaboration was both in-person and
online using git.

How to compile: Using the Makefile
    make clean (optional)
    make
How to run:
    main <input.txt>
    main

Commands:
(s) - Selection-sort
(m) - Merge-sort
(h) - Heap-sort
(q) - Quick-sort-fp
(r) - Quick-sort-rp
----------------------------------------
To run the program so that the user can pick the number of random values to sort, run using only the command "main", as
shown above. Because there is no file, main.cpp will change how it uses Sorting.cpp using a conditional statement that
checks for the number of command line arguments. 