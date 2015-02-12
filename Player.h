#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "cocos2d.h"
#define TAG_LABEL_HP 1001

using namespace cocos2d;

class Player : public cocos2d::CCSprite
{
private:
	Player();
	~Player();
	static Player* player;

	Sprite* characterBody;//Player Sprite.
	Label* labelHP;//에너지바 폰트.

	float maxEnergy; //Player 최대HP.
	int curEnergy; //Player 현재HP.
	float defensivePower; //Player 방어력.
	float speedOfMove; //Player 이동속도.
	int weaponType; //Player가 가진 무기 type.
	std::vector<int*> arrStage; //Player의 stage진행 상황.

public:
	
	static Player* getInstance();
	
	//캐릭터 생성 함수.
	void createWithType(int type);
	//캐릭터 Sprite 설정 함수.
	void setCharacter(Sprite* character);
	//캐릭터 Sprite 반환 함수.
	Sprite* getCharacter();
	//플레이어 max에너지 설정 함수.
	void setEnergey(float max);
	//플레이어 받는피해처리 함수.
	float subEnergy(float damage);
	//플레이어 에너지회복처리 함수.
	float plusEnergy(float heal);
	//플레이어 현재 에너지 반환 함수.
	float getEnergey();
	//플레이어 방어력 설정 함수.
	void setDefensivePower(float defensive);
	//플레이어 방어력 반환 함수.
	float getDefensivePower();
	//플레이어 이동속도 설정 함수.
	void setSpeedOfMove(float speed);
	//플레이어 이동속도 반환 함수.
	float getSpeedOfMove();
	//플레이어 에너지바 설정 함수.
	void setHpBar();
	//void setCharacterHP();
	//void setCharacterWeapon();
	//void setCharacterArmor();
};
#endif // __PLAYER_H__
