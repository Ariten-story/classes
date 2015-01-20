#ifndef __CharInvenScene_H__
#define __CharInvenScene_H__

#include "cocos2d.h"
using namespace cocos2d;

class CharInven : public cocos2d::LayerColor
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	CREATE_FUNC(CharInven);
};
#endif // __CharInvenScene_H__
