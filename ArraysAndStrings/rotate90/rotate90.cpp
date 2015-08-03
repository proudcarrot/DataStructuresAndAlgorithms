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
	int bly = 5;
	int brx = 5;

	for (; tlx < size/2; ++tlx, ++tryy, --brx, --bly) {
		int tly = 0;
		int trx = 5;
		int blx = 0;
		int bry = 5;
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
	vector<vector<int> > array;
	for (int i = 0; i < 6; ++i) {
		vector<int> line;
		for (int j = 0; j < 6; ++j) {
			int num = i*6 + j;
			line.push_back(num);
			cout << num << "\t";
		}
		array.push_back(line);
		cout << endl;
	}
	cout << endl;
	shift90(array);
	for (int i = 0; i < 6; ++i) {
		for (int j = 0; j < 6; ++j) {
			cout << array[i][j] << "\t";
		}
		cout << endl;
	}
}