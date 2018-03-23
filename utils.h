#pragma once

#include <stdio.h>
#include <iostream>
#include <string>
#include <set>
#include <vector>

#define cardsProSuit 13
#define suits 4
#define cardsInHand 2
#define cardsInFlop 3
#define cardsInRiver 2

typedef std::set<int> hand;

enum CardsNumbers {

	As = 0,
	Two = 1,
	Three = 2,
	Four = 3,
	Five = 4,
	Six = 5,
	Seven = 6,
	Eight = 7,
	Nine = 8,
	Ten = 9,
	Jack = 10,
	Queen = 11,
	King = 12
};

//	1º row is diamonds
//	2º row is clubs
//	3º row is hearts
//	4º row is spades
enum Suit {

	Diamonds = 0,
	Clubs = 1, 
	Hearts = 2,
	Spades = 3
};

std::string cardNumberToString(int cardNumber);
std::string suitToString(int suit);