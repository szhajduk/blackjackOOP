#include "stdafx.h"
#include "Game.h"
#include "CpuPlayer.h"
#include "HumanPlayer.h"
#include "Deck.h"
#include "Card.h"
#include <iostream>

Game::Game() //constructor takes care of players and such
{
	//player_ = new HumanPlayer;
	//cpu_ = new CpuPlayer;
	player_ = std::make_unique<HumanPlayer>();
	cpu_ = std::make_unique<CpuPlayer>();
	deck_ = std::make_unique<Deck>();
	interface_ = std::make_unique<Interface>();
	betpool_ = 0;
}

Game::~Game()
{
	//nothing to see here, move along
	//unique_ptr will automatically call destructors of
	//each member class, since there will be no more ownership anymore
}


 // void Game::setDeck(Deck * deckptr)
 // {
 // 	deck_ = deckptr;
 // }

 void Game::intoBetPool(int bet)
{
	 betpool_ += bet;
}

//resets bet-pool and returns it (to collect winnings)
int Game::returnBets()
{
	int temp = betpool_;
	betpool_ = 0;
	return temp;
}

//betting function, will check both players whether they have enough monies
void Game::bet()
{
	interface_->resetHands();
	interface_->resetScores();
	interface_->pushSpecialMsg("how much do you want to bet?");
	int bet = 0;
	char confirm;
	while (true) {
		
		std::cin >> bet;
		if ((player_->getCash() >= bet)) //if we bet less than we have
		{
			if(bet <= cpu_->getCash()) //if cpu can afford it.
			{
				player_->decreaseCash(bet); 
				cpu_->decreaseCash(bet);
				interface_->updateCpuCash(cpu_->getCash());
				interface_->updatePlayerCash(player_->getCash());
				interface_->updateBetAmnt(bet);
				intoBetPool(bet * 2);
				break;
			}

			else
			{
				interface_->pushSpecialMsg("CPU cannot afford it.");
				std::cin >> confirm;
				interface_->popSpecialMsg();
				continue;
			}
		}

		interface_->pushSpecialMsg("you dont have enough money. Bet less.");
		std::cin >> confirm;
	
	}
	interface_->flushSpecialMsg(); //no more specials.
}

bool Game::askContinue()
{
	char play;
	while (true)
	{
		std::cin >> play;
		if (play == 'y') return true;
		if (play == 'n') {
			return false;
		}
	}
}



void Game::prepareRound()
{
	player_->resetHand();
	cpu_->resetHand();
	deck_->restart();
	deck_->shuffleDeck();
	//lets give both players two cards.
	for (int i = 0; i < 2; i++) {
		player_->giveCard(deck_->popCard());
		cpu_->giveCard(deck_->popCard());
	}
	
	interface_->updatePlayerHand(player_->getPrintCardVector());
	interface_->updatePlayerScore(player_->calculateHandValue());
	interface_->updateCpuHand(cpu_->getPrintCardVector());
	std::pair<int, int> empty;
	empty.first = 0;
	empty.second = 0;
	interface_->updateCpuScore(empty); //we dont see it.
}

//here we will implement main game logic. 
void Game::play()
{
	player_->setCash(100);
	cpu_->setCash(100);
	interface_->updateCpuCash(cpu_->getCash());
	interface_->updatePlayerCash(player_->getCash());
	bool inPlay = true;
	while (inPlay) {
		
		bet();
		prepareRound();
		int playerScore = 0, cpuScore = 0;
		playerScore = player_->play(deck_.get(),interface_.get());
		
		//losing and shit, wanting to continue playing or not.
		if (playerScore == 0)
		{
			cpu_->increaseCash(returnBets());
			interface_->updateCpuCash(cpu_->getCash());
			interface_->pushSpecialMsg("Overdraw. Play again? y/n");
			inPlay=askContinue();
			interface_->popSpecialMsg();
			//we start from the top.
			continue;
		}
		//blackjack
		if (playerScore == 21)
		{
			interface_->pushSpecialMsg("***Blackjack!*** Play again? y/n");
			player_->increaseCash(returnBets());
			interface_->updatePlayerCash(player_->getCash());
			inPlay = askContinue();
			interface_->popSpecialMsg();
			continue;
		}

		cpuScore = cpu_->play(deck_.get(),interface_.get());

		if (cpuScore > playerScore)
		{
			cpu_->increaseCash(returnBets());
			interface_->updateCpuCash(cpu_->getCash());
			interface_->pushSpecialMsg("CPU won.");
		}

		if (cpuScore == playerScore)
		{
			int bet = returnBets();
			player_->increaseCash(bet / 2);
			cpu_->increaseCash(bet / 2);
			interface_->updatePlayerCash(player_->getCash());
			interface_->updateCpuCash(cpu_->getCash());
			interface_->pushSpecialMsg("Draw!");
		}

		if(cpuScore < playerScore) {
			player_->increaseCash(returnBets());
			interface_->updatePlayerCash(player_->getCash());
			interface_->pushSpecialMsg("Player won.");
		}

		if (cpu_->getCash() == 0)
		{
			interface_->pushSpecialMsg("***CPU IS BROKE, GG***");
			break;
		}

		if (player_->getCash() == 0)
		{
			interface_->pushSpecialMsg("***YOU ARE BROKE, GG***");
			break;
		}

		interface_->pushSpecialMsg("Continue? y/n");
		inPlay=askContinue();
		interface_->flushSpecialMsg(); //we always ought to do this.
	}
}