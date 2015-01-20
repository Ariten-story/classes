#ifndef __Shop_BG_LAYER_H__
#define __Shop_BG_LAYER_H__

#include "cocos2d.h"
using namespace cocos2d;

class Shop_BG : public cocos2d::LayerColor
{
public:
	virtual bool init();

	CREATE_FUNC(Shop_BG);
};

#endif // __Shop_BG_LAYER_H__
