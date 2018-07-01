#include "stdafx.h"
#include "Player.h"
#include <iostream>


Player::Player()
{
}


Player::~Player()
{
}

//we will also have a game class that will connect both player and cashier - this is just game itself.


void Player::setCash(int amount)
{
	cash_ = amount;
}

int Player::getCash()
{
	return cash_;
}

void Player::giveCard(Card card)
{
	hand_.push_back(card);
}

void Player::resetHand()
{
	hand_.clear();
}

void Player::decreaseCash(int cash)
{
	if (cash_ - cash >= 0)
		cash_ -= cash;
	else
	{
		std::string notEnoughMoney;
		throw notEnoughMoney;
	}
}

void Player::increaseCash(int cash)
{
	cash_ += cash;
}

std::pair<int,int> Player::calculateHandValue()
{
	std::vector<int> values;
	for (auto &card : hand_)
	{
		values.push_back(card.getCardValue()); //we got vector of values, now to iterate it and find value of cards.
	}
	int sumAce2 = 0;
	int sumAce11 = 0;
	for (auto &value : values)
	{
		if(value == 14)
		{
			sumAce2 += 2;
			sumAce11 += 11;
			continue;
		}
		sumAce2 += value;
		sumAce11 += value;
	}
	std::pair<int,int> result;
	
		result.first = sumAce2;
		result.second = sumAce11;
	
	return result;
}

void Player::printHandValue()
{
	if (calculateHandValue().first == calculateHandValue().second) std::cout << calculateHandValue().first << std::endl;
	else std::cout << calculateHandValue().first << " or " << calculateHandValue().second << std::endl;
}


