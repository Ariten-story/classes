#ifndef __SHOP_MENU_LAYER_H__
#define __SHOP_MENU_LAYER_H__

#include "cocos2d.h"
using namespace cocos2d;

class Shop_MENU : public cocos2d::LayerColor
{
public:

	virtual bool init();

	void BackButton(Object* pSender);
	void WeaponSlot(Object* pSender);
	void ArmorSlot(Object* pSender);
	void AccessorySlot(Object* pSender);
	void ConsumSlot(Object* pSender);
	void ReinforceSlot(Object* pSender);
	void MyinvenSlot(Object* pSender);



	TransitionScene* createTransition(int nIndex, float t, Scene* s);

	CREATE_FUNC(Shop_MENU);
};
#endif // __SHOP_MENU_LAYER_H__
