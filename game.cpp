#include "game.h"
#include "utils.h"

Game::Game() {

	srand(time(NULL));
}

void Game::addPlayers(int players){

	for (size_t i = 0; i < players; i++) {

		//	TODO: Implement a class to display output nicely
		std::cout << "Do you want to set a name for the player? (Leave in blank for anonymous): ";
		std::string playerName = "";
		std::cin >> playerName;

		Player* player;
		if (playerName == "")
			player = new Player();
		else
			player = new Player(playerName);

		m_activePlayers.push_back(player);
	}
}

void Game::initGame() {

	//	Shuffle the deck.
	initTheDeck();

	//	Give two cards to each player (pre-flop).
	drawHandCards(m_activePlayers.size());

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

	//	Check the final hand of each player
	for (size_t i = 0; i < m_activePlayers.size(); i++) {

		hand hand = getFinalHand(i);

	}
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

hand Game::getFinalHand(int player) {

	hand hand;
	for (size_t i = 0; i < suits; i++)
	for (size_t j = 0; j < cardsProSuit; j++) {

		if(m_deck[i][j] == 0 || m_deck[i][j] == player)
			hand.insert(m_deck[i][j]);
	}

	return hand;
}