#include "player.h"

Player::Player(std::string playerName, const size_t money) {

	m_name = playerName;
	m_money = money;
	m_bet = 0;
	m_totalBet = 0;
}

const size_t Player::getMoney() {

	return m_money;
}

void Player::setMoney(const size_t money) {

	m_money = money;
}

void Player::addMoney(const size_t money) {

	m_money += money;
}

void Player::bet(size_t bet) {

	m_money -= bet;
	m_bet += bet;
}

void Player::loseBet() {

	m_money -= m_totalBet;
}

void Player::winBet(const size_t externalBet) {

	m_money += externalBet + m_totalBet;
}

void Player::endBet() {

	m_totalBet += m_bet;
	m_bet = 0;
}

void Player::endRound() {

	m_totalBet = 0;
	m_bet = 0;
}

hand Player::getHand() {

	return m_hand;
}

void Player::addCardToHand(int deckCard) {

	m_hand.insert(deckCard);
}