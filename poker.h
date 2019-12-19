#pragma once
#include <vector>
#include <map>
#include <set>
#include "hand.h"
#include "utils.h"

class Poker {

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

	bool checkHand(int number, int idPlayer);
};