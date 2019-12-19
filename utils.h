#pragma once

#if defined(_WIN32) || defined(__MSDOS__)
#define SPADE   "\u2660"
#define CLUB    "\u2663"
#define HEART   "\u2665"
#define DIAMOND "\u2666"
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
#include <windows.h>

#define cardsProSuit 13
#define suits 4
#define cardsInHand 2
#define cardsInFlop 3
#define cardsInRiver 1
#define cardsInTurn 1
#define cardsInTable 5

typedef std::set<int> hand;
typedef std::vector<int> tableHand;
typedef struct console_info {
	ULONG cbSize;
	DWORD nFont;
	COORD dwFontSize;
	UINT  FontFamily;
	UINT  FontWeight;
	WCHAR FaceName[LF_FACESIZE];
} console_info;

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
	Hearts = 1, 
	Clubs = 2,
	Spades = 3
};

std::string cardNumberToString(int cardNumber);
std::string suitToString(int suit);