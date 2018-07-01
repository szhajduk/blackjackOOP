#pragma once
#include "Card.h"
#include "Deck.h"
#include "Interface.h"

//Player class has everything that cpu and human have in common.
class Player
{
	//we need access to those from inherited classes
protected:
	int cash_;
	std::vector<Card> hand_;

public:
	Player();
	virtual ~Player();
	//virtual void play();
	void setCash(int amount); //initial amount.
	int getCash(); //get current.
	void giveCard(Card card); //gives a card to hand
	void resetHand(); //empties hand
	void decreaseCash(int cash);
	void increaseCash(int cash);
	std::pair<int,int> calculateHandValue(); //returns a pair<int,int> with first=treat ace as 2, second=treat ace as 11;
	void printHandValue();
	int stringHandValue();
	virtual std::vector<std::string> getPrintCardVector() = 0;
	virtual void printCards() = 0; //prints all cards, will differ for cashier and player
	virtual int play(Deck *deck, Interface *interface) = 0; //play will also differ between players
};