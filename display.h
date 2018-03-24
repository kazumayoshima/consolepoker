#pragma once
#include "utils.h"
#include <stdlib.h>
#include "numberToCardConverter.h"
#include <clocale>

class Display {

public:

	static void clearScreen();
	static void showGreetings();
	void showTable();
	void showCards(hand hand);
	
private:

	void showTableFirstRows();
	void showTableGreenRow();
	void showTableCardSpace();
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