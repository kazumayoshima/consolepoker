// poker.cpp: define el punto de entrada de la aplicacion de consola.
//

#include "utils.h"
#include "poker.h"
#include "display.h"
#include <cstdio>
#include <windows.h>

int main()
{
	SetConsoleOutputCP(850);
	Display::showGreetings();
	getchar();
	Game game;
	game.addPlayers(1);
	game.initGame();
    return 0;
}