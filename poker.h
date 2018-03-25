#include "utils.h"
#include "game.h"
#include "hand.h"
#include "numberToCardConverter.h"
#include <vector>
#include <map>
#include <set>

class Poker: public Game {

public:

	Poker() {};
	Rank processHand(int **hand, int idPlayer);

private:
	
	bool checkRoyalFlush(int **hand, int idPlayer);
	bool checkStraightFlush(int **hand, int idPlayer);
	bool checkFourOfAKind(int **hand, int idPlayer);
	bool checkFullHouse(int **hand, int idPlayer);
	bool checkFlush(int **hand, int idPlayer);
	bool checkStraight(int **hand, int idPlayer);
	bool checkThreeOfAKind(int **hand, int idPlayer);
	bool checkTwoPairs(int **hand, int idPlayer);
	bool checkOnePair(int **hand, int idPlayer);
	bool checkNoPair(int **hand, int idPlayer);
};