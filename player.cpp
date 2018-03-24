#include "player.h"

Player::Player(std::string playerName, const size_t money) {

	m_name = playerName;
	m_money = money;
	m_bet = 0;
	m_currentlyBet = 0;
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

	m_money -= m_currentlyBet;
}

void Player::winBet(const size_t externalBet) {

	m_money += externalBet + m_currentlyBet;
}

void Player::endBet() {

	m_currentlyBet += m_bet;
	m_bet = 0;
}

void Player::endRound() {

	m_currentlyBet = 0;
	m_bet = 0;
}

hand Player::getHand() {

	return m_hand;
}

size_t Player::getBet() {

	return m_bet;
}

size_t Player::getCurrentlyBet() {

	return m_currentlyBet;
}

void Player::addCardToHand(int deckCard) {

	m_hand.insert(deckCard);
}

void Player::clearOutHand() {

	m_hand.clear();
};