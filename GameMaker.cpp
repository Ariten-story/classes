#include "GameMaker.h"
#include "Controller.h"
#include "BGMaker.h"
#include "Player.h"

/*
GameMaker::GameMaker(){}
GameMaker::~GameMaker(){}
*/

bool GameMaker::init()
{
	if (!LayerColor::initWithColor(Color4B(0, 0, 0, 0)))
	{
		return false;
	}
	winSize = Director::getInstance()->getWinSize();

	backgroundLayer = BGMaker::create();
	controllerLayer = Controller::create();
	//backgroundLayer->schedule(schedule_selector(GameMaker::createMonster), 1.0f);
	this->addChild(backgroundLayer);
	this->addChild(controllerLayer);

	return true;
}

// 몬스터 생성위치 지정.
void GameMaker::setFirstPosition(Sprite* sprite)
{
	float xPos = rand() % (1280 * 2);
	float yPos = winSize.height / 2;
	sprite->setPosition(Point(xPos, yPos));
	sprite->setAnchorPoint(Point(0.0, 0.5));
}

// 몬스터 생성.
void GameMaker::createMonster(float t)
{
	Monster* monster = new Monster();
	auto monsterBody = Sprite::create("Monster1.png");
	monster->setMonsterBody(monsterBody);
	monster->setEnergey(100);
	monster->setIsEnermy(true);
	this->setFirstPosition(monster->getMonsterBody());
	float distance = monster->getMonsterBody()->getPositionX();
	float speed = 50.0f;
	float movetime = distance / speed;
	//this->moveToPlayer(monsterSprite, 10.f);
	this->moveToCastle(monster->getMonsterBody(), movetime);
	this->addMonsterList(monster);
	addChild(monster->getMonsterBody());
}

//몬스터 vector에 추가.
void GameMaker::addMonsterList(Monster* monster)
{
	if (true == monster->getIsEnermy())
		arrMonster.push_back(monster);
}

//몬스터 액션 완료시 삭제.
void GameMaker::monsterRemover(Node* sender)
{
	Monster* monster = NULL;
	for (std::vector<Monster*>::iterator iter = arrMonster.begin(); iter != arrMonster.end(); iter++)
	{
		monster = (Monster*)*iter;
		if (monster->getMonsterBody() == sender)
		{
			arrMonster.erase(iter);
			break;
		}
		monster = NULL;
	}
	if (NULL != monster)
	{
		monster->release();
		delete monster;
	}
}

//몬스터 성으로 이동.
void GameMaker::moveToCastle(Sprite* sprite, float movetime)
{
	auto newPos = Point(0, winSize.height / 2);
	MoveTo* moveTo = MoveTo::create(movetime, newPos);
	CallFuncN* callfunc = CallFuncN::create(CC_CALLBACK_1(GameMaker::monsterRemover, this));
	Sequence* sequence = Sequence::create(moveTo, callfunc, NULL);
	sprite->runAction(sequence);
}

//몬스터 player쪽으로 이동
void GameMaker::moveToPlayer(Sprite* sprite, float movetime)
{
	auto playerCharacter = Player::getInstance()->getCharacter();
	auto newPos = Point(playerCharacter->getPosition().x, playerCharacter->getPosition().y);

	MoveTo* moveTo = MoveTo::create(movetime, newPos);
	CallFuncN* callfunc = CallFuncN::create(CC_CALLBACK_1(GameMaker::monsterRemover, this));
	Sequence* sequence = Sequence::create(moveTo, callfunc, NULL);
	sprite->runAction(sequence);
}

//충돌 검사
void GameMaker::checkCollision(float t)
{

}