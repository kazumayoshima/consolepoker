// poker.cpp: define el punto de entrada de la aplicación de consola.
//

#include "utils.h"
#include "poker.h"

int main()
{
	Game game;
	game.addPlayers(1);
	game.initGame();
    return 0;
}

