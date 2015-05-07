#include <vector>

enum Value {
	Ace = 1,
	Two,
	Three,
	Four,
	Five,
	Six,
	Seven,
	Eight,
	Nine,
	Ten,
	Jack,
	Queen,
	King,
};

enum Suit {
	Diamond,
	Heart,
	Club,
	Spade,
};

struct Card {
	Value value_;
	Suit suit_;
	Card (Value value, Suit suit)
		: value_(value), suit_(suit) 
	{

	}
};

class BlackJackHand {

public:
	BlackJackHand() {};
	std::vector<Card> hand_;
	std::vector<int> getScore()
	{
		int lowScore = 0;
		int highScore = 0;

		for(int i=0; i<hand_.size(); ++i)
		{
			int value = hand_[i].value_;
			if(value == 1)
			{
				lowScore += 1;
				highScore += 11;
			}
			else if(value < 11)
			{
				lowScore += value;
				highScore += value;
			}
			else
			{
				lowScore += 10;
				highScore += 10;
			}
		}

		std::vector<int> scores;
		if(lowScore != highScore)
		{
			scores.push_back(lowScore);
			scores.push_back(highScore);
		}
		else
		{
			scores.push_back(lowScore);
		}
		return scores;
	}
};