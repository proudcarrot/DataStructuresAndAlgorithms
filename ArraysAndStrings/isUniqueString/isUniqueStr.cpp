#include <string>
#include <set>
#include <iostream>

#include <boost/algorithm/string.hpp>
#include <algorithm>

// Finds if an input string is unique using a set
// O(n) - time
// O(n) - space
bool isUniqueStrSet(std::string str)
{
	int length = str.size();
	if(length <= 1)
	{
		return true;
	}

	// Assuming that case does not matter
	boost::algorithm::to_lower(str);

	std::set<char> foundChars;

	for(int i=0; i<length; ++i)
	{
		// If the current character is already in the set,
		// the string is not unique
		char curr = str.at(i);
		if(foundChars.find(curr) != foundChars.end())
		{
			return false;
		}
		foundChars.insert(curr);
	}

	return true;
}

// Finds if an input string is unique using sorting
// O(nlog(n)) - time
// O(1) - space
bool isUniqueStrSort(std::string str)
{
	int length = str.size();
	if(length <= 1)
	{
		return true;
	}

	// Assuming that case does not matter
	std::transform(str.begin(),str.end(),str.begin(),::tolower);
	
	std::sort(str.begin(),str.end());

	for(int i=0; i<length-1; ++i)
	{
		if(str.at(i) == str.at(i+1))
		{
			return false;
		}
	}

	return true;
}

int main(int argc, char** argv)
{
	std::string str;

	// Must input a string with no spaces and can't be an empty string
	std::cin >> str;

	bool unique = isUniqueStrSet(str);

	std::cout << "Using set: " << unique << std::endl;

	unique = isUniqueStrSort(str);
	std::cout << "Using sorting: " << unique << std::endl;

	return 0;
}