#ifndef __PopLayer__
#define __PopLayer__

#include "cocos2d.h"
#include "GameIntroScene.h"

USING_NS_CC;

class PopLayer : public cocos2d::CCLayerColor
{
public:

	virtual bool init();


	cocos2d::CCSize winSize;
	CCLayerColor* backLayer;
	CCLayerColor* popUpLayer;
	void PopLayer::doClose(CCObject* pSender);

	CREATE_FUNC(PopLayer);
};

#endif // _Pop_Layer__H
