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

	As = 1,
	Two = 2,
	Three = 3,
	Four = 4,
	Five = 5,
	Six = 6,
	Seven = 7,
	Eight = 8,
	Nine = 9,
	Ten = 10,
	Jack = 11,
	Queen = 12,
	King = 13
};

//	1º row is diamonds
//	2º row is clubs
//	3º row is hearts
//	4º row is spades
enum Suit {

	Diamonds = 1,
	Clubs = 2, 
	Hearts = 3,
	Spades = 4
};