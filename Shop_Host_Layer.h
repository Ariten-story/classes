#ifndef __Shop_HOST_LAYER_H__
#define __Shop_HOST_LAYER_H__

#include "cocos2d.h"
using namespace cocos2d;

class Shop_Host : public cocos2d::LayerColor
{
public:
	virtual bool init();

	CREATE_FUNC(Shop_Host);
};

#endif // __Shop_Host_LAYER_H__
