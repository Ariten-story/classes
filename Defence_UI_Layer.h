#ifndef __DEFENCE_UI_LAYER_H__
#define __DEFENCE_UI_LAYER_H__

#include "cocos2d.h"
#include "Defence_BG_Layer.h"
using namespace cocos2d;

class Defence_UI : public cocos2d::Layer
{
public:

	virtual bool init();

	CREATE_FUNC(Defence_UI);

};
#endif // __DEFENCE_UI_LAYER_H__
