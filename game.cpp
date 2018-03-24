#include "game.h"

Game::Game() {

	srand((unsigned int)time(NULL));
}

void Game::addPlayers(size_t players){

	for (size_t i = 0; i < players; i++) {

		//	TODO: Implement a class to display output nicely
		std::cout << "Do you want to set a name for the player [Max 10 characters]? (Leave in blank for anonymous): \n";
		std::string playerName = "";
		getline(std::cin, playerName);

		Player* player;
		player = new Player();
		if (playerName == "")
			player = new Player();
		else
			player = new Player(playerName.substr(0,10));

		m_activePlayers.push_back(player);
	}
}

void Game::initGame() {

	//	Show the table empty
	m_display.showTable();

	//	Shuffle the deck.
	initTheDeck();

	while (1) {
		//	Give two cards to each player (pre-flop).
		drawHandCards(m_activePlayers.size());

		//	Show cards for player 1 (testing)
		m_display.showCards(m_activePlayers[0]->getHand());
		getchar();
		m_activePlayers[0]->clearOutHand();
		initTheDeck();
		std::cout << std::endl;
	}
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
	for (size_t i = 0; i < m_activePlayers.size(); i++)

		hand hand = getFinalHand(i);
}

//	Init the cards of the deck to -1. That's mean the cards are in the deck and not in the table neither
//	in the hand of a player.
void Game::initTheDeck() {

	for(size_t i=0; i<suits;i++)
	for (size_t j = 0; j < cardsProSuit; j++)
		m_deck[i][j] = -1;
}

//	Get cards for the players
void Game::drawHandCards(size_t numberOfPlayers) {

	//	Draw 2 cards to each player
	for (size_t i = 1; i < numberOfPlayers+1; i++) {

		//	The player J gets 2 cards
		getCardFromTheDeck(i, 2);
	}
}

//	Get a card from the deck, it can be for a player or to be put in the table
void Game::getCardFromTheDeck(size_t entity, size_t times) {

	std::pair<int, int> card;
	int deckCard;

	for(size_t i = 0; i < times; i++){

		//	TODO:	Check if the number was already taken from the deck
		do {
			deckCard = (rand() % (cardsProSuit * suits)) + 1;
		} while (checkIfEmpty(deckCard));

		//	Add the card to the player
		if (entity != 0)
			m_activePlayers[entity-1]->addCardToHand(deckCard);

		//	Set the card as taken in the deck
		card = numberToCard(deckCard);
		m_deck[card.first][card.second] = entity;
	}
}

//	Check if a card it's already on the deck or in a player's hand
bool Game::checkIfEmpty(int number) {

	auto card = numberToCard(number);
	return m_deck[card.first][card.second] != -1;
}

//	Get the final hand of a player, the final hand is a combination of five cards
//	mixing the cards of the hand and the cards of the deck.
hand Game::getFinalHand(int player) {

	hand hand;
	for (size_t i = 0; i < suits; i++)
	for (size_t j = 0; j < cardsProSuit; j++) {

		if(m_deck[i][j] == 0 || m_deck[i][j] == player)
			hand.insert(m_deck[i][j]);
	}

	return hand;
}