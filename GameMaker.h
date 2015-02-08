#ifndef __GAMEMAKER_H__
#define __GANENAKER_H__

#include "cocos2d.h"
#include "Monster.h"
#include "Weapon.h"
#include "Background.h"
using namespace cocos2d;

class GameMaker : public cocos2d::LayerColor
{
private:
	Layer* backgroundLayer;
	Layer* controllerLayer;
	Size winSize;

	Sprite* characterSprite;
	Sprite* rightSprite;
	Sprite* leftSprite;
	Sprite* attackSprite;
	Sprite* skillSprite[4];

	bool isLeftPressed;
	bool isRightPressed;
	bool isAttackPressed;
	bool isSkillPressed;
	bool isRight;

	Background* background;

	std::vector<Monster*> arrMonster;
	std::vector<Weapon*> arrWeapon;
	
public:

	//GameMaker();
	//~GameMaker();

	virtual bool init();

	void createButtons(); //버튼 구현 함수.
	void createBackgroundParallax(); //배경을 만드는 함수.
	void setPositionPlayer(); // 플레이어 위치 설정 함수.

	virtual void onEnter();
	virtual void onExit();
	virtual bool onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *event);
	virtual void onTouchMoved(cocos2d::Touch *touch, cocos2d::Event *event);
	virtual void onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *event);
	virtual void onKeyReleased(cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event *event);

	bool isTouchInside(cocos2d::Sprite* sprite, cocos2d::Touch* touch);

	void startMovingCharacter();
	void stopMovingCharacter();
	void moveCharacter(float t);

	void startAttackCharacter();
	void stopAttackCharacter();
	void attackCharacter(float t);

	void setFirstPositionWeapon(Sprite* sprite); //무기 생성위치 지정.
	void createWeapon(); // 무기 생성.
	void addWeaponList(Weapon* weapon); //무기 vector에 추가.
	void WeaponRemover(Node* sender); //무기 액션 완료시 삭제.

	void moveToCastle(Sprite* sprite, float movetime); //몬스터 성으로 이동.
	void moveToPlayer(Sprite* sprite, float movetime); //몬스터 player쪽으로 이동
	void setFirstPositionMonster(Sprite* sprite); //몬스터 생성위치 지정.
	void createMonster(float t); // 몬스터 생성.
	void addMonsterList(Monster* monster); //몬스터 vector에 추가.
	void monsterRemover(Node* sender); //몬스터 액션 완료시 삭제.
	
	void checkCollision(float t); //충돌 검사

	CREATE_FUNC(GameMaker);
};
#endif // __GANENAKER_H__