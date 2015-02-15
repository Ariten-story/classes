#include "GameMaker.h"
#include "Player.h"
#include "GameIntroScene.h"
#include "Castle.h"
#include <random>

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
	// 현재 사용하지않는 texture 전부 삭제.
	Director::getInstance()->getTextureCache()->removeUnusedTextures();
	isLeftPressed = false;
	isRightPressed = false;
	isAttackPressed = false;
	isSkillPressed = false;
	isRight = false;
	winSize = Director::getInstance()->getWinSize();

	backgroundLayer = Layer::create();
	controllerLayer = Layer::create();
	this->addChild(backgroundLayer);
	this->addChild(controllerLayer);
	
	this->createButtons();
	this->createTimer();
	this->setKeypadEnabled(true);
	this->setCastlePosition();
	this->createBackgroundParallax();
	this->setPositionPlayer();
	backgroundLayer->addChild(characterSprite);
	backgroundLayer->addChild(Fcastle);
	backgroundLayer->addChild(Ecastle);
	
	backgroundLayer->runAction(Follow::create(characterSprite, Rect(0, 0, 1280 * 2, 720)));
	this->schedule(schedule_selector(GameMaker::createMonster), 3.0f);
	this->schedule(schedule_selector(GameMaker::checkCollision));
	this->schedule(schedule_selector(GameMaker::checkCharacterCollision));
	this->schedule(schedule_selector(GameMaker::timeCount), 1.0f);

	return true;
}

// 버튼 생성
void GameMaker::createButtons()
{
	characterSprite = Player::getInstance()->getCharacter();
	rightSprite = Sprite::create("right.png");
	leftSprite = Sprite::create("left.png");
	attackSprite = Sprite::create("Attack.png");
	skillSprite[0] = Sprite::create("Skill_1.png");
	skillSprite[1] = Sprite::create("Skill_2.png");
	skillSprite[2] = Sprite::create("Skill_3.png");
	skillSprite[3] = Sprite::create("Skill_3.png");

	rightSprite->setPosition(Point(winSize.width*0.28, 0));
	rightSprite->setAnchorPoint(Point(0.5, 0.0));
	leftSprite->setPosition(Point(winSize.width*0.14, 0));
	leftSprite->setAnchorPoint(Point(0.5, 0.0));
	attackSprite->setPosition(Point(winSize.width*0.42, 0));
	attackSprite->setAnchorPoint(Point(0.5, 0.0));
	attackSprite->setTag(0);
	skillSprite[0]->setPosition(Point(winSize.width*0.56, 0));
	skillSprite[0]->setAnchorPoint(Point(0.5, 0.0));
	skillSprite[0]->setTag(1);
	skillSprite[1]->setPosition(Point(winSize.width*0.7, 0));
	skillSprite[1]->setAnchorPoint(Point(0.5, 0.0));
	skillSprite[1]->setTag(2);
	skillSprite[2]->setPosition(Point(winSize.width*0.84, 0));
	skillSprite[2]->setAnchorPoint(Point(0.5, 0.0));
	skillSprite[2]->setTag(3);
	skillSprite[3]->setPosition(Point(winSize.width*0.95, 0));
	skillSprite[3]->setAnchorPoint(Point(0.5, 0.0));
	skillSprite[3]->setTag(4);

	controllerLayer->addChild(rightSprite);
	controllerLayer->addChild(leftSprite);
	controllerLayer->addChild(attackSprite);
	for (int i = 0; i < 4; i++)
	{
		controllerLayer->addChild(skillSprite[i]);
	}
}

// 안드로이드 Back버튼 활성화
void GameMaker::onKeyReleased(cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event *event)
{
	if (keycode == EventKeyboard::KeyCode::KEY_BACK)
	{
		auto pScene = GameIntro::createScene();
		Director::getInstance()->replaceScene(TransitionFade::create(1.0, pScene));
	}
}

// 터치 이벤트 등록
void GameMaker::onEnter()
{
	Layer::onEnter();

	auto listener = EventListenerTouchAllAtOnce::create();

	listener->onTouchesBegan = CC_CALLBACK_2(GameMaker::onTouchesBegan, this);
	listener->onTouchesMoved = CC_CALLBACK_2(GameMaker::onTouchesMoved, this);
	listener->onTouchesEnded = CC_CALLBACK_2(GameMaker::onTouchesEnded, this);

	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
}

