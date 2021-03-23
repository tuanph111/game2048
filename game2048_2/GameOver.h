#pragma once
#ifndef GAME_OVER_H_
#define GAME_OVER_H_
#include "GameMenu.h"


#endif
class GameOver {
	GameMenu gameover;
	const char* Menu[2] = { "Play Again","Exit" };
	SDL_Rect arrRect[2];
	SDL_Color Black = { 51, 51, 0, 255 };
	SDL_Color White = { 230, 230, 230 ,255 };
	SDL_Rect loadText(SDL_Renderer *renderer, const char* xau, const int &xp, const int &yp,
		const int &w, const int &h, const SDL_Color &TextColor);
	bool CheckForcusWithRect(const int &x, const int &y, const SDL_Rect &_rect);

public:
	bool loadGameOver(SDL_Renderer *renderer, SDL_Event *M_event);
	void loadBackGroundgameOver(SDL_Renderer *renderer);
};
