#ifndef DRAW_BLOCK_H

#define DRAW_BLOCK_H
#include "Block.h"
#include <SDL.h>
#include <SDL_ttf.h>

#endif

class DrawBlock {
	SDL_Rect block;
public:
	void get_block();
	void showBlock(int const &_x, int const &_y, SDL_Renderer *renderer,Block BlockDraw);
};

