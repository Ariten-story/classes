#include "GameIntro_MENU_Layer.h"
#include "CharSlotScene.h"
#include "OptionScene.h"

USING_NS_CC;

const int FONTSIZE = 40;
const int INTERVAL = 50;
/*
GameIntro_MENU::GameIntro_MENU()
{
}

GameIntro_MENU::~GameIntro_MENU()
{
}
*/
bool GameIntro_MENU::init()
{
	if (!LayerColor::initWithColor(ccc4(0, 0, 0, 0)))
	{
		return false;
	}

	Size winSize = Director::getInstance()->getWinSize();

	auto *Sprite_Start = Sprite::create("Start-normal.png");
	auto *Sprite_Option = Sprite::create("Option.png");

	auto pLabel1 = LabelTTF::create("Start", "fonts/Paint Boy.ttf", FONTSIZE);
	auto pLabel2 = LabelTTF::create("Option", "fonts/Paint Boy.ttf", FONTSIZE);
	auto pLabel3 = LabelTTF::create("Exit", "fonts/Paint Boy.ttf", FONTSIZE);
	
	auto MenuItem1 = MenuItemSprite::create(Sprite_Start, Sprite_Option, CC_CALLBACK_1(GameIntro_MENU::StartButton, this));
	auto MenuItem2 = MenuItemLabel::create(pLabel2, CC_CALLBACK_1(GameIntro_MENU::OptionButton, this));
	auto MenuItem3 = MenuItemLabel::create(pLabel3, CC_CALLBACK_1(GameIntro_MENU::ExitButton, this));

	MenuItem2->setColor(Color3B(0, 0, 0));
	MenuItem3->setColor(Color3B(0, 0, 0));

	auto pMenu = Menu::create(MenuItem1, MenuItem2, MenuItem3, NULL);
	pMenu->alignItemsVerticallyWithPadding(INTERVAL);
	pMenu->setPosition(Point(winSize.width/2, winSize.height/4));
	this->addChild(pMenu);

	return true;
}

void GameIntro_MENU::StartButton(Object* pSender)
{
	log("Start click");
	auto pScene1 = CharSlot::createScene();
	Director::getInstance()->replaceScene(TransitionFade::create(1.0, pScene1));
}
void GameIntro_MENU::OptionButton(Object* pSender)
{
	log("Option click");
	auto pScene2 = Option::createScene();
	Director::getInstance()->replaceScene(TransitionFade::create(1.0, pScene2));
}
void GameIntro_MENU::ExitButton(Object* pSender)
{
	log("Exit click");
	Director::sharedDirector()->end();
}
