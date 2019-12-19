// poker.cpp: define el punto de entrada de la aplicacion de consola.
//

#include "utils.h"
#include "poker.h"
#include "display.h"
#include "game.h"
#include <cstdio>
#include <windows.h>
#include <fcntl.h>
#include <io.h>
#include <stdlib.h>

int main()
{
	// Set display UTF-8 on Windows command prompt. 
	// TODO: Find a safer alternative to chcp
	// info: https://dev.to/mattn/please-stop-hack-chcp-65001-27db
	system("chcp 65001");
	Display::showGreetings();
	Game game;
	game.addPlayers(1);
	game.initGame();
    return 0;
}