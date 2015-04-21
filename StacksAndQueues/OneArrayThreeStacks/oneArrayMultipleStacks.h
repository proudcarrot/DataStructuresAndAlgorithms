#include <vector>


template <class T>
class StaticStack {

public:
	StaticStack(int numStacks, int totalSize);	
	bool push(int stack, T val);
	bool pop(int stack, T& val);
	bool peek(int stack, T& val);

private:
	int numStacks_;
	std::vector<int> stackOffset_;
	std::vector<T> combinedStack_;
};