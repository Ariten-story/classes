#ifndef __GAMEINTRO_ANI_LAYER_H__
#define __GAMEINTRO_ANI_LAYER_H__

#include "cocos2d.h"
using namespace cocos2d;

class GameIntro_ANI : public cocos2d::LayerColor
{
public:

//	GameIntro_ANI();
	//~GameIntro_ANI();

	virtual bool init();

	Sprite* parent;
	Sprite* rightSprite;
	Sprite* leftSprite;

	virtual void onEnter();
	virtual void onExit();
	virtual bool onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *event);
	virtual void onTouchMoved(cocos2d::Touch *touch, cocos2d::Event *event);
	virtual void onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *event);
	virtual void onTouchCancelled(cocos2d::Touch *touch, cocos2d::Event *event);
	
	void rightmoveChar(float f);
	void leftmoveChar(float f);

	CREATE_FUNC(GameIntro_ANI);
};
#endif // __GAMEINTRO_ANI_LAYER_H__
