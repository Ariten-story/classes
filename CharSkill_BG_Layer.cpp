#include "CharSkill_BG_Layer.h"

USING_NS_CC;

bool CharSkill_BG::init()
{
	if (!LayerColor::initWithColor(Color4B(255, 255, 255, 255)))
	{
		return false;
	}

	Size winSize = Director::getInstance()->getWinSize();

	auto pBackGround = Sprite::create("INN_BG1.png");
	if (!pBackGround)
	{
		return false;
	}
	pBackGround->setPosition(Point(winSize.width / 2, winSize.height / 2));
	pBackGround->setScaleY(winSize.height / pBackGround->getContentSize().height);
	pBackGround->setScaleX(winSize.width / pBackGround->getContentSize().width);

	this->addChild(pBackGround);

	return true;
}