#ifndef MAIN_GAME_H_
#define MAIN_GAME_H_

#include "DrawBlock.h"
#include <SDL_ttf.h>
#include <time.h>
#include <cstdlib>
#include <iostream>

#endif

class MainGame{
	long long points = 0;
	Block GameMain[4][4];
	Block Random[2] = { Block(2),Block(4) };
	const int xp = 25;
	const int yp = SCREEN_HEIGHT / 3;
public:
	//MainGame();
	~MainGame();
	void DrawMainGame(Block GameMain[4][4], SDL_Renderer *renderer);
	void add_new(Block GameMain[4][4]);
	void showGameMain(Block GameMain[4][4], SDL_Renderer *renderer, const long long &points);
	bool test_oke(Block GameMain[4][4]);
	bool RightToLeft(Block GameMain[4][4], long long &points);
	bool LeftToRight(Block GameMain[4][4], long long &points);
	bool UpToDown(Block GameMain[4][4], long long &points);
	bool DownToUp(Block Gamemain[4][4], long long &points);
	void LoadPoint(const long long &points, SDL_Renderer* renderer);
	void runGame(SDL_Renderer *renderer, SDL_Event *e);
};
