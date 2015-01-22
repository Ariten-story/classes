#include "Shop_HOST_Layer.h"

USING_NS_CC;

bool Shop_Host::init()
{
	if (!LayerColor::init())
	{
		return false;
	}

	Size winSize = Director::getInstance()->getWinSize();
	auto pMan = Sprite::create("host.png");
	pMan->setPosition(Point(winSize.width / 4, winSize.height / 2));
	pMan->setScaleY(winSize.height / pMan->getContentSize().height/2);
	pMan->setScaleX(winSize.width / pMan->getContentSize().width / 3);
	this->addChild(pMan);

	return true;
}









