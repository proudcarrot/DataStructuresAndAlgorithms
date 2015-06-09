#include <vector>

class Stack {

public:
	Stack();
	void push(int value);
	bool pop(int& value);
	bool min(int& minimum);
	void printStackAndMins();

private:
	std::vector<int> stack_;
	std::vector<int> min_;
};
