#pragma once
#include "utils.h"
#include "numberToCardConverter.h"
#include "player.h"
#include <stdlib.h>

class Display {

public:

	static void clearScreen();
	static void showGreetings();
	void showTable(tableHand tableHand);
	void showCards(hand hand);
	void showStatus(Player* player, int totalBet);
	
private:

	void showTableFirstRows();
	void showTableGreenRow();
	void showTableCardSpace(tableHand tableHand);
	void showTableCardNumberRowL();
	void showTableCardSuit();
	void showTableCardNumberRowR();
	void showTableCardBlankRow();
	void showTableLastRows();

	void showCardTop(std::pair<int, int> pair);
	void showCardSuit(int suit);
	void showCardBlank();
	void showCardBottom(std::pair<int, int> pair);
};