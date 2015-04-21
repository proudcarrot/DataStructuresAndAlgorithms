#include "oneArrayMultipleStacks.h"
#include <iostream>

// This set of stacks assumes a static array with stacks of
// approximately the same size
template <typename T>
StaticStack<T>::StaticStack(int numStacks, int totalSize)
	: numStacks_(numStacks), stackOffset_(std::vector<int>(numStacks)), combinedStack_(std::vector<T>(totalSize))
{
	for(int i=0; i<numStacks; ++i)
	{
		stackOffset_[i] = i - numStacks;
		std::cout << i << ":" << stackOffset_[i] << std::endl;
	}
}

// Pushes new value onto the given stack, returns true 
// If the stack is full, returns false
template <typename T>
bool StaticStack<T>::push(int stack, T val) 
{
	if(stack < 0 || stack > numStacks_ - 1)
	{
		return false;
	}

	int location = stackOffset_[stack] + numStacks_;
	if(combinedStack_.size() > location)
	{
		combinedStack_[location] = val;
		stackOffset_[stack] = location;
		return true;
	}
	else
	{
		return false;
	}
}

// Pops the top off the given stack if there
// is a value and returns it in val
// Otherwise it returns false
template <typename T>
bool StaticStack<T>::pop(int stack, T& val)
{
	if(stack < 0 || stack > numStacks_ - 1)
	{
		return false;
	}

	int location = stackOffset_[stack];
	if(location < 0)
	{
		return false;
	}

	val = combinedStack_[location];
	stackOffset_[stack] = location - numStacks_;
	return true;
}

// Peeks at the given stack
// If it is empty, returns false
// Otherwise val will contain the top value
template <typename T>
bool StaticStack<T>::peek(int stack, T& val)
{
	if(stack < 0 || stack > numStacks_ - 1)
	{
		return false;
	}
	
	int location = stackOffset_[stack];
	if(location < 0)
	{
		return false;
	}

	val = combinedStack_[location];
	return true;
}

template class StaticStack<int>;