#ifndef __GAMETEST_SCENE_H__
#define __GAMETEST_SCENE_H__

#include "cocos2d.h"
using namespace cocos2d;

class GameTestScene : public cocos2d::LayerColor
{
public:
	static cocos2d::Scene* createScene();

	GameTestScene();
	~GameTestScene();

	CREATE_FUNC(GameTestScene);
};
#endif // __GAMETEST_SCENE_H__
