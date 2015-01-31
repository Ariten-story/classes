#include "Defence_Monster_Layer.h"

USING_NS_CC;

bool Defence_Monster::init()
{
	if (!LayerColor::init())
	{
		return false;
	}

	Size winSize = Director::getInstance()->getWinSize();
	
	
	auto spr_M_Castle = Sprite::create("M_Castle.png");
	auto spr_H_Castle = Sprite::create("H_Castle.png");
	
	
	
	spr_M_Castle->setScaleY(winSize.height / spr_M_Castle->getContentSize().height/3);
	spr_M_Castle->setScaleX(winSize.width / spr_M_Castle->getContentSize().width/8);
	spr_M_Castle->setAnchorPoint(Point(1, 0));
	spr_M_Castle->setPosition(Point(winSize.width, winSize.height / 4));
	spr_M_Castle->setTag(TAG_SPRITE_M_CASTLE);

	spr_H_Castle->setScaleY(winSize.height / spr_H_Castle->getContentSize().height/3);
	spr_H_Castle->setScaleX(winSize.width / spr_H_Castle->getContentSize().width/8);
	spr_H_Castle->setPosition(Point(winSize.width/20 , winSize.height / 5 *2));
	spr_H_Castle->setTag(TAG_SPRITE_H_CASTLE);
	

	

	this->addChild(spr_M_Castle,2);
	this->addChild(spr_H_Castle,1);

	this->scheduleUpdate();
	this->schedule(schedule_selector(Defence_Monster::setMonster), 5.0);
	

	return true;
}

void Defence_Monster::setMonster(float delta)
{

	Size winSize = Director::getInstance()->getWinSize();

	auto spr_Monster1 = Sprite::create("Monster1.png");

	spr_Monster1->setScaleY(winSize.height / spr_Monster1->getContentSize().height / 9);
	spr_Monster1->setScaleX(winSize.width / spr_Monster1->getContentSize().width / 13);
	spr_Monster1->setPosition(Point(winSize.width, winSize.height/3));
	spr_Monster1->setTag(TAG_SPRITE_MONSTER1);
	this->addChild(spr_Monster1);



	auto M_ActionForward = MoveBy::create(2, Point(-100, 0));
	auto M_DelayAction = DelayTime::create(2.0);
	auto M_Action = Sequence::create(M_ActionForward, M_DelayAction,NULL);
	auto rep1 = RepeatForever::create(M_Action);
	spr_Monster1->runAction(rep1);
	
}

void Defence_Monster::update(float delta)
{
	if (this->getChildByTag(TAG_SPRITE_MONSTER1) != NULL)
	{

		auto spr_H_Castle = (Sprite*)this->getChildByTag(TAG_SPRITE_H_CASTLE);
		auto spr_Monster = (Sprite*)this->getChildByTag(TAG_SPRITE_MONSTER1);

		Rect rectCastle = spr_H_Castle->getBoundingBox();
		Rect rectMonster = spr_Monster->getBoundingBox();

		if (rectCastle.intersectsRect(rectMonster))
		{
			this->removeChildByTag(TAG_SPRITE_MONSTER1);
		}
	}
}