// 터치 해제
void GameMaker::onExit()
{
	_eventDispatcher->removeEventListenersForTarget(this);

	Layer::onExit();
}
// 터치 시작
void GameMaker::onTouchesBegan(const std::vector<cocos2d::Touch*>& touches, Event* event) // 터치 시작시
{
	for (auto &item : touches)
	{
		auto touch = item;
		log("id = %d", touch->getID());
		// 터치가 어느 버튼안에 들어갔는지 체크
		if (this->isTouchInside(leftSprite, touch) == true)
		{
			log("left: x = %f, y =%f", touch->getLocation().x, touch->getLocation().y);
			isLeftPressed = true;
			isRight = false;
		}
		else if (this->isTouchInside(rightSprite, touch) == true)
		{
			log("right: x = %f, y =%f", touch->getLocation().x, touch->getLocation().y);
			isRightPressed = true;
			isRight = true;
		}
		else if (this->isTouchInside(attackSprite, touch) == true)
		{
			log("attack: x = %f, y =%f", touch->getLocation().x, touch->getLocation().y);
			isAttackPressed = true;
		}
		else
		{
			log("skill: x = %f, y =%f", touch->getLocation().x, touch->getLocation().y);
			for (int i = 0; i < 4; i++)
			{
				if (this->isTouchInside(skillSprite[i], touch))
					isSkillPressed = true;
			}
		}

		// 버튼이 눌러졌으면 실행.
		if (isLeftPressed == true || isRightPressed == true)
		{
			this->startMovingCharacter();
		}
		if (isAttackPressed == true || isSkillPressed == true)
		{
			this->startAttackCharacter();
		}
	}
}

// 터치 중
void GameMaker::onTouchesMoved(const std::vector<cocos2d::Touch*>& touches, Event* event)
{
	for (auto &item : touches)
	{
		auto touch = item;
		// 왼쪽 터치 체크
		if (isLeftPressed == true && this->isTouchInside(leftSprite, touch) == false)
		{
			log("exit left: x = %f, y =%f", touch->getLocation().x, touch->getLocation().y);
			isLeftPressed = false;
			isRight = false;
			this->stopMovingCharacter();
		}
		else if (isLeftPressed == false && this->isTouchInside(leftSprite, touch) == true)
		{
			log("enter left: x = %f, y =%f", touch->getLocation().x, touch->getLocation().y);
			isLeftPressed = true;
			isRight = false;
			this->startMovingCharacter();
		}
		// 오른쪽 터치 체크
		if (isRightPressed == true && this->isTouchInside(rightSprite, touch) == false)
		{
			log("exit right: x = %f, y =%f", touch->getLocation().x, touch->getLocation().y);
			isRightPressed = false;
			isRight = true;
			this->stopMovingCharacter();
		}
		else if (isRightPressed == false && this->isTouchInside(rightSprite, touch) == true)
		{
			log("enter right: x = %f, y =%f", touch->getLocation().x, touch->getLocation().y);
			isRightPressed = true;
			isRight = true;
			this->startMovingCharacter();
		}
		// 공격 터치 체크
		if (isAttackPressed == true && this->isTouchInside(attackSprite, touch) == false)
		{
			log("exit attack: x = %f, y =%f", touch->getLocation().x, touch->getLocation().y);
			isAttackPressed = false;
			this->stopAttackCharacter();
		}
		// 스킬 터치 체크
		if (isSkillPressed == true)
		{
			log("exit skill: x = %f, y =%f", touch->getLocation().x, touch->getLocation().y);
			for (int i = 0; i < 4; i++)
			{
				if (this->isTouchInside(skillSprite[i], touch) == false)
				{
					isSkillPressed = false;
					this->stopAttackCharacter();
				}
			}
		}
	}
	
}

// 터치 종료
void GameMaker::onTouchesEnded(const std::vector<cocos2d::Touch*>& touches, Event* event)
{

	for (auto &item : touches)
	{
		auto touch = item;
		//움직임 & 공격 종료.
		if (isLeftPressed == true || isRightPressed == true)
		{
			log("end touch : move");
			isLeftPressed = false;
			isRightPressed = false;
			this->stopMovingCharacter();
		}
		if (isAttackPressed == true || isSkillPressed == true)
		{
			log("end touch : attack");
			isAttackPressed = false;
			isSkillPressed = false;
			this->stopAttackCharacter();
		}
	}
}

