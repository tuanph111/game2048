#ifndef MAIN_GAME_H_
#define MAIN_GAME_H_

#include "DrawBlock.h"
#include <SDL_ttf.h>
#include <time.h>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <SDL_mixer.h>

#endif

class MainGame{
	long long points = 0;
	vector<vector<Block>> GameMain;
	Block Random[2] = { Block(2),Block(4) };
	const int xp = 25;
	const int yp = SCREEN_HEIGHT / 3;
	Mix_Music *gMusic = NULL;
	Mix_Chunk *gChunk = NULL;
public:
	MainGame();
	~MainGame();
	void DrawMainGame(vector<vector<Block>> &GameMain, SDL_Renderer *renderer);
	void add_new();
	void showGameMain(SDL_Renderer *renderer);
	bool test_oke();
	bool moveLeft();
	bool moveRight();
	bool moveDown();
	bool moveUp();
	void LoadPoint(SDL_Renderer* renderer);
	void runGame(SDL_Renderer *renderer, SDL_Event *e);
	void LoadBackgroundMusic();
	void LoadSoundEffect();
};
