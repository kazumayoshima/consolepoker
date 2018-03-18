#include "display.h"
#include <windows.h>

void Display::clearScreen() {

	//	NOTE: Maybe It should be taken an alternative to system("cls")
	system("cls");
	std::cout << "                                                                      " << std::endl;
}

void Display::showGreetings() {

	//	TODO: Make the application compatible for UNIX systems (clear command)
	system("cls");
	std::cout << "  _____        _                                              _        " << std::endl;
	std::cout << " |  __ \\      | |                                            | |       " << std::endl;
	std::cout << " | |__) |___  | | __ ___  _ __  ___  ___   _ __   ___   ___  | |  ___  " << std::endl;
	std::cout << " |  ___// _ \\ | |/ // _ \\| '__|/ __|/ _ \\ | '_ \\ / __| / _ \\ | | / _ \\ " << std::endl;
	std::cout << " | |   | (_) ||   <|  __/| |  | (__| (_) || | | |\\__ \\| (_) || ||  __/ " << std::endl;
	std::cout << " |_|    \\___/ |_|\\_\\\\___||_|   \\___|\\___/ |_| |_||___/ \\___/ |_| \\___| " << std::endl;
	std::cout << "                                                                       " << std::endl;
	std::cout << " made by KazumaYoshima" << std::endl;
}

// Ansi Version
enum colors {
	BLACK = 0, BLUE, GREEN, YELLOW, LIGHTBLUE, PURPLE, CYAN, GREY,
	LIGHTGREY, LIGHTRED, LIGHTGREEN, LIGHTYELLOW, RED,
	LIGHTPURPLE, LIGHTCYAN, WHITE, DEFAULT
};

void setconsolecolor(int textColor, int bgColor) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (textColor + (bgColor * 16)));
}

void consolecolor(colors textColor = DEFAULT, colors backgroundColor = DEFAULT) {

	// Set default foreground color
	if (textColor == DEFAULT)
		std::cout << "\x1B[39m";

	// Set bright foreground color
	else if (textColor > GREY) {
		// Set bright mode
		std::cout << "\x1B[1m";
		// Set color
		std::cout << "\x1B[3" << textColor - LIGHTGREY << "m";
	}

	// Set normal foreground color
	else {
		// Set normal mode
		std::cout << "\x1B[22m";
		// Set color
		std::cout << "\x1B[3" << textColor << "m";
	}

	// Set default background color
	if (backgroundColor == DEFAULT)
		std::cout << "\x1B[49m";

	// Set bright background color
	else if (backgroundColor > GREY) {
		// Set bright mode
		std::cout << "\x1B[1m";
		// Set color
		std::cout << "\x1B[4" << backgroundColor - LIGHTGREY << "m";
	}

	// Set normal background color
	else {
		// Set normal mode
		std::cout << "\x1B[22m";
		// Set color
		std::cout << "\x1B[4" << backgroundColor << "m";
	}
}

void Display::showTableFirstRows() {

	//	First rows
	std::cout << "  __________________________________________________________________  " << std::endl;
	std::cout << " |  \\_____________________________________________________________/ | " << std::endl;
}

void Display::showTableGreenRow() {

	//	Green rows
	std::cout << " |  |";
	setconsolecolor(BLACK, GREEN);
	std::cout << "                                                             ";
	setconsolecolor(WHITE, BLACK);
	std::cout << "| | " << std::endl;
}

void Display::showTableCardSpace() {

	//	Rows with cards
	std::cout << " |  |";
	setconsolecolor(WHITE, GREEN);
	std::cout << "   ";
	setconsolecolor(WHITE, LIGHTBLUE);
	std::cout << "       ";
	setconsolecolor(WHITE, GREEN);
	std::cout << "     ";
	setconsolecolor(WHITE, LIGHTBLUE);
	std::cout << "       ";
	setconsolecolor(WHITE, GREEN);
	std::cout << "     ";
	setconsolecolor(WHITE, LIGHTBLUE);
	std::cout << "       ";
	setconsolecolor(WHITE, GREEN);
	std::cout << "     ";
	setconsolecolor(WHITE, LIGHTBLUE);
	std::cout << "       ";
	setconsolecolor(WHITE, GREEN);
	std::cout << "    ";
	setconsolecolor(WHITE, LIGHTBLUE);
	std::cout << "       ";
	setconsolecolor(WHITE, GREEN);
	std::cout << "    ";
	setconsolecolor(WHITE, BLACK);
	std::cout << "| | " << std::endl;
}

void Display::showTableCardNumberRowL() {


}

void Display::showTableCardSuit() {


}

void Display::showTableCardNumberRowR() {


}

void Display::showTableCardBlankRow() {


}

void Display::showTableLastRows() {

	//	Last rows
	setconsolecolor(WHITE, BLACK);
	std::cout << " |__/_____________________________________________________________\\_| " << std::endl;
}

//	This function draws the table in the display
//	TODO: It has to receive the cards of the players and the cards in the table
void Display::showTable() {

	clearScreen();
	showTableFirstRows();
	showTableGreenRow();
	showTableGreenRow();
	showTableCardSpace();
	showTableCardSpace();
	showTableCardSpace();
	showTableCardSpace();
	showTableCardSpace();
	showTableGreenRow();
	showTableGreenRow();
	showTableLastRows();

	//	TODO: This must be removed in the future and set a timer 
	getchar();
}

void Display::showCardTop(std::pair<int,int> pair) {

	setconsolecolor(WHITE, BLACK);
	std::cout << " ";
	setconsolecolor(RED, WHITE);
	std::cout << " " << cardNumberToString(pair.second) << "      ";
	setconsolecolor(WHITE, BLACK);
	std::cout << "  ";
}

void Display::showCardBlank() {

	setconsolecolor(WHITE, BLACK);
	std::cout << " ";
	setconsolecolor(WHITE, WHITE);
	std::cout << "        ";
	setconsolecolor(WHITE, BLACK);
	std::cout << "  ";
}

void Display::showCardSuit(std::pair<int, int> pair) {


}

void Display::showCardBottom(std::pair<int, int> pair) {

	setconsolecolor(WHITE, BLACK);
	std::cout << " ";
	setconsolecolor(RED, WHITE);
	std::cout << "      " << cardNumberToString(pair.second) << " ";
	setconsolecolor(WHITE, BLACK);
	std::cout << "  ";
}

void Display::showCards(hand hand) {

	std::string top;
	std::string middle;
	std::string bottom;

	std::vector<std::pair<int, int>> cardsIdx;
	if(hand.size() == 2){
		for(auto &card : hand)
			cardsIdx.push_back(numberToCard(card));
		showCardTop(cardsIdx[0]);
		showCardTop(cardsIdx[1]);
		std::cout << std::endl;
		showCardBlank();
		showCardBlank();
		std::cout << std::endl;
		showCardBlank();
		showCardBlank();
		std::cout << std::endl;
		showCardBlank();
		showCardBlank();
		std::cout << std::endl;
		showCardBottom(cardsIdx[0]);
		showCardBottom(cardsIdx[1]);
	}
}



