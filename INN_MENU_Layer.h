#ifndef __INN_MENU_LAYER_H__
#define __INN_MENU_LAYER_H__

#include "cocos2d.h"
using namespace cocos2d;

class INN_MENU : public cocos2d::LayerColor
{
public:

	virtual bool init();

	void CharInfoButton(Object* pSender);
	void CharInvenButton(Object* pSender);
	void CharSkillButton(Object* pSender);
	void ShopButton(Object* pSender);
	void MissionStartButton(Object* pSender);
	void ExitButton(Object* pSender);

	TransitionScene* createTransition(int nIndex, float t, Scene* s);

	CREATE_FUNC(INN_MENU);
};
#endif // __INN_MENU_LAYER_H__
