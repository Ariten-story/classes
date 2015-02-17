#ifndef __CASTLE_H__
#define __CASTLE_H__

#include "cocos2d.h"
using namespace cocos2d;

class Castle
{
private:
	Sprite* castleBody; //Enemy Castle Sprite.
	Label* labelHP;//에너지바 폰트.

	int maxEnergy; //Castle Max HP.
	int curEnergy; //Castle Current HP.
	bool isEnemyCastle;

public:

	Castle();
	virtual ~Castle();

	//Make Castle
	static Castle* createCastle(int Type);
	//set Castle
	void Castle::setCastleBody(Sprite* sprite);

	//return Castle sprite
	Sprite* getCastleBody();
	//set Castle Energey
	void setEnergey(float max);
	//Castle attacked damage
	float subEnergy(float damage);
	//set Castle Hp
	void setHpBar();
	//set isEnemyCastle
	void setIsEnemy(bool Enemy);
	//get isEnemyCastle
	bool getIsEnemy();
	//delete Castle
	void release();
};
#endif // __CASTLE_H__
