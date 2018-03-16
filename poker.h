#include "utils.h"
#include "game.h"
#include "hand.h"

class Poker: public Game {

public:

	Poker() {};

	Rank checkRoyalFlush(hand);
	Rank checkStraightFlush(hand);
	Rank checkFourOfAKind(hand);
	Rank checkFullHouse(hand);
	Rank checkFlush(hand);
	Rank checkStraight(hand);
	Rank checkThreeOfAKind(hand);
	Rank checkTwoPairs(hand);
	Rank checkOnePair(hand);
	Rank checkNoPair(hand);

private:
	

};