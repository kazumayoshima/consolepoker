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

void setConsoleColor(int textColor, int bgColor) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (textColor + (bgColor * 16)));
}

void setConsoleSize(int xSize, int ySize) {
	HANDLE outcon = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_FONT_INFOEX font;
	font.dwFontSize.X = xSize;
	font.dwFontSize.Y = ySize;
	SetCurrentConsoleFontEx(outcon, false, &font);
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
	std::cout << " ________________________________________________________________  " << std::endl;
	std::cout << " ";
	setConsoleColor(WHITE, GREY);
	std::cout << "| \\__________________________________________________________/ |";
	setConsoleColor(WHITE, BLACK);
	std::cout << " " << std::endl;
}

void Display::showTableGreenRow() {

	//	Green rows
	std::cout << " ";
	setConsoleColor(WHITE, GREY);
	std::cout << "| |";
	setConsoleColor(BLACK, GREEN);
	std::cout << "                                                          ";
	
	setConsoleColor(WHITE, GREY);
	std::cout << "| |";
	setConsoleColor(WHITE, BLACK);
	std::cout << " " << std::endl;
}

void Display::showTableCardSpace(tableHand tableHand) {

	//	Rows with cards
	std::cout << " ";
	setConsoleColor(WHITE, GREY);
	std::cout << "| |";
	setConsoleColor(WHITE, GREEN);
	std::cout << "   ";

	for (auto &hand : tableHand) {

		setConsoleColor(WHITE, WHITE);
		std::cout << "       ";
		setConsoleColor(WHITE, GREEN);
		std::cout << "    ";
	}

	for(size_t a=0; a< cardsInTable - tableHand.size(); a++){

		setConsoleColor(LIGHTBLUE, LIGHTBLUE);
		std::cout << "       ";
		setConsoleColor(WHITE, GREEN);
		std::cout << "    ";
	}
	
	setConsoleColor(WHITE, GREY);
	std::cout << "| |";
	setConsoleColor(WHITE, BLACK);
	std::cout << " " << std::endl;;
}

void Display::showTableCardSuit(tableHand tableHand) {

	//	Rows with cards
	std::cout << " ";
	setConsoleColor(WHITE, GREY);
	std::cout << "| |";
	setConsoleColor(WHITE, GREEN);
	std::cout << "   ";

	for (auto &hand : tableHand) {

		auto card = numberToCard(hand);
		switch (card.first) {
			case Suit::Clubs:
				setConsoleColor(BLACK, WHITE);
				std::cout << "   " << CLUB << "   ";
				break;
			case Suit::Diamonds:
				setConsoleColor(RED, WHITE);
				std::cout << "   " << DIAMOND << "   ";
				break;
			case Suit::Hearts:
				setConsoleColor(RED, WHITE);
				std::cout << "   " << HEART << "   ";
				break;
			case Suit::Spades:
				setConsoleColor(BLACK, WHITE);
				std::cout << "   " << SPADE << "   ";
				break;
			default:
				break;
		}
		setConsoleColor(WHITE, GREEN);
		std::cout << "    ";
	}

	for(size_t a=0; a< cardsInTable - tableHand.size(); a++){

		setConsoleColor(LIGHTBLUE, LIGHTBLUE);
		std::cout << "       ";
		setConsoleColor(WHITE, GREEN);
		std::cout << "    ";
	}

	setConsoleColor(WHITE, GREY);
	std::cout << "| |";
	setConsoleColor(WHITE, BLACK);
	std::cout << " " << std::endl;
}

void Display::showTableCardTop(tableHand tableHand) {

	//	Rows with cards
	std::cout << " ";
	setConsoleColor(WHITE, GREY);
	std::cout << "| |";
	setConsoleColor(WHITE, GREEN);
	std::cout << "   ";

	for (auto &hand : tableHand) {

		auto card = numberToCard(hand);
		if(card.first == Suit::Diamonds || card.first == Suit::Hearts)
			setConsoleColor(RED, WHITE);
		else
			setConsoleColor(BLACK, WHITE);
		std::cout << " " << cardNumberToString(card.second) << "    ";
			if (card.second != 9)
		std::cout << " ";
		setConsoleColor(WHITE, GREEN);
		std::cout << "    ";
	}

	for(size_t a=0; a< cardsInTable - tableHand.size(); a++){

		setConsoleColor(LIGHTBLUE, LIGHTBLUE);
		std::cout << "       ";
		setConsoleColor(WHITE, GREEN);
		std::cout << "    ";
	}
	setConsoleColor(WHITE, GREY);
	std::cout << "| |";
	setConsoleColor(WHITE, BLACK);
	std::cout << " " << std::endl;
}

