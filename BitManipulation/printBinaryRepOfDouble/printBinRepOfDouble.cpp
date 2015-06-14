#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

// Print the binary representation of a double between
// 0 and 1 if it can be represented in 32bits or less
// Print ERROR if it cannot be accurately represented 

void printBinRepOfDouble(double d) {

	vector<int> binary;
	cout << "Original Number: " << d << endl;

	for(int i=0; i<33; ++i) {
		double diff = d - int(d);

		if(diff == 0.0) {
			break;
		}
		d = diff*2;

		binary.push_back(int(d));
	}

	if(binary.size() == 33) {
		cout << "ERROR" << endl;
	}
	else {
		cout << "Binary Number: 0."; 
		for(int i=0; i<binary.size(); ++i) {
			cout << binary[i];
		}
		cout << endl;
	}
}

int main() {
	double d = .75;
	printBinRepOfDouble(d);
	d = .99;
	printBinRepOfDouble(d);
	d = .67;
	printBinRepOfDouble(d);
	d = .0625;
	printBinRepOfDouble(d);
	d = d/64;
	printBinRepOfDouble(d);
	d = d/128;
	printBinRepOfDouble(d);	
	d = pow(2,-32);
	printBinRepOfDouble(d);
	d = pow(2,-33);
	printBinRepOfDouble(d);
	d = .5432;
	printBinRepOfDouble(d);
}