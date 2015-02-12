#ifndef __BGMAKER_H__
#define __BGMAKER_H__

#include "cocos2d.h"
using namespace cocos2d;

class BGMaker : public cocos2d::LayerColor
{
private:
	Sprite* characterSprite;
	Size winSize;

public:

	//BGMaker();
	//~BGMaker();

	virtual bool init();

	void createBackgroundParallax(); //배경을 만드는 함수.
	void setPositionPlayer(); // 플레이어 위치 설정 함수.
	
	CREATE_FUNC(BGMaker);
};
#endif // __BGMAKER_H__
