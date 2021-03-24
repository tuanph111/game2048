#include "GameOver.h"

GameOver::~GameOver() {

}
bool GameOver::loadGameOver(SDL_Renderer *renderer, SDL_Event *M_event, long long points) {
	SDL_RenderClear(renderer);
	loadBackGroundgameOver(renderer,points);
	bool running = true;
	while (running) {
		while (SDL_PollEvent(M_event)) {
			if (M_event->type == SDL_QUIT) {
				return false;
			}
			if (M_event->type == SDL_MOUSEMOTION) {
				int xm = M_event->motion.x;
				int ym = M_event->motion.y;
				if (CheckForcusWithRect(xm, ym, arrRect[0]) == true) {
					arrRect[0] = loadText(renderer, Menu[0], 270, 300, 120, 80, Black);
				}
				else {
					arrRect[0] = loadText(renderer, Menu[0], 270, 300, 120, 80, White);
				}
				if (CheckForcusWithRect(xm, ym, arrRect[1]) == true) {
					arrRect[1] = loadText(renderer, Menu[1], 270, 380, 100, 80, Black);
				}
				else {
					arrRect[1] = loadText(renderer, Menu[1], 270, 380, 100, 80, White);
				}
			}
			if (M_event->type == SDL_MOUSEBUTTONDOWN) {
				int xm = M_event->button.x;
				int ym = M_event->button.y;
				if (CheckForcusWithRect(xm, ym, arrRect[0])) {
					return true;
				}
				if (CheckForcusWithRect(xm, ym, arrRect[1])) {
					return false;
				}
			}
		}
	}
}
void GameOver::loadBackGroundgameOver(SDL_Renderer *renderer,long long points) {
	string xau;
	ostringstream convert;
	convert << points;
	xau = convert.str();
	xau = "Score:" + xau;
	SDL_Texture *tex = loadTexture("D://anh//gameover.bmp", renderer);
	renderTexture(tex, renderer, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
	arrRect[2] = loadText(renderer, xau.c_str(), 200, 200, 300, 100, White);
	arrRect[0] = loadText(renderer, Menu[0], 270, 300, 120, 80, White);
	arrRect[1] = loadText(renderer, Menu[1], 270, 380, 100, 80, White);
	SDL_RenderPresent(renderer);
	SDL_DestroyTexture(tex);
}
SDL_Rect GameOver::loadText(SDL_Renderer *renderer, const char* xau, const int &xp, const int &yp,
	const int &w, const int &h, const SDL_Color &TextColor) {
	SDL_Rect _rect = { xp, yp, w, h };
	TTF_Font *font = TTF_OpenFont("D://anh//font.ttf", 60);
	SDL_Surface *surf = TTF_RenderText_Solid(font, xau, TextColor);
	SDL_Texture *tex = SDL_CreateTextureFromSurface(renderer, surf);
	renderTexture(tex, renderer, xp, yp, w, h);
	SDL_RenderPresent(renderer);
	SDL_DestroyTexture(tex);
	SDL_FreeSurface(surf);
	TTF_CloseFont(font);
	return _rect;
}
bool GameOver::CheckForcusWithRect(const int &x, const int &y, const SDL_Rect &_rect) {
	if (x >= _rect.x && x <= _rect.x + _rect.w && y >= _rect.y &&y <= _rect.y + _rect.h) {
		return true;
	}
	return false;
}