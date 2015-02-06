#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "cocos2d.h"
#include "Weapon.h"
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

	void setFirstPosition(Sprite* sprite); //무기 생성위치 지정.
	void createWeapon(float t); // 무기 생성.
	void addMonsterList(Weapon* monster); //무기 vector에 추가.
	void WeaponRemover(Node* sender); //무기 액션 완료시 삭제.

};
#endif // __PLAYER_H__
