#pragma once
#include "Deck.h"
#include "Player.h"
#include "Interface.h"
#include <memory>

//TODO use a fucking SVN/Git you fucking moron

class Game
{
private:
	//unique pointers, might change to std::shared_ptr if need be
	std::unique_ptr<Player> player_;
	std::unique_ptr<Player> cpu_;
	std::unique_ptr<Interface> interface_;
	std::unique_ptr<Deck> deck_;
	int betpool_;
	void intoBetPool(int bet);
	int returnBets();
public:
	Game();
	~Game();
	void play(); 
	void setDeck(Deck* deckptr);
	void bet();
	bool askContinue();
	void prepareRound();
};

