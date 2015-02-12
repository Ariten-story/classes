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

	void createBackgroundParallax(); //����� ����� �Լ�.
	void setPositionPlayer(); // �÷��̾� ��ġ ���� �Լ�.
	
	CREATE_FUNC(BGMaker);
};
#endif // __BGMAKER_H__