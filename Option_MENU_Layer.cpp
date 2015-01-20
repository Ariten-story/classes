#include "GameIntroScene.h"
#include "Option_MENU_Layer.h"

USING_NS_CC;

const int FONTSIZE = 40;
const int INTERVAL = 40;
/*
Option_MENU::Option_MENU()
{
}

Option_MENU::~Option_MENU()
{
}
*/
bool Option_MENU::init()
{
	if (!LayerColor::initWithColor(ccc4(0, 0, 0, 0)))
	{
		return false;
	}

	Size winSize = Director::getInstance()->getWinSize();

	auto pLabel3 = LabelTTF::create("Back", "fonts/Paint Boy.ttf", FONTSIZE);

	auto MenuItem3 = MenuItemLabel::create(pLabel3, CC_CALLBACK_1(Option_MENU::BackButton, this));
	MenuItem3->setColor(Color3B(0, 0, 0));

	MenuItem3->setPosition(Point(winSize.width, 0));
	MenuItem3->setAnchorPoint(Point(1.0, 0.0));
	auto BackMenu = Menu::create(MenuItem3, NULL);
	BackMenu->setPosition(Point::ZERO);

	this->addChild(BackMenu);

	return true;
}

void Option_MENU::SoundButton(Object* pSender)
{

}
void Option_MENU::Button(Object* pSender)
{

}
void Option_MENU::BackButton(Object* pSender)
{
	log("Back click");
	auto *pScene = GameIntro::createScene();
	Director::getInstance()->replaceScene(TransitionFade::create(1.0, pScene));
}