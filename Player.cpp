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

// 무기 생성위치 지정.
void Player::setFirstPosition(Sprite* sprite)
{
	auto newPos = playerChar->getPosition();
	sprite->setPosition(newPos);
}

 // 무기 생성.
void Player::createWeapon(float t)
{
	float distance = 100.f;
	float speed = 25.0f;
	float lifetime = distance / speed;

	Weapon* weapon = new Weapon();
	auto weaponBody = Sprite::create("Monster1.png");
	weapon->setweaponBody(weaponBody);
	weapon->setDamage(100);
	weapon->setIsEnermy(true);

	this->setFirstPosition(weapon->getweaponBody());
	

	

	
	
}

// 무기 vector에 추가.
void Player::addMonsterList(Weapon* monster)
{

}

 // 무기 액션 완료시 삭제.
void Player::WeaponRemover(Node* sender)
{

}