#include <SDL.h>
#include <SDL_ttf.h>
#include <iostream>
#include <time.h>
#include <cstdlib>
#include "MainGame.h"
#include "GameMenu.h"
#include "GameOver.h"
using namespace std;




int main(int argc, char* argv[]) {
	TTF_Init();
	srand(time(NULL));
	SDL_Window *window=NULL;
	SDL_Renderer *renderer=NULL;
	initSDL(window, renderer);
	SDL_Event e;
	GameMenu MenuGame;
	bool Continue = true;
	while (Continue) {
		if (MenuGame.LoadGameMenu(renderer, window, &e) == true) {
			MainGame mainGame;
			Continue=mainGame.runGame(renderer, &e, window);
			if (!Continue) return 0;
			GameOver gameover;
			Continue=gameover.loadGameOver(renderer, &e, mainGame.get_points());
		}
		else break;
	}
	quitSDL(window, renderer);
	return 0;
}

