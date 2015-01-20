#ifndef __CharInfo_SCENE_H__
#define __CharInfo_SCENE_H__

#include "cocos2d.h"
using namespace cocos2d;

class CharInfo : public cocos2d::LayerColor
{
public:
	static cocos2d::Scene* createScene();

	
	CREATE_FUNC(CharInfo);
};

#endif // __CharInfo_SCENE_H__
