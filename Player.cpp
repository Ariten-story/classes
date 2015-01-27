#include "Player.h"

Player::Player(){}
Player::~Player(){}

Player* Player::inst = nullptr;
Player* Player::getInstance()
{
	if (inst == NULL)
		inst = new Player();
	return inst;
}
void Player::setCharacter(Sprite* character)
{
	PlayerChar = character;
}
Sprite* Player::getCharacter()
{
	return PlayerChar;
}