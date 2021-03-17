#include <SDL.h>
#include <SDL_ttf.h>
#include <iostream>
#include <time.h>
#include <cstdlib>
#include "MainGame.h"
using namespace std;

void loadBG(SDL_Renderer *renderer) {
	SDL_Texture *texture = loadTexture("img\\bg.bmp", renderer);
	renderTexture(texture, renderer, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
	SDL_DestroyTexture(texture);
}



int main(int argc, char* argv[]) {
	TTF_Init();
	srand(time(0));
	SDL_Window *window;
	SDL_Renderer *renderer;
	initSDL(window, renderer);
	SDL_Event e;
	loadBG(renderer);
	MainGame mainGame;
	mainGame.runGame(renderer, &e);
	quitSDL(window, renderer);
	return 0;
}

