#ifndef __GAMEMAKER_H__
#define __GANENAKER_H__

#include "cocos2d.h"
#include "Monster.h"
#include "Weapon.h"
#include "Background.h"
#include "INNScene.h"
#include "PopScene.h"

using namespace cocos2d;

class GameMaker : public cocos2d::LayerColor
{
private:
	Layer* backgroundLayer;
	Layer* controllerLayer;
	Size winSize;

	CCProgressTimer* _progressTimeBar;
	Sprite* characterSprite;
	Sprite* Fcastle;
	Sprite* Ecastle;
	Sprite* rightSprite;
	Sprite* leftSprite;
	Sprite* attackSprite;
	Sprite* skillSprite[4];

	int _gameTime;

	bool isLeftPressed;
	bool isRightPressed;
	bool isAttackPressed;
	bool isSkillPressed;
	bool isRight;

	std::vector<Monster*> arrMonster;
	std::vector<Weapon*> arrWeapon;
	
public:

	//GameMaker();
	//~GameMaker();

	virtual bool init();

	//버튼 구현 함수.
	void createButtons(); 
	//배경을 만드는 함수.
	void createBackgroundParallax(); 
	// 플레이어 위치 설정 함수.
	void setPositionPlayer(); 
	//터치구현 함수들.
	virtual void onEnter();
	virtual void onExit();
	virtual void onTouchesBegan(const std::vector<cocos2d::Touch*>& touches, cocos2d::Event *event);
	virtual void onTouchesMoved(const std::vector<cocos2d::Touch*>& touches, cocos2d::Event *event);
	virtual void onTouchesEnded(const std::vector<cocos2d::Touch*>& touches, cocos2d::Event *event);
	//안드로이드 back버튼 구현 함수.
	virtual void onKeyReleased(cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event *event);
	//터치 확인 함수.
	bool isTouchInside(cocos2d::Sprite* sprite, cocos2d::Touch* touch);
	//bool isTouchInside(cocos2d::Sprite* sprite, cocos2d::Touch* touch);
	
	//캐릭터 움직임 시작 함수.
	void startMovingCharacter();
	//캐릭터 움직임 중지 함수.
	void stopMovingCharacter();
	//캐릭터 움직임 구현 함수.
	void moveCharacter(float t);
	//캐릭터 공격 시작 함수.
	void startAttackCharacter();
	//캐릭터 공격 중지 함수.
	void stopAttackCharacter();
	//캐릭터 공격 구현 함수.
	void attackCharacter(float t);
	//캐릭터 피해발생시 움직임.
	void jumpToBack(Sprite* sprite, Point pos);
	//무기 생성위치 지정.
	void setFirstPositionWeapon(Sprite* sprite); 
	// 무기 생성.
	void createWeapon(); 
	//무기 vector에 추가.
	void addWeaponList(Weapon* weapon); 
	//무기 액션 완료시 삭제.
	void WeaponRemover(Node* sender); 
	//몬스터 성으로 이동.
	void moveToCastle(Sprite* sprite, float movetime); 
	//몬스터 player쪽으로 이동
	void moveToPlayer(Sprite* sprite, float movetime); 
	//몬스터 생성위치 지정.
	void setFirstPositionMonster(Sprite* sprite,int switch_on);
	// 몬스터 생성.
	void createMonster(float t); 
	//몬스터 vector에 추가.
	void addMonsterList(Monster* monster); 
	//몬스터 액션 완료시 삭제.
	void monsterRemover(Node* sender); 
	//충돌 검사
	void checkCollision(float t);
	//캐릭터 충돌 검사
	void checkCharacterCollision(float t);
	//캐릭터 충돌 스케쥴 on.
	void onCharacterCollision();
	//Castle position set
	void setCastlePosition();
	//Timer set
	void createTimer();
	void timeCount(float t);
	void changeToOpeningScene();
	void initGameCoin();
	//game end
	void missionEnd(float);


	CREATE_FUNC(GameMaker);
};
#endif // __GANENAKER_H__