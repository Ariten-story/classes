#ifndef __CharSkill_SKILLMENU_LAYER_H__
#define __CharSkill_SKILLMENU_LAYER_H__

#include "cocos2d.h"
using namespace cocos2d;

class CharSkill_SKILLMENU : public cocos2d::LayerColor
{
public:
	virtual bool init();

	void SkillClick(Object* pSender);
	void SlotButton1(Object* pSender);
	void SlotButton2(Object* pSender);
	void SlotButton3(Object* pSender);
	void BackButton(Object* pSender);

	CREATE_FUNC(CharSkill_SKILLMENU);
};

#endif // __CharSkill_SKILLMENU_LAYER_H__
