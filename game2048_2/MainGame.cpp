#include "MainGame.h"

MainGame::MainGame() {

}
MainGame::~MainGame() {

}

bool MainGame::runGame(SDL_Renderer *renderer, SDL_Event *e,SDL_Window *window) {
	bool running = true;
	bool right = false, left = false, up = false, down = false;
	loadBG(renderer);
	DrawMainGame(renderer);
	LoadBackgroundMusic();
	const int FPS = 120;
	const int FRAME_PERIOD = 1000.0f / FPS;
	Uint32 FrameStart, FrameTime;
	while (running) {
		FrameStart = SDL_GetTicks();
		showGameMain(renderer);
		if (test_oke() == false) {
			running = false;
			break;
		}
		while (SDL_PollEvent(e)) {
			if (e->type == SDL_QUIT) {
				quitSDL(window, renderer);
				running = false;
				loadHighScoreToFile();
				Mix_FreeMusic(gMusic);
				return false;
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
			if (canMoveRight(GameMain) == true) {
				points += moveRight(GameMain);
				add_new();
				LoadSoundEffect(); 
			}
			right = false;
		}
		if (left) {
			if (canMoveLeft(GameMain) == true) {
				points += moveLeft(GameMain);
				add_new();
				LoadSoundEffect();
			}
			left = false;
		}
		if (up) {
			if (canMoveUp(GameMain) == true) {
				points += moveUp(GameMain);
				add_new(); 
				LoadSoundEffect();
			}
			up = false;
		}
		if (down) {
			if (canMoveDown(GameMain) == true) {
				points += moveDown(GameMain);
				add_new(); 
				LoadSoundEffect();
			}
			down = false;
		}
		SDL_RenderPresent(renderer);
		FrameTime = SDL_GetTicks() - FrameStart;
		if (FrameTime < FRAME_PERIOD) {
			SDL_Delay((int)FRAME_PERIOD - FrameTime);
		}
	}
	loadHighScoreToFile();
	Mix_FreeMusic(gMusic);
	return true;
}
void MainGame::DrawMainGame(SDL_Renderer *renderer) {
	loadHighScore(renderer);
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
void MainGame::loadBG(SDL_Renderer *renderer) {
	SDL_Texture *texture = loadTexture("img\\bg.bmp", renderer);
	renderTexture(texture, renderer, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
	SDL_DestroyTexture(texture);
}
void MainGame::showGameMain(SDL_Renderer *renderer) {
	LoadPoint( renderer);
	DrawBlock BlockDraw;
	for (int cols = 0; cols < 4; cols++) {
		for (int rows = 0; rows < 4; rows++) {
			BlockDraw.showBlock(xp + 90 * rows, yp + 90 * cols, renderer,GameMain[cols][rows]);
		}
	}
}
void MainGame::add_new() {
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
bool MainGame::test_oke() {
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
bool MainGame::canMoveRight(vector<vector<Block>> &GameMain) {
	for (short cols = 0; cols < 4; cols++) {
		for (short rows = 0; rows < 3; rows++) {
			if (GameMain[cols][rows].get_value() == GameMain[cols][rows + 1].get_value() && GameMain[cols][rows].get_value() != 0) {
				return true;
			}
		}
	}
	for (short cols = 0; cols < 4; cols++) {
		for (short rows = 3; rows > 0; rows--) {
			if (GameMain[cols][rows].get_value() == 0) {
				for (short index = rows - 1; index >= 0; index--) {
					if (GameMain[cols][index].get_value() != 0) {
						return true;
					}
				}
			}
		}
	}
	return false;
}
int MainGame :: moveRight(vector<vector<Block>> &GameMain) {
	int point = 0;
	for (short cols = 0; cols < 4; cols++) {
		for (short rows = 3; rows > 0; rows--) {
			if (GameMain[cols][rows].get_value() != 0) {
				for (short index = rows - 1; index >= 0; index--) {
					if (GameMain[cols][rows] == GameMain[cols][index]) {
						GameMain[cols][rows] = GameMain[cols][rows] + GameMain[cols][index];
						point += GameMain[cols][rows].get_value();
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
						GameMain[cols][rows] = GameMain[cols][index];
						GameMain[cols][index] = Block(0);
						break;
					}
				}
			}
		}
	}
	return point;
}
bool MainGame::canMoveLeft(vector<vector<Block>> &GameMain) {
	for (short cols = 0; cols < 4; cols++) {
		for (short rows = 3; rows > 0; rows--) {
			if (GameMain[cols][rows].get_value() == GameMain[cols][rows - 1].get_value() && GameMain[cols][rows].get_value() != 0) {
				return true;
			}
		}
	}
	for (short cols = 0; cols < 4; cols++) {
		for (short rows = 0; rows < 3; rows++) {
			if (GameMain[cols][rows].get_value() == 0) {
				for (short index = rows + 1; index < 4; index++) {
					if (GameMain[cols][index].get_value() != 0) return true;
				}
			}
		}
	}
	return false;
}
int MainGame :: moveLeft(vector<vector<Block>> &GameMain) {
	int point=0;
	for (short cols = 0; cols < 4; cols++) {
		for (short rows = 0; rows < 3; rows++) {
			if (GameMain[cols][rows].get_value() != 0) {
				for (short index = rows + 1; index < 4; index++) {
					if (GameMain[cols][rows] == GameMain[cols][index]) {
						GameMain[cols][rows] = GameMain[cols][rows] + GameMain[cols][index];
						point += GameMain[cols][rows].get_value();
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
						GameMain[cols][rows] = GameMain[cols][index];
						GameMain[cols][index] = Block(0);
						break;
					}
				}
			}
		}
	}
	return point;
}
bool MainGame::canMoveUp(vector<vector<Block>> &GameMain) {
	for (short rows = 0; rows < 4; rows++) {
		for (short cols = 0; cols < 3; cols++) {
			if (GameMain[cols][rows].get_value() == GameMain[cols + 1][rows].get_value() && GameMain[cols][rows].get_value() != 0) {
				return true;
			}
		}
	}
	for (short rows = 0; rows < 4; rows++) {
		for (short cols = 0; cols < 3; cols++) {
			if (GameMain[cols][rows].get_value() == 0) {
				for (short index = cols + 1; index < 4; index++) {
					if (GameMain[index][rows].get_value() != 0) {
						return true;
					}
				}
			}
		}
	}
	return false;
}
int MainGame ::moveUp(vector<vector<Block>> &GameMain) {
	int point = 0;
	for (short rows = 0; rows < 4; rows++) {
		for (short cols = 0; cols < 3; cols++) {
			if (GameMain[cols][rows].get_value() != 0) {
				for (short index = cols + 1; index < 4; index++) {
					if (GameMain[cols][rows].get_value() == GameMain[index][rows].get_value()) {
						GameMain[cols][rows] = GameMain[cols][rows] + GameMain[index][rows];
						point += GameMain[cols][rows].get_value();
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
						break;
					}
				}
			}
		}
	}
	return point;
}
bool MainGame::canMoveDown(vector<vector<Block>> &GameMain) {
	for (short rows = 0; rows < 4; rows++) {
		for (short cols = 0; cols < 3; cols++) {
			if (GameMain[cols][rows].get_value() == GameMain[cols + 1][rows].get_value() && GameMain[cols][rows].get_value() != 0) {
				return true;
			}
		}
	}
	for (short rows = 0; rows < 4; rows++) {
		for (short cols = 3; cols > 0; cols--) {
			if (GameMain[cols][rows].get_value() == 0) {
				for (short index = cols - 1; index >= 0; index--) {
					if (GameMain[index][rows].get_value() != 0) {
						return true;
					}
				}
			}
		}
	}
	return false;
}
int MainGame :: moveDown(vector<vector<Block>> &GameMain) {
	int point = 0;
	for (short rows = 0; rows < 4; rows++) {
		for (short cols = 3; cols > 0; cols--) {
			if (GameMain[cols][rows].get_value() != 0) {
				for (short index = cols - 1; index >= 0; index--) {
					if (GameMain[cols][rows] == GameMain[index][rows]) {
						GameMain[cols][rows] = GameMain[cols][rows] + GameMain[index][rows];
						point += GameMain[cols][rows].get_value();
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
						GameMain[cols][rows] = GameMain[index][rows];
						GameMain[index][rows] = Block(0);
						break;
					}
				}
			}
		}
	}
	return point;
}
//load Points
void MainGame :: LoadPoint( SDL_Renderer* renderer) {
	SDL_Rect rect_ = { SCREEN_WIDTH / 4, SCREEN_HEIGHT / 3 - 150,80,80 };
	SDL_SetRenderDrawColor(renderer, 224, 224, 209, 255);
	SDL_RenderFillRect(renderer, &rect_);
	LoadText(renderer, SCREEN_WIDTH / 4 - 150, SCREEN_HEIGHT / 3 - 150, 150, 80, "SCORE:");
	string xau;
	ostringstream convert;
	convert << points;
	xau = convert.str();
	LoadText(renderer, SCREEN_WIDTH / 4, SCREEN_HEIGHT / 3 - 150, 80, 80, xau);
}
// Load Music and Sound Effect
void MainGame::LoadBackgroundMusic() {
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
		std::cout << "Loi";
	}
	gMusic = Mix_LoadMUS("music\\beat_2048.wav");
	if (gMusic == NULL) {
		cout << "Loi";
	}
	if (Mix_PlayingMusic() == 0) {
		Mix_PlayMusic(gMusic, -1);
	}

}
void MainGame::LoadSoundEffect() {
	gChunk = Mix_LoadWAV("music\\4.wav");
	if (gChunk == NULL) {
		cout << "loi:";
	}
	Mix_PlayChannel(-1, gChunk, 0);
	SDL_Delay(200);
	Mix_FreeChunk(gChunk);
}
// Load and Save High Score
void MainGame::loadHighScoreFromFile() {
	ifstream openFile("highScore.txt");
	int dem = 0;
	highScore.resize(5);
	while (dem<5) {
		openFile >> highScore[dem];
		dem++;
	}
	openFile.close();
}
void MainGame::loadHighScoreToFile() {
	highScore[highScore.size() - 1] = points;
	std::sort(highScore.begin(), highScore.begin() + highScore.size(), SoSanh);
	ofstream GhiFile("highScore.txt");
	GhiFile.clear();
	for (short i = 0; i < highScore.size(); i++) {
		GhiFile << highScore[i] << " ";
	}
	GhiFile.close();
}
bool SoSanh(const int &a, const int &b) {
	return a > b;

}
void MainGame::loadHighScore(SDL_Renderer *renderer) {
	loadHighScoreFromFile();
	LoadText(renderer, SCREEN_WIDTH / 2 + 100, SCREEN_HEIGHT / 3 - 150, 200, 80, "HIGH SCORE:");
	for (int i = 0; i < 5; i++) {
		ostringstream convert[2];
		string xau;
		convert[0] << i+1;
		xau = xau + convert[0].str();
		xau = xau + ". ";
		convert[1] << highScore[i];
		xau = xau + convert[1].str();
		LoadText(renderer, SCREEN_WIDTH / 2 + 100 , SCREEN_HEIGHT / 3 - 150 + 80 * (i + 1), 200, 80, xau);
	}
}
void MainGame::LoadText(SDL_Renderer *renderer, const int &xp, const int &yp, const int &w, const int &h,string Text) {
	TTF_Font *font = TTF_OpenFont("font\\font.ttf", 600);
	SDL_Surface *surf = TTF_RenderText_Solid(font, Text.c_str(), SDL_Color{ 153, 153, 153 ,255 });
	SDL_Texture *tex = SDL_CreateTextureFromSurface(renderer, surf);
	renderTexture(tex, renderer, xp, yp, w, h);
	SDL_DestroyTexture(tex);
	SDL_FreeSurface(surf);
	TTF_CloseFont(font);
}

