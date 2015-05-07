#include "BlackJackHand.h"
#include <iostream>

using namespace std;

int main()
{
	BlackJackHand bjh;

	bjh.hand_.push_back(Card(Ace,Club));
	bjh.hand_.push_back(Card(Queen,Diamond));
	bjh.hand_.push_back(Card(Three,Spade));

	vector<int> score = bjh.getScore();
	cout << "Possible scores: " << endl;
	for(int i=0; i<score.size(); ++i)
	{
		cout << score[i] << endl;
	}
}
