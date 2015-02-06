#ifndef __WEAPON_H__
#define __WEAPON_H__

#include "cocos2d.h"
using namespace cocos2d;

class Weapon
{
private:
	Sprite* weaponBody;
	bool isEnermy;
	float damage;

public:

	Weapon();
	virtual ~Weapon();

	void setweaponBody(Sprite* sprite);
	Sprite* getweaponBody();
	void setDamage(float damage);
	float getDamage();
	void setIsEnermy(bool check);
	bool getIsEnermy();
	void release();

};
#endif // __WEAPON_H__
