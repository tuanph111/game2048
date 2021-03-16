#include "Block.h"



Block::Block() {
	value = 0;
}
Block::Block(int _value) {
	value = _value;
}
Block::~Block() {

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