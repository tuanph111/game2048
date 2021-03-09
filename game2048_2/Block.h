#pragma once
#include "loadTexture.h"
#include <SDL_ttf.h>
#include <string>
#include <sstream>
using namespace std;
class Block{
	SDL_Rect block;
	int value;
public:
	Block();
	Block(int _value);
	~Block();
	int get_value() { return value; }
	void get_block();
	void showBlock(int const &_x,int const &_y,SDL_Renderer *renderer);
	Block operator+(Block &_block);
	bool operator==(Block &_block);

};
Block::Block() {
	value = 0;
}
Block::Block(int _value) {
	value = _value;
}
Block::~Block(){

}
Block Block::operator+(Block &_block) {
		this->value *= 2;
		_block.value = 0;
	return *this;
}
bool Block::operator==(Block &_block) {
	if (this->get_value() == _block.get_value()) {
		return true;
	}
	return false;
}
void Block::get_block() {
	this->block.h = 80;
	this->block.w = 80;
}
void Block::showBlock(int const &_x, int const &_y, SDL_Renderer *renderer) {
	this->block.x = _x;
	this->block.y = _y;
	this->get_block();
	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
	TTF_Font *font = TTF_OpenFont("C:\\Windows\\Fonts\\Arial.ttf", 600);
	//int value to string
	string xau;
	ostringstream convert;
	convert << this->get_value();
	xau = convert.str();
	SDL_Surface *surf = TTF_RenderText_Solid(font, xau.c_str(), SDL_Color{ 255,255,255,255 });
	SDL_Texture *tex = SDL_CreateTextureFromSurface(renderer, surf);
	if (value > 0 && value < 10) {
		SDL_RenderFillRect(renderer, &(this->block));
		renderTexture(tex, renderer, this->block.x + 20, this->block.y + 20, 40, 40);

	}
	else if (value < 100 && value>10) {
		SDL_RenderFillRect(renderer, &(this->block));
		renderTexture(tex, renderer, this->block.x + 15, this->block.y + 20, 50, 40);
	}
	else if (value > 100 && value < 1000) {
		SDL_RenderFillRect(renderer, &(this->block));
		renderTexture(tex, renderer, this->block.x + 10, this->block.y + 15, 60, 50);
	}
	else if (value>1000) {
		SDL_RenderFillRect(renderer, &(this->block));
		renderTexture(tex, renderer, this->block.x, this->block.y + 15, 80, 50);
	}
	else if (value == 0) {
		SDL_SetRenderDrawColor(renderer, 194, 194, 163, 255);
		SDL_RenderFillRect(renderer, &(this->block));
	}
	SDL_RenderPresent(renderer);
	SDL_DestroyTexture(tex);
	SDL_FreeSurface(surf);
	TTF_CloseFont(font);
}

