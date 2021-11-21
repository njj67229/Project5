CFLAGS = -g -Wall -Wreturn-type
CC = g++

all: main

main: main.o Sorting.o
	$(CC) $(CFLAGS) main.o Sorting.o -o main

main.o : main.cpp
	$(CC) -c main.cpp

Sorting.o : Sorting.cpp Sorting.h
	$(CC) -c Sorting.cpp

clean:
	-rm -f core *.o
	-rm -f *.class
	-rm -f main
