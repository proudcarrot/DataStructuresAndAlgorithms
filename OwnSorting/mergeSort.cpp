#include <iostream> 
#include <vector>

using namespace std;

void merge(vector<int>& array, vector<int>& helper, int begin, int middle, int end)
{
	// Copying 
	for(int i = begin; i <= end; ++i)
	{
		helper[i] = array[i];
	}

	// Now using helper to get correct places
	int lIndex = begin;
	int rIndex = middle + 1;
	int arrayIndex = begin;
	while(lIndex <= middle && rIndex <= end)
	{
		if(helper[lIndex] < helper[rIndex])
		{
			array[arrayIndex] = helper[lIndex];
			++lIndex;
		}
		else
		{
			array[arrayIndex] = helper[rIndex];
			++rIndex;
		}
		++arrayIndex;
	}

	while(lIndex <= middle)
	{
		array[arrayIndex] = helper[lIndex];
		++arrayIndex;
		++lIndex;
	}
}

void mergeSort(vector<int>& array, vector<int>& helper, int begin, int end)
{
	if(begin < end)
	{
		int middle = (begin + end)/2;
		// Left half
		mergeSort(array, helper, begin, middle);
		// Right half
		mergeSort(array, helper, middle + 1, end);
		// Merging
		merge(array, helper, begin, middle, end);
	}
}

void mergeSort(vector<int>& array)
{
	vector<int> helper(array);

	mergeSort(array, helper, 0, array.size() - 1);
}

int main()
{
	// Test 1 - Odd Sized Array
	vector<int> array;
	array.push_back(10);
	array.push_back(8);
	array.push_back(3);
	array.push_back(5);
	array.push_back(8);
	array.push_back(4);
	array.push_back(3);
	array.push_back(2);
	array.push_back(1);

	mergeSort(array);

	for(int i=0; i<array.size(); ++i)
	{
		cout << array[i] << " ";
	}
	cout << endl;

	// Test 2 - Even Sized Array
	array.clear();
	array.push_back(8);
	array.push_back(3);
	array.push_back(5);
	array.push_back(8);
	array.push_back(4);
	array.push_back(3);
	array.push_back(2);
	array.push_back(1);

	mergeSort(array);

	for(int i=0; i<array.size(); ++i)
	{
		cout << array[i] << " ";
	}
	cout << endl;

	// Test 3 - 1 element Array
	array.clear();
	array.push_back(15);

	mergeSort(array);

	for(int i=0; i<array.size(); ++i)
	{
		cout << array[i] << " ";
	}
	cout << endl;

	// Test 4 - 0 element Array
	array.clear();
	
	mergeSort(array);

	for(int i=0; i<array.size(); ++i)
	{
		cout << array[i] << " ";
	}
	cout << endl;

	return 0;
}