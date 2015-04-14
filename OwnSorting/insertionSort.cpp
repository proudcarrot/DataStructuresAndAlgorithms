#include <iostream>
#include <vector>

void insertionSort(std::vector<int> &vec)
{
	for(int i=1; i<vec.size(); ++i)
	{
		int j = i;
		while(j>0 && vec[j-1]>vec[j])
		{
			std::swap(vec[j-1],vec[j]);
			j = j-1;
		}
	}
}

void insertionSortStart(std::vector<int> &vec)
{
	int length = vec.size();
	for(int i=0; i<length; ++i)
	{
		if(vec[i-1] > vec[i])
		{
			int curr = vec[i];

			for(int j=i-1; j >= -1; --j)
			{
				if(j==-1)
				{
					vec[j+1] = curr;
				}
				else if(vec[j] > curr)
				{
					vec[j+1] = vec[j];
				}
				else
				{
					vec[j+1] = curr;
					break;
				}
			}
		}
	}

}

int main(int argc, char** argv)
{
	std::vector<int> vec = {3, 3, 5, 6, 1, 8, 7, 1, 4, 9, 2};

	insertionSort(vec);
	for(int i=0; i<vec.size(); ++i)
	{
		std::cout << vec[i];
	}
	std::cout << std::endl;

	return 0;
}