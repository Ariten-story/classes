#ifndef __WEAPON_H__
#define __WEAPON_H__

#include "cocos2d.h"
using namespace cocos2d;

class Weapon : public cocos2d::CCSprite
{
private:
	Sprite* weaponBody; //무기 이미지
	bool isshortdistance; //근거리,원거리 체크
	bool isEnermy; //피아 식별
	float damage; //무기 데미지
	float speedOfAttack; //무기 공속
	Point* range; //무기 사정거리

public:
	float xPos, yPos;

	Weapon();
	virtual ~Weapon();

	//타입별 무기 생성 함수.
	static Weapon* createWithType(int type);
	//무기 Sprite 설정 함수.
	void setweaponBody(Sprite* sprite);
	//무기 Sprite 반환 함수.
	Sprite* getweaponBody();
	//데미지 설정 함수.
	void setDamage(float damage);
	//데미지 반환 함수.
	float getDamage();
	//피아식별 설정 함수.
	void setIsEnermy(bool check);
	//피아식별 반환 함수.
	bool getIsEnermy();
	//공격속도 설정 함수.
	void setSpeedOfAttack(float speed);
	//공격속도 반환 함수.
	float getSpeedOfAttack();
	//사정거리 설정 함수.
	void setRange(float xPos, float yPos);
	//사정거리 반환 함수.
	Point* getRange();
	//원/근거리 설정 함수.
	void setIsShortDistance(bool check);
	//원/근거리 반환 함수.
	bool getIsShortDistance();
	//무기 삭제 함수.
	void release();
};
#endif // __WEAPON_H__
