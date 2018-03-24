#include "poker.h"

Rank Poker::processHand(hand hand) {

	if (checkRoyalFlush(hand) != Rank::Invalid)
		return Rank::RoyalFlush;
	else if (checkStraightFlush(hand) != Rank::Invalid)
		return Rank::StraightFlush;
	else if (checkFourOfAKind(hand) != Rank::Invalid)
		return Rank::FourOfAKind;
	else if (checkFullHouse(hand) != Rank::Invalid)
		return Rank::FullHouse;
	else if (checkFlush(hand) != Rank::Invalid)
		return Rank::Flush;
	else if (checkStraight(hand) != Rank::Invalid)
		return Rank::Straight;
	else if (checkThreeOfAKind(hand) != Rank::Invalid)
		return Rank::ThreeOfAKind;
	else if (checkTwoPairs(hand) != Rank::Invalid)
		return Rank::TwoPairs;
	else if (checkOnePair(hand) != Rank::Invalid)
		return Rank::OnePair;
	else if (checkNoPair(hand) != Rank::Invalid)
		return Rank::NoPair;
	else
		return Rank::Invalid;
}

//	Transform the index cards into combinations of suits and numbers
Poker::combinations Poker::getSuitNumberCombination(hand hand) {

	combinations combo;
	for (auto &card : hand)
		combo.push_back(numberToCard(card));
	return combo;
}

Rank Poker::checkRoyalFlush(hand hand) {

	combinations combo = getSuitNumberCombination(hand);
	
	//	Save the result of each suit
	std::map<int, int> result;
	for (auto a : combo)
		if ((a.second <= 13 && a.second >= 10) || a.second == 1)
			result[a.first]++;

	//	If the result was 5, return success
	for(auto &r: result)
		if(r.second == 5)
			return Rank::RoyalFlush;
	
	return Rank::Invalid;
}

Rank Poker::checkStraightFlush(hand hand) {

	combinations combo = getSuitNumberCombination(hand);
	return Rank::StraightFlush;
}
Rank Poker::checkFourOfAKind(hand hand) {

	combinations combo = getSuitNumberCombination(hand);
	return Rank::FourOfAKind;
}
Rank Poker::checkFullHouse(hand hand) {

	combinations combo = getSuitNumberCombination(hand);
	return Rank::FullHouse;
}
Rank Poker::checkFlush(hand hand) {

	combinations combo = getSuitNumberCombination(hand);
	return Rank::Flush;
}
Rank Poker::checkStraight(hand hand) {

	combinations combo = getSuitNumberCombination(hand);
	return Rank::Straight;
}
Rank Poker::checkThreeOfAKind(hand hand) {

	combinations combo = getSuitNumberCombination(hand);
	return Rank::ThreeOfAKind;
}
Rank Poker::checkTwoPairs(hand hand) {

	combinations combo = getSuitNumberCombination(hand);
	return Rank::TwoPairs;
}
Rank Poker::checkOnePair(hand hand) {

	combinations combo = getSuitNumberCombination(hand);
	return Rank::OnePair;
}
Rank Poker::checkNoPair(hand hand) {

	combinations combo = getSuitNumberCombination(hand);
	return Rank::NoPair;
}
