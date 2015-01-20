#ifndef __SelectChar_SCENE_H__
#define __SelectChar_SCENE_H__

#include "cocos2d.h"
using namespace cocos2d;

class SelectChar : public cocos2d::LayerColor
{
public:
	static cocos2d::Scene* createScene();

	SelectChar();
	~SelectChar();

	CREATE_FUNC(SelectChar);
};

#endif // __SelectChar_SCENE_H__