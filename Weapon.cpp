#include "Weapon.h"


Weapon::Weapon()
{
	weaponBody = NULL;
	isEnermy = true;
	isshortdistance = false;
	damage = 0;
	speedOfAttack = 0;
	range = NULL;
}

Weapon::~Weapon()
{
	log("delete weapon");
	release();
}

//무기 삭제 함수.
void Weapon::release()
{
	if (NULL != weaponBody)
	{
		weaponBody->removeFromParentAndCleanup(true);
		weaponBody = NULL;
	}
}

//타입별 무기 생성 함수.
Weapon* Weapon::createWithType(int type)
{
	const char *fileName;

	Weapon* weapon = new Weapon();

	//이부분 추후에 if~else로 구성.
	fileName = "sword.png";
	weapon->setIsShortDistance(false);
	weapon->setDamage(50);
	weapon->setSpeedOfAttack(1.0f);
	weapon->setRange(300,0);
	weapon->setIsEnermy(true);

	auto weaponBody = Sprite::create(fileName);
	weapon->setweaponBody(weaponBody);
	
	return weapon;

	CC_SAFE_DELETE(weapon);
}

//무기 Sprite 설정 함수.
void Weapon::setweaponBody(Sprite* sprite)
{
	weaponBody = sprite;
}

//무기 Sprite 반환 함수.
Sprite* Weapon::getweaponBody()
{
	return weaponBody;
}

//데미지 설정 함수.
void Weapon::setDamage(float damage)
{
	this->damage = damage;
}

//데미지 반환 함수.
float Weapon::getDamage()
{
	return damage;
}

//피아식별 설정 함수.
void Weapon::setIsEnermy(bool check)
{
	isEnermy = check;
}

//피아식별 반환 함수.
bool Weapon::getIsEnermy()
{
	return isEnermy;
}

//공격속도 설정 함수.
void Weapon::setSpeedOfAttack(float speed)
{
	speedOfAttack = speed;
}

//공격속도 반환 함수.
float Weapon::getSpeedOfAttack()
{
	return speedOfAttack;
}

//사정거리 설정 함수.
void Weapon::setRange(float xPos, float yPos)
{
	range = new Point();
	this->xPos = xPos;
	this->yPos = yPos;
	range->setPoint(xPos, yPos);
}

//사정거리 반환 함수.
Point* Weapon::getRange()
{
	return range;
}

//원/근거리 설정 함수.
void Weapon::setIsShortDistance(bool check)
{
	isshortdistance = check;
}

//원/근거리 반환 함수.
bool Weapon::getIsShortDistance()
{
	return isshortdistance;
}