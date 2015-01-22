#ifndef __SELECTCHAR_MENU_LAYER_H__
#define __SELECTCHAR_MENU_LAYER_H__

#include "cocos2d.h"
using namespace cocos2d;

class SelectChar_MENU : public cocos2d::LayerColor
{
public:

	//SelectChar_MENU();
	//~SelectChar_MENU();

	virtual bool init();

	void charButton(Object* pSender);
	void backButton(Object* pSender);
	void selectButton(Object* pSender);

	CREATE_FUNC(SelectChar_MENU);
};
#endif // __SELECTCHAR_MENU_LAYER_H__
