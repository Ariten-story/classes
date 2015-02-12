#include "BGMaker.h"
#include "Player.h"
/*
BGMaker::BGMaker(){}
BGMaker::~BGMaker(){}
*/

bool BGMaker::init()
{
	if (!LayerColor::initWithColor(Color4B(0, 0, 0, 0)))
	{
		return false;
	}
	winSize = Director::getInstance()->getWinSize();
	this->createBackgroundParallax();
	this->setPositionPlayer();
	this->addChild(characterSprite);
	this->runAction(Follow::create(characterSprite, Rect(0, 0, 1280 * 2, 720)));
	return true;
}

//����� ����� �Լ�.
void BGMaker::createBackgroundParallax()
{
	auto background1 = Sprite::create("bg1.png");
	background1->setAnchorPoint(Point(0, 0));
	background1->setScaleY(winSize.height / background1->getContentSize().height);
	background1->setScaleX(winSize.width / background1->getContentSize().width);

	auto background2 = Sprite::create("bg1.png");
	background2->setAnchorPoint(Point(0, 0));
	background2->setScaleY(winSize.height / background1->getContentSize().height);
	background2->setScaleX(winSize.width / background1->getContentSize().width);

	auto voidNode = ParallaxNode::create();

	voidNode->addChild(background1, 1, Point(1.0f, 0.0f), Point(0, 0));
	voidNode->addChild(background2, 1, Point(1.0f, 0.0f), Point(1280, 0));

	voidNode->setTag(1);
	this->addChild(voidNode, 0);
}

// �÷��̾� ��ġ ���� �Լ�.
void BGMaker::setPositionPlayer()
{
	characterSprite = Player::getInstance()->getCharacter();
	characterSprite->setPosition(Point(winSize.width / 2, winSize.height / 2));
}