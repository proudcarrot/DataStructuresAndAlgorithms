#include "hashTable.h"
#include <string>
#include <iostream>

using namespace std;

void hashGet(HashTable<int,string>& hash, int k)
{
	string outV;
	bool get = hash.get(k, outV);
	if(get)
	{
		cout << "Pair: " << k << " -> " << outV << endl;
	}
	else
	{
		cout << "Nothing with key: " << k << endl;
	}
}

void hashRemoval(HashTable<int,string>& hash, int k)
{
	bool removal = hash.remove(k);
	if(removal)
	{
		cout << "Removed Key " << k << endl;
	}
	else
	{
		cout << "Key " << k << " cannot be removed as it doesn't exist" << endl;
	}
}

int main()
{
	HashTable<int,string> hash;

	int k = 4;
	string v = "fun";

	hash.put(k, v);
	hashGet(hash, k);

	k = 5;
	hashGet(hash, k);

	k = 4;
	v = "pug";
	hash.put(k, v);
	hashGet(hash, k);

	hashRemoval(hash, k);
	hashRemoval(hash, k);


	return 0;
}
