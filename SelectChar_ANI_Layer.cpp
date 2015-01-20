#include "SelectChar_ANI_Layer.h"

USING_NS_CC;
/*
SelectChar_ANI::SelectChar_ANI()
{
}
SelectChar_ANI::~SelectChar_ANI()
{
}
*/
bool SelectChar_ANI::init()
{
	if (!LayerColor::initWithColor(Color4B(0, 0, 0, 0)))
	{
		return false;
	}

	Size winSize = Director::getInstance()->getWinSize();

	return true;
}