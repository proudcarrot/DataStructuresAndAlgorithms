#include <iostream>
#include <fstream>
#include <deque>
#include <vector>
#include <string>

using namespace std;

deque<string> getLastKLinesOfInputFileDeque(string fileName, int k) {
	deque<string> lines;

	if(k <= 0) {
		return lines;
	}
	
	int front = 0;

	std::ifstream in(fileName);

	if(in.is_open()) {
		string line;
		while(getline(in,line)) {
			if(lines.size() >= k) {
				lines.pop_front();
			}
			lines.push_back(line);
		}
	}

	return lines;
}

vector<string> getLastKLinesOfInputFileCircularArray(string fileName, int k) {
	int front = 0;
	int end = 0;
	vector<string> lines(k,"");

	std::ifstream in(fileName);

	if(in.is_open()) {
		string line;
		while(getline(in,line)) {
			if(end < k) {
				lines[end] = line;
				++end;
			}
			else {
				lines[front] = line;
				front = (front < k-1 ? front+1 : 0);
			}
		}
	}

	vector<string> orderedLines(end,"");
	int orderedLoc = 0;
	for(int i=front; i<end; ++i, ++orderedLoc) {
		orderedLines[orderedLoc] = lines[i];
	}
	for(int i=0; i<front; ++i, ++orderedLoc) {
		orderedLines[orderedLoc] = lines[i];
	}

	return orderedLines;
}

int main() {
	string inputFile("input.txt");

	int k = 15;
	cout << "Last " << k << " lines of file with 10 lines" << endl;

	cout << "Using deque" << endl;
	deque<string> kLinesDeque = getLastKLinesOfInputFileDeque(inputFile, k);
	for(int i=0; i<kLinesDeque.size(); ++i) {
		cout << kLinesDeque[i] << endl;
	}

	cout << "Using circular array" << endl;
	vector<string> kLinesArray = getLastKLinesOfInputFileCircularArray(inputFile, k);
	for(int i=0; i<kLinesArray.size(); ++i) {
		cout << kLinesArray[i] << endl;
	}

	k = 4;
	cout << "Last " << k << " lines of file with 10 lines" << endl;

	cout << "Using deque" << endl;
	kLinesDeque = getLastKLinesOfInputFileDeque(inputFile, k);
	for(int i=0; i<kLinesDeque.size(); ++i) {
		cout << kLinesDeque[i] << endl;
	}

	cout << "Using circular array" << endl;
	kLinesArray = getLastKLinesOfInputFileCircularArray(inputFile, k);
	for(int i=0; i<kLinesArray.size(); ++i) {
		cout << kLinesArray[i] << endl;
	}

	k = 10;
	cout << "Last " << k << " lines of file with 10 lines" << endl;

	cout << "Using deque" << endl;
	kLinesDeque = getLastKLinesOfInputFileDeque(inputFile, k);
	for(int i=0; i<kLinesDeque.size(); ++i) {
		cout << kLinesDeque[i] << endl;
	}

	cout << "Using circular array" << endl;
	kLinesArray = getLastKLinesOfInputFileCircularArray(inputFile, k);
	for(int i=0; i<kLinesArray.size(); ++i) {
		cout << kLinesArray[i] << endl;
	}
}