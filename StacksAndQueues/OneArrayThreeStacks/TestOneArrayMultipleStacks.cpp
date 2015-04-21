#include "oneArrayMultipleStacks.h"
#include <iostream>


int main(int argc, char** argv)
{
	// This test only puts numbers in 3 of the 5 stacks
	// The stack has a size of 100
	// This means that the stack should fill up after
	// 60 pushes
	// This test tries the following:
	// 1. Pushing onto an empty stack
	// 2. Pushing onto a full stack
	// 3. Popping from a full stack
	// 4. Popping from an empty stack

	int numStacks = 5;
	int size = 100;
	StaticStack<int> multiStack(numStacks,size);
	for(int i=0; i<size+10; ++i)
	{
		// If push returns false, that stack is full 
		// and will print when it became full
		if(!multiStack.push(i%3,i))
		{
			std::cout << "Stack " << i%3 << " is full at: " << i << std::endl;
			break;
		}
	}

	for(int i=0; i<size+10; ++i)
	{
		// If pop returns false, that stack is empty 
		// and will print when it became empty 
		int val = 0;
		if(!multiStack.pop(i%3,val))
		{
			std::cout << "Stack " << i%3 << " is empty at: " << i << std::endl;
			break;
		}
	}
}