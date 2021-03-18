#include "DrawBlock.h"

void DrawBlock::showBlock(int const &_x, int const &_y, SDL_Renderer *renderer,Block BlockDraw) {
	int value = BlockDraw.get_value();
	SDL_Texture *tex=NULL;
	this->block.x = _x;
	this->block.y = _y;
	this->block.w = 80;
	this->block.h = 80;
	if (value == 0) {
		SDL_SetRenderDrawColor(renderer, 194, 194, 163, 255);
		SDL_RenderFillRect(renderer, &(this->block));
	}
	else if (value == 2) {
		tex = loadTexture("img\\2.bmp", renderer);
		renderTexture(tex, renderer, _x, _y, 80, 80);
		SDL_RenderPresent(renderer);
	}
	else if (value == 4) {
		tex = loadTexture("img\\4.bmp", renderer);
		renderTexture(tex, renderer, _x, _y, 80, 80);
		SDL_RenderPresent(renderer);
	}
	else if (value == 8) {
		tex = loadTexture("img\\8.bmp", renderer);
		renderTexture(tex, renderer, _x, _y, 80, 80);
		SDL_RenderPresent(renderer);
	} 
	else if (value == 16) {
		tex = loadTexture("img\\16.bmp", renderer);
		renderTexture(tex, renderer, _x, _y, 80, 80);
		SDL_RenderPresent(renderer);
	}
	else if (value == 32) {
		tex = loadTexture("img\\32.bmp", renderer);
		renderTexture(tex, renderer, _x, _y, 80, 80);
		SDL_RenderPresent(renderer);
	}
	else if (value == 64) {
		tex = loadTexture("img\\64.bmp", renderer);
		renderTexture(tex, renderer, _x, _y, 80, 80);
		SDL_RenderPresent(renderer);
	}
	else if (value == 128) {
		tex = loadTexture("img\\128.bmp", renderer);
		renderTexture(tex, renderer, _x, _y, 80, 80);
		SDL_RenderPresent(renderer);
	}
	else if (value == 256) {
		tex = loadTexture("img\\256.bmp", renderer);
		renderTexture(tex, renderer, _x, _y, 80, 80);
		SDL_RenderPresent(renderer);
	}
	else if (value == 512) {
		tex = loadTexture("img\\512.bmp", renderer);
		renderTexture(tex, renderer, _x, _y, 80, 80);
		SDL_RenderPresent(renderer);
	}
	else if (value == 1024) {
		tex = loadTexture("img\\1024.bmp", renderer);
		renderTexture(tex, renderer, _x, _y, 80, 80);
		SDL_RenderPresent(renderer);
	}
	else if (value == 2048) {
		tex = loadTexture("img\\2048.bmp", renderer);
		renderTexture(tex, renderer, _x, _y, 80, 80);
		SDL_RenderPresent(renderer);
	}
	else if (value > 2048) {
		string xau;
		ostringstream convert;
		convert << value;
		xau = convert.str();
		TTF_Font *font = TTF_OpenFont("font\\font.ttf", 60);
		SDL_Surface *surf = TTF_RenderText_Solid(font, xau.c_str(), SDL_Color{ 255,255,255,255 });
		SDL_Texture *tex_1 = SDL_CreateTextureFromSurface(renderer, surf);
		SDL_SetRenderDrawColor(renderer, 0, 204, 0, 255);
		SDL_RenderFillRect(renderer, &(this->block));
		renderTexture(tex_1, renderer, this->block.x+3, this->block.y + 20, 74, 40);
		SDL_RenderPresent(renderer);
		SDL_DestroyTexture(tex_1);
		SDL_FreeSurface(surf);
		TTF_CloseFont(font);

	}
	SDL_DestroyTexture(tex);
}