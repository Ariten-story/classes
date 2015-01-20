#include "CharInfo_Hero_Layer.h"

USING_NS_CC;

bool CharInfo_Hero::init()
{
	if (!LayerColor::init()) 
	{
		return false;
	}

	Size winSize = Director::getInstance()->getWinSize();
	auto pMan = Sprite::create("Images/Hero.png");
	pMan->setPosition(Point(winSize.width/4, winSize.height/2));
	pMan->setScaleY(winSize.height /pMan->getContentSize().height);
	pMan->setScaleX(winSize.width /pMan->getContentSize().width/3);

	this->addChild(pMan);

	return true;
}

