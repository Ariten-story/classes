#ifndef __CHARINVEN_MENU_LAYER_H__
#define __CHARINVEN_MENU_LAYER_H__

#include "cocos2d.h"
using namespace cocos2d;

class CharInven_MENU : public cocos2d::LayerColor
{
public:

	virtual bool init();

	void BackButton(Object* pSender);

	TransitionScene* createTransition(int nIndex, float t, Scene* s);

	CREATE_FUNC(CharInven_MENU);
};
#endif // __CHARINVEN_MENU_LAYER_H__
