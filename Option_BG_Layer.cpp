#include "Option_BG_Layer.h"

USING_NS_CC;
/*
Option_BG::Option_BG()
{
}

Option_BG::~Option_BG()
{
}
*/
bool Option_BG::init()
{
	if (!LayerColor::initWithColor(Color4B(255, 255, 255, 255)))
	{
		return false;
	}

	Size winSize = Director::getInstance()->getWinSize();

	return true;
}