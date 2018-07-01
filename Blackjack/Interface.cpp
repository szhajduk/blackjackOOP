#include "stdafx.h"
#include "Interface.h"
#include <iostream>
#include <string>

Interface::Interface():cpuScore_(0),playerScore_(0),betAmnt_(0),cpuCash_(0),playerCash_(0)
{
}


Interface::~Interface()
{
}

//we call this function after each and every UI update.
void Interface::draw()
{
	clearScreen(); //we always clear.
	std::cout << "Bet amount: " << betAmnt_ << std::endl;
	std::cout << "CPU cash: " << cpuCash_ << " Player cash:" << playerCash_ << std::endl;
	std::cout << "********************************" << std::endl<<std::endl;
	std::cout << "Player hand: " << std::endl;
	for(auto &card : playerHand_)
	{
		std::cout << card << std::endl;
	}

	std::cout << "--------------" << std::endl << "Player Score: ";
	if (playerScore_ == playerScoreAlt_) std::cout << playerScore_ << std::endl;
	else std::cout << playerScore_ << " or " << playerScoreAlt_ << std::endl;


	std::cout << std::endl << "CPU hand: " <<std::endl;

	for(auto &card : cpuHand_)
	{
		std::cout << card << std::endl;
	}
	std::cout << "--------------" << std::endl << "CPU Score: ";
	if (cpuScore_ == cpuScoreAlt_) std::cout << cpuScore_ << std::endl;
	else std::cout << cpuScore_ << " or " << cpuScoreAlt_ << std::endl;

	std::cout << std::endl;
	//special messages like h for hit s for stand or lose/win info.
	for(auto &msg : specialMsgStack_)
	{
		std::cout << msg << std::endl;
	}

}

//ill experiment whether stack structure will be better or this.
void Interface::updatePlayerHand(std::vector<std::string> hand)
{
	playerHand_ = hand;
	draw();
}

void Interface::updateCpuHand(std::vector<std::string> hand)
{
	cpuHand_ = hand;
	draw();
}

void Interface::resetHands()
{
	playerHand_.clear();
	cpuHand_.clear();
}

void Interface::resetScores()
{
	cpuScore_ = 0;
	cpuScoreAlt_ = 0;
	playerScore_ = 0;
	playerScoreAlt_ = 0;
}


void Interface::pushSpecialMsg(std::string msg)
{
	specialMsgStack_.push_back(msg);
	draw();
}

void Interface::popSpecialMsg()
{
	if(specialMsgStack_.size()!=0) specialMsgStack_.pop_back();
	draw();
}

void Interface::flushSpecialMsg()
{
	specialMsgStack_.clear();
}

void Interface::updateCpuCash(int cash)
{
	cpuCash_ = cash;
	draw();
}

void Interface::updateCpuScore(std::pair<int,int> score)
{
	cpuScore_ = score.first;
	cpuScoreAlt_ = score.second;
	draw();
}

void Interface::updatePlayerCash(int cash)
{
	playerCash_ = cash;
	draw();
}

void Interface::updatePlayerScore(std::pair<int,int> score)
{
	playerScore_ = score.first;
	playerScoreAlt_ = score.second;
	draw();
}

void Interface::updateBetAmnt(int bet)
{
	betAmnt_ = bet;
	draw();
}


void Interface::clearScreen()
{
	system("CLS");
}
