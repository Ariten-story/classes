#include "Player.h"

Player::Player(){}
Player::~Player(){}

Player* Player::inst = NULL;

Player* Player::getInstance()
{
	if (inst == NULL)
		inst = new Player();
	return inst;
}
void Player::setCharacter(Sprite* character)
{
	playerChar = character;
	playerChar->retain();
}
Sprite* Player::getCharacter()
{
	return playerChar;
}