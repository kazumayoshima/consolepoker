#include "poker.h"

Rank Poker::checkRoyalFlush(hand) {

	return Rank::RoyalFlush;
}
Rank Poker::checkStraightFlush(hand) {

	return Rank::StraightFlush;
}
Rank Poker::checkFourOfAKind(hand) {

	return Rank::FourOfAKind;
}
Rank Poker::checkFullHouse(hand) {

	return Rank::FullHouse;
}
Rank Poker::checkFlush(hand) {

	return Rank::Flush;
}
Rank Poker::checkStraight(hand) {

	return Rank::Straight;
}
Rank Poker::checkThreeOfAKind(hand) {

	return Rank::ThreeOfAKind;
}
Rank Poker::checkTwoPairs(hand) {

	return Rank::TwoPairs;
}
Rank Poker::checkOnePair(hand) {

	return Rank::OnePair;
}
Rank Poker::checkNoPair(hand) {

	return Rank::NoPair;
}
