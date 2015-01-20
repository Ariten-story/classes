#include "CharSlot_MENU_Layer.h"
#include "GameIntroScene.h"
#include "SelectCharScene.h"

USING_NS_CC;

const int FONTSIZE = 40;
const int INTERVAL = 120;
/*
CharSlot_MENU::CharSlot_MENU()
{
}

CharSlot_MENU::~CharSlot_MENU()
{
}
*/
bool CharSlot_MENU::init()
{
	if (!LayerColor::initWithColor(Color4B(0, 0, 0, 0)))
	{
		return false;
	}

	Size winSize = Director::getInstance()->getWinSize();

	auto pLabel1 = LabelTTF::create("Slot1", "fonts/Paint Boy.ttf", FONTSIZE);
	auto pLabel2 = LabelTTF::create("Slot2", "fonts/Paint Boy.ttf", FONTSIZE);
	auto pLabel3 = LabelTTF::create("Slot3", "fonts/Paint Boy.ttf", FONTSIZE);
	auto pLabel4 = LabelTTF::create("Back", "fonts/Paint Boy.ttf", FONTSIZE);

	auto MenuItem1 = MenuItemLabel::create(pLabel1, CC_CALLBACK_1(CharSlot_MENU::SlotButton1, this));
	auto MenuItem2 = MenuItemLabel::create(pLabel2, CC_CALLBACK_1(CharSlot_MENU::SlotButton2, this));
	auto MenuItem3 = MenuItemLabel::create(pLabel3, CC_CALLBACK_1(CharSlot_MENU::SlotButton3, this));
	auto MenuItem4 = MenuItemLabel::create(pLabel4, CC_CALLBACK_1(CharSlot_MENU::BackButton, this));

	MenuItem1->setColor(Color3B(0, 0, 0));
	MenuItem2->setColor(Color3B(0, 0, 0));
	MenuItem3->setColor(Color3B(0, 0, 0));
	MenuItem4->setColor(Color3B(0, 0, 0));

	MenuItem4->setPosition(Point(winSize.width, 0));
	MenuItem4->setAnchorPoint(Point(1.0, 0.0));
	auto BackMenu = Menu::create(MenuItem4, NULL);
	BackMenu->setPosition(Point::ZERO);

	auto pMenu = Menu::create(MenuItem1, MenuItem2, MenuItem3, NULL);
	pMenu->alignItemsHorizontallyWithPadding(INTERVAL);

	this->addChild(BackMenu);
	this->addChild(pMenu);

	return true;
}

void CharSlot_MENU::SlotButton1(Object* pSender)
{
	log("Select 1");
	auto pScene = SelectChar::createScene();
	Director::getInstance()->replaceScene(TransitionFade::create(1.0, pScene));
}
void CharSlot_MENU::SlotButton2(Object* pSender)
{
	log("Select 2");
	auto pScene = SelectChar::createScene();
	Director::getInstance()->replaceScene(TransitionFade::create(1.0, pScene));
}
void CharSlot_MENU::SlotButton3(Object* pSender)
{
	log("Select 3");
	auto pScene = SelectChar::createScene();
	Director::getInstance()->replaceScene(TransitionFade::create(1.0, pScene));
}
void CharSlot_MENU::BackButton(Object* pSender)
{
	auto pScene = GameIntro::createScene();
	Director::getInstance()->replaceScene(TransitionFade::create(1.0, pScene));
}
