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
bool GameIntro_ANI::init()
{
	if (!LayerColor::initWithColor(Color4B(0, 0, 0, 0)))
	{
		return false;
	}

	Size winSize = Director::getInstance()->getWinSize();

	auto parent = Sprite::create("grossini.png");
	parent->setPosition(winSize.width*0.25, winSize.height/3);
	this->addChild(parent);

	auto child = Sprite::create("white-512x512.png");
	child->setTextureRect(Rect(0, 0, 50, 5));
	child->setColor(Color3B::RED);
	Size parentSize = parent->getContentSize();
	child->setPosition(Point(parentSize.width / 2.0, parentSize.height + 10));
	parent->addChild(child);


	return true;
}