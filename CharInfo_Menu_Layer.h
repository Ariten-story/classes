#ifndef __CHARINFO_MENU_LAYER_H__
#define __CHARINFO_MENU_LAYER_H__

#include "cocos2d.h"
using namespace cocos2d;

class CharInfo_MENU : public cocos2d::LayerColor
{
public:

	virtual bool init();

	void Info_First(Object* pSender);
	void Info_Second(Object* pSender);
	void Info_Third(Object* pSender);
	void Info_Out(Object* pSender);

	CREATE_FUNC(CharInfo_MENU);
};
#endif // __CHARINFO_MENU_LAYER_H__