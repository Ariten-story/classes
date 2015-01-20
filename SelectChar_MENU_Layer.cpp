#include "SelectChar_MENU_Layer.h"
#include "CharSlotScene.h"
#include "INNScene.h"

USING_NS_CC;

const int FONTSIZE = 40;
const int INTERVAL = 40;
/*
SelectChar_MENU::SelectChar_MENU()
{
}
SelectChar_MENU::~SelectChar_MENU()
{
}
*/
bool SelectChar_MENU::init()
{
	if (!LayerColor::initWithColor(Color4B(0, 0, 0, 0)))
	{
		return false;
	}

	Size winSize = Director::getInstance()->getWinSize();

	auto pLabel1 = LabelTTF::create("Knight", "fonts/Paint Boy.ttf", FONTSIZE);
	auto pLabel2 = LabelTTF::create("Assassin", "fonts/Paint Boy.ttf", FONTSIZE);
	auto pLabel3 = LabelTTF::create("Archer", "fonts/Paint Boy.ttf", FONTSIZE);
	auto pLabel4 = LabelTTF::create("Back", "fonts/Paint Boy.ttf", FONTSIZE);

	auto MenuItem1 = MenuItemLabel::create(pLabel1, CC_CALLBACK_1(SelectChar_MENU::KnightButton, this));
	auto MenuItem2 = MenuItemLabel::create(pLabel2, CC_CALLBACK_1(SelectChar_MENU::AssassinButton, this));
	auto MenuItem3 = MenuItemLabel::create(pLabel3, CC_CALLBACK_1(SelectChar_MENU::ArcherButton, this));
	auto MenuItem4 = MenuItemLabel::create(pLabel4, CC_CALLBACK_1(SelectChar_MENU::BackButton, this));
	
	MenuItem1->setColor(Color3B(0, 0, 0));
	MenuItem2->setColor(Color3B(0, 0, 0));
	MenuItem3->setColor(Color3B(0, 0, 0));
	MenuItem4->setColor(Color3B(0, 0, 0));

	MenuItem4->setPosition(Point(winSize.width, 0));
	MenuItem4->setAnchorPoint(Point(1.0, 0.0));
	auto backMenu = Menu::create(MenuItem4, NULL);
	backMenu->setPosition(Point::ZERO);
	
	auto selectMenu = Menu::create(MenuItem1, MenuItem2, MenuItem3, NULL);
	selectMenu->alignItemsHorizontallyWithPadding(INTERVAL);

	this->addChild(backMenu);
	this->addChild(selectMenu);
	return true;
}

void SelectChar_MENU::KnightButton(Object* pSender)
{
	log("Knight click");
	auto *pScene = INN::createScene();
	Director::getInstance()->replaceScene(TransitionFade::create(1.0, pScene));
}
void SelectChar_MENU::AssassinButton(Object* pSender)
{
	log("Assassin click");
	auto *pScene = INN::createScene();
	Director::getInstance()->replaceScene(TransitionFade::create(1.0, pScene));
}
void SelectChar_MENU::ArcherButton(Object* pSender)
{
	log("Archer click");
	auto *pScene = INN::createScene();
	Director::getInstance()->replaceScene(TransitionFade::create(1.0, pScene));
}
void SelectChar_MENU::BackButton(Object* pSender)
{
	log("Back click");
	auto *pScene = CharSlot::createScene();
	Director::getInstance()->replaceScene(TransitionFade::create(1.0, pScene));
}