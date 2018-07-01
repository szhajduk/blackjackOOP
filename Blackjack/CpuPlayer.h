#pragma once
#include "Card.h"
#include "Player.h"

//inherits from Player class
class CpuPlayer : public Player
{
public:
	CpuPlayer();
	~CpuPlayer();
	void printCards() override;
	void printAllCards();
	std::vector<std::string> getPrintCardVector() override;
	std::vector<std::string> getPrintCardAllVector();
	int play(Deck* deck, Interface* interface) override;
};

