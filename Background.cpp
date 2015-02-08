#include "Background.h"


Background::Background()
{
	voidNode = NULL;
}

Background::~Background()
{
	log("delete Background");
	release();
}

// Stage별 배경 생성 함수.
Background* Background::creaeteWithType(int stage)
{
	const char *fileName;
	Background* background = new Background();

	//이부분 추후에 if~else로 구성.
	fileName = "bg1.png";
	auto background1 = Sprite::create(fileName);
	auto background2 = Sprite::create(fileName);
	background->setbackgroundScale(background1, background2);
	background->setParallaxNode(background1, background2);
	
	return background;

	CC_SAFE_DELETE(background);
}

//배경 크기 조절 함수.
void Background::setbackgroundScale(Sprite* sprite1, Sprite* sprite2)
{
	winSize = Director::getInstance()->getWinSize();

	sprite1->setAnchorPoint(Point(0, 0));
	sprite1->setScaleY(winSize.height / sprite1->getContentSize().height);
	sprite1->setScaleX(winSize.width / sprite1->getContentSize().width);

	sprite2->setAnchorPoint(Point(0, 0));
	sprite2->setScaleY(winSize.height / sprite2->getContentSize().height);
	sprite2->setScaleX(winSize.width / sprite2->getContentSize().width);
}

//ParallaxNode생성 함수.
void Background::setParallaxNode(Sprite* sprite1, Sprite* sprite2)
{
	voidNode = ParallaxNode::create();

	voidNode->addChild(sprite1, 1, Point(1.0f, 0.0f), Point(0, 0));
	voidNode->addChild(sprite2, 1, Point(1.0f, 0.0f), Point(1280, 0));

	voidNode->setTag(1);
}

//ParallaxNode반환 함수.
Node* Background::getParallaxNode()
{
	return voidNode;
}

//ParallaxNode삭제 함수.
void Background::release()
{
	if (voidNode != NULL)
	{
		voidNode->removeFromParentAndCleanup(true);
		voidNode = NULL;
	}
}