// 터치 확인.
bool GameMaker::isTouchInside(cocos2d::Sprite* sprite, cocos2d::Touch* touch)
{
	auto touchPoint = touch->getLocation();
	bool bTouch = sprite->getBoundingBox().containsPoint(touchPoint);
	return bTouch;
}
// 캐릭터 이동시작.
void GameMaker::startMovingCharacter()
{
	log("Start moving");
	this->schedule(schedule_selector(GameMaker::moveCharacter));
}

// 캐릭터 이동종료.
void GameMaker::stopMovingCharacter()
{
	log("Stop moving");
	this->unschedule(schedule_selector(GameMaker::moveCharacter));
}

// 캐릭터 이동구현
void GameMaker::moveCharacter(float t)
{
	auto moveStep = 5;
	if (isLeftPressed == true && isRightPressed == true)
	{
		moveStep = 0;
	}
	if (isLeftPressed == true)
	{
		moveStep = -5;
		characterSprite->setFlippedX(false);
	}
	else if (isRightPressed == true)
	{
		moveStep = 5;
		characterSprite->setFlippedX(true);
	}

	auto newPos = Point(characterSprite->getPosition().x + moveStep, characterSprite->getPosition().y);

	if (newPos.x < 0)
	{
		newPos.x = 0;
	}
	else if (newPos.x > 1280 * 2)
	{
		newPos.x = 1280 * 2;
	}

	characterSprite->setPosition(newPos);
}

// 캐릭터 공격시작.
void GameMaker::startAttackCharacter()
{
	log("Start Attack");
	this->schedule(schedule_selector(GameMaker::attackCharacter),0.6f);
}

// 캐릭터 공격종료.
void GameMaker::stopAttackCharacter()
{
	log("Stop Attack");
	this->unschedule(schedule_selector(GameMaker::attackCharacter));
}

// 캐릭터 공격구현
void GameMaker::attackCharacter(float t)
{
	log("Attack");
	this->createWeapon();
}

//배경을 만드는 함수.
void GameMaker::createBackgroundParallax()
{
	//스테이지 배경 생성. ->player의 stage정보이용.
	Background* background = Background::creaeteWithType(0);
	//ParallaxNode 받기.
	auto voidNode = background->getParallaxNode();
	//ParallaxNode 추가.
	backgroundLayer->addChild(voidNode, 0);
}

// 플레이어 위치 설정 함수.
void GameMaker::setPositionPlayer()
{
	characterSprite = Player::getInstance()->getCharacter();
	characterSprite->setPosition(Point(winSize.width / 2, winSize.height / 4));
}

// 무기 생성위치 지정.
void GameMaker::setFirstPositionWeapon(Sprite* sprite)
{
	auto newPos = convertToNodeSpace(characterSprite->getPosition());
	log("%f", newPos.x);
	sprite->setPosition(newPos);
}

// 무기 생성.
void GameMaker::createWeapon()
{
	//현재 무기 생성->player의 무기 정보이용.
	Weapon* weapon = Weapon::createWithType(0);
	Point* newPos;

	//무기의 초기 위치 지정.
	this->setFirstPositionWeapon(weapon->getweaponBody());

	//케릭터가 바라보는 시점 체크.
	if (isRight == false)
	{
		weapon->setRange(-(weapon->xPos), weapon->yPos);
		newPos = weapon->getRange();
		weapon->getweaponBody()->setRotation(-90);
	}
	else if (isRight == true)
	{
		newPos = weapon->getRange();
		weapon->getweaponBody()->setRotation(90);
	}

	//무기가 근거리인지 원거리인지 체크.
	if (false == weapon->getIsShortDistance())
	{

		MoveBy* moveby = MoveBy::create(weapon->getSpeedOfAttack(), *newPos);
		CallFuncN* callfunc = CallFuncN::create(CC_CALLBACK_1(GameMaker::WeaponRemover, this));
		Sequence* sequence = Sequence::create(moveby, callfunc, NULL);
		weapon->getweaponBody()->runAction(sequence);
		this->addWeaponList(weapon);

		backgroundLayer->addChild(weapon->getweaponBody());
	}
	else if (true == weapon->getIsShortDistance())
	{

	}
}

// 무기 vector에 추가.
void GameMaker::addWeaponList(Weapon* weapon)
{
	arrWeapon.push_back(weapon);
}

