#include "Weapon.h"


Weapon::Weapon() : weaponBody(NULL), isEnermy(false), damage(0){}

Weapon::~Weapon()
{
	release();
}

void Weapon::release()
{
	if (NULL != weaponBody)
	{
		weaponBody->removeFromParentAndCleanup(true);
		weaponBody = NULL;
	}
}
void Weapon::setweaponBody(Sprite* sprite)
{
	weaponBody = sprite;
}
Sprite* Weapon::getweaponBody()
{
	return weaponBody;
}
void Weapon::setDamage(float damage)
{
	this->damage = damage;
}
float Weapon::getDamage()
{
	return damage;
}
void Weapon::setIsEnermy(bool check)
{
	isEnermy = check;
}
bool Weapon::getIsEnermy()
{
	return isEnermy;
}