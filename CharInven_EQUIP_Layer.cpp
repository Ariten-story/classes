#include "CHARINVEN_EQUIP_Layer.h"

USING_NS_CC;

bool CharInven_EQUIP::init()
{
	if (!Layer::init())
	{
		return false;
	}

	auto pBackGround = Sprite::create("INN_CHAR1.png");
	if (!pBackGround)
	{
		return false;
	}
	pBackGround->setPosition(Point(180, 200));

	this->addChild(pBackGround);

	return true;
}