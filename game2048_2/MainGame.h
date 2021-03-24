#ifndef MAIN_GAME_H_
#define MAIN_GAME_H_

#include "DrawBlock.h"
#include <SDL_ttf.h>
#include <time.h>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <SDL_mixer.h>
#include <fstream>
#include <algorithm>

#endif
bool SoSanh(const int &a, const int &b);
class MainGame{
	int points = 0;
	vector<vector<Block>> GameMain;
	vector<int> highScore;
	Block Random[2] = { Block(2),Block(4) };
	const int xp = 25;
	const int yp = SCREEN_HEIGHT / 3;
	Mix_Music *gMusic = NULL;
	Mix_Chunk *gChunk = NULL;
	void loadHighScore(SDL_Renderer *renderer);
	void loadHighScoreFromFile();
	void loadHighScoreToFile();
	void LoadText(SDL_Renderer *renderer,const int &xp, const int &yp, const int &w, const int &h, string Text);
public:
	MainGame();
	~MainGame();
	void loadBG(SDL_Renderer *renderer);
	void DrawMainGame(SDL_Renderer *renderer);
	void add_new();
	void showGameMain(SDL_Renderer *renderer);
	bool test_oke();
	bool moveLeft();
	bool moveRight();
	bool moveDown();
	bool moveUp();
	void LoadPoint(SDL_Renderer* renderer);
	bool runGame(SDL_Renderer *renderer, SDL_Event *e,SDL_Window *window);
	void LoadBackgroundMusic();
	void LoadSoundEffect();
	long long get_points() { return points; };
};
