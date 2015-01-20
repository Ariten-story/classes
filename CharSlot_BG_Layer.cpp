#include "CharSlot_BG_Layer.h"

USING_NS_CC;
/*
CharSlot_BG::CharSlot_BG()
{
}

CharSlot_BG::~CharSlot_BG()
{
}
*/
bool CharSlot_BG::init()
{
	if (!LayerColor::initWithColor(Color4B(255, 255, 255, 255)))
	{
		return false;
	}

	Size winSize = Director::getInstance()->getWinSize();

	return true;
}