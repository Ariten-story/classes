#include "Controller.h"
#include "Player.h"
#include "GameIntroScene.h"
/*
Controller::Controller(){}
Controller::~Controller(){}
*/

USING_NS_CC;

bool Controller::init()
{
	if (!LayerColor::initWithColor(Color4B(0, 0, 0, 0)))
	{
		return false;
	}
	// 현재 사용하지않는 texture 전부 삭제.
	//Director::getInstance()->getTextureCache()->removeUnusedTextures();

	winSize = Director::getInstance()->getWinSize();
	
	this->createButtons();
	
	this->setKeypadEnabled(true);

	return true;
}

 // 버튼 생성
void Controller::createButtons()
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
	
	this->addChild(rightSprite);
	this->addChild(leftSprite);
	this->addChild(attackSprite);
	for (int i = 0; i < 4; i++)
	{
		this->addChild(skillSprite[i]);
	}
}

 // 안드로이드 Back버튼 활성화
void Controller::onKeyReleased(cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event *event)
{
	if (keycode == EventKeyboard::KeyCode::KEY_BACK)
	{
		auto pScene = GameIntro::createScene();
		Director::getInstance()->replaceScene(TransitionFade::create(1.0, pScene));
	}
}

 // 터치 이벤트 등록
void Controller::onEnter()
{
	Layer::onEnter();
	
	auto listener = EventListenerTouchOneByOne::create();
	
	listener->setSwallowTouches(true);

	listener->onTouchBegan = CC_CALLBACK_2(Controller::onTouchBegan, this);
	listener->onTouchMoved = CC_CALLBACK_2(Controller::onTouchMoved, this);
	listener->onTouchEnded = CC_CALLBACK_2(Controller::onTouchEnded, this);
	
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
}

 // 터치 해제
void Controller::onExit() 
{
	_eventDispatcher->removeEventListenersForTarget(this);

	Layer::onExit();
}


bool Controller::onTouchBegan(Touch* touch, Event* event) // 터치 시작시
{
	isLeftPressed = false;
	isRightPressed = false;
	isAttackPressed = false;
	isSkillPressed = false;

	 // 터치가 어느 버튼안에 들어갔는지 체크
	if (this->isTouchInside(leftSprite, touch) == true) 
	{
		isLeftPressed = true;
	}
	else if (this->isTouchInside(rightSprite, touch) == true)
	{
		isRightPressed = true;
	}
	else if (this->isTouchInside(attackSprite, touch) == true)
	{
		isAttackPressed = true;
	}
	else 
	{
		for (int i = 0; i < 4; i++)
		{
			if (this->isTouchInside(skillSprite[i], touch) == true)
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

	return true;
}

 // 터치 중
void Controller::onTouchMoved(Touch* touch, Event* event)
{
	 // 왼쪽 터치 체크
	if (isLeftPressed == true && this->isTouchInside(leftSprite, touch) == false)
	{
		isLeftPressed = false;
		this->stopMovingCharacter();
	}
	else if (isLeftPressed == false && this->isTouchInside(leftSprite, touch) == true)
	{
		isLeftPressed = true;
		this->startMovingCharacter();
	}
	 // 오른쪽 터치 체크
	if (isRightPressed == true && this->isTouchInside(rightSprite, touch) == false)
	{
		isRightPressed = false;
		this->stopMovingCharacter();
	}
	else if (isRightPressed == false && this->isTouchInside(rightSprite, touch) == true)
	{
		isRightPressed = true;
		this->startMovingCharacter();
	}
	 // 공격 터치 체크
	if (isAttackPressed == true && this->isTouchInside(attackSprite, touch) == false)
	{
		isAttackPressed = false;
		this->stopAttackCharacter();
	}
	 // 스킬 터치 체크
	if (isSkillPressed == true)
	{
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

 // 터치 종료
void Controller::onTouchEnded(Touch* touch, Event* event)
{
	 //움직임 & 공격 종료.
	if (isLeftPressed == true || isRightPressed == true)
	{
		isLeftPressed = false;
		isRightPressed = false;
		this->stopMovingCharacter();
	}
	else if (isAttackPressed == true || isSkillPressed == true)
	{
		isAttackPressed = false;
		isSkillPressed = false;
		this->stopAttackCharacter();
	}
}
 // 터치 확인.
bool Controller::isTouchInside(cocos2d::Sprite* sprite, cocos2d::Touch* touch)
{
	auto touchPoint = touch->getLocation();
	bool bTouch = sprite->getBoundingBox().containsPoint(touchPoint);
	return bTouch;
}

 // 캐릭터 이동시작.
void Controller::startMovingCharacter()
{
	log("Start moving");
	this->schedule(schedule_selector(Controller::moveCharacter));
}

 // 캐릭터 이동종료.
void Controller::stopMovingCharacter()
{
	log("Stop moving");
	this->unschedule(schedule_selector(Controller::moveCharacter));
}

 // 캐릭터 이동구현
void Controller::moveCharacter(float t)
{
	auto moveStep = 5;
	if (isLeftPressed == true)
	{
		moveStep = -5;
		characterSprite->setFlippedX(false);
	}
	else
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
void Controller::startAttackCharacter()
{
	log("Start Attack");
	this->schedule(schedule_selector(Controller::attackCharacter), 0.6f);
}

 // 캐릭터 공격종료.
void Controller::stopAttackCharacter()
{
	log("Stop Attack");
	this->unschedule(schedule_selector(Controller::attackCharacter));
}

 // 캐릭터 공격구현
void Controller::attackCharacter(float t)
{
	log("Attack");
}