// 무기 액션 완료시 삭제.
void GameMaker::WeaponRemover(Node* sender)
{
	Weapon* weapon = NULL;
	for (std::vector<Weapon*>::iterator iter = arrWeapon.begin(); iter != arrWeapon.end(); iter++)
	{
		weapon = (Weapon*)*iter;
		if (weapon->getweaponBody() == sender)
		{
			arrWeapon.erase(iter);
			log("weapon delete");
			break;
		}
		weapon = NULL;
	}
	if (NULL != weapon)
	{
		weapon->release();
		delete weapon;
	}
}

// 몬스터 생성위치 지정.
void GameMaker::setFirstPositionMonster(Sprite* sprite,int switch_on)
{
	switch (switch_on)
	{
	case 0:
	{
		float yPos = (winSize.height / 4) + 20;
		sprite->setPosition(Point(2400, yPos));
		sprite->setAnchorPoint(Point(0.5, 0.5));
		break;
	}
	case 1:

	case 2:
	{
		std::random_device rd;
		std::mt19937 rEngine(rd());
		std::uniform_int_distribution<> dist(0, 2500);
		auto result = dist(rEngine);
		float xPos = result;//rand() % (1280 * 2);
		float yPos = (winSize.height / 4) + 20;
		sprite->setPosition(Point(xPos, yPos));
		sprite->setAnchorPoint(Point(0.5, 0.5));
		break;
	}
	default:
		break;
	}
	
}

// 몬스터 생성.
void GameMaker::createMonster(float t)
{
	//Type별 몬스터 생성.
	Monster* monster = Monster::createWithType(0);
	//몬스터 최초위치 설정.
	this->setFirstPositionMonster(monster->getMonsterBody(),0);
	//거리,시간 계산.
	float distance = monster->getMonsterBody()->getPositionX();
	float movetime = distance / monster->getSpeedOfMove();
	//액션주기 & 벡터에 저장.
	this->moveToCastle(monster->getMonsterBody(), movetime);
	this->addMonsterList(monster);
	//레이어에 추가.
	backgroundLayer->addChild(monster->getMonsterBody());
}

