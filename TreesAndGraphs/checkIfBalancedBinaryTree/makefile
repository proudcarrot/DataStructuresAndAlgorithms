# Makefile for CheckIfBalancedBinaryTree

CC = clang++
CFLAGS = -std=c++11 -stdlib=libc++ -Weverything
binaries = test

all: test

test: 	TestCheckIfBalancedBinaryTree.o checkIfBalancedBinaryTree.o
		$(CC) $(CFLAGS) -o $(binaries) TestCheckIfBalancedBinaryTree.o checkIfBalancedBinaryTree.o

TestCheckIfBalancedBinaryTree.o: TestCheckIfBalancedBinaryTree.cpp checkIfBalancedBinaryTree.h
		$(CC) $(CFLAGS) -c TestCheckIfBalancedBinaryTree.cpp

checkIfBalancedBinaryTree.o: checkIfBalancedBinaryTree.cpp checkIfBalancedBinaryTree.h
		$(CC) $(CFLAGS) -c checkIfBalancedBinaryTree.cpp

clean:
		$(RM) $(binaries) *.o *~