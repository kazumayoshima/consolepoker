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

	int spadeCount, clubCount, diamondCount, heartsCount = 0;
	for (size_t i = 0; i < cardsProSuit; i++) {

		if (hand[Suit::Hearts][i] == idPlayer ) {
			heartsCount++;
			spadeCount = 0;
			clubCount = 0;
			diamondCount = 0;
		}
		else if (hand[Suit::Diamonds][i] == idPlayer) {
			diamondCount++;
			spadeCount = 0;
			clubCount = 0;
			heartsCount = 0;
		}
		else if(hand[Suit::Clubs][i] == idPlayer){
			clubCount++;
			spadeCount = 0;
			diamondCount = 0;
			heartsCount = 0;
		}
		else if (hand[Suit::Spades][i] == idPlayer) {
			spadeCount++;
			clubCount = 0;
			diamondCount = 0;
			heartsCount = 0;
		}
		else {
			clubCount = 0;
			spadeCount = 0;
			diamondCount = 0;
			heartsCount = 0;
		}
		if (clubCount == cardsInTable || spadeCount == cardsInTable || diamondCount == cardsInTable || heartsCount == cardsInTable)
			return true;
	}

	//	Take into account the possibility of a straight ended in A
	if (heartsCount == (cardsInTable - 1)) {

		if (hand[Suit::Hearts][0] == idPlayer)
			return true;
	}
	else if (spadeCount == (cardsInTable - 1)) {

		if (hand[Suit::Spades][0] == idPlayer)
			return true;
	}
	else if (diamondCount == (cardsInTable - 1)) {

		if (hand[Suit::Diamonds][0] == idPlayer)
			return true;
	}
	else if (clubCount == (cardsInTable - 1)) {

		if (hand[Suit::Clubs][0] == idPlayer)
			return true;
	}

	return false;
}

bool Poker::checkStraightFlush(int **hand, int idPlayer) {

	int redCount, blackCount=0;
	for (size_t i = 0; i < cardsProSuit; i++) {

		if (hand[Suit::Hearts][i] == idPlayer || hand[Suit::Diamonds][i] == idPlayer) {
			redCount++;
			blackCount = 0;
		}
		else if(hand[Suit::Clubs][i] == idPlayer || hand[Suit::Spades][i] == idPlayer){
			blackCount++;
			redCount = 0;
		}
		else {
			redCount = 0;
			blackCount = 0;
		}
		if (redCount == cardsInTable || blackCount == cardsInTable)
			return true;
	}

	//	Take into account the possibility of a straight ended in A
	if (redCount == (cardsInTable - 1)) {

		if (hand[Suit::Hearts][0] == idPlayer || hand[Suit::Diamonds][0] == idPlayer)
			return true;
	}
	else if (blackCount == (cardsInTable - 1)) {

		if (hand[Suit::Clubs][0] == idPlayer || hand[Suit::Spades][0] == idPlayer)
			return true;
	}

	return false;
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
