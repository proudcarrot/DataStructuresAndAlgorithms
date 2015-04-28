#include <vector>
#include <iostream> //cout, endl

using namespace std;

typedef unsigned int uint;

// This function replaces part of number N with number M. 
// THey are both 32 bits or less. M is inserted between a lower
// bound of i and an upper bound of j. It is assumed that
// j-i is >= the number of bits needed to represent M.
uint insertMintoN(uint N, uint M, int i, int j)
{
	uint mask_j = (~0 << (j+1));
	uint mask_i = (1 << i) - 1;
	uint mask = mask_j | mask_i;

	uint maskedN = mask & N;
	uint shiftedM = M << i;

	return maskedN | shiftedM;
}

// This function prints out binary numbers given a base 10
// number
void printBinaryfromBase10(uint base10)
{
	vector<int> reversedBinary;

	while(base10 != 0)
	{
		reversedBinary.push_back(base10 & 1);
		base10 = base10 >> 1;
	}

	for(int i = reversedBinary.size()-1; i >= 0 ; --i)
	{
		cout << reversedBinary[i];
	}

	cout << endl;
}

int main()
{
	uint N = 1024;
	uint M = 19;
	int i = 2;
	int j = 6;

	uint insertedMandN = insertMintoN(N,M,i,j);

	cout << "Test 1" << endl;
	cout << "N: "; printBinaryfromBase10(N);
	cout << "M: "; printBinaryfromBase10(M);
	cout << "Inserted: "; printBinaryfromBase10(insertedMandN);


	N = 2087;
	M = 56;
	i = 3;
	j = 8;

	insertedMandN = insertMintoN(N,M,i,j);

	cout << "Test 2" << endl;
	cout << "N: "; printBinaryfromBase10(N);
	cout << "M: "; printBinaryfromBase10(M);
	cout << "Inserted: "; printBinaryfromBase10(insertedMandN);

	return 0;
}