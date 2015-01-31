#ifndef __DEFENCE_UI_LAYER_H__
#define __DEFENCE_UI_LAYER_H__

#include "cocos2d.h"
#include "Defence_BG_Layer.h"
using namespace cocos2d;

class Defence_UI : public cocos2d::Layer
{
public:

	virtual bool init();

	void Rudder(Object* pSender);

	CREATE_FUNC(Defence_UI);

private:
	Defence_BG* pDefence_bg;

};
#endif // __DEFENCE_UI_LAYER_H__
