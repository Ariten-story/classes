#ifndef __OPTION_MENU_LAYER_H__
#define __OPTION_MENU_LAYER_H__

#include "cocos2d.h"
using namespace cocos2d;

class Option_MENU : public cocos2d::LayerColor
{
public:

	//Option_MENU();
	//~Option_MENU();

	virtual bool init();

	void SoundButton(Object* pSender);
	void Button(Object* pSender);
	void BackButton(Object* pSender);

	CREATE_FUNC(Option_MENU);
};
#endif // __OPTION_MENU_LAYER_H__
