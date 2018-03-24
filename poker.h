#include "utils.h"
#include "game.h"
#include "hand.h"
#include "numberToCardConverter.h"
#include <vector>
#include <map>

class Poker: public Game {

public:

	Poker() {};
	Rank processHand(hand);
	typedef std::vector<std::pair<int, int>> combinations;

private:

	combinations getSuitNumberCombination(hand hand);
	
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
};