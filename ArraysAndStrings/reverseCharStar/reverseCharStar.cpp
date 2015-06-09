#include <algorithm>
#include <iostream>

using namespace std;

void reverse(char* str)
{
	if(!str) return;
	int count = 0;
	char* end = str;

	while(*end != '\0')
	{
		++count;
		++end;
	}

	for(int i=0; i<count/2; ++i)
	{
		std::swap(str[i],str[(count - 1) - i]);
	}
}

int main()
{
	char hello[] = { 'h', 'e', 'l', 'l', 'o', '\0'};
	cout << "Original: " << hello << endl;
	reverse(hello);
	cout << "Reversed: " << hello << endl;

	char ab[] = { 'a', 'b', '\0'};
	cout << "Original: " << ab << endl;
	reverse(ab);
	cout << "Reversed: " << ab << endl;
	
	char even[] = { 'e', 'v', 'e', 'n', '\0'};
	cout << "Original: " << even << endl;
	reverse(even);
	cout << "Reversed: " << even << endl;

	char one[] = { '1', '\0'};
	cout << "Original: " << one << endl;
	reverse(one);
	cout << "Reversed: " << one << endl;

	char * none = "";
	cout << "Original: " << none << endl;
	reverse(none);
	cout << "Reversed: " << none << endl;
}
