#ifndef __DEFENCE_BG_LAYER_H__
#define __DEFENCE_BG_LAYER_H__

#include "cocos2d.h"
using namespace cocos2d;

class Defence_BG : public cocos2d::LayerColor
{
public:

	virtual bool init();

	void chbg_direction();//작동 안함

	CREATE_FUNC(Defence_BG);

private:
	ParallaxNode* node = ParallaxNode::create();

	enum {
		RIGHT,
		LEFT,
		STOP
	};
	int state = 0;
	//state 0 1 2 오른쪽 왼쪽 정지 실험 완료
};

#endif // __DEFENCE_BG_LAYER_H__
