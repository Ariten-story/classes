#include "GameIntro_BG_Layer.h"

USING_NS_CC;
/*
GameIntro_BG::GameIntro_BG()
{
}

GameIntro_BG::~GameIntro_BG()
{
}
*/
bool GameIntro_BG::init()
{
	if (!LayerColor::initWithColor(Color4B(255, 255, 255, 255)))
	{
		return false;
	}

	Size winSize = Director::getInstance()->getWinSize();

	auto *Sprite_BG = Sprite::create("BG.png");
	
	Sprite_BG->setPosition(Point(winSize.width/2, winSize.height/2));
	Sprite_BG->setScaleY(winSize.height / Sprite_BG->getContentSize().height);
	Sprite_BG->setScaleX(winSize.width / Sprite_BG->getContentSize().width);
	this->addChild(Sprite_BG);

	return true;
}