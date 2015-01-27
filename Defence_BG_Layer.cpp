#include "Defence_BG_Layer.h"

USING_NS_CC;

bool Defence_BG::init()
{
	if (!LayerColor::initWithColor(ccc4(0, 0, 0, 0)))
	{
		return false;
	}
	//add PARALLAXNODE
	this->addChild(node);

	//후경
	auto spr_0 = Sprite::create("bg1.png");
	spr_0->setAnchorPoint(Point::ZERO);
	node->addChild(spr_0, 0, Point(1, 0), Point::ZERO);
	
	auto spr_0_1 = Sprite::create("bg1.png");
	spr_0_1->setAnchorPoint(Point::ZERO);
	node->addChild(spr_0_1, 0, Point(1, 0), Point(1280, 0));
	
	auto spr_0_2 = Sprite::create("bg1.png");
	spr_0_2->setAnchorPoint(Point::ZERO);
	node->addChild(spr_0_2, 0, Point(1, 0), Point(-1280, 0));
	//후경
	//전경
	auto spr_2 = Sprite::create("bg2.png");
	spr_2->setAnchorPoint(Point::ZERO);
	node->addChild(spr_2, 1, Point(2, 0), Point::ZERO);
	
	auto spr_2_1 = Sprite::create("bg2.png");
	spr_2_1->setAnchorPoint(Point::ZERO);
	node->addChild(spr_2_1, 1, Point(2, 0), Point(1280, 0));

	auto spr_2_2 = Sprite::create("bg2.png");
	spr_2_2->setAnchorPoint(Point::ZERO);
	node->addChild(spr_2_2, 1, Point(2, 0), Point(2560, 0));

	auto spr_2_3 = Sprite::create("bg2.png");
	spr_2_3->setAnchorPoint(Point::ZERO);
	node->addChild(spr_2_3, 1, Point(2, 0), Point(-1280, 0));

	auto spr_2_4 = Sprite::create("bg2.png");
	spr_2_4->setAnchorPoint(Point::ZERO);
	node->addChild(spr_2_4, 1, Point(2, 0), Point(-2560, 0));
	//전경	
	
	

	return true;
}
void Defence_BG::chbg_direction(){
	state = (state + 1) % 3;
	log("%d", state);
	if (state == RIGHT){
		node->stopAllActions();
		auto action_0 = MoveBy::create(10.0, Point(-1280, 0));//right
		auto action_1 = Place::create(Point::ZERO);
		auto action_2 = Sequence::create(action_0, action_1, NULL);
		auto action_3 = RepeatForever::create(action_2);
		node->runAction(action_3);
	}
	else if (state == LEFT){
		node->stopAllActions();
		auto action_0 = MoveBy::create(10.0, Point(1280, 0));//left
		auto action_1 = Place::create(Point::ZERO);
		auto action_2 = Sequence::create(action_0, action_1, NULL);
		auto action_3 = RepeatForever::create(action_2);
		node->runAction(action_3);
	}
	else if (state == STOP){
		node->stopAllActions();
	}

}