#ifndef __CHARINVEN_INVEN_LAYER_H__
#define __CHARINVEN_INVEN_LAYER_H__

#include "cocos2d.h"
using namespace cocos2d;

class CharInven_INVEN : public cocos2d::Layer
{
public:

	virtual bool init();

	void WeaponSlot(Object* pSender);
	void ArmorSlot(Object* pSender);
	void AccessorySlot(Object* pSender);
	void ConsumSlot(Object* pSender);
	void ReinforceSlot(Object* pSender);
	void MyinvenSlot(Object* pSender);

	TransitionScene* createTransition(int nIndex, float t, Scene* s);

	CREATE_FUNC(CharInven_INVEN);
};
#endif // __CHARINVEN_INVEN_LAYER_H__
