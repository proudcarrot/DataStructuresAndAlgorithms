
CC = g++
CFLAGS = -g -Wall
binaries = test

all: test

test: 	TestOneArrayMultipleStacks.o oneArrayMultipleStacks.o
		$(CC) $(CFLAGS) -o $(binaries) TestOneArrayMultipleStacks.o oneArrayMultipleStacks.o

TestOneArrayMultipleStacks.o: TestOneArrayMultipleStacks.cpp oneArrayMultipleStacks.h
		$(CC) $(CFLAGS) -c TestOneArrayMultipleStacks.cpp

oneArrayMultipleStacks.o: oneArrayMultipleStacks.cpp oneArrayMultipleStacks.h
		$(CC) $(CFLAGS) -c oneArrayMultipleStacks.cpp

clean:
		$(RM) $(binaries) *.o *~
