#ifndef __GAMEINTRO_MENU_LAYER_H__
#define __GAMEINTRO_MENU_LAYER_H__

#include "cocos2d.h"
using namespace cocos2d;

class GameIntro_MENU : public cocos2d::LayerColor
{
public:
	//GameIntro_MENU();
	//~GameIntro_MENU();

	virtual bool init();

	void StartButton(Object* pSender);
	void OptionButton(Object* pSender);
	void ExitButton(Object* pSender);

	CREATE_FUNC(GameIntro_MENU);
};
#endif // __GAMEINTRO_MENU_LAYER_H__
