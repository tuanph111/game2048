#pragma once
#ifndef GAME_MENU_H_
#define GAME_MENU_H_
#include <SDL_ttf.h>
#include "Block.h"
#endif
class GameMenu {
	const char* Menu[2] = { "Play Game","Exit" };
	SDL_Rect arrRect[2];
	SDL_Rect loadText(SDL_Renderer *renderer, const char* xau, const int &xp, const int &yp,
					const int &w, const int &h);
	bool CheckForcusWithRect(const int &x, const int &y,const SDL_Rect &_rect);
public:
	bool LoadGameMenu(SDL_Renderer *renderer, SDL_Window *window,SDL_Event *M_event);
	void loadBG_GameMenu(SDL_Renderer *renderer);
};