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

	int spadeCount = 0, clubCount=0, diamondCount=0, heartsCount = 0;
	for (size_t i = 0; i < cardsProSuit; i++) {

		if (checkHand(hand[Suit::Hearts][i], idPlayer)) {
			heartsCount++;
			spadeCount = 0;
			clubCount = 0;
			diamondCount = 0;
		}
		else if (checkHand(hand[Suit::Diamonds][i],idPlayer)) {
			diamondCount++;
			spadeCount = 0;
			clubCount = 0;
			heartsCount = 0;
		}
		else if(checkHand(hand[Suit::Clubs][i], idPlayer)){
			clubCount++;
			spadeCount = 0;
			diamondCount = 0;
			heartsCount = 0;
		}
		else if (checkHand(hand[Suit::Spades][i], idPlayer)) {
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
	}

	//	Check the straight ended in A
	if (heartsCount == (cardsInTable - 1)) {

		if (checkHand(hand[Suit::Hearts][0], idPlayer))
			return true;
	}
	else if (spadeCount == (cardsInTable - 1)) {

		if (checkHand(hand[Suit::Spades][0], idPlayer))
			return true;
	}
	else if (diamondCount == (cardsInTable - 1)) {

		if (checkHand(hand[Suit::Diamonds][0], idPlayer))
			return true;
	}
	else if (clubCount == (cardsInTable - 1)) {

		if (checkHand(hand[Suit::Clubs][0], idPlayer))
			return true;
	}

	return false;
}

bool Poker::checkStraightFlush(int **hand, int idPlayer) {

	int spadeCount = 0, clubCount = 0, diamondCount = 0, heartsCount = 0;
	for (size_t i = 0; i < cardsProSuit; i++) {

		if (checkHand(hand[Suit::Hearts][i], idPlayer)) {
			heartsCount++;
			spadeCount = 0;
			clubCount = 0;
			diamondCount = 0;
		}
		else if (checkHand(hand[Suit::Diamonds][i], idPlayer)) {
			diamondCount++;
			spadeCount = 0;
			clubCount = 0;
			heartsCount = 0;
		}
		else if (checkHand(hand[Suit::Clubs][i], idPlayer)) {
			clubCount++;
			spadeCount = 0;
			diamondCount = 0;
			heartsCount = 0;
		}
		else if (checkHand(hand[Suit::Spades][i], idPlayer)) {
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

	return false;
}
bool Poker::checkFourOfAKind(int **hand, int idPlayer) {

	for (size_t i = 0; i < cardsProSuit; i++) {
		if(checkHand(hand[Suit::Hearts][i], idPlayer) && checkHand(hand[Suit::Clubs][i], idPlayer) && checkHand(hand[Suit::Diamonds][i], idPlayer) && checkHand(hand[Suit::Spades][i], idPlayer))
			return true;
	}
	
	return false;
}
bool Poker::checkFullHouse(int **hand, int idPlayer) {

	bool countThree = false;
	bool countTwo = false;
	int count = 0;
	for (size_t i = 0; i < cardsProSuit; i++) {
		for (size_t j = 0; j < suits; j++) {
			if (checkHand(hand[j][i], idPlayer))
				count++;
		}
		if (count == 3)
			countThree = true;
		else if (count == 2)
			countTwo = true;
		count = 0;
	}
	return countThree && countTwo;
}
bool Poker::checkFlush(int **hand, int idPlayer) {

	int count = 0;
	for (size_t i = 0; i < suits; i++) {
		for (size_t j = 0; j < cardsProSuit; j++) {
			if (checkHand(hand[i][j], idPlayer)){
				count++;
			}
		}
		if (count >= 5)
			return true;
		else
			count = 0;
	}
	return false;
}
bool Poker::checkStraight(int **hand, int idPlayer) {

	int count = 0;
	for (size_t i = 0; i < cardsProSuit; i++) {
		if (checkHand(hand[0][i], idPlayer) || checkHand(hand[1][i], idPlayer) || checkHand(hand[2][i], idPlayer) || checkHand(hand[3][i], idPlayer))
			count++;
		else
			count = 0;
		if (count == 5)
			return true;
	}
	return false;
}
bool Poker::checkThreeOfAKind(int **hand, int idPlayer) {

	int count = 0;
	for (size_t i = 0; i < cardsProSuit; i++) {
		for (size_t j = 0; j < suits; j++) {
			if (checkHand(hand[j][i], idPlayer))
				count++;
		}
		if (count > 2)
			return true;
		count = 0;
	}
	return false;
}
bool Poker::checkTwoPairs(int **hand, int idPlayer) {

	int pairs = 0;
	int count = 0;
	for (size_t i = 0; i < cardsProSuit; i++) {
		for (size_t j = 0; j < suits; j++) {
			if (checkHand(hand[j][i], idPlayer))
				count++;
		}
		if (count == 2 )
			pairs++;
		count = 0;
	}
	return pairs == 2;
}
bool Poker::checkOnePair(int **hand, int idPlayer) {

	int count = 0;
	for (size_t i = 0; i < cardsProSuit; i++) {
		for (size_t j = 0; j < suits; j++) {
			if (checkHand(hand[j][i], idPlayer))
				count++;
		}
		if (count > 1)
			return true;
		count = 0;
	}
	return false;
}
bool Poker::checkNoPair(int **hand, int idPlayer) {

	return true;
}

bool Poker::checkHand(int number, int idPlayer) {

	return (number == idPlayer || number == 0);
}
