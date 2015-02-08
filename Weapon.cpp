#include "Weapon.h"


Weapon::Weapon()
{
	weaponBody = NULL;
	isEnermy = false;
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

//���� ���� �Լ�.
void Weapon::release()
{
	if (NULL != weaponBody)
	{
		weaponBody->removeFromParentAndCleanup(true);
		weaponBody = NULL;
	}
}

//Ÿ�Ժ� ���� ���� �Լ�.
Weapon* Weapon::createWithType(int type)
{
	const char *fileName;

	Weapon* weapon = new Weapon();

	//�̺κ� ���Ŀ� if~else�� ����.
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

//���� Sprite ���� �Լ�.
void Weapon::setweaponBody(Sprite* sprite)
{
	weaponBody = sprite;
}

//���� Sprite ��ȯ �Լ�.
Sprite* Weapon::getweaponBody()
{
	return weaponBody;
}

//������ ���� �Լ�.
void Weapon::setDamage(float damage)
{
	this->damage = damage;
}

//������ ��ȯ �Լ�.
float Weapon::getDamage()
{
	return damage;
}

//�Ǿƽĺ� ���� �Լ�.
void Weapon::setIsEnermy(bool check)
{
	isEnermy = check;
}

//�Ǿƽĺ� ��ȯ �Լ�.
bool Weapon::getIsEnermy()
{
	return isEnermy;
}

//���ݼӵ� ���� �Լ�.
void Weapon::setSpeedOfAttack(float speed)
{
	speedOfAttack = speed;
}

//���ݼӵ� ��ȯ �Լ�.
float Weapon::getSpeedOfAttack()
{
	return speedOfAttack;
}

//�����Ÿ� ���� �Լ�.
void Weapon::setRange(float xPos, float yPos)
{
	range = new Point();
	this->xPos = xPos;
	this->yPos = yPos;
	range->setPoint(xPos, yPos);
}

//�����Ÿ� ��ȯ �Լ�.
Point* Weapon::getRange()
{
	return range;
}

//��/�ٰŸ� ���� �Լ�.
void Weapon::setIsShortDistance(bool check)
{
	isshortdistance = check;
}

//��/�ٰŸ� ��ȯ �Լ�.
bool Weapon::getIsShortDistance()
{
	return isshortdistance;
}