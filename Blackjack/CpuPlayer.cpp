#include "stdafx.h"
#include "CpuPlayer.h"
#include <iostream>


CpuPlayer::CpuPlayer()
{
}


CpuPlayer::~CpuPlayer()
{
}

//we dont want to show the first card to the player, it will be left hidden
void CpuPlayer::printCards()
{
	std::cout << "<hidden>" << std::endl;
	for(int i=1;i<hand_.size();i++)
	{
		hand_.at(i).printCard();
	}
}



//prints without hidden, we can show them later.
void CpuPlayer::printAllCards()
{
	for(auto &card : hand_)
	{
		card.printCard();
	}
}

//this will print <hidden> as first card
std::vector<std::string> CpuPlayer::getPrintCardVector()
{
	std::vector<std::string> result;
	result.push_back("<hidden>");
	for (int i = 1; i<hand_.size(); i++)
	{
		result.push_back(hand_.at(i).stringCard());
	}
	return result;
}

//this will print all cards
std::vector<std::string> CpuPlayer::getPrintCardAllVector()
{
	std::vector<std::string> result;
	for(auto &card : hand_)
	{
		result.push_back(card.stringCard());
	}
	return result;
}


//dealer has to hit on soft 17 as well.
int CpuPlayer::play(Deck* deck, Interface *interface)
{
	//as long as we have less than 17 points, we get cards.
	while((calculateHandValue().first < 17) || (calculateHandValue().second <17)){
		giveCard(deck->popCard());
		}

	interface->updateCpuHand(getPrintCardAllVector());
	interface->updateCpuScore(calculateHandValue());

	//overdraw, return 0; 
	if ((calculateHandValue().first > 21) && (calculateHandValue().second > 21))
		return 0; 

	int result1, result2;
	if (calculateHandValue().first <= 21) result1 = calculateHandValue().first;
	else result1 = 0;

	if (calculateHandValue().second <= 21) result2 = calculateHandValue().second;
	else result2 = 0;

	if (result1 < result2) return result2;
	return result1;
}

