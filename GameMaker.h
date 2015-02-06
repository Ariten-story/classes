#ifndef __GAMEMAKER_H__
#define __GANENAKER_H__

#include "cocos2d.h"
#include "Monster.h"
using namespace cocos2d;

class GameMaker : public cocos2d::LayerColor
{
private:
	Layer* backgroundLayer;
	Layer* controllerLayer;
	Size winSize;
	
	std::vector<Monster*> arrMonster;

public:

	//GameMaker();
	//~GameMaker();

	virtual bool init();

	void moveToCastle(Sprite* sprite, float movetime); //몬스터 성으로 이동.
	void moveToPlayer(Sprite* sprite, float movetime); //몬스터 player쪽으로 이동
	void setFirstPosition(Sprite* sprite); //몬스터 생성위치 지정.
	void createMonster(float t); // 몬스터 생성.
	void addMonsterList(Monster* monster); //몬스터 vector에 추가.
	void monsterRemover(Node* sender); //몬스터 액션 완료시 삭제.
	void checkCollision(float t); //충돌 검사

	CREATE_FUNC(GameMaker);
};
#endif // __GANENAKER_H__