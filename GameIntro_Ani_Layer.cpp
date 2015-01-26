#include "GameIntro_Ani_Layer.h"

USING_NS_CC;
/*
GameIntro_ANI::GameIntro_ANI()
{
}

GameIntro_ANI::~GameIntro_ANI()
{
}
*/
bool rightselected = false;
bool leftselected = false;

bool GameIntro_ANI::init()
{
	if (!LayerColor::initWithColor(Color4B(0, 0, 0, 0)))
	{
		return false;
	}
	Size winSize = Director::getInstance()->getWinSize();
	rightSprite = Sprite::create("right.png");
	leftSprite = Sprite::create("left.png");
	
	rightSprite->setPosition(winSize.width*0.75, 0);
	leftSprite->setPosition(winSize.width *0.25, 0);
	rightSprite->setAnchorPoint(Point(0.5, 0.0));
	leftSprite->setAnchorPoint(Point(0.5, 0.0));
	this->addChild(rightSprite);
	this->addChild(leftSprite);

	parent = Sprite::create("grossini.png");
	parent->setPosition(winSize.width*0.25, winSize.height/3);
	this->addChild(parent);

	auto child = Sprite::create("white-512x512.png");
	child->setTextureRect(Rect(0, 0, 50, 5));
	child->setColor(Color3B::RED);
	Size parentSize = parent->getContentSize();
	child->setPosition(Point(parentSize.width / 2.0, parentSize.height + 10));
	parent->addChild(child);

	this->schedule(schedule_selector(GameIntro_ANI::rightmoveChar));
	this->schedule(schedule_selector(GameIntro_ANI::leftmoveChar));

	return true;
}
void GameIntro_ANI::onEnter()
{
	Layer::onEnter();
	auto listener = EventListenerTouchOneByOne::create();

	listener->setSwallowTouches(true);

	listener->onTouchBegan = CC_CALLBACK_2(GameIntro_ANI::onTouchBegan, this);
	listener->onTouchMoved = CC_CALLBACK_2(GameIntro_ANI::onTouchMoved, this);
	listener->onTouchEnded = CC_CALLBACK_2(GameIntro_ANI::onTouchEnded, this);

	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
}
void GameIntro_ANI::onExit()
{
	_eventDispatcher->removeEventListenersForTarget(this);

	Layer::onExit();
}
bool GameIntro_ANI::onTouchBegan(Touch* touch, Event* event)
{
	auto touchPoint = touch->getLocation();
	log("onTouchBegan id = %d, x =%f, y = %f", touch->getID(), touchPoint.x, touchPoint.y);

	bool rTouch = rightSprite->getBoundingBox().containsPoint(touchPoint);
	if (rTouch)
	{
		log("rightSprite clicked...");
		rightselected = true;
	}
	bool lTouch = leftSprite->getBoundingBox().containsPoint(touchPoint);
	if (lTouch)
	{
		log("leftSprite clicked...");
		leftselected = true;
	}
	return true;
}
void GameIntro_ANI::onTouchMoved(Touch* touch, Event* event)
{
	auto touchPoint = touch->getLocation();

	log("onTouchMoved id = %d, x = %f, y = %f", touch->getID(), touchPoint.x, touchPoint.y);

	bool bTouch = parent->getBoundingBox().containsPoint(touchPoint);
	if (bTouch)
	{
		log("Sprite clicked...");
	}
	bool rTouch = rightSprite->getBoundingBox().containsPoint(touchPoint);
	if (rTouch)
	{
		log("rightSprite clicked...");
		rightselected = true;
	}
	else
	{
		rightselected = false;
	}

	bool lTouch = leftSprite->getBoundingBox().containsPoint(touchPoint);
	if (lTouch)
	{
		log("leftSprite clicked...");
		leftselected = true;
	}
	else
	{
		leftselected = false;
	}

}
void GameIntro_ANI::onTouchEnded(Touch* touch, Event* event)
{
	auto touchPoint = touch->getLocation();
	log("onTouchMoved id = %d, x = %f, y = %f", touch->getID(), touchPoint.x, touchPoint.y);
	rightselected = false;
	leftselected = false;
}
void GameIntro_ANI::onTouchCancelled(Touch* touch, Event* event)
{
}
void GameIntro_ANI::rightmoveChar(float f)
{
	if (rightselected)
	{
		auto posX = parent->getPositionX();
		auto posY = parent->getPositionY();
		posX+=5;
		parent->setPosition(Point(posX, posY));
	}
}
void GameIntro_ANI::leftmoveChar(float f)
{
	if (leftselected)
	{
		auto posX = parent->getPositionX();
		auto posY = parent->getPositionY();
		posX -= 5;
		parent->setPosition(Point(posX, posY));
	}
}