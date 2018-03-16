#include "utils.h"
#include "numberToCardConverter.h"
#include <stdlib.h>
#include <time.h>
#include <set>

class Game {

public:

	Game();

public:
	typedef std::set<int> hand;
	void initGame(int players = 1);
	

private:

	void initTheDeck();
	void drawHandCards(int numberOfPlayers);
	void getCardFromTheDeck(int entity, int times = 1);
	hand getFinalHand(int player);

	hand m_hand[cardsInHand];
	int m_deck[cardsProSuit][suits];
	int m_players;
};