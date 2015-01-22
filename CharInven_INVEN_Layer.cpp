
#include "CharInven_Inven_Layer.h"

USING_NS_CC;

const int FONTSIZE = 40;
const int INTERVAL = 10;

bool CharInven_INVEN::init()
{
	if (!Layer::init())
	{
		return false;
	}

	Size winSize = Director::getInstance()->getWinSize();
	/*
	auto pBackGround = Sprite::create("CHARINVEN_INVEN1.png");
	if (!pBackGround)
	{
		return false;
	}

	pBackGround->setPosition(Point(winSize.width*11 / 16, winSize.height*11 / 24));
	pBackGround->setScaleY(winSize.height / 400);
	pBackGround->setScaleX(winSize.width / 640);

	this->addChild(pBackGround);
	*/
	auto spr_1_n = Sprite::create("inven-btn-weapon-n.png");
	auto spr_1_s = Sprite::create("inven-btn-weapon-s.png");
	auto spr_2_n = Sprite::create("inven-btn-armor-n.png");
	auto spr_2_s = Sprite::create("inven-btn-armor-s.png");
	auto spr_3_n = Sprite::create("inven-btn-accessory-n.png");
	auto spr_3_s = Sprite::create("inven-btn-accessory-s.png");
	auto spr_4_n = Sprite::create("inven-btn-consum-n.png");
	auto spr_4_s = Sprite::create("inven-btn-consum-s.png");
	auto spr_5_n = Sprite::create("inven-btn-reinforce-n.png");
	auto spr_5_s = Sprite::create("inven-btn-reinforce-s.png");
	auto spr_6_n = Sprite::create("inven-btn-myinven-n.png");
	auto spr_6_s = Sprite::create("inven-btn-myinven-s.png");

	auto item_1 = MenuItemSprite::create(spr_1_n, spr_1_s, CC_CALLBACK_1(CharInven_INVEN::WeaponSlot, this));
	auto item_2 = MenuItemSprite::create(spr_2_n, spr_2_s, CC_CALLBACK_1(CharInven_INVEN::ArmorSlot, this));
	auto item_3 = MenuItemSprite::create(spr_3_n, spr_3_s, CC_CALLBACK_1(CharInven_INVEN::AccessorySlot, this));
	auto item_4 = MenuItemSprite::create(spr_4_n, spr_4_s, CC_CALLBACK_1(CharInven_INVEN::ConsumSlot, this));
	auto item_5 = MenuItemSprite::create(spr_5_n, spr_5_s, CC_CALLBACK_1(CharInven_INVEN::ReinforceSlot, this));
	auto item_6 = MenuItemSprite::create(spr_6_n, spr_6_s, CC_CALLBACK_1(CharInven_INVEN::MyinvenSlot, this));

	auto menu = Menu::create(item_1, item_2, item_3, item_4, item_5, item_6, NULL);
	menu->alignItemsHorizontallyWithPadding(INTERVAL);
	


	menu->setPosition(Point(winSize.width * 11 / 16, winSize.height*9 / 10));
	this->addChild(menu);

	return true;
}

void CharInven_INVEN::WeaponSlot(Object* pSender)
{
	Size winSize = Director::getInstance()->getWinSize();
	auto tItem = (MenuItem *)pSender;

	for (int j = 11; j < 70; j += 11)
	{
		auto pInven_d = (Sprite *)getChildByTag(j);
		this->removeChild(pInven_d, true);
	}
	auto pInven = Sprite::create("inven.png");

	pInven->setPosition(Point(winSize.width * 11 / 16, winSize.height * 11 / 24));
	pInven->setScaleY(winSize.height / 400);
	pInven->setScaleX(winSize.width / 640);
	pInven->setTag(11);

	this->addChild(pInven);
	
}
void CharInven_INVEN::ArmorSlot(Object* pSender)
{
	Size winSize = Director::getInstance()->getWinSize();
	auto tItem = (MenuItem *)pSender;

	for (int j = 11; j < 70; j += 11)
	{
		auto pInven_d = (Sprite *)getChildByTag(j);
		this->removeChild(pInven_d, true);
	}
	auto pInven = Sprite::create("inven.png");

	pInven->setPosition(Point(winSize.width * 11 / 16, winSize.height * 11 / 24));
	pInven->setScaleY(winSize.height / 400);
	pInven->setScaleX(winSize.width / 640);
	pInven->setTag(22);

	this->addChild(pInven);
}
void CharInven_INVEN::AccessorySlot(Object* pSender)
{
	Size winSize = Director::getInstance()->getWinSize();
	auto tItem = (MenuItem *)pSender;

	for (int j = 11; j < 70; j += 11)
	{
		auto pInven_d = (Sprite *)getChildByTag(j);
		this->removeChild(pInven_d, true);
	}
	auto pInven = Sprite::create("inven.png");

	pInven->setPosition(Point(winSize.width * 11 / 16, winSize.height * 11 / 24));
	pInven->setScaleY(winSize.height / 400);
	pInven->setScaleX(winSize.width / 640);
	pInven->setTag(33);

	this->addChild(pInven);
}
void CharInven_INVEN::ConsumSlot(Object* pSender)
{
	Size winSize = Director::getInstance()->getWinSize();
	auto tItem = (MenuItem *)pSender;

	for (int j = 11; j < 70; j += 11)
	{
		auto pInven_d = (Sprite *)getChildByTag(j);
		this->removeChild(pInven_d, true);
	}
	auto pInven = Sprite::create("inven.png");

	pInven->setPosition(Point(winSize.width * 11 / 16, winSize.height * 11 / 24));
	pInven->setScaleY(winSize.height / 400);
	pInven->setScaleX(winSize.width / 640);
	pInven->setTag(44);

	this->addChild(pInven);
}
void CharInven_INVEN::ReinforceSlot(Object* pSender)
{
	Size winSize = Director::getInstance()->getWinSize();
	auto tItem = (MenuItem *)pSender;

	for (int j = 11; j < 70; j += 11)
	{
		auto pInven_d = (Sprite *)getChildByTag(j);
		this->removeChild(pInven_d, true);
	}
	auto pInven = Sprite::create("inven.png");

	pInven->setPosition(Point(winSize.width * 11 / 16, winSize.height * 11 / 24));
	pInven->setScaleY(winSize.height / 400);
	pInven->setScaleX(winSize.width / 640);
	pInven->setTag(55);

	this->addChild(pInven);
}
void CharInven_INVEN::MyinvenSlot(Object* pSender)
{
	Size winSize = Director::getInstance()->getWinSize();
	auto tItem = (MenuItem *)pSender;

	for (int j = 11; j < 70; j += 11)
	{
		auto pInven_d = (Sprite *)getChildByTag(j);
		this->removeChild(pInven_d, true);
	}
	auto pInven = Sprite::create("inven.png");

	pInven->setPosition(Point(winSize.width * 11 / 16, winSize.height * 11 / 24));
	pInven->setScaleY(winSize.height / 400);
	pInven->setScaleX(winSize.width / 640);
	pInven->setTag(66);

	this->addChild(pInven);
}


TransitionScene* CharInven_INVEN::createTransition(int nIndex, float t, Scene* s)
{
	Director::getInstance()->setDepthTest(false);

	switch (nIndex)
	{

	case 0:
		return TransitionJumpZoom::create(t, s);

	case 17:
		return TransitionFade::create(t, s);

	case 18:
		return TransitionFade::create(t, s, Color3B::WHITE);
	}
}