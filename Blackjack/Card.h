#pragma once
#include <string>
#include <vector>

//this class stores information about Cards and is used in deck class, as well as in Player class as a vector of cards (hand) 
class Card
{
private:
	 enum suits {hearts, spades, diamonds, clubs};
	//how to encode higher cards? i suppose we could call them higher numbers
	//11 is J, 12 is Q, 13 is K, 14 is Ace
	int number_; //so this will hold a number!
	suits suit_;
	std::vector<std::string> enum_names_ = {"hearts", "spades", "diamonds", "clubs"};
public:
	
	Card(const int num, const int suit);
	~Card();
	void setCard(const int num, const int suit);
	void printCard();
	std::string stringCard();
	int getCardValue();
};

