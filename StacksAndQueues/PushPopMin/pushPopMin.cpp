#include "pushPopMin.h"
#include <iostream>

using namespace std;

Stack::Stack() {

}

void Stack::push(int value) {
	stack_.push_back(value);

	if(min_.empty()) {
		min_.push_back(value);
		return;
	}

	int minimum = min_.back();

	if(value <= minimum) {
		min_.push_back(value);
	}
}

bool Stack::pop(int& value) {
	if(stack_.empty()) return false;

	value = stack_.back();
	stack_.pop_back();
	int minimum = min_.back();

	if(value == minimum) {
		min_.pop_back();
	}

	return true;
}

bool Stack::min(int& minimum) {
	if(min_.empty()) return false;

	minimum = min_.back();

	return true;
}

void Stack::printStackAndMins()
{
	if(stack_.empty()) return;

	cout << "Stack: " << stack_[0];
	for(int i=1; i<stack_.size(); ++i) {
		cout << " -> " << stack_[i];
	}
	cout << endl;

	cout << "Min: " << min_[0];
	for(int i=1; i<min_.size(); ++i) {
		cout << " -> " << min_[i];
	}
	cout << endl;


}