//set castle Position
void GameMaker::setCastlePosition()
{
	Castle* castle = Castle::createCastle(0);
	Fcastle = castle->getFCastleBody();
	Ecastle = castle->getECastleBody();

	Fcastle->setPosition(Point(winSize.width/10, winSize.height / 4));
	Ecastle->setPosition(Point(2490, winSize.height / 4));
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
			log("Monster delete");
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
	auto newPos = Point(0, sprite->getPositionY());
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

//캐릭터 피해발생시 움직임.
void GameMaker::jumpToBack(Sprite* sprite, Point newPos)
{
	JumpBy* jumpBy = JumpBy::create(1, newPos, 20, 1);
	CallFuncN* callfunc = CallFuncN::create(CC_CALLBACK_0(GameMaker::onCharacterCollision, this));
	Sequence* sequence = Sequence::create(jumpBy, callfunc, NULL);
	sprite->runAction(sequence);
}

//무기와 몬스터 충돌 검사
void GameMaker::checkCollision(float t)
{
	Weapon* weapon = NULL;
	Monster* monster = NULL;
	
	for (std::vector<Weapon*>::iterator iterWeapon = arrWeapon.begin(); iterWeapon != arrWeapon.end(); iterWeapon++)
	{
		weapon = (Weapon*)*iterWeapon;

		bool bHit = false;
		for (std::vector<Monster*>::iterator iterMonster = arrMonster.begin(); iterMonster != arrMonster.end(); iterMonster++)
		{
			monster = (Monster*)*iterMonster;

			Rect boundingBox = monster->getMonsterBody()->getBoundingBox();
			if (boundingBox.containsPoint(weapon->getweaponBody()->getPosition()))
			{
				bHit = true;
				if (0 >= monster->subEnergy(weapon->getDamage()))
				{
					log("%f", monster->subEnergy(0));
					monster->release();
					delete monster;
					iterMonster = arrMonster.erase(iterMonster);
					if (iterMonster == arrMonster.end())
						break;
				}
				else
				{
					log("%f", monster->subEnergy(0));
				}
				break;
			}
		}
		if (true == bHit)
		{
			weapon->release();
			delete weapon;
			iterWeapon = arrWeapon.erase(iterWeapon);
			if (iterWeapon == arrWeapon.end())
				break;
		}
	}
}

//캐릭터 충돌 검사
void GameMaker::checkCharacterCollision(float t)
{
	Point newPos;
	Monster* monster = NULL;
	Player* player = Player::getInstance();
	for (std::vector<Monster*>::iterator iterMonster = arrMonster.begin(); iterMonster != arrMonster.end(); iterMonster++)
	{
		monster = (Monster*)*iterMonster;

		Rect boundingBox = monster->getMonsterBody()->getBoundingBox();
		if (boundingBox.containsPoint(player->getCharacter()->getPosition()))
		{
			this->unschedule(schedule_selector(GameMaker::checkCharacterCollision));
			if (0 >= player->subEnergy(50))
			{
				//캐릭터 죽음.
				player->getCharacter()->setRotation(90);
				DelayTime::create(5.0f);
				missionEnd(player->getEnergey());
				auto pScene = GameIntro::createScene();
				Director::getInstance()->replaceScene(TransitionFade::create(1.0, pScene));
				break;
			}
			else
			{
				if (isLeftPressed || isRightPressed)
				{
					this->stopMovingCharacter();
					if (monster->getMonsterBody()->getPositionX() < player->getCharacter()->getPositionX())
					{
						newPos = Point(60, 0);
						this->jumpToBack(player->getCharacter(), newPos);
					}
					else
					{
						newPos = Point(-60, 0);
						this->jumpToBack(player->getCharacter(), newPos);
					}
				}
				else
				{
					if (monster->getMonsterBody()->getPositionX() < player->getCharacter()->getPositionX())
					{
						newPos = Point(60, 0);
						this->jumpToBack(player->getCharacter(), newPos);
					}
					else
					{
						newPos = Point(-60, 0);
						this->jumpToBack(player->getCharacter(), newPos);
					}
				}
			}
			break;
		}
	}
}

//캐릭터 충돌 스케쥴 on.
void GameMaker::onCharacterCollision()
{
	this->schedule(schedule_selector(GameMaker::checkCharacterCollision));
}


//mission end
void GameMaker::missionEnd(float HP)
{
	if (HP <= 0)
	{
		auto gameover = Label::createWithSystemFont("Game Over !!", "Thonburi", 34);
		gameover->setAnchorPoint(Point(1.0, 1.0));
		gameover->setPosition(Point(winSize.width / 2, winSize.height / 2));

		this->addChild(gameover);

	}
	else
	{
		auto clearMessage = Label::createWithSystemFont("Game Clear !!", "Thonburi", 34);
		clearMessage->setAnchorPoint(Point(1.0, 1.0));
		clearMessage->setPosition(Point(winSize.width / 2, winSize.height / 2));

		this->addChild(clearMessage);

	}

}
//Timer set
void GameMaker::createTimer()
{
	winSize = Director::getInstance()->getWinSize();

	CCSprite* timeBar = CCSprite::create("Timer.png");
	_progressTimeBar = CCProgressTimer::create(timeBar);
	_progressTimeBar->setPosition(ccp(winSize.width * 0.5f, 27));
	_progressTimeBar->setPercentage(100.0f);
	_progressTimeBar->setMidpoint(ccp(0, 0.5f));
	_progressTimeBar->setBarChangeRate(ccp(1, 0));
	_progressTimeBar->setType(kCCProgressTimerTypeBar);

	this->addChild(_progressTimeBar);

	CCProgressFromTo* progressToZero = CCProgressFromTo::create(10, 100, 0);
	_progressTimeBar->runAction(progressToZero);

	CCSprite* timeOutline = CCSprite::create("Timer_square.png");
	timeOutline->setPosition(ccp(winSize.width * 0.5f, 27));
	timeOutline->setVisible(true);
	this->addChild(timeOutline,2);
	
	initGameCoin();
}

void GameMaker::initGameCoin()
{
	_gameTime = 10;  // set sec.
}

void GameMaker::timeCount(float t)
{
	if (--_gameTime == 0) {
		changeToOpeningScene();
	}
}

void GameMaker::changeToOpeningScene()
{
	this->unschedule(schedule_selector(GameMaker::timeCount));
	CCDirector::sharedDirector()->pause();
	CCScene* pScene =Pop::createScene();
	this->addChild(pScene, 2000);
	
	
}


