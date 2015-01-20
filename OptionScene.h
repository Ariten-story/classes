#ifndef __OPTION_SCENE_H__
#define __OPTION_SCENE_H__

#include "cocos2d.h"
using namespace cocos2d;

class Option : public cocos2d::LayerColor
{
public:
	static cocos2d::Scene* createScene();

	Option();
	~Option();

	CREATE_FUNC(Option);
};
#endif // __OPTION_SCENE_H__
