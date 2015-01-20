#include "SelectChar_BG_Layer.h"

USING_NS_CC;
/*
SelectChar_BG::SelectChar_BG()
{
}
SelectChar_BG::~SelectChar_BG()
{
}
*/
bool SelectChar_BG::init()
{
	if (!LayerColor::initWithColor(Color4B(255, 255, 255, 255)))
	{
		return false;
	}

	Size winSize = Director::getInstance()->getWinSize();

	return true;
}
