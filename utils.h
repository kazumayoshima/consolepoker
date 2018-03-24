#pragma once

#if defined(_WIN32) || defined(__MSDOS__)
	#define SPADE   "\x06"
	#define CLUB    "\x05"
	#define HEART   "\x03"
	#define DIAMOND "\x04"
#else
	#define SPADE   "\xE2\x99\xA0"
	#define CLUB    "\xE2\x99\xA3"
	#define HEART   "\xE2\x99\xA5"
	#define DIAMOND "\xE2\x99\xA6"
#endif

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

//	1 row is diamonds
//	2 row is clubs
//	3 row is hearts
//	4 row is spades
enum Suit {

	Diamonds = 0,
	Clubs = 1, 
	Hearts = 2,
	Spades = 3
};

std::string cardNumberToString(int cardNumber);
std::string suitToString(int suit);