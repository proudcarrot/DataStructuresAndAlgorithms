#include <iostream>
#include <vector>

void insertionSort(std::vector<int> &vec)
{
	int length = vec.length();
	for(int i=0; i<length; ++i)
	{
		if(x[i-1] > x[i])
		{
			int curr = x[i];

			for(int j=i-1; j >= -1; --j)
			{
				if(j==-1)
				{
					x[j+1] = curr;
				}
				if(x[j] > curr)
				{
					x[j+1] = x[j];
				}
				else
				{
					x[j+1] = curr;
					break;
				}
			}
		}
	}

}

int main(int argc, char** argv)
{
	std::vector<int> vec = {3, 5, 2, 8, 7, 1};

	insertionSort(vec);
	for(int i=0; i<vec.length(); ++i)
	{
		std::cout << vec[i];
	}
	std::cout << std::endl;

	return 0;
}