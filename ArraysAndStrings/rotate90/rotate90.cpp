#include <vector>
#include <iostream>

using namespace std;

void shift90(vector<vector<int> > &array) {
	if (array.size() != array[0].size()) {
		return;
	}
	int size = array.size();
	cout << size << endl;
	int tlx = 0;
	int tryy = 0;
	int bly = size - 1;
	int brx = size - 1;

	for (; tlx < (size+1)/2; ++tlx, ++tryy, --brx, --bly) {
		int tly = 0;
		int trx = size - 1;
		int blx = 0;
		int bry = size - 1;
		for (; tly < size/2; ++tly, --trx, --bry, ++blx) {
			cout << "(" << tlx << "," << tly << "), (" << trx << "," << tryy << "), (" << brx << "," << bry << "), (" << blx << "," << bly << ")" << endl;
			int temp = array[blx][bly];
			array[blx][bly] = array[brx][bry];
			array[brx][bry] = array[trx][tryy];
			array[trx][tryy] = array[tlx][tly];
			array[tlx][tly] = temp;
		}
	}

}

int main() {
	int size = 6;
	vector<vector<int> > array;
	for (int i = 0; i < size; ++i) {
		vector<int> line;
		for (int j = 0; j < size; ++j) {
			int num = i*size + j;
			line.push_back(num);
			cout << num << "\t";
		}
		array.push_back(line);
		cout << endl;
	}
	cout << endl;
	shift90(array);
	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j) {
			cout << array[i][j] << "\t";
		}
		cout << endl;
	}

	cout << endl;
	size = 5;
	array.clear();
	for (int i = 0; i < size; ++i) {
		vector<int> line;
		for (int j = 0; j < size; ++j) {
			int num = i*size + j;
			line.push_back(num);
			cout << num << "\t";
		}
		array.push_back(line);
		cout << endl;
	}
	cout << endl;
	shift90(array);
	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j) {
			cout << array[i][j] << "\t";
		}
		cout << endl;
	}
}