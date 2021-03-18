#include "MainGame.h"

MainGame::MainGame() {

}
MainGame::~MainGame() {

}

void MainGame::runGame(SDL_Renderer *renderer, SDL_Event *e) {
	bool running = true;
	bool right = false, left = false, up = false, down = false;
	DrawMainGame(GameMain, renderer);
	while (running) {
		SDL_Delay(10);
		showGameMain(GameMain, renderer, points);
		if (test_oke(GameMain) == false) {
			running = false;
			break;
		}
		while (SDL_PollEvent(e)) {
			if (e->type == SDL_QUIT) {
				running = false;
				break;
			}
			if (e->type == SDL_KEYDOWN) {
				if (e->key.keysym.sym == SDLK_ESCAPE) running = false;
				if (e->key.keysym.sym == SDLK_a) left = true;
				if (e->key.keysym.sym == SDLK_w) up = true;
				if (e->key.keysym.sym == SDLK_d) right = true;
				if (e->key.keysym.sym == SDLK_s) down = true;
				break;
			}
		}
		if (right) {
			if (moveRight(GameMain, points) == true) add_new(GameMain);
			right = false;
		}
		if (left) {
			if (moveLeft(GameMain, points) == true) add_new(GameMain);
			left = false;
		}
		if (up) {
			if (moveUp(GameMain, points) == true) add_new(GameMain);
			up = false;
		}
		if (down) {
			if (moveDown(GameMain, points) == true) add_new(GameMain);
			down = false;
		}
		SDL_RenderPresent(renderer);
	}
}
void MainGame::DrawMainGame(vector<vector<Block>> &GameMain, SDL_Renderer *renderer) {
	for (int cols = 0; cols < 4; cols++) {
		GameMain.resize(4 * 4);
		for (int rows = 0; rows < 4; rows++) {
			Block m_block = Block(0);
			GameMain[cols].push_back(m_block);
		}
	}
	for (int index = 0; index < 2; index++) {
		int a = rand() % 4;
		int b = rand() % 4;
		if (GameMain[a][b].get_value() == 0) {
			GameMain[a][b] = Random[rand() % 2];
		}
		else {
			index--;
		}
	}
}
void MainGame::showGameMain(vector<vector<Block>> &GameMain, SDL_Renderer *renderer, const long long &points) {
	LoadPoint(points, renderer);
	DrawBlock BlockDraw;
	for (int cols = 0; cols < 4; cols++) {
		for (int rows = 0; rows < 4; rows++) {
			BlockDraw.showBlock(xp + 90 * rows, yp + 90 * cols, renderer,GameMain[cols][rows]);
		}
	}
}
void MainGame::add_new(vector<vector<Block>> &GameMain) {
	bool oke = true;
	while (oke) {
		int a = rand() % 4;
		int b = rand() % 4;
		if (GameMain[a][b].get_value() == 0) {
			GameMain[a][b] = Random[rand() % 2];
			oke = false;
		}
	}
}
bool MainGame::test_oke(vector<vector<Block>> &GameMain) {
	for (int cols = 0; cols < 4; cols++) {
		for (int rows = 0; rows < 4; rows++) {
			if (GameMain[cols][rows].get_value() == 0) return true;
		}
	}
	for (int cols = 0; cols < 4; cols++) {
		for (int rows = 0; rows < 3; rows++) {
			if (GameMain[cols][rows].get_value() == GameMain[cols][rows + 1].get_value()) return true;
		}
	}
	for (int rows = 0; rows < 4; rows++) {
		for (int cols = 0; cols < 3; cols++) {
			if (GameMain[cols][rows].get_value() == GameMain[cols + 1][rows].get_value()) return true;
		}
	}
	return false;
}
bool MainGame :: moveRight(vector<vector<Block>> &GameMain, long long &points) {
	bool success = false;
	for (short cols = 0; cols < 4; cols++) {
		for (short rows = 3; rows > 0; rows--) {
			if (GameMain[cols][rows].get_value() != 0) {
				for (short index = rows - 1; index >= 0; index--) {
					if (GameMain[cols][rows] == GameMain[cols][index]) {
						GameMain[cols][rows] = GameMain[cols][rows] + GameMain[cols][index];
						points += GameMain[cols][index].get_value();
						success = true;
						break;
					}
					if (GameMain[cols][rows].get_value() != GameMain[cols][index].get_value() && GameMain[cols][index].get_value() != 0) {
						break;
					}
				}
			}
		}
	}
	for (short cols = 0; cols < 4; cols++) {
		for (short rows = 3; rows > 0; rows--) {
			if (GameMain[cols][rows].get_value() == 0) {
				for (short index = rows - 1; index >= 0; index--) {
					if (GameMain[cols][index].get_value() != 0) {
						success = true;
						GameMain[cols][rows] = GameMain[cols][index];
						GameMain[cols][index] = Block(0);
						break;
					}
				}
			}
		}
	}
	return success;
}
bool MainGame :: moveLeft(vector<vector<Block>> &GameMain, long long &points) {
	bool success = false;
	for (short cols = 0; cols < 4; cols++) {
		for (short rows = 0; rows < 3; rows++) {
			if (GameMain[cols][rows].get_value() != 0) {
				for (short index = rows + 1; index < 4; index++) {
					if (GameMain[cols][rows] == GameMain[cols][index]) {
						success = true;
						GameMain[cols][rows] = GameMain[cols][rows] + GameMain[cols][index];
						points += GameMain[cols][rows].get_value();
						break;
					}
					if (GameMain[cols][rows].get_value() != GameMain[cols][index].get_value() && GameMain[cols][index].get_value() != 0) {
						break;
					}
				}
			}
		}
	}
	for (short cols = 0; cols < 4; cols++) {
		for (short rows = 0; rows < 3; rows++) {
			if (GameMain[cols][rows].get_value() == 0) {
				for (short index = rows + 1; index < 4; index++) {
					if (GameMain[cols][index].get_value() != 0) {
						success = true;
						GameMain[cols][rows] = GameMain[cols][index];
						GameMain[cols][index] = Block(0);
						break;
					}
				}
			}
		}
	}
	return success;
}
bool MainGame ::moveUp(vector<vector<Block>> &GameMain, long long &points) {
	bool success = false;
	for (short rows = 0; rows < 4; rows++) {
		for (short cols = 0; cols < 3; cols++) {
			if (GameMain[cols][rows].get_value() != 0) {
				for (short index = cols + 1; index < 4; index++) {
					if (GameMain[cols][rows].get_value() == GameMain[index][rows].get_value()) {
						success = true;
						GameMain[cols][rows] = GameMain[cols][rows] + GameMain[index][rows];
						points += GameMain[cols][rows].get_value();
						break;
					}
					if (GameMain[cols][rows].get_value() != GameMain[index][rows].get_value() && GameMain[index][rows].get_value() != 0) {
						break;
					}
				}
			}
		}
	}
	for (short rows = 0; rows < 4; rows++) {
		for (short cols = 0; cols < 3; cols++) {
			if (GameMain[cols][rows].get_value() == 0) {
				for (short index = cols + 1; index < 4; index++) {
					if (GameMain[index][rows].get_value() != 0) {
						GameMain[cols][rows] = GameMain[index][rows];
						GameMain[index][rows] = Block(0);
						success = true;
						break;
					}
				}
			}
		}
	}
	return success;
}
bool MainGame :: moveDown(vector<vector<Block>> &GameMain, long long &points) {
	bool success = false;
	for (short rows = 0; rows < 4; rows++) {
		for (short cols = 3; cols > 0; cols--) {
			if (GameMain[cols][rows].get_value() != 0) {
				for (short index = cols - 1; index >= 0; index--) {
					if (GameMain[cols][rows] == GameMain[index][rows]) {
						success = true;
						GameMain[cols][rows] = GameMain[cols][rows] + GameMain[index][rows];
						points += GameMain[cols][rows].get_value();
						break;
					}
					if (GameMain[cols][rows].get_value() != GameMain[index][rows].get_value() && GameMain[index][rows].get_value() != 0) break;
				}
			}
		}
	}
	for (short rows = 0; rows < 4; rows++) {
		for (short cols = 3; cols > 0; cols--) {
			if (GameMain[cols][rows].get_value() == 0) {
				for (short index = cols - 1; index >= 0; index--) {
					if (GameMain[index][rows].get_value() != 0) {
						success = true;
						GameMain[cols][rows] = GameMain[index][rows];
						GameMain[index][rows] = Block(0);
						break;
					}
				}
			}
		}
	}
	return success;
}
void MainGame :: LoadPoint(const long long &points, SDL_Renderer* renderer) {
	TTF_Font *font = TTF_OpenFont("font\\font.ttf", 600);
	string xau;
	SDL_Rect rect_ = { SCREEN_WIDTH / 4, SCREEN_HEIGHT / 3 - 150,80,80 };
	SDL_SetRenderDrawColor(renderer, 224, 224, 209, 255);
	SDL_RenderFillRect(renderer, &rect_);
	SDL_Surface *surf = TTF_RenderText_Solid(font, "SCORE:", SDL_Color{ 153, 153, 153 ,255 });
	SDL_Texture *tex = SDL_CreateTextureFromSurface(renderer, surf);
	renderTexture(tex, renderer, SCREEN_WIDTH / 4 - 150, SCREEN_HEIGHT / 3 - 150, 150, 80);
	ostringstream convert;
	convert << points;
	xau = convert.str();
	SDL_Surface *surf_1 = TTF_RenderText_Solid(font, xau.c_str(), SDL_Color{ 153, 153, 153 ,255 });
	SDL_Texture *tex_1 = SDL_CreateTextureFromSurface(renderer, surf_1);
	renderTexture(tex_1, renderer, SCREEN_WIDTH/4, SCREEN_HEIGHT/3-150, 80, 80);
	TTF_CloseFont(font);
	SDL_FreeSurface(surf);
	SDL_DestroyTexture(tex);
	SDL_FreeSurface(surf_1);
	SDL_DestroyTexture(tex_1);
}
