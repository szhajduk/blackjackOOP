#include "stdafx.h"
#include "Deck.h"
#include <algorithm>
#include <ctime>
#include <random>


Deck::Deck()
{
	//i is number, j is suit
	for(int i = 2; i<=14; i++)
	{
		for(int j = 0; j<4 ;j++)
		{
			deck_of_cards_.push_back(Card(i, j));  //create Card and init it.
		}
	}
}


Deck::~Deck()
{
}

void Deck::restart()
{
	
	deck_of_cards_.clear(); //erease vector content

	for (int i = 2; i <= 14; i++)
	{
		for (int j = 0; j<4; j++)
		{
			deck_of_cards_.push_back(Card(i, j));  
		}
	}
}


void Deck::shuffleDeck()
{
	//kinda nice shuffle
	std::srand(time(0));
	std::random_shuffle(deck_of_cards_.begin(), deck_of_cards_.end());
}

//doesnt work when empty.
Card Deck::popCard()
{
	Card toReturn = deck_of_cards_[deck_of_cards_.size() - 1]; //we get last card
	deck_of_cards_.pop_back(); //we remove last card
	return toReturn;
}


