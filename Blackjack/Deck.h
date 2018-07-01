#pragma once
#include "Card.h"
#include <stack>
#include <vector>

//this is basically a vector of cards to store information.
class Deck
{
private:
	std::vector<Card> deck_of_cards_;

public:
	Deck();
	~Deck();
	void restart(); //this is used to reset deck to 52 cards.
	void shuffleDeck(); //shuffle
	Card popCard(); //returns card and pops if from vector.
};

