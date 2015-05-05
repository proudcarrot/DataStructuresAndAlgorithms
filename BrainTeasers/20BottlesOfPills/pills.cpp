#include <iostream>

using namespace std;

/* Problem: 
 * You have 20 bottles of pills. 19 bottles have 1.0 gram pills
 * and 1 has 1.1 gram pills. How do you determine which bottle
 * contains the 1.1 gram pills by only using a scale once?
 *
 * Assumptions:
 * There are enough pills to take 1,2,3,...,20 pills out of the
 * bottles. IE, one bottle contains at least 20 pills, another
 * 19, etc.
 *
 * Solution:
 * Take 1 pill from bottle 1, 2 pills from bottle 2, etc, all the
 * way to 20 pills from bottle 20. Put them on the scale and weigh 
 * them.
 * If all pills were 1.0 grams, their total weight would be:
 * 1.0 + 2.0 + 3.0 + ... + 20.0 = 210.0
 * Due to the fact that there will be a set of pills weighing 1.1 
 * grams each, you can subtract 210 from the total and multiply the
 * difference by 10 yielding the number of the bottle with 1.1 gram
 * pills.
 * For example: 
 * If bottle 1 has 1.1 gram pills, the total will be 210.1
 * Subtracting 210 yields .1 so .1*10 is 1 for bottle 1
 * If bottle 20 has 1.1 gram pills, the total will be 212.0
 * Subtracting 210 yields 2.0 so 2.0*10 is 20 for bottle 20
 *
 * A slightly better way to do it would require n-1 pills in each
 * bottle. So Bottle 1 would contribute 0 pills. The total weight
 * would be 190 if all bottles were 1.0 grams.
 * If this were the total weight, Bottle 1 would be the one that
 * has 1.1 gram pills.
 */

// This function determines the total weight of the scale
// assuming the parameter numOfHeavier is the number of the
// bottle that has pills that weighs 1.1 grams. This also 
// assumes that numOfHeavier is between 1 and 20 inclusive.
double totalWeight(int numOfHeavier)
{
	double sum = 0;
	for(int i=1; i<=20; ++i)
	{
		if(i == numOfHeavier)
		{
			sum += i*1.1;
		}
		else
		{
			sum += i;
		}
	}
	return sum;
}

// This function determines the number of the bottle that 
// contains pills weighing 1.1 grams using my algorithm 
// stated in the solution above for all possibilities of 
// 1 to 20
double determineHeavier(double totalWeight)
{
	double diff = totalWeight - 210;
	return diff*10;
}

// This tests the functions for bottles 1 to 20
int main()
{
	int sum = 0;
	for(int i=1; i<=20; ++i)
	{
		sum+=i;
	}
	cout << sum << endl;

	cout << "Trying each 1 to 20" << endl;
	cout << "Numbers should all equal each other" << endl;

	for(int numOfHeavier=1; numOfHeavier<=20; ++numOfHeavier)
	{
		cout << numOfHeavier << " = " << determineHeavier(totalWeight(numOfHeavier)) << endl;
	}

	return 0;
}
