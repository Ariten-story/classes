#ifndef __MONSTER_H__
#define __MONSTER_H__

#include "cocos2d.h"
using namespace cocos2d;

class Monster
{
private:
	Sprite* monsterBody;
	float maxEnergy;
	float curEnergy;
	bool isEnermy;

public:

	Monster();
	virtual ~Monster();
	
	void setMonsterBody(Sprite* sprite);
	Sprite* getMonsterBody();
	void setEnergey(float max);
	float subEnergy(float damage);
	void setIsEnermy(bool check);
	bool getIsEnermy();
	void release();

};
#endif // __MONSTER_H__
