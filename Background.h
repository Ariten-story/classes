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
	// Stage�� ��� ���� �Լ�.
	static Background* creaeteWithType(int stage);
	//��� ũ�� ���� �Լ�.
	void setbackgroundScale(Sprite* sprite1, Sprite* sprite2);
	//ParallaxNode���� �Լ�.
	void setParallaxNode(Sprite* sprite1, Sprite* sprite2);
	//ParallaxNode��ȯ �Լ�.
	Node* getParallaxNode();
	//ParallaxNode���� �Լ�.
	void release();
};
#endif // __BACKGROUND_H__