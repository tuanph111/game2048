#pragma once
#ifndef BLOCK_H
#define BLOCK_H

#include "loadTexture.h"
#include <SDL_ttf.h>
#include <string>
#include <sstream>


#endif
using namespace std;
class Block{
	int value;
public:
	Block();
	Block(int _value);
	~Block();
	int get_value() { return value; }
	Block operator+(Block &_block);
	bool operator==(Block &_block);

};