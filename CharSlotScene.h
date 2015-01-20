#ifndef __CharSlot_SCENE_H__
#define __CharSlot_SCENE_H__

#include "cocos2d.h"
using namespace cocos2d;

class CharSlot : public cocos2d::LayerColor
{
public:
	static cocos2d::Scene* createScene();
	
	CharSlot();
	~CharSlot();
	
	CREATE_FUNC(CharSlot);
};

#endif // __CharSlot_SCENE_H__
