#include "hashTable.h"

template <typename K, typename V>
HashTable<K,V>::HashTable()
{

}

template <typename K, typename V>
bool HashTable<K,V>::put(const K& key, V value)
{
	int loc = hashFunction(key);

	hashmap[loc][key] = value;

	return true;
}

template <typename K, typename V>
bool HashTable<K,V>::get(const K& key, V& value)
{
	int loc = hashFunction(key);

	//typename std::map<K,V>::iterator 
	auto it = hashmap[loc].find(key);
	if(it != hashmap[loc].end())
	{
		value = it->second;
		return true;
	}

	return false;
}

template <typename K, typename V>
bool HashTable<K,V>::remove(const K& key)
{
	int loc = hashFunction(key);

	size_t num = hashmap[loc].erase(key);

	return num >= 1;
}

template <typename K, typename V>
int HashTable<K,V>::hashFunction(K key)
{
	return key%5;
} 

template class HashTable<int,std::string>;
