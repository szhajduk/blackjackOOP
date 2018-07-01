#include "stdafx.h"
#include "HumanPlayer.h"
#include <iostream>
#include "Deck.h"
#include "Interface.h"


HumanPlayer::HumanPlayer()
{
}


HumanPlayer::~HumanPlayer()
{
}


//this prints all cards of human.
void HumanPlayer::printCards()
{
	for (auto &card : hand_)
	{
		card.printCard();
	}
}

std::vector<std::string> HumanPlayer::getPrintCardVector()
{
	std::vector<std::string> result;
	for (auto &card : hand_)
	{
		result.push_back(card.stringCard());
	}
	return result;
}


//we need to create a play function
//we will get cards from deck that is created in Game object.
//returns 0 for loss, otherwise returns score.
int HumanPlayer::play(Deck *deck, Interface* interface)
{
	interface->pushSpecialMsg("h for hit, s for stand.");
	char option='\0';
	
	while(true)
	{
		std::cin >> option;
		if(option=='h')
		{
			//we give card, we print them, we print out the value
			giveCard(deck->popCard());
			interface->updatePlayerHand(getPrintCardVector());
			interface->updatePlayerScore(calculateHandValue());
	
			if((calculateHandValue().first)>21 && (calculateHandValue().second)>21)
			{
				return 0; 
			}
		}
		if (option == 's') break;
	}
	interface->flushSpecialMsg();
	//we first zero scores higher than 21 - at least one of scores is less.
	int result1, result2;
	if (calculateHandValue().first <= 21) result1 = calculateHandValue().first;
	else result1 = 0;

	if (calculateHandValue().second <= 21) result2 = calculateHandValue().second;
	else result2 = 0;

	if (result1 < result2) return result2;
	return result1;
}



