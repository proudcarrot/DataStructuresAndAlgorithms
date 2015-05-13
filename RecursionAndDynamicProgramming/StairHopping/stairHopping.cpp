#include <iostream>
#include <map>

using namespace std;

// Problem: 
// A child is running up a staircase with n steps, and can 
// hop either 1,2, or 3 steps at a time. Figure out how many possible
// ways the child could run up the stairs.
// 
// Assumptions:
// Order matters  - If there are 3 steps the child could do 1-1-1, 
// 1-2, 2-1, or 3

// Using a map for memoization purposes
map<int,long> g_mapNumRoutes;

// Method to recursively determine the number of possible routes.
// Starts with the number of stairs and subtracts down. If 0 is 
// passed, it is not an acceptable route, however if it is reached, 
// it is a potential route. Otherwise, recursion needs to continue.
long takeXSteps(int n)
{
	if(n < 0)
	{
		return 0;
	}
	else if(n == 0)
	{
		return 1;
	}
	else if(g_mapNumRoutes.find(n) != g_mapNumRoutes.end())
	{
		return g_mapNumRoutes[n];
	}
	else
	{
		g_mapNumRoutes[n] = takeXSteps(n-1) + takeXSteps(n-2) + takeXSteps(n-3);
		return g_mapNumRoutes[n];
	}
}

long getNumRoutes(int n)
{
	if(n <= 0)
	{
		return 0;
	}
	else
	{
		return takeXSteps(n);
	}
}

int main()
{
	// With a long, it can get to 73 without overflow (for my 
	// compiler)
	for(int i=-2; i<78; ++i)
	{
		cout << i << " Steps: " << getNumRoutes(i) << endl;
	}
}
