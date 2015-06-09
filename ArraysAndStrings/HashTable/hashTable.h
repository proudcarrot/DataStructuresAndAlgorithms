#include <string>
#include <array>
#include <map>

// Implemented as a static array of maps
// Should be O(logn) lookup time assuming map is a BST
template <typename K, typename V>
class HashTable {

public:
	HashTable();
	bool put(const K& key, V value);
	bool get(const K& key, V& value);
	bool remove(const K& key);
private:
	std::map<K,V> hashmap [5];
	int hashFunction(K key);
};
