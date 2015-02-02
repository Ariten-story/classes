#include "Defence_BG_Layer.h"

USING_NS_CC;

bool Defence_BG::init()
{
	if (!LayerColor::initWithColor(ccc4(0, 0, 0, 0)))
	{
		return false;
	}
	//add PARALLAXNODE
	//this->addChild(node);
	Size winSize = Director::getInstance()->getWinSize();
	//배경 좌표 카운터..
	bg_pos = -SPEED;
	//배경 좌표 카운터..

	//BG
	spr_0_0->setAnchorPoint(Point::ZERO);
	spr_0_0->setPosition(Point(0, 0));
	spr_0_0->setScaleY(winSize.height / spr_0_0->getContentSize().height);
	spr_0_0->setScaleX(winSize.width / spr_0_0->getContentSize().width);
	this->addChild(spr_0_0);

	spr_0_1->setAnchorPoint(Point::ZERO);
	spr_0_1->setPosition(Point(winSize.width, 0));
	spr_0_1->setScaleY(winSize.height / spr_0_1->getContentSize().height);
	spr_0_1->setScaleX(winSize.width / spr_0_1->getContentSize().width);
	this->addChild(spr_0_1);
	//BG
	//FG
	spr_1_0->setAnchorPoint(Point::ZERO);
	spr_1_0->setPosition(Point(0, 0));
	spr_1_0->setScaleX(winSize.width / spr_1_0->getContentSize().width);
	this->addChild(spr_1_0);

	spr_1_1->setAnchorPoint(Point::ZERO);
	spr_1_1->setPosition(Point(winSize.width, 0));
	spr_1_1->setScaleX(winSize.width / spr_1_1->getContentSize().width);
	this->addChild(spr_1_1);

	spr_1_2->setAnchorPoint(Point::ZERO);
	spr_1_2->setPosition(Point(winSize.width*2, 0));
	spr_1_2->setScaleX(winSize.width / spr_1_2->getContentSize().width);
	this->addChild(spr_1_2);
	//FG
	return true;
}
void Defence_BG::chbg_Left(){
	
	if (bg_pos < -5){
		bg_pos += SPEED;
		//BG
		spr_0_0->setPosition(Point(spr_0_0->getPositionX() + SPEED, spr_0_0->getPositionY()));
		spr_0_1->setPosition(Point(spr_0_1->getPositionX() + SPEED, spr_0_1->getPositionY()));
		//BG
		//FG
		spr_1_0->setPosition(Point(spr_1_0->getPositionX() + SPEED*2, spr_1_0->getPositionY()));
		spr_1_1->setPosition(Point(spr_1_1->getPositionX() + SPEED*2, spr_1_1->getPositionY()));
		spr_1_2->setPosition(Point(spr_1_2->getPositionX() + SPEED*2, spr_1_2->getPositionY()));
		//FG
	}
	log("%d", bg_pos);
}

void Defence_BG::chbg_Right(){
	
	if (bg_pos > -1280){
		bg_pos -= SPEED;
		//BG
		spr_0_0->setPosition(Point(spr_0_0->getPositionX() - SPEED, spr_0_0->getPositionY()));
		spr_0_1->setPosition(Point(spr_0_1->getPositionX() - SPEED, spr_0_1->getPositionY()));
		//BG
		//FG
		spr_1_0->setPosition(Point(spr_1_0->getPositionX() - SPEED * 2, spr_1_0->getPositionY()));
		spr_1_1->setPosition(Point(spr_1_1->getPositionX() - SPEED * 2, spr_1_1->getPositionY()));
		spr_1_2->setPosition(Point(spr_1_2->getPositionX() - SPEED * 2, spr_1_2->getPositionY()));
		//FG
	}
	log("%d", bg_pos);
}
