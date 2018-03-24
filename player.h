#pragma once
#include "utils.h"

class Player{

public:

	Player(std::string playerName = "anonymous", const size_t money = 500);
	const size_t getMoney();
	void setMoney(const size_t money);
	void addMoney(const size_t money);
	void bet(size_t bet);
	void loseBet();
	void winBet(const size_t externalBet);
	void endBet();
	void endRound();
	hand getHand();
	void addCardToHand(int deckCard);
	void clearOutHand();
private:

	size_t m_money;
	size_t m_bet;
	size_t m_totalBet;
	std::string m_name;
	hand m_hand;
};