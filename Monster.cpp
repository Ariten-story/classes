#include "Monster.h"

Monster::Monster() : monsterBody(NULL), maxEnergy(100), curEnergy(0), isEnermy(true){}
Monster::~Monster()
{
	release();
}

void Monster::release()
{
	if (monsterBody != NULL)
	{
		monsterBody->removeFromParentAndCleanup(true);
		monsterBody = NULL;
	}
}

void Monster::setEnergey(float max)
{
	maxEnergy = curEnergy = max;
}

float Monster::subEnergy(float damage)
{
	curEnergy -= damage;
	if (curEnergy < 0)
		curEnergy = 0;
	return curEnergy;
}

void Monster::setMonsterBody(Sprite* sprite)
{
	monsterBody = sprite;
}
Sprite* Monster::getMonsterBody()
{
	return monsterBody;
}
void Monster::setIsEnermy(bool check)
{
	isEnermy = check;
}
bool Monster::getIsEnermy()
{
	return isEnermy;
}