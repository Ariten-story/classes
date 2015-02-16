#ifndef __MONSTER_H__
#define __MONSTER_H__

#include "cocos2d.h"
using namespace cocos2d;

class Monster
{
private:
	Sprite* monsterBody; //몬스터 Sprite.
	Label* labelHP;//에너지바 폰트.

	int maxEnergy; //몬스터 최대HP.
	int curEnergy; //몬스터 현재HP.
	float defensivePower; //몬스터 방어력.
	float speedOfMove; //몬스터 이동속도.
	bool isEnemy; //몬스터 식별.

	//후에 공격력,공격속도,사정거리 등등 만들어야됨.

public:

	Monster();
	virtual ~Monster();
	
	//타입별 몬스터 생성 함수.
	static Monster* createWithType(int Type);
	//몬스터 sprite 설정 함수.
	void setMonsterBody(Sprite* sprite);
	//몬스터 sprite 반환 함수.
	Sprite* getMonsterBody();
	//몬스터 max에너지 설정 함수.
	void setEnergey(float max);
	//몬스터 받는피해처리 함수.
	float subEnergy(float damage);
	//몬스터 식별 설정 함수.
	void setIsEnemy(bool check);
	//몬스터 식별 반환 함수.
	bool getIsEnemy();
	//몬스터 방어력 설정 함수.
	void setDefensivePower(float defensive);
	//몬스터 방어력 반환 함수.
	float getDefensivePower();
	//몬스터 이동속도 설정 함수.
	void setSpeedOfMove(float speed);
	//몬스터 이동속도 반환 함수.
	float getSpeedOfMove();
	//몬스터 에너지바 설정 함수.
	void setHpBar();
	//몬스터 삭제 함수.
	void release();

};
#endif // __MONSTER_H__
