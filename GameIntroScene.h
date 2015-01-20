#ifndef __GAMEINTRO_SCENE_H__
#define __GAMEINTRO_SCENE_H__

#include "cocos2d.h"
using namespace cocos2d;

class GameIntro : public cocos2d::LayerColor
{
public:
	static cocos2d::Scene* createScene();
	
	GameIntro();
	~GameIntro();

	CREATE_FUNC(GameIntro);
};
#endif // __GAMEINTRO_SCENE_H__
