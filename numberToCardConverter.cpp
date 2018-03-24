#include "numberToCardConverter.h"
//	The poker deck is structured in diamonds, clubs, hearts and spades.
//	For us the deck is a 4x13 matrix:
//	1 row is diamonds
//	2 row is clubs
//	3 row is hearts
//	4 row is spades
//
//	So a card will be indexed as a number between 1 and 52
//	being 1 the A of diamonds and 52 the king of spades
//
//	The normal sequence of cards will be translated like this:
//	A 2 3 4 5 6 7 8 9 10 J Q K: 1 2 3 4 5 6 7 8 9 10 11 12 13
std::pair<int,int> numberToCard(int number) {

	std::pair <int,int>card;
	card.first = (number / cardsProSuit);
	card.second = (number % cardsProSuit);
	return card;
}