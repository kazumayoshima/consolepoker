#include "game.h"

Game::Game() {

	srand(time(NULL));
}

void Game::initGame(int players) {

	//	Shuffle the deck.
	initTheDeck();

	//	Give two cards to each player (pre-flop).
	drawHandCards(players);

	//	Do your bets
	//	for(auto i : player)
	//		bet();

	//	Draw the flop in the table (three cards).
	//	The cards in the table are marked with the number 0.
	getCardFromTheDeck(0, 3);

	//	Do your bets
	//	for(auto i : player)
	//		bet();

	//	Draw the turn in the table (one card).
	getCardFromTheDeck(0, 1);

	//	Do your bets
	//	for(auto i : player)
	//		bet();

	//	Draw the river in the table (one card).
	getCardFromTheDeck(0, 1);

}

//	Init the cards of the deck to -1. That's mean the cards are in the deck and not in the table neither
//	in the hand of a player.
void Game::initTheDeck() {

	for(size_t i=0; i<suits;i++)
	for (size_t j = 0; j < cardsProSuit; j++)
		m_deck[i][j] = -1;
}

//	Get cards for the players
void Game::drawHandCards(int numberOfPlayers) {

	//	Draw 2 cards to each player
	for(size_t i = 0; i < cardsInHand; i++)
	for (size_t j = 0; j < numberOfPlayers; j++) {

		//	The player J draw a card
		getCardFromTheDeck(j);
	}
}

//	Get a card from the deck, it can be for a player or to be put in the table
void Game::getCardFromTheDeck(int entity, int times) {

	std::pair<int, int> card;
	for(size_t i = 0; i < times; i++)
	for (size_t j = 0; j < cardsInHand; j++) {

		card = numberToCard(rand() % (cardsProSuit * suits));
		m_deck[card.first][card.second] = entity;
	}
}