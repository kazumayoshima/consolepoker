#include "poker.h"

Rank Poker::processHand(int **hand, int idPlayer) {

	if (checkRoyalFlush(hand, idPlayer))
		return Rank::RoyalFlush;
	else if (checkStraightFlush(hand, idPlayer))
		return Rank::StraightFlush;
	else if (checkFourOfAKind(hand, idPlayer))
		return Rank::FourOfAKind;
	else if (checkFullHouse(hand, idPlayer))
		return Rank::FullHouse;
	else if (checkFlush(hand, idPlayer))
		return Rank::Flush;
	else if (checkStraight(hand, idPlayer))
		return Rank::Straight;
	else if (checkThreeOfAKind(hand, idPlayer))
		return Rank::ThreeOfAKind;
	else if (checkTwoPairs(hand, idPlayer))
		return Rank::TwoPairs;
	else if (checkOnePair(hand, idPlayer))
		return Rank::OnePair;
	else if (checkNoPair(hand, idPlayer))
		return Rank::NoPair;
	else
		return Rank::Invalid;
}

bool Poker::checkRoyalFlush(int **hand, int idPlayer) {

	for (size_t i = 0; i < suits; i++) {
		std::set<int> count;
		for (size_t j = 0; j < cardsProSuit; j++) {
			if (hand[i][j] == 1) {
				count.insert(j);
			}
		}
		size_t auxCount = 0;
		size_t auxSeries = 0;
		for (auto &c : count) {

			if (auxSeries == 0)
				auxSeries = c;
			else {

				if (c - auxSeries == idPlayer) {
					auxCount++;
					auxSeries = c;
				}
				else {
					auxCount = 0;
					auxSeries = 0;
				}
			}
			if (auxCount == 5)
				return true;
		}
	}
	return false;
}

bool Poker::checkStraightFlush(int **hand, int idPlayer) {

	return true;
}
bool Poker::checkFourOfAKind(int **hand, int idPlayer) {

	return true;
}
bool Poker::checkFullHouse(int **hand, int idPlayer) {

	return true;
}
bool Poker::checkFlush(int **hand, int idPlayer) {

	return true;
}
bool Poker::checkStraight(int **hand, int idPlayer) {

	return true;
}
bool Poker::checkThreeOfAKind(int **hand, int idPlayer) {

	return true;
}
bool Poker::checkTwoPairs(int **hand, int idPlayer) {

	return true;
}
bool Poker::checkOnePair(int **hand, int idPlayer) {

	return true;
}
bool Poker::checkNoPair(int **hand, int idPlayer) {

	return true;
}
