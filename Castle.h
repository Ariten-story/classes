#ifndef __CASTLE_H__
#define __CASTLE_H__

#include "cocos2d.h"
using namespace cocos2d;

class Castle
{
private:
	Sprite* EnemyCastleBody; //Enemy Castle Sprite.
	Sprite* FriendCastleBody; //Friend Castle Sprite.
	Sprite* FriendhpBar; //Friend hp Sprite.
	float F_Castle_maxEnergy; //Castle Max HP.
	float F_Castle_curEnergy; //Castle Current HP.


public:

	Castle();
	virtual ~Castle();


	//Make Castle
	static Castle* createCastle(int Type);
	//set Castle
	void Castle::setFCastleBody(Sprite* sprite);
	void Castle::setECastleBody(Sprite* sprite);
	
	//return Castle sprite
	Sprite* getFCastleBody();
	Sprite* getECastleBody();
	//set Castle Energey
	void setEnergey(float max);
	//Castle attacked damage
	float subEnergy(float damage);
	//set F_Castle Hp
	void setHpBar();

};
#endif // __CASTLE_H__
