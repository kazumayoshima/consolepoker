#pragma once
#include "utils.h"
#include "numberToCardConverter.h"
#include "player.h"
#include "display.h"
#include <stdlib.h>
#include <time.h>

class Game {

public:

	Game();
	typedef std::vector<Player*> ActivePlayers;

public:
	
	void initGame();
	void addPlayers(size_t players = 1);

private:

	void initTheDeck();
	void drawHandCards(size_t numberOfPlayers);
	void getCardFromTheDeck(size_t entity, size_t times = 1);
	hand getFinalHand(int player);
	bool checkIfEmpty(int number);

	int m_deck[suits][cardsProSuit];
	ActivePlayers m_activePlayers;
	Display m_display;
};