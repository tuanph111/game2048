#include "GameMenu.h"

bool GameMenu::LoadGameMenu(SDL_Renderer *renderer, SDL_Window *window, SDL_Event *M_event) {
	loadBG_GameMenu(renderer);
	bool running = true;
	while(running) {
		while (SDL_PollEvent(M_event)) {
			if (M_event->type == SDL_QUIT) {
				quitSDL(window, renderer);
				return false;
			}
			if (M_event->key.keysym.sym == SDLK_ESCAPE) {
				quitSDL(window, renderer);
				return false;
			}
			if (M_event->type == SDL_MOUSEMOTION) {
				int xm = M_event->motion.x;
				int ym = M_event->motion.y;
				if (CheckForcusWithRect(xm, ym, arrRect[0]) == true) {
					arrRect[0] = loadText(renderer, Menu[0], 270, 300, 200, 80, Black);
				}
				else {
					arrRect[0] = loadText(renderer, Menu[0], 270, 300, 200, 80, White);
				}
				if (CheckForcusWithRect(xm, ym, arrRect[1]) == true) {
					arrRect[1] = loadText(renderer, Menu[1], 270, 400, 100, 80, Black);
				}
				else {
					arrRect[1] = loadText(renderer, Menu[1], 270, 400, 100, 80, White);
				}
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
SDL_Rect GameMenu::loadText(SDL_Renderer *renderer, const char* xau, 
							const int &xp, const int &yp,const int &w, const int &h,const SDL_Color &TextColor) {
	SDL_Rect _rect = { xp, yp, w, h };
	SDL_Texture *tex_1 = loadTexture("D:\\anh\\image.bmp", renderer);
	renderTexture(tex_1, renderer, xp-10, yp - 10, w + 20, h);
	TTF_Font *font = TTF_OpenFont("D://anh//font.ttf", 60);
	SDL_Surface *surf = TTF_RenderText_Solid(font, xau, TextColor);
	SDL_Texture *tex = SDL_CreateTextureFromSurface(renderer, surf);
	renderTexture(tex, renderer, xp, yp, w, h);
	SDL_RenderPresent(renderer);
	SDL_DestroyTexture(tex);
	SDL_FreeSurface(surf);
	SDL_DestroyTexture(tex_1);
	TTF_CloseFont(font);
	return _rect;
}
bool GameMenu::CheckForcusWithRect(const int &x,const  int &y, const SDL_Rect &_rect) {
	if (x >= _rect.x && x <= _rect.x + _rect.w && y >= _rect.y &&y <= _rect.y + _rect.h) {
		return true;
	}
	return false;
}
