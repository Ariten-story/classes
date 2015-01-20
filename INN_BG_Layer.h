#ifndef __INN_BG_LAYER_H__
#define __INN_BG_LAYER_H__

#include "cocos2d.h"
using namespace cocos2d;

class INN_BG : public cocos2d::LayerColor
{
public:

	virtual bool init();

	CREATE_FUNC(INN_BG);
};
#endif // __INN_BG_LAYER_H__
