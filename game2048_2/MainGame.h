#ifndef MAIN_GAME_H_
#define MAIN_GAME_H_

#include "DrawBlock.h"
#include <SDL_ttf.h>
#include <time.h>
#include <cstdlib>
#include <iostream>
#include <vector>

#endif

class MainGame{
	long long points = 0;
	vector<vector<Block>> GameMain;
	Block Random[2] = { Block(2),Block(4) };
	const int xp = 25;
	const int yp = SCREEN_HEIGHT / 3;
public:
	MainGame();
	~MainGame();
	void DrawMainGame(vector<vector<Block>> &GameMain, SDL_Renderer *renderer);
	void add_new(vector<vector<Block>> &GameMain);
	void showGameMain(vector<vector<Block>> &GameMain, SDL_Renderer *renderer, const long long &points);
	bool test_oke(vector<vector<Block>> &GameMain);
	bool moveLeft(vector<vector<Block>> &GameMain, long long &points);
	bool moveRight(vector<vector<Block>> &GameMain, long long &points);
	bool moveDown(vector<vector<Block>> &GameMain, long long &points);
	bool moveUp(vector<vector<Block>> &GameMain, long long &points);
	void LoadPoint(const long long &points, SDL_Renderer* renderer);
	void runGame(SDL_Renderer *renderer, SDL_Event *e);
};
