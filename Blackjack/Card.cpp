#include "stdafx.h"
#include "Card.h"
#include <iostream>
#include <string>


Card::Card(const int num, const int suit)
{
	number_ = num;
	suit_ = (suits)suit;
}


Card::~Card()
{
}


void Card::setCard(const int num, const int suit)
{
	number_ = num;
	suit_ = (suits) suit;
}


void Card::printCard()
{
	std::string literal;
	switch (number_) {
	case 11:
		literal = "J";
		break;
	case 12:
		literal = "Q";
		break;
	case 13:
		literal = "K";
		break;
	case 14:
		literal = "A";
		break;
	default:
		literal = std::to_string(number_);
	}
	std::cout << literal << " of " << enum_names_[suit_] << std::endl;
}

std::string Card::stringCard()
{
	std::string literal;
	switch (number_) {
	case 11:
		literal = "J";
		break;
	case 12:
		literal = "Q";
		break;
	case 13:
		literal = "K";
		break;
	case 14:
		literal = "A";
		break;
	default:
		literal = std::to_string(number_);
	}
	return (literal + " of " + enum_names_[suit_]);
}

//returns 1-10 and 10 for JQK and 14 for A
int Card::getCardValue()
{	
	if ((number_ > 10) && (number_ != 14)) return 10;
	return number_;
}