void Display::showTableCardBottom(tableHand tableHand) {

	//	Rows with cards
	std::cout << " ";
	setConsoleColor(WHITE, GREY);
	std::cout << "| |";
	setConsoleColor(WHITE, GREEN);
	std::cout << "   ";

	for (auto &hand : tableHand) {

		auto card = numberToCard(hand);
		if(card.first == Suit::Diamonds || card.first == Suit::Hearts)
			setConsoleColor(RED, WHITE);
		else
			setConsoleColor(BLACK, WHITE);
		if (card.second != 9)
			std::cout << " ";
		std::cout << "    " << cardNumberToString(card.second) << " ";
		setConsoleColor(WHITE, GREEN);
		std::cout << "    ";
	}

	for(size_t a=0; a< cardsInTable - tableHand.size(); a++){

		setConsoleColor(LIGHTBLUE, LIGHTBLUE);
		std::cout << "       ";
		setConsoleColor(WHITE, GREEN);
		std::cout << "    ";
	}
	setConsoleColor(WHITE, GREY);
	std::cout << "| |";
	setConsoleColor(WHITE, BLACK);
	std::cout << " " << std::endl;
}

void Display::showTableLastRows() {

	//	Last rows
	setConsoleColor(WHITE, BLACK);
	std::cout << " ";
	setConsoleColor(WHITE, GREY);
	std::cout << "|_/__________________________________________________________\\_|";
	setConsoleColor(WHITE, BLACK);
	std::cout << " \n" << std::endl;
}

//	This function draws the table in the display
//	TODO: It has to receive the cards of the players and the cards in the table
void Display::showTable(tableHand tableHand) {

	clearScreen();

	/* First table rows */
	showTableFirstRows();

	/* Green table rows */
	showTableGreenRow();
	showTableGreenRow();

	//	Check the cards in the table
	std::vector<std::pair<int, int>> cardsIdx;
	for(auto &card : tableHand)
		cardsIdx.push_back(numberToCard(card));

	/* Cards row*/
	showTableCardTop(tableHand);
	showTableCardSpace(tableHand);
	showTableCardSuit(tableHand);
	showTableCardSpace(tableHand);
	showTableCardBottom(tableHand);

	/* Green table rows */
	showTableGreenRow();
	showTableGreenRow();

	/* Last table rows */
	showTableLastRows();
}

void Display::showCardTop(std::pair<int,int> pair) {

	setConsoleColor(WHITE, BLACK);
	std::cout << " ";
	if (pair.first == Suit::Diamonds || pair.first == Suit::Hearts)
		setConsoleColor(RED, WHITE);
	else
		setConsoleColor(BLACK, WHITE);
	std::cout << " " << cardNumberToString(pair.second) << "      ";
	if (pair.second != 9)
		std::cout << " ";
	setConsoleColor(WHITE, BLACK);
	std::cout << "  ";
}

void Display::showCardBlank() {

	setConsoleColor(WHITE, BLACK);
	std::cout << " ";
	setConsoleColor(WHITE, WHITE);
	std::cout << "         ";
	setConsoleColor(WHITE, BLACK);
	std::cout << "  ";
}

void Display::showCardSuit(int suit) {

	
	std::cout << " ";
	setConsoleSize(15, 15);
	switch (suit) {

	case Suit::Clubs:
		setConsoleColor(BLACK, WHITE);
		std::cout << "    " << CLUB << "    ";
		break;
	case Suit::Diamonds:
		setConsoleColor(RED, WHITE);
		std::cout << "    " << DIAMOND << "    ";
		break;
	case Suit::Hearts:
		setConsoleColor(RED, WHITE);
		std::cout << "    " << HEART << "    ";
		break;
	case Suit::Spades:
		setConsoleColor(BLACK, WHITE);
		std::cout << "    " << SPADE << "    ";
		break;
	default:
		break;
	}
	setConsoleColor(WHITE, BLACK);
	std::cout << "  ";
	
}

void Display::showCardBottom(std::pair<int, int> pair) {

	if (cardNumberToString(pair.second) == "Invalid card number")
		std::cout << pair.second;
	setConsoleColor(WHITE, BLACK);
	std::cout << " ";
	if(pair.first == Suit::Diamonds || pair.first == Suit::Hearts)
		setConsoleColor(RED, WHITE);
	else
		setConsoleColor(BLACK, WHITE);
	if (pair.second != 9)
		std::cout << " ";
	std::cout << "      " << cardNumberToString(pair.second) << " ";
	setConsoleColor(WHITE, BLACK);
	std::cout << "  ";
}

void Display::showCards(hand hand) {

	std::string top;
	std::string middle;
	std::string bottom;

	std::cout << " Your cards in hand: \n" << std::endl;

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
		showCardSuit(cardsIdx[0].first);
		showCardSuit(cardsIdx[1].first);
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

void Display::showStatus(Player* player, int totalBet){

	std::cout << "\n" << std::endl;
	std::cout << " Your money: " << player->getMoney() << std::endl;
	std::cout << " Your bet: " << player->getBet() << std::endl;
	std::cout << " Currently bet: " << player->getCurrentlyBet() << std::endl;
	std::cout << " Total bet: " << totalBet << std::endl;
	getchar();
}



