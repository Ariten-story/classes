#ifndef __POP_SCENE_H__
#define __POP_SCENE_H__

#include "cocos2d.h"
using namespace cocos2d;

class Pop : public cocos2d::LayerColor
{
public:
	static cocos2d::Scene* createScene();

	Pop();
	~Pop();

	CREATE_FUNC(Pop);
};
#endif // __POP_SCENE_H__
