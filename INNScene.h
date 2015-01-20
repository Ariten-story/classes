#ifndef __INNScene_H__
#define __INNScene_H__

#include "cocos2d.h"
using namespace cocos2d;

class INN : public cocos2d::LayerColor
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	CREATE_FUNC(INN);
};
#endif // __INNScene_H__
