#include "CHARINVEN_CHAR_Layer.h"

USING_NS_CC;

bool CharInven_CHAR::init()
{
	if (!Layer::init())
	{
		return false;
	}

	Size winSize = Director::getInstance()->getWinSize();

	auto pBackGround = Sprite::create("INN_CHAR1.png");
	if (!pBackGround)
	{
		return false;
	}
	//pBackGround->setPosition(Point(180, 200));

	pBackGround->setPosition(Point(winSize.width / 4, winSize.height / 2));
	pBackGround->setScaleY(winSize.height / 400);
	pBackGround->setScaleX(winSize.width / 640);

	this->addChild(pBackGround);

	return true;
}