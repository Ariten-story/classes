#ifndef __DefenceGame_SCENE_H__
#define __DEFENCEGAME_SCENE_H__

#include "cocos2d.h"
using namespace cocos2d;

class Defence : public cocos2d::LayerColor
{
public:
	static cocos2d::Scene* createScene();

	CREATE_FUNC(Defence);
};

#endif // __DEFENCEGAME_SCENE_H__
