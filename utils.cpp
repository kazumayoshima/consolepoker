#include "utils.h"

std::string suitToString(int suit) {

	if (suit == Suit::Diamonds)
		return "Diamonds";
	else if (suit == Suit::Clubs)
		return "Clubs";
	else if (suit == Suit::Hearts)
		return "Hearts";
	else if (suit == Suit::Spades)
		return "Spades";
	else
		return "Invalid suit";
}

std::string cardNumberToString(int cardNumber) {

	if (cardNumber == (int)CardsNumbers::As)
		return "A";
	else if (cardNumber == (int)CardsNumbers::Two)
		return "2";
	else if (cardNumber == (int)CardsNumbers::Three)
		return "3";
	else if (cardNumber == (int)CardsNumbers::Four)
		return "4";
	else if (cardNumber == (int)CardsNumbers::Five)
		return "5";
	else if (cardNumber == (int)CardsNumbers::Six)
		return "6";
	else if (cardNumber == (int)CardsNumbers::Seven)
		return "7";
	else if (cardNumber == (int)CardsNumbers::Eight)
		return "8";
	else if (cardNumber == (int)CardsNumbers::Nine)
		return "9";
	else if (cardNumber == (int)CardsNumbers::Ten)
		return "10";
	else if (cardNumber == (int)CardsNumbers::Jack)
		return "J";
	else if (cardNumber == (int)CardsNumbers::Queen)
		return "Q";
	else if (cardNumber == (int)CardsNumbers::King)
		return "K";
	else
		return "Invalid card number";
}