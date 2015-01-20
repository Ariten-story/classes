#ifndef __CharSlot_MENU_LAYER_H__
#define __CharSlot_MENU_LAYER_H__

#include "cocos2d.h"
using namespace cocos2d;

class CharSlot_MENU : public cocos2d::LayerColor
{
public:

	//CharSlot_MENU();
	//~CharSlot_MENU();

	virtual bool init();

	void SlotButton1(Object* pSender);
	void SlotButton2(Object* pSender);
	void SlotButton3(Object* pSender);
	void BackButton(Object* pSender);

	CREATE_FUNC(CharSlot_MENU);
};

#endif // __CharSlot_MENU_LAYER_H__
