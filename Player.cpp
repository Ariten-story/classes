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

void Player::createCharacter(Sprite* character)
{
	playerChar = character;
	auto hpBar = Sprite::create("white-512x512.png");
	hpBar->setTextureRect(Rect(0, 0, 50, 5));
	hpBar->setColor(Color3B::RED);
	Size parentSize = playerChar->getContentSize();
	hpBar->setPosition(Point(parentSize.width / 2.0, parentSize.height + 10));
	playerChar->addChild(hpBar);

	playerChar->retain();
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