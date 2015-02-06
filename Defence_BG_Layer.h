#ifndef __DEFENCE_BG_LAYER_H__
#define __DEFENCE_BG_LAYER_H__

#include "cocos2d.h"
using namespace cocos2d;

#define SPEED 5

class Defence_BG : public cocos2d::LayerColor
{
public:

	virtual bool init();

	void chbg_Right();//오른쪽으로 이동
	void chbg_Left();//왼쪽으로 이동

	CREATE_FUNC(Defence_BG);

private:
	int bg_pos ;
	Sprite* spr_0_0 = Sprite::create("bg1.png");
	Sprite* spr_0_1 = Sprite::create("bg1.png");
	Sprite* spr_1_0 = Sprite::create("bg2.png");
	Sprite* spr_1_1 = Sprite::create("bg2.png");
	Sprite* spr_1_2 = Sprite::create("bg2.png");
};

#endif // __DEFENCE_BG_LAYER_H__
