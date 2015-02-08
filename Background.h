#ifndef __BACKGROUND_H__
#define __BACKGROUND_H__

#include "cocos2d.h"
using namespace cocos2d;

class Background : public cocos2d::CCSprite
{
private:
	ParallaxNode* voidNode;
	Size winSize;

public:

	Background();
	virtual ~Background();
	// Stage별 배경 생성 함수.
	static Background* creaeteWithType(int stage);
	//배경 크기 조절 함수.
	void setbackgroundScale(Sprite* sprite1, Sprite* sprite2);
	//ParallaxNode생성 함수.
	void setParallaxNode(Sprite* sprite1, Sprite* sprite2);
	//ParallaxNode반환 함수.
	Node* getParallaxNode();
	//ParallaxNode삭제 함수.
	void release();
};
#endif // __BACKGROUND_H__
