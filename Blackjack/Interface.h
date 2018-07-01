#pragma once
#include <vector>
#include <cstdlib> 

//interface for blackjack,operates on basis of updating information
//and redrawing whole console window per-update.
//hope this will be fast enough, CMD interfaces 
//are not known for fast throughputs

class Interface
{
	std::vector<std::string> playerHand_;
	std::vector<std::string> cpuHand_;
	int cpuCash_;
	int playerCash_;
	int cpuScore_;
	int cpuScoreAlt_;
	int playerScore_;
	int playerScoreAlt_;
	int betAmnt_;
	std::vector<std::string> specialMsgStack_; //will work in a stack structure and show things like h for hit s for stand.
public:
	Interface();
	~Interface();
	void draw();
	void updatePlayerHand(std::vector<std::string> hand);
	void updateCpuHand(std::vector<std::string> hand);
	void resetHands();
	void resetScores();
	void updatePlayerScore(std::pair<int,int> score); //two scores
	void updateCpuScore(std::pair<int,int> score);
	void updateCpuCash(int cash);
	void updatePlayerCash(int cash);
	void updateBetAmnt(int bet);
	void pushSpecialMsg(std::string msg);
	void popSpecialMsg();
	void flushSpecialMsg();
	void clearScreen(); //THIS IS SO DIRTY
};

