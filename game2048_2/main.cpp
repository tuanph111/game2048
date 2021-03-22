#include <SDL.h>
#include <SDL_ttf.h>
#include <iostream>
#include <time.h>
#include <cstdlib>
#include "MainGame.h"
#include "GameMenu.h"
using namespace std;




int main(int argc, char* argv[]) {
	TTF_Init();
	srand(time(0));
	SDL_Window *window=NULL;
	SDL_Renderer *renderer=NULL;
	initSDL(window, renderer);
	SDL_Event e;
	GameMenu MenuGame;
	if (MenuGame.LoadGameMenu(renderer, window, &e) == true) {
		MainGame mainGame;
		mainGame.runGame(renderer, &e);
		quitSDL(window, renderer);
	}
	return 0;
}

