#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "cocos2d.h"
using namespace cocos2d;

class Player
{
private:
	Player();
	~Player();
	static Player* inst;
	Sprite* playerChar;

public:
	
	static Player* getInstance();
	void createCharacter(Sprite* character);
	//void setCharacterHP();
	//void setCharacterWeapon();
	//void setCharacterArmor();
	void setCharacter(Sprite* character);
	Sprite* getCharacter();
};
#endif // __PLAYER_H__
