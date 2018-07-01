#pragma once
#include "Player.h"
#include "Deck.h"


class HumanPlayer :
	public Player
{
public:
	HumanPlayer();
	~HumanPlayer();
	// int bet(); //we call this to bet, will ask how much we want to bet. will return bet amount
	void printCards() override;
	std::vector<std::string> getPrintCardVector() override;
	int play(Deck *deck, Interface * interface);
};

