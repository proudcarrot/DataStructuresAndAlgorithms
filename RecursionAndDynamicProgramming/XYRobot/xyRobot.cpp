#include <iostream>
#include <vector>

using namespace std;

int getNumWaysToXY(int x, int y) 
{
	if( (x<0) || (y<0) || (x==0 && y==0)) {
		return 0;
	}

	if(x+y == 1) {
		return 1;
	}

	return getNumWaysToXY(x,y-1) + getNumWaysToXY(x-1,y);
}

int getNumWaysToXYWithLimits(int x, int y, vector<vector<bool> > &limits)
{
	if(limits.size() < x || limits.size() < y) {
		return 0;
	}

	if( (x<0) || (y<0) || (x==0 && y==0)) {
		return 0;
	}

	if(!limits[x][y]) {
		return 0;
	}

	if(x+y == 1) {
		return 1;
	}
	return getNumWaysToXYWithLimits(x,y-1,limits) + getNumWaysToXYWithLimits(x-1,y,limits);
}

int main() 
{
	int x = 1;
	int y = 1;
	cout << "Ways to " << x << ", " << y << " : " << getNumWaysToXY(x,y) << endl;

	x = 2;
	y = 1;
	cout << "Ways to " << x << ", " << y << " : " << getNumWaysToXY(x,y) << endl;

	x = 3;
	y = 3;
	cout << "Ways to " << x << ", " << y << " : " << getNumWaysToXY(x,y) << endl;

	x = 2;
	y = 2;
	cout << "Ways to " << x << ", " << y << " : " << getNumWaysToXY(x,y) << endl;

	vector<vector<bool> > limits;
	cout << "Ways to get to " << x << ", " << y << " with limits 2d vector too small" << " : " << getNumWaysToXYWithLimits(x,y,limits) << endl;

	vector<vector<bool> > limits2(4, vector<bool>(4,true));
	limits2[1][1] = false;
	cout << "Ways to get to " << x << ", " << y << " with limits blocking 1,1 off" << " : " << getNumWaysToXYWithLimits(x,y,limits2) << endl;

	limits2[1][1] = true;
	limits2[1][0] = false;
	cout << "Ways to get to " << x << ", " << y << " with limits blocking 1,0 off" << " : " << getNumWaysToXYWithLimits(x,y,limits2) << endl;

	limits2[1][0] = true;
	limits2[2][2] = false;
	cout << "Ways to get to " << x << ", " << y << " with limits blocking 2,2 off" << " : " << getNumWaysToXYWithLimits(x,y,limits2) << endl;
}