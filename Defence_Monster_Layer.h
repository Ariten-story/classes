#ifndef __DEFENCE_MONSTER_LAYER_H__
#define __DEFENCE_MONSTER_LAYER_H__

#include "cocos2d.h"
using namespace cocos2d;

#define TAG_SPRITE_M_CASTLE 1
#define TAG_SPRITE_H_CASTLE 2
#define TAG_SPRITE_Hero 3
#define TAG_SPRITE_MONSTER1 4


class Defence_Monster : public cocos2d::LayerColor
{
public:

	virtual bool init();

	CREATE_FUNC(Defence_Monster);

	void setMonster(float delta);
	void update(float delta);
};
#endif // __DEFENCE_Monster_LAYER_H__
