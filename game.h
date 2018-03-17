#include "utils.h"
#include "numberToCardConverter.h"
#include "player.h"
#include <stdlib.h>
#include <time.h>
#include <set>
#include <vector>

class Game {

public:

	Game();
	typedef std::vector<Player*> ActivePlayers;

public:
	
	void initGame();
	void addPlayers(int players = 1);

private:

	void initTheDeck();
	void drawHandCards(int numberOfPlayers);
	void getCardFromTheDeck(int entity, int times = 1);
	hand getFinalHand(int player);

	int m_deck[cardsProSuit][suits];
	ActivePlayers m_activePlayers;
};