#include "Controller.h"
#include "Player.h"
#include "GameIntroScene.h"
/*
Controller::Controller()
{
}
Controller::~Controller()
{
}
*/

USING_NS_CC;

bool selected[7] = { false, false, false, false, false, false, false }; //왼쪽, 오른쪽, 공격, 스킬1, 스킬2, 스킬3, 스킬4

bool Controller::init()
{
	if (!LayerColor::initWithColor(Color4B(0, 0, 0, 0)))
	{
		return false;
	}
	//Director::getInstance()->getTextureCache()->removeUnusedTextures();//현재 사용하지않는 texture 전부 삭제.

	Size winSize = Director::getInstance()->getWinSize();
	
	spriteCharacter = Player::getInstance()->getCharacter();
	spriteRight = Sprite::create("right.png");
	spriteLeft = Sprite::create("left.png");
	spriteAttack = Sprite::create("Attack.png");
	spriteSkill_1 = Sprite::create("Skill_1.png");
	spriteSkill_2 = Sprite::create("Skill_2.png");
	spriteSkill_3 = Sprite::create("Skill_3.png");
	spriteSkill_4 = Sprite::create("Skill_3.png");
	
	spriteCharacter->setPosition(Point(winSize.width / 2, winSize.height / 2));
	spriteRight->setPosition(Point(winSize.width*0.28, 0));
	spriteRight->setAnchorPoint(Point(0.5, 0.0));
	spriteLeft->setPosition(Point(winSize.width*0.14, 0));
	spriteLeft->setAnchorPoint(Point(0.5, 0.0));
	spriteAttack->setPosition(Point(winSize.width*0.42, 0));
	spriteAttack->setAnchorPoint(Point(0.5, 0.0));
	spriteSkill_1->setPosition(Point(winSize.width*0.56, 0));
	spriteSkill_1->setAnchorPoint(Point(0.5, 0.0));
	spriteSkill_2->setPosition(Point(winSize.width*0.7, 0));
	spriteSkill_2->setAnchorPoint(Point(0.5, 0.0));
	spriteSkill_3->setPosition(Point(winSize.width*0.84, 0));
	spriteSkill_3->setAnchorPoint(Point(0.5, 0.0));
	spriteSkill_4->setPosition(Point(winSize.width*0.95, 0));
	spriteSkill_4->setAnchorPoint(Point(0.5, 0.0));

	this->addChild(spriteCharacter);
	this->addChild(spriteRight);
	this->addChild(spriteLeft);
	this->addChild(spriteAttack);
	this->addChild(spriteSkill_1);
	this->addChild(spriteSkill_2);
	this->addChild(spriteSkill_3);
	this->addChild(spriteSkill_4);
	

	//////Test용. Test후 삭제할 것.
	enemy = Sprite::create("grossini.png");
	enemy->setPosition(Point(winSize.width / 3, winSize.height / 2));
	this->addChild(enemy);

	auto hpBar = Sprite::create("white-512x512.png");
	hpBar->setTextureRect(Rect(0, 0, 50, 5));
	hpBar->setColor(Color3B::RED);
	Size parentSize = spriteCharacter->getContentSize();
	hpBar->setPosition(Point(parentSize.width / 2.0, parentSize.height + 10));
	spriteCharacter->addChild(hpBar);

	sworld = Sprite::create("sword.png");
	sworld->setAnchorPoint(Point(0.5, 0.0));
	sworld->setPosition(Point(30, (parentSize.height / 2.0) - 25.0));
	spriteCharacter->addChild(sworld);
	//////<-여기까지 Test

	this->schedule(schedule_selector(Controller::rightMoveChar));
	this->schedule(schedule_selector(Controller::leftMoveChar));
	this->schedule(schedule_selector(Controller::attackChar));
	this->schedule(schedule_selector(Controller::skillChar));

	this->setKeypadEnabled(true);

	return true;
}
void Controller::onKeyReleased(cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event *event)
{
	if (keycode == EventKeyboard::KeyCode::KEY_BACK)
	{
		auto pScene = GameIntro::createScene();
		Director::getInstance()->replaceScene(TransitionFade::create(1.0, pScene));
	}
}
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
void Controller::onExit()
{
	_eventDispatcher->removeEventListenersForTarget(this);

	Layer::onExit();
}
bool Controller::onTouchBegan(Touch* touch, Event* event)
{
	auto touchPoint = touch->getLocation();
	log("onTouchBegan id = %d, x =%f, y = %f", touch->getID(), touchPoint.x, touchPoint.y);
	
	bool rightTouch = spriteRight->getBoundingBox().containsPoint(touchPoint);
	bool leftTouch = spriteLeft->getBoundingBox().containsPoint(touchPoint);
	bool attackTouch = spriteAttack->getBoundingBox().containsPoint(touchPoint);
	bool skill1Touch = spriteSkill_1->getBoundingBox().containsPoint(touchPoint);
	bool skill2Touch = spriteSkill_2->getBoundingBox().containsPoint(touchPoint);
	bool skill3Touch = spriteSkill_3->getBoundingBox().containsPoint(touchPoint);
	bool skill4Touch = spriteSkill_4->getBoundingBox().containsPoint(touchPoint);
	
	if (rightTouch)
	{
		log("spriteRight clicked...");
		selected[1] = true;
	}
	if (leftTouch)
	{
		log("spriteLeft clicked...");
		selected[0] = true;
	}
	if (attackTouch)
	{
		log("spriteAttack clicked...");
		selected[2] = true;
	}
	if (skill1Touch)
	{
		log("spriteSkill_1 clicked...");
		selected[3] = true;
	}
	if (skill2Touch)
	{
		log("spriteSkill_2 clicked...");
		selected[4] = true;
	}
	if (skill3Touch)
	{
		log("spriteSkill_3 clicked...");
		selected[5] = true;
	}
	if (skill4Touch)
	{
		log("spriteSkill_4 clicked...");
		selected[6] = true;
	}
	
	return true;
}
void Controller::onTouchMoved(Touch* touch, Event* event)
{
	auto touchPoint = touch->getLocation();

	log("onTouchMoved id = %d, x = %f, y = %f", touch->getID(), touchPoint.x, touchPoint.y);
	
	bool rightTouch = spriteRight->getBoundingBox().containsPoint(touchPoint);
	bool leftTouch = spriteLeft->getBoundingBox().containsPoint(touchPoint);
	bool attackTouch = spriteAttack->getBoundingBox().containsPoint(touchPoint);
	bool skill1Touch = spriteSkill_1->getBoundingBox().containsPoint(touchPoint);
	bool skill2Touch = spriteSkill_2->getBoundingBox().containsPoint(touchPoint);
	bool skill3Touch = spriteSkill_3->getBoundingBox().containsPoint(touchPoint);
	bool skill4Touch = spriteSkill_4->getBoundingBox().containsPoint(touchPoint);

	if (rightTouch)
	{
		log("spriteRight clicked...");
		selected[1] = true;
	}
	else
	{
		selected[1] = false;
	}
	if (leftTouch)
	{
		log("spriteLeft clicked...");
		selected[0] = true;
	}
	else
	{
		selected[0] = false;
	}
	if (attackTouch)
	{
		log("spriteAttack clicked...");
		selected[2] = true;
	}
	else
	{
		selected[2] = false;
	}
	if (skill1Touch)
	{
		log("spriteSkill_1 clicked...");
		selected[3] = true;
	}
	else
	{
		selected[3] = false;
	}
	if (skill2Touch)
	{
		log("spriteSkill_2 clicked...");
		selected[4] = true;
	}
	else
	{
		selected[4] = false;
	}
	if (skill3Touch)
	{
		log("spriteSkill_3 clicked...");
		selected[5] = true;
	}
	else
	{
		selected[5] = false;
	}
	if (skill4Touch)
	{
		log("spriteSkill_4 clicked...");
		selected[6] = true;
	}
	else
	{
		selected[6] = false;
	}
	
}
void Controller::onTouchEnded(Touch* touch, Event* event)
{
	auto touchPoint = touch->getLocation();
	log("onTouchMoved id = %d, x = %f, y = %f", touch->getID(), touchPoint.x, touchPoint.y);
	for (int i = 0; i < 7; i++)
	{
		selected[i] = false;
	}
}
void Controller::onTouchCancelled(Touch* touch, Event* event)
{
}
void Controller::rightMoveChar(float f)
{
	if (selected[1])
	{
		auto posX = spriteCharacter->getPositionX();
		auto posY = spriteCharacter->getPositionY();
		posX += 5;
		spriteCharacter->setPosition(Point(posX, posY));
	}
}
void Controller::leftMoveChar(float f)
{
	if (selected[0])
	{
		auto posX = spriteCharacter->getPositionX();
		auto posY = spriteCharacter->getPositionY();
		posX -= 5;
		spriteCharacter->setPosition(Point(posX, posY));
	}
}
void Controller::attackChar(float f)
{
	if (selected[2])
	{
		log("Attack!");
		RotateTo* attack = RotateTo::create(0.5, -130);
		RotateBy* reverseAttack = RotateBy::create(0.5, 130);
		auto action = Sequence::create(attack, reverseAttack, NULL);
		sworld->runAction(action);
	}
}
void Controller::skillChar(float f)
{
	if (selected[3])
	{
		log("Skill_1!");
	}
	else if (selected[4])
	{
		log("Skill_2!");
	}
	else if (selected[5])
	{
		log("Skill_3!");
	}
	else if (selected[6])
	{
		log("Skill_4!");
	}
}