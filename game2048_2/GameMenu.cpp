#include "GameMenu.h"

bool GameMenu::LoadGameMenu(SDL_Renderer *renderer, SDL_Window *window, SDL_Event *M_event) {
	loadBG_GameMenu(renderer);
	bool running = true;
	while(running) {
		arrRect[0] = loadText(renderer, Menu[0], 270, 300, 200, 80);
		arrRect[1] = loadText(renderer, Menu[1], 270, 400, 100, 80);
		while (SDL_PollEvent(M_event)) {
			if (M_event->type == SDL_QUIT) {
				quitSDL(window, renderer);
				return false;
			}
			if (M_event->key.keysym.sym == SDLK_ESCAPE) {
				quitSDL(window, renderer);
				return false;
			}
			if (M_event->type == SDL_MOUSEBUTTONDOWN) {
				int xm = M_event->button.x;
				int ym = M_event->button.y;
				if (CheckForcusWithRect(xm, ym, arrRect[0])) {
					return true;
				}
				if (CheckForcusWithRect(xm, ym, arrRect[1])) {
					quitSDL(window, renderer);
					return false;
				}
			}
		}
	}
}
void GameMenu::loadBG_GameMenu(SDL_Renderer *renderer) {
	SDL_Texture *tex = loadTexture("D://anh//gamemenu.bmp", renderer);
	renderTexture(tex, renderer, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
	SDL_DestroyTexture(tex);
}
SDL_Rect GameMenu::loadText(SDL_Renderer *renderer, const char* xau, const int &xp, const int &yp,
	const int &w, const int &h) {
	SDL_Rect _rect = { xp, yp, w, h };
	TTF_Font *font = TTF_OpenFont("D://anh//font.ttf", 60);
	SDL_Surface *surf = TTF_RenderText_Solid(font, xau, SDL_Color{ 255,255,255 });
	SDL_Texture *tex = SDL_CreateTextureFromSurface(renderer, surf);
	renderTexture(tex, renderer, xp, yp, w, h);
	SDL_RenderPresent(renderer);
	SDL_DestroyTexture(tex);
	SDL_FreeSurface(surf);
	TTF_CloseFont(font);
	return _rect;
}
bool GameMenu::CheckForcusWithRect(const int &x,const  int &y, const SDL_Rect &_rect) {
	if (x >= _rect.x && x <= _rect.x + _rect.w && y >= _rect.y &&y <= _rect.y + _rect.h) {
		return true;
	}
	return false;
}
