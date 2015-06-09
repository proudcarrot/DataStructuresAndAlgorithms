#include "pushPopMin.h"
#include <iostream>

using namespace std;

int main() {
	Stack s;

	int r = 0;
	int min = 0;
	bool done = false;

	done = s.pop(r);
	if(!done) {
		cout << "Stack empty" << endl;
	}
	else {
		cout << "Popped: " << r << endl;
	}
	done = s.min(min);
	if(!done) {
		cout << "Stack empty" << endl;
	}
	else {
		cout << "Min: " << min << endl;
	}

	s.push(50);
	s.push(6);
	s.push(4);
	s.push(3);
	s.push(6);
	s.push(5);
	s.push(10);
	s.push(3);
	s.push(2);
	s.push(2);
	s.printStackAndMins();

	s.min(min);
	cout << "Min: " << min << endl;
	s.pop(r);
	cout << "Popped: " << r << endl;
	s.min(min);
	cout << "Min: " << min << endl;
	r = 0;
	s.pop(r);
	cout << "Popped: " << r << endl;
	s.min(min);
	cout << "Min: " << min << endl;

	s.printStackAndMins();